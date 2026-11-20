# Dangling Reference in Return-by-Reference

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
Returning a reference to the local `result` returns an alias to an object whose lifetime ends when the function returns. Return the integer by value. Returning an array element by reference is safe while the caller-owned array remains alive.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
