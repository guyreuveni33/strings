### README

This repository contains two implementations of string distance functions, `hamming_dist` and `b64_distance`, as per the assignment instructions provided.

#### Files

1. **hamming_dist.s**: This file contains the implementation of the `hamming_dist` function using assembly language. The `hamming_dist` function calculates the Hamming distance between two strings, which is the number of positions at which the corresponding symbols are different.

2. **b64.c**: This file contains the implementation of the `b64_distance` function using Intel Intrinsics. The `b64_distance` function calculates the Base64 distance between two strings. It involves removing non-Base64 characters from the input strings, calculating the numerical values represented by the cleaned strings, and then subtracting the first from the second.

3. **libstr.h**: Header file containing function prototypes for `hamming_dist` and `b64_distance`, as well as any necessary constants and definitions.

4. **main.c**: This file contains the main program where users can choose between different distance functions (`hamming_dist` or `b64_distance`) and provide input strings to calculate the respective distances.

5. **Makefile**: The Makefile contains rules for compiling the source files into executable binaries. It also includes rules for cleaning up generated object files and the executable.

#### Compilation and Execution

To compile the program, simply run `make` in the terminal. This will generate an executable named `part1.out`.

To run the program, execute `./part1.out` in the terminal. Follow the on-screen prompts to choose a distance function and input strings to calculate the distance.

#### Notes

- Ensure that the GCC compiler is installed on your system to compile the code.
- The code is intended to be run on systems with AVX-512 support.
#### Instructions for Running the Code

1. **Clone the Repository:**
   ```
   git clone https://github.com/guyreuveni33/strings_distance.git
   ```

2. **Navigate to the Repository Directory:**
   ```
   cd strings
   ```

3. **Compile the Code:**
   ```
   make
   ```
   This command will compile the source files and generate an executable named `part1.out`.

4. **Run the Program:**
   ```
   ./part1.out
   ```
   This command executes the compiled program. Follow the on-screen prompts to choose a distance function and input strings to calculate the distance.
