# Shallow Copy & Double-Free Runtime Crash

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
The compiler-generated copy constructor copies the raw pointer value, not the pointed-to array. Both objects then own the same allocation and both destructors delete it. Implement a deep copy that allocates and copies a distinct buffer.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
