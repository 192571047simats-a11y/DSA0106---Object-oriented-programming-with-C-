# Incorrect Return Type in this Pointer Method Chaining

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
`setWidth` returns a pointer, but the next chained call uses dot syntax. Return `WindowBox&` and `*this` consistently to support fluent chaining.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
