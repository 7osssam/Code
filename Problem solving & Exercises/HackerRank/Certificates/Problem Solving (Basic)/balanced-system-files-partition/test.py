import os
import subprocess


def run_test_case(input_file, output_file, executable):
    # Check if the input file exists
    if not os.path.isfile(input_file):
        print(f"Input file '{input_file}' does not exist.")
        return

    # Check if the output file exists
    if not os.path.isfile(output_file):
        print(f"Output file '{output_file}' does not exist.")
        return

    # Execute the C file and capture its output
    try:
        output = subprocess.check_output([executable], stdin=open(
            input_file), timeout=1, universal_newlines=True)
    except subprocess.CalledProcessError:
        print("Error occurred while executing the C file.")
        return
    except subprocess.TimeoutExpired:
        print("Execution of the C file timed out.")
        return
    except FileNotFoundError:
        print(f"C file '{executable}' not found.")
        return

    # Compare the output with the expected output
    with open(output_file, 'r') as f:
        expected_output = f.read()

    if output.strip() == expected_output.strip():
        print(f"Test case passed 🟩: {input_file}")
    else:
        print(f"Test case failed 🟥: {input_file}")


def run_tests():
    # Get the list of input files
    input_files = sorted([filename for filename in os.listdir(
        'test-cases') if filename.startswith('input')])

    # Get the corresponding output files
    output_files = ['test-cases/' +
                    f.replace('input', 'output', 1) for f in input_files]

    # Get the name of the C file
    c_file = 'solution.c'

    # Compile the C file
    if subprocess.call(['gcc', c_file, '-o', 'solution']):
        print("Compilation failed.")
        return

    # Run the tests
    for input_file, output_file in zip(input_files, output_files):
        run_test_case('test-cases/' + input_file, output_file, './solution')


if __name__ == '__main__':
    run_tests()
