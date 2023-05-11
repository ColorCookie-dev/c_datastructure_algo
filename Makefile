##
# Experiments
#
# @file
	#@time --format="\n===============\ntook %E" ./$<
# @version 0.1

SRC = src
SRCS = $(wildcard ${SRC}/*.c)

INC = inc

OBJ = obj
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

BIN = bin
BINS = $(patsubst $(OBJ)/%.o, $(BIN)/%, $(OBJS))

CC = gcc
CFLAGS = -Wall -g -O0 -I${INC}
LINKERFLAGS = -lm

all: $(BINS)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN)/%: $(OBJ)/%.o
	$(CC) $(LINKERFLAGS) -o $@ $<

%: $(BIN)/%
	@echo ===============
	@./$<
	@echo ===============

.PHONY: clean
clean:
	rm -f $(BIN)/* $(OBJ)/*.o

# end
