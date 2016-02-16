%{
  #include <stdio.h>
  #include <chrono>
  #include <iostream>
  #include "ast.h"

  #define SLOC(term) { (term).first_line, (term).last_line, (term).first_column, (term).last_column }

  extern FILE *yyin;
  extern void yyerror(const char *s);
  extern int yylex();

  Node *ast = NULL;
%}

/* yylval potential value types */
%union {
  int num;
  char *str;
  Node *node;
}

/* Terminal nodes */
%token ID NUM STR
%type<num> NUM
%type<str> STR
%type<str> ID

/* Nonterminal nodes */
%type<node> script statement simple_statement complex_statement declaration assignment write assert return
%type<node> declaration_value object_initializer field_initializer array_initializer
%type<node> expr logical_or_expr logical_and_expr equality_expr relational_expr
%type<node> additive_expr mult_expr unary_expr postfix_expr primary_expr
%type<node> statement_list field_init_list member_init_list expr_list param_list
%type<node> conditional optional_else while_loop do_while_loop function_def

/* Symbols */
%token SEMICOL NEWLINE

/* Keywords */
%token kVAR kSTART kEND kWRITE kASSERT
%token kTRUE kFALSE kIF kELSE
%token kDO kWHILE kBREAK kCONTINUE
%token kFUNCTION kRETURN

/* Multi-character operators */
%token LE EE NE GE OR AND

/* Initial state */
%start script


%%

script              : start statement_list end { ast = $2; }

start               : opt_line kSTART NEWLINE

end                 : kEND opt_line

separator           : SEMICOL
                    | NEWLINE
                    | SEMICOL NEWLINE

opt_line            : NEWLINE
                    | /* empty */
                    ;

statement_list      : statement_list statement { $1->add_child($2); }
                    | /* empty */ { $$ = new StatementList(SLOC(@$)); }
                    ;

statement           : simple_statement separator
                    | complex_statement
                    ;

simple_statement    : declaration
                    | assignment
                    | write
                    | assert
                    | return
                    | kBREAK { $$ = new BreakStatement(SLOC(@1)); }
                    | kCONTINUE { $$ = new ContinueStatement(SLOC(@1)); }
                    | postfix_expr '(' expr_list ')' { $$ = new FunctionCall($1, (ExpressionList*) $3, SLOC(@1)); }
                    ;

complex_statement   : conditional opt_line
                    | while_loop opt_line
                    | do_while_loop separator
                    | function_def opt_line
                    ;

declaration         : kVAR ID '=' declaration_value { $$ = new InitializationStatement($2, $4, SLOC(@2)); }
                    | kVAR ID { $$ = new DeclarationStatement($2, SLOC(@2)); }

declaration_value   : object_initializer
                    | array_initializer
                    | expr
                    ;

object_initializer  : '{' opt_line field_init_list opt_line '}' { $$ = $3; }
                    | '{' '}' { $$ = new FieldInitializerList(SLOC(@1)); }
                    ;

field_init_list     : field_init_list ',' opt_line field_initializer { $1->add_child($4); }
                    | field_initializer { $$ = new FieldInitializerList(SLOC(@1)); $$->add_child($1); }
                    ;

field_initializer   : ID ':' expr { $$ = new FieldInitialization($1, $3, SLOC(@1)); }
                    ;

array_initializer   : '[' opt_line member_init_list opt_line ']' { $$ = $3; }
                    | '[' ']' { $$ = new MemberInitializerList(SLOC(@1)); }
                    ;

member_init_list    : member_init_list ',' opt_line expr { $1->add_child($4); }
                    | expr { $$ = new MemberInitializerList(SLOC(@1)); $$->add_child($1); }
                    ;


assignment          : postfix_expr '=' expr { $1->lhs = true; $$ = new AssignmentStatement($1, $3, SLOC(@1)); }
                    ;

write               : kWRITE '(' expr_list ')' { $$ = new WriteStatement((ExpressionList*) $3, SLOC(@1)); }
                    ;

assert              : kASSERT '(' expr ')' { $$ = new AssertStatement($3, SLOC(@1)); }
                    ;

return              : kRETURN /**/ { $$ = new ReturnStatement(NULL, SLOC(@1)); }
                    | kRETURN expr { $$ = new ReturnStatement($2, SLOC(@1)); }
                    ;

conditional         : kIF '(' expr ')' '{' NEWLINE statement_list '}' optional_else { $$ = new IfStatement($3, (StatementList*) $7, $9, SLOC(@1)); }
                    ;

optional_else       : kELSE conditional { $$ = $2; }
                    | kELSE '{' NEWLINE statement_list '}' { $$ = $4; }
                    | /* empty */ { $$ = NULL; }
                    ;

