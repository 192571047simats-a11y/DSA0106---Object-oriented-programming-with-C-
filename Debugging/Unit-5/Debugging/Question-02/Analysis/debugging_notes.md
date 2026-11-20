# Inverted Exception Catch Handlers & Unreachable Code

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
Catch handlers are tested in order. A base-class handler placed first also matches derived exceptions, making the derived handler unreachable. Put the most specific handler first and catch-all last.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
