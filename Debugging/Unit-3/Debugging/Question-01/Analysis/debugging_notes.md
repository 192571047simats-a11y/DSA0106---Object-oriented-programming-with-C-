# Copy Constructor Pass-by-Value Infinite Recursion Trap

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
A copy constructor taking its own class by value would itself require copying the argument, recursively invoking the same constructor. Use `const DynamicString&` and allocate a separate buffer. Copy assignment is also implemented to satisfy the Rule of Three.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
