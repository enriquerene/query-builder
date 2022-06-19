CC=g++
CFLAGS=-std=c++11 -Wall

DIR_BIN=bin
DIR_TEST=tests
DIR_SRC=src

TEST_MAIN=$(DIR_TEST)/main.cpp
TEST_BIN=$(DIR_BIN)/test-query-builder
TEST_FLAGS=--success

all: clean $(DIR_BIN) test

$(TEST_BIN): $(TEST_MAIN)
	@echo "Building $@"
	$(CC) $(CFLAGS) -o $@ $<
	@echo "Now you can run $(TEST_BIN) $(TEST_FLAGS)"
	@echo ""

$(DIR_BIN):
	mkdir -p $(DIR_BIN)

test: $(TEST_BIN)
	@echo "Running $(TEST_BIN)"
	$(TEST_BIN) $(TEST_FLAGS)

clean: 
	rm -rf $(DIR_BIN)
	@echo "directory $(DIR_BIN) deleted."
	rm -rf $(DIR_OBJ)
	@echo "directory $(DIR_OBJ) files deleted."
