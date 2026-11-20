# Prefix vs. Postfix Increment Signature Inversion

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
Prefix increment has no dummy parameter and conventionally returns `StepCounter&` after modifying the object. Postfix has a dummy int and returns the old value by value.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
