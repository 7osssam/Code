# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Source files
SRCS = main.cpp Bank.cpp BankAccount.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = bank_system

# Target: Build the executable
$(EXEC): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(EXEC)

# Target: Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Target: Clean up
clean:
	rm -f $(EXEC)

# Target: Run the program
run: $(EXEC)
	./$(EXEC)
