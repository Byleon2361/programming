APP_NAME = app
OBJ = obj/coder.o obj/command.o obj/main.o 
LIB  = obj/command.a obj/coder.a
CFLAGS = -Wall 
DEPSFLAGS = -MMD 
GDB = -g 

DEPS = $(OBJ:.o=.d)
-include $(DEPS)
.PHONY: all clean run
all: $(APP_NAME)

$(APP_NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(GDB) $(DEPSFLAGS) -o $@ $^
obj/%.o: src/%.c 
	$(CC) $(CFLAGS)  $(GDB) $(DEPSFLAGS) -c $< -o $@
clean:
	rm -rf $(APP_NAME) obj/*.o obj/*.d
run:
	./$(APP_NAME)
