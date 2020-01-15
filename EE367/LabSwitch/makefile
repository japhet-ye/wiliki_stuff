# You can use variables in Makefiles in order to make all of the repetitive 
# typing much easier. Here, we include the C++11 version flag as well as 
# additional warning flags to make compilation stricter (and, thus, our programs 
# safer).
#
CXXFLAGS := -Wall 
CC := gcc

SRC_DIR := ./src
OBJ_DIR := ./obj
INCLUDE_DIRS := -I./dep/ -I./include/

# Here, we are calling functions available in GNU Make in order to get all of 
# the .o and .cpp files in ./src so we can use them in our rules later.
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: ./bin/net367

# This build each of the .c in the src dir into a .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC)  $(INCLUDE_DIRS)  -c -o  $@ $<

./bin/net367: $(OBJ_FILES) 
	$(CC)  $(INCLUDE_DIRS) -o ./bin/net367 $(OBJ_FILES)


# Convenience rules for the command line to quickly test a class

net367: ./bin/net367

clean:
	rm ./obj/*.o
	rm ./bin/*.out



