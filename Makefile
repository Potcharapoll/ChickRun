CC 		  = gcc
CFLAGS  = -Wall -Wextra -O2

LD      = gcc
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

OBJ     = obj
SRC     = src
SRCS	  = $(wildcard $(SRC)/*.c)
OBJS    = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
TARGET  = chickrun

all: dir $(TARGET)
	
debug: CFLAGS += -DDEBUG -g
debug: dir $(TARGET)

$(OBJ)/%.o:$(SRC)/%.c
	$(CC) -MMD -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJS)
	$(LD) -o $@ $^ $(LDFLAGS) 

run:
	./$(TARGET)

dir:
	mkdir -p obj

.PHONY: clean
clean:
	rm -rf $(OBJ) $(TARGET)

main:
	$(CC) main.c $(CFLAGS) $(LDFLAGS)
