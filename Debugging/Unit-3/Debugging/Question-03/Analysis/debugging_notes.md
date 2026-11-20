# Stream Insertion Operator << Member Function Violation

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
For `left.operator<<(right)`, the left operand must be a Fraction for a member overload. In `std::cout << f`, the left operand is an ostream, so insertion must be a non-member friend taking ostream& first.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
