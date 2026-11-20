# Array of Objects Missing Default Constructor

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
Declaring a parameterized constructor suppresses implicit default-constructor generation. `Student batch[3]` requires a zero-argument constructor for each element. Add a default constructor or use an initializer list.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
