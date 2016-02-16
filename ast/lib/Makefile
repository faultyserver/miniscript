CC=g++ -std=c++11 -g

TARGET=tester

default: remake

remake:
	make --always-make $(TARGET)


# Build the compiler
$(TARGET):
	$(CC) -o $(TARGET) test_symtab.cc

