# Diagnose, Redesign and Validate

Diagnose a measurable limitation and compare an original design with a redesign.

- The demonstration performs a fixed number of operations, so its per-record primitive operations are generally O(1), unless a loop traverses n records/elements.
- The source uses standard C++17 facilities and avoids platform-specific APIs.
- For dynamic arrays/collections, space is O(n) in the number of stored elements; fixed-size scalar state is O(1).
- Validate boundary cases with the same compiler and environment used for submission.
