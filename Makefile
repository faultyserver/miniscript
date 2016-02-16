CC= g++ -std=c++11 -Ofast -fprofile-use -Wno-deprecated-register -x c++
YACC= bison -d --verbose
LEX= flex

TARGET= parser

SINGLE_TEST_FILE= temp_test
TEST_DIR= ./test

default: remake

remake:
	@make --always-make --ignore-errors -s $(TARGET)

# Build the compiler
$(TARGET): parser.tab.cc lex.yy.c
	# ifeq is weird, so I just pushed everything into a separate bash script
	bash ./portable_build.sh "$(CC)" $(TARGET)

dev: parser.tab.cc lex.yy.c
	$(YACC) parser.yy
	$(LEX) parser.l
	$(CC) -o $(TARGET) parser.tab.cc lex.yy.c -ll

# Compile the parser
parser.tab.cc:
	$(YACC) parser.yy

# Compile the lexer
lex.yy.c:
	$(LEX) parser.l


# Clean up
clean:
	rm -f lex.yy.* parser.tab.* parser.output parser


# Testing script
.PHONY: test
test:
	ruby $(TEST_DIR)/test.rb

# One-off testing
.PHONY: single_test
single_test:
	./$(TARGET) $(SINGLE_TEST_FILE)

# Line count
.PHONY: line_count
line_count:
	ls ast/*/* parser.yy parser.l Makefile | xargs wc -l | sort
