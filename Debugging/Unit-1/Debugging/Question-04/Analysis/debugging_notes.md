# Reference Variable Initialization & Constant Binding Violations

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
References must bind at declaration. A non-const lvalue reference cannot bind to a literal temporary or to a different type through a conversion. A const reference can bind to a temporary and extends its lifetime; it cannot be used to modify the referred value.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
