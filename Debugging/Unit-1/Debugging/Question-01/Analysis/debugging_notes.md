# Operator Precedence Trap with Bitwise Operations & Implicit Promotion

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
The equality operator has higher precedence than bitwise AND, so `num & 1 == 1` is parsed as `num & (1 == 1)`. Parenthesize `(num & 1) == 1`. An unsigned loop variable cannot become negative; after zero it wraps to its maximum value. A signed `int` loop variable safely counts down through zero.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
