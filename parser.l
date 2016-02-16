%{
  #include <stdio.h>
  #include <string.h>

  #include "ast.h"
  #include "parser.tab.hh"
  #define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;
%}

%option yylineno

%%


  /* KEYWORDS */
var                                   { return kVAR;      }
\<script\ type=\"text\/JavaScript\"\> { return kSTART;    }
\<\/script\>                          { return kEND;      }
document\.write                       { return kWRITE;    }
assert                                { return kASSERT;   }
true                                  { return kTRUE;     }
false                                 { return kFALSE;    }
if                                    { return kIF;       }
else                                  { return kELSE;     }
do                                    { return kDO;       }
while                                 { return kWHILE;    }
break                                 { return kBREAK;    }
continue                              { return kCONTINUE; }
function                              { return kFUNCTION; }
return                                { return kRETURN;   }
  /* END KEYWORDS */

  /* Operators */
==    { return EE;  }
!=    { return NE;  }
\|\|  { return OR;  }
&&    { return AND; }
\<=   { return LE;  }
\>=   { return GE;  }


  /* Standard identifier */
[a-zA-Z][a-zA-Z0-9_]*     { yylval.str = strdup(yytext); return ID;  }
  /* Any number on its on will get converted */
[0-9]+                    { yylval.num = atoi(yytext);   return NUM; }
  /* Strings can not contain quotes or newlines inside of them */
\"[^\"\n]*\"              { char* str = strdup(yytext); str++; str[strlen(str)-1]=0; yylval.str = str; return STR; }

  /* Symbols */
;                         { return SEMICOL; }
(\r?\n)+                  { return NEWLINE; }

  /* No one likes you, whitespace */
[ \t\r\f]+                    /* ignore */;

  /* Everything else gets passed as a literal */
. { return *yytext; }
