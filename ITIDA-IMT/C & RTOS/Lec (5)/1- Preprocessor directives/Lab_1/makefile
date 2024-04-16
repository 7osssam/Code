COMPILER=gcc

.PHONY: all clean

# The default target is "all" which will run every target
all: executable assemblyfile intermediatefile

# compiling process
executable: objectfile.o
	$(COMPILER) objectfile.o -o executablefile

# linking process
objectfile.o: code.c
	$(COMPILER) -c code.c -o objectfile.o

# assembling process
assemblyfile: code.c
	$(COMPILER) -S code.c -o assemblyfile.s

# preprocessing process
intermediatefile: code.c
	$(COMPILER) -E code.c -o code.i

# Clean the directory
clean:
	rm -f *.o *.s *.i executablefile
