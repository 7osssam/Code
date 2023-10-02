# compiler {gcc} or {clang}better for desktop(low size) or {avr-gcc}
CC := gcc

# source files {all .c files}
SRC_FILES_LIST := *.c
#SRC_FILES_LIST += file.c

# header files {all .h files}
HEADER_FILES_LIST := *.h

# output file variable
EXC_NAME := app.exe
# output file for debugging variable
EXC_DEBUG_NAME := app_debug.exe

# compiling paramter 
# -O is the optimization 0:3{performance} or s{size} or g{debug} or fast
CFLAGS := -Os
# Errors and warnings
# -w{ignore all warn} or -Wall{show all warning} or -Werror{consider any warn as error abort build} 
CFLAGS += -Wall

# enalbe debugging symbols
CC_DEBUG_FLAGS := -g
#close optimization for debugging
CC_DEBUG_FLAGS += -Og
CC_DEBUG_FLAGS += -Wall

print_msg:
	@echo "-----------------------------------------------"
	@echo "Building process started..."
	@echo "-----------------------------------------------"

preprocess:
	@${CC} -E main.c -o app.i -I ${HEADER_FILES_LIST}  

# size --format=sysv file.run more details about mem sections
build: print_msg
	@${CC} ${CFLAGS} ${SRC_FILES_LIST} -o ${EXC_NAME} -I ${HEADER_FILES_LIST} 
	@echo "-----------------------------------------------"
	@size ${EXC_NAME}
	@echo "-----------------------------------------------"

clean:
	@echo "Cleaning building directory..." 
	@echo "-----------------------------------------------"
	@rm *.exe
	@rm *.i
	@rm *.o

run: build
	@echo "Executable file runing..."
	@echo "-----------------------------------------------"
	@./${EXC_NAME}

debug:
	@${CC} ${CC_DEBUG_FLAGS} ${SRC_FILES_LIST} -o ${EXC_DEBUG_NAME} -I ${HEADER_FILES_LIST}
	@size ${EXC_DEBUG_NAME}
