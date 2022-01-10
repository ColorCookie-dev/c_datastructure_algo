##
# Experiments
#
# @file
# @version 0.1

CC = gcc
CFLAGS = -Wall -g -O2
LINKERFLAGS =

SRC = src
SRCS = $(wildcard ${SRC}/*.c)

OBJ = obj
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

BIN = bin
BINS = $(patsubst $(OBJ)/%.o, $(BIN)/%, $(OBJS))

all: $(BINS)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN)/%: $(OBJ)/%.o
	$(CC) $(LINKERFLAGS) -o $@ $<

%: $(BIN)/%
	@echo ===============
	@time ./$<

.PHONY: clean
clean:
	rm -f $(BIN)/* $(OBJ)/*.o

# end
