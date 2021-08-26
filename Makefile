CC=g++
PROJ_DIR=$(IHOURS)/iHours-api
LIBS=$(PROJ_DIR)/libs
LIB_DIR=$(PROJ_DIR)/libs/database/query-builder
SRC_CPP=query-builder.cpp
SRC_HPP=query-builder.h
CFLAGS=-I$(LIBS)

DIR_BIN=bin
DIR_OBJ=obj

TEST_CPP=$(DIR_BIN)/query-builder-test.cpp
TEST_BIN=$(DIR_BIN)/test-query-builder
TEST_OBJ=$(DIR_OBJ)/query-builder-test.o $(DIR_OBJ)/query-builder.o
TEST_CFLAGS=-I$(LIBS)

all: clean test

$(DIR_OBJ)/%.o: %.cpp
	@echo "Compiling $^ into $@"
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $^
	mv -t $(DIR_OBJ) ./*.o
	@echo ""

$(TEST_BIN): $(TEST_OBJ)
	@echo "Linking $^ into $@"
	mkdir -p $(DIR_BIN)
	$(CC) -o $(TEST_BIN) $^
	@echo "Now you can run $(TEST_BIN)"
	@echo ""

test: $(TEST_BIN)
	@echo "Running $(TEST_BIN)"
	$(TEST_BIN)

clean: 
	rm -rf $(DIR_BIN)
	@echo "directory $(DIR_BIN) deleted."
	rm -rf $(DIR_OBJ)
	@echo "directory $(DIR_OBJ) files deleted."
