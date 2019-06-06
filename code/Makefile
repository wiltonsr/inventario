#------------------------------------------------------------------------------
# Project's name
#------------------------------------------------------------------------------
PROGRAM = inventario-TH

#------------------------------------------------------------------------------
# Directories
#------------------------------------------------------------------------------
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

#------------------------------------------------------------------------------
# All source and objects files
#------------------------------------------------------------------------------
SOURCE = ${wildcard $(SRC_DIR)/*.c}
OBJ = ${addprefix $(OBJ_DIR)/, ${notdir ${SOURCE:.c=.o}}}
INCLUDE = -Iinclude/

#------------------------------------------------------------------------------
# Alias to commands
#------------------------------------------------------------------------------
MKDIR_P = mkdir -p
MYSQL_FLAGS := $(shell mysql_config --cflags --libs)

#------------------------------------------------------------------------------
# Compilator and flags
#------------------------------------------------------------------------------
CC = gcc
CFLAGS = -std=c99 -Wall -O2 $(INCLUDE) $(MYSQL_FLAGS)

.PHONY: clean directories

all: clean directories $(PROGRAM)

$(PROGRAM): $(SOURCE)
	@echo "Initing compilation..."
	@echo "Compile source files"
	$(CC) -c $(SRC_DIR)/mysql_utils.c -o $(OBJ_DIR)/mysql_utils.o $(CFLAGS)
	$(CC) -c $(SRC_DIR)/parser_options.c -o $(OBJ_DIR)/parser_options.o $(CFLAGS)
	$(CC) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o $(CFLAGS)
	@echo "Compile objects to main"
	$(CC)  $(OBJ) -o $(BIN_DIR)/$(PROGRAM) $(CFLAGS)
	@echo "Done!"

directories:
	@$(MKDIR_P) $(OBJ_DIR)
	@$(MKDIR_P) $(BIN_DIR)

clean:
	@echo "Initing Cleaning..."
	@echo "Clean executables..."
	rm -f $(PROGRAM)
	rm -rf $(BIN_DIR)
	@echo "Clean objects..."
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)
	rm -rf *.o
	rm -rf *a.out
	@echo "Ready exclusion!"
