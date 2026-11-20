# Function Overload Ambiguity via Default Arguments

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
A one-argument call matches both the cuboid overload with default width/height and the dedicated cube overload. The signatures are ambiguous. Give the operations distinct names and retain explicit dimensional parameters.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