while_loop          : kWHILE '(' expr ')' '{' NEWLINE statement_list '}' { $$ = new WhileStatement($3, (StatementList*) $7, SLOC(@1)); }
                    ;

do_while_loop       : kDO '{' NEWLINE statement_list '}' opt_line kWHILE '(' expr ')' { $$ = new DoWhileStatement($9, (StatementList*) $4, SLOC(@9)); }
                    ;

function_def        : kFUNCTION ID '(' param_list ')' '{' NEWLINE statement_list '}' { $$ = new FunctionDeclaration($2, (ParameterList*) $4, (StatementList*) $8, SLOC(@1)); }

param_list          : param_list ',' ID { ((ParameterList*) $1)->add_child($3); }
                    | ID { $$ = new ParameterList(SLOC(@1)); ((ParameterList*) $$)->add_child($1); }
                    | /* empty */ { $$ = new ParameterList(SLOC(@$)); }

expr_list           : expr_list ',' expr { $1->add_child($3); }
                    | expr { $$ = new ExpressionList(SLOC(@1)); $$->add_child($1); }
                    | /* empty */ { $$ = new ExpressionList(SLOC(@$)); }
                    ;

expr                : logical_or_expr
                    ;

logical_or_expr     : logical_and_expr
                    | logical_or_expr OR logical_and_expr { $$ = new LogicalOpExpression($1, "||", $3, SLOC(@1)); }
                    ;

logical_and_expr    : equality_expr
                    | logical_and_expr AND equality_expr { $$ = new LogicalOpExpression($1, "&&", $3, SLOC(@1)); }
                    ;

equality_expr       : relational_expr
                    | equality_expr EE relational_expr { $$ = new EqualityOpExpression($1, "==", $3, SLOC(@1)); }
                    | equality_expr NE relational_expr { $$ = new EqualityOpExpression($1, "!=", $3, SLOC(@1)); }
                    ;

relational_expr     : additive_expr
                    | relational_expr '<' additive_expr { $$ = new RelationalOpExpression($1, "<",  $3, SLOC(@1)); }
                    | relational_expr '>' additive_expr { $$ = new RelationalOpExpression($1, ">",  $3, SLOC(@1)); }
                    | relational_expr GE  additive_expr { $$ = new RelationalOpExpression($1, ">=", $3, SLOC(@1)); }
                    | relational_expr LE  additive_expr { $$ = new RelationalOpExpression($1, "<=", $3, SLOC(@1)); }
                    ;

additive_expr       : mult_expr
                    | additive_expr '+' mult_expr { $$ = new BinaryOpExpression($1, "+", $3, SLOC(@1)); }
                    | additive_expr '-' mult_expr { $$ = new BinaryOpExpression($1, "-", $3, SLOC(@1)); }
                    ;

mult_expr           : unary_expr
                    | mult_expr '*' unary_expr { $$ = new BinaryOpExpression($1, "*", $3, SLOC(@1)); }
                    | mult_expr '/' unary_expr { $$ = new BinaryOpExpression($1, "/", $3, SLOC(@1)); }
                    ;

unary_expr          : postfix_expr
                    | '!' postfix_expr { $$ = new NegationOpExpression($2, SLOC(@1)); }
                    ;

postfix_expr        : primary_expr
                    | postfix_expr '.' ID { $$ = new ObjectReference($1, $3, SLOC(@3)); }
                    | postfix_expr '[' expr ']' { $$ = new ArraySubscript($1, $3, SLOC(@3)); }
                    | postfix_expr '(' expr_list ')' { $$ = new FunctionCall($1, (ExpressionList*) $3, SLOC(@1)); }
                    ;

primary_expr        : '(' expr ')' { $$ = $2; }
                    | ID      { $$ = new VariableReference($1, SLOC(@1)); }
                    | NUM     { $$ = new NumericLiteral($1,    SLOC(@1)); }
                    | STR     { $$ = new StringLiteral($1,     SLOC(@1)); }
                    | kTRUE   { $$ = new BooleanLiteral(true,  SLOC(@1)); }
                    | kFALSE  { $$ = new BooleanLiteral(false, SLOC(@1)); }
                    ;

%%

void yyerror(const char *s) {
  fprintf(stderr, "%s\n", s);
}

int main(int charc, char** argv) {
  yyin = fopen(argv[1], "r");

  yyparse();

  /* Set up the initial Symbol Table */
  SYMTAB.push_scope(new Scope());
  ast->visit();
  /* Clear the last scope from the table */
  SYMTAB.pop_scope();
}
