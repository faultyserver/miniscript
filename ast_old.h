#pragma once

/* Root */
#include "ast/script.h"

/* Values */
#include "ast/field.h"
#include "ast/numeric_literal.h"
#include "ast/string_literal.h"
#include "ast/boolean_literal.h"
#include "ast/variable.h"

/* Object Initialization */
#include "ast/field_access.h"
#include "ast/field_initialization.h"

/* Lists */
#include "ast/initializer_list.h"
#include "ast/expression_list.h"
#include "ast/statement_list.h"

/* Expressions */
#include "ast/binary_op_expression.h"
#include "ast/logical_op_expression.h"
#include "ast/relational_op_expression.h"
#include "ast/negation_expression.h"
#include "ast/unary_op_expression.h"

/* Statements */
#include "ast/assignment_statement.h"
#include "ast/declaration_statement.h"
#include "ast/initialization_statement.h"
#include "ast/write_statement.h"
