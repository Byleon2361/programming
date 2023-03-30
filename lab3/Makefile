#OBJ = src/main.o src/coder.o src/command.o
APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

 CFLAGS = -Wall 
 DEPS = -MMD
 GDB = 

 all: main

 main: $(APP_OBJECTS)
 	$(CC) -o $@ $^
 %.o: %.c
 	$(CC) $(CFLAGS)  $(DEPS) -c $^ -o $@
 clean:
 	rm main *.o
