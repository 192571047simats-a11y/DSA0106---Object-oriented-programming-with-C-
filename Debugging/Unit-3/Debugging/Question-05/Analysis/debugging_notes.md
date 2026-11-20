# Violation of Fundamental Operator Overloading Rules

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
Operators such as `.`, `.*`, `::`, `?:`, and `sizeof` cannot be overloaded. A user-defined overload must involve a class or enum operand. Use legal `+` and `==` overloads and a named method for dot product.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
