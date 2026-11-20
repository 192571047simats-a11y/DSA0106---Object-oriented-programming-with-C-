# The Diamond Problem in Multipath Hybrid Inheritance

## Defect classification
The supplied question identifies the defect in the corresponding buggy implementation. The corrected implementation is in `Source_Code/main.cpp`.

## Root cause and correction
Ordinary multiple inheritance creates two Person subobjects, one through Student and one through Employee, making `id` ambiguous. Virtual inheritance shares one Person subobject; the most-derived TeachingAssistant initializes it.

## Build and verification
- Standard: C++17
- Compiler flags: `-Wall -Wextra -pedantic`
- Result: compiled and executed successfully in the build environment.
- Exact standard output: `../Output/actual_output.txt`
