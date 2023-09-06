.PHONY: all clean re

CC:= gcc
SRC_DIR:=srcs/
OBJ_DIR:=build/
SRC:= main.c
OBJ = $(addprefix $(OBJ_DIR),$(notdir $(SRC:.c=.o)))
TARGET:= main

HEADER:= include/header.h
CFLAGS:= -Wall -Werror -Wextra
LIBS = -lXft -lX11 -lXcursor -lXcomposite
DEP:= -I /usr/X11/include -L /usr/X11/lib
INC:= -I include

all: $(OBJ_DIR) $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $< -o $@ $(INC) $(LIBS) $(DEP)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HEADER)
	$(CC) $(CFLAGS) $(DEP) $(LIBS) $(INC) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

re: clean all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
