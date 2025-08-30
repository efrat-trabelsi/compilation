# Compiler settings
CC = gcc
CFLAGS = -Wall -g
TARGET = cpq
SRCDIR = src

# Generated files
PARSER_FILES = $(SRCDIR)/cpl.tab.c $(SRCDIR)/cpl.tab.h $(SRCDIR)/cpl.output
LEXER_FILES = $(SRCDIR)/lex.yy.c

# Default target
all: $(TARGET)

# Build the compiler
$(TARGET): $(SRCDIR)/cpl.tab.c $(SRCDIR)/lex.yy.c $(SRCDIR)/cpq.c $(SRCDIR)/code_gen.c $(SRCDIR)/symbol_table.c
	$(CC) -o $@ $^

# Generate parser files
$(SRCDIR)/cpl.tab.c $(SRCDIR)/cpl.tab.h: $(SRCDIR)/cpl.y
	cd $(SRCDIR) && bison -v -d cpl.y

# Generate lexer files
$(SRCDIR)/lex.yy.c: $(SRCDIR)/cla.lex.txt $(SRCDIR)/cpl.tab.h
	cd $(SRCDIR) && flex cla.lex.txt

# Clean generated files
clean:
	rm -f $(TARGET) $(PARSER_FILES) $(LEXER_FILES)

# Rebuild everything
rebuild: clean all

# Run tests
test: $(TARGET)
	python3 test_runner.py

# Clean test output files
test-clean:
	rm -f tests/*.qud

clean-all: clean test-clean

.PHONY: all clean rebuild test test-clean clean-all
