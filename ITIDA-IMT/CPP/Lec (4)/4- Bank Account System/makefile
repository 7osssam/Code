# How to use:
# Run `make` to build the main executable
# Run `make test` to build and run the test executable
# Run `make run` to build and run the main executable
# Run `make clean` to clean up

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Source files
SRCS = main.cpp Bank.cpp BankAccount.cpp
TEST_SRCS = test/BankAccountSystem_test.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Executable names
EXEC = bank_system
TEST_EXEC = test/BankAccountSystem_test

# Target: Build the main executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

# Target: Build the test executable
$(TEST_EXEC): $(TEST_OBJS) $(filter-out main.o, $(OBJS))
	$(CXX) $(CXXFLAGS) $(TEST_OBJS) $(filter-out main.o, $(OBJS)) -o $(TEST_EXEC)

# Target: Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Target: Clean up
clean:
	rm -f $(EXEC) $(OBJS) $(TEST_EXEC) $(TEST_OBJS)

# Target: Run the program
run: $(EXEC)
	./$(EXEC)

# Target: Run the tests
test: $(TEST_EXEC)
	./$(TEST_EXEC)
