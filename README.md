# Push_swap

*This project has been created as part of the 42 curriculum by hhdili and mbihti.*

## Description

**Push_swap** is a sorting algorithm project from the 42 curriculum.

The objective is to sort a list of integers using two stacks, A and B, and a restricted set of operations.

The challenge is not only to sort the numbers correctly, but also to minimize the number of operations used.

This implementation provides several sorting strategies and an adaptive mode that selects an algorithm according to the disorder of the input.

## Instructions

### Requirements

- A C compiler (`cc`)
- GNU Make

### Compilation
```

Compile the project:

```bash
make
```

Clean object files:

```bash
make clean
```

Remove all generated files:

```bash
make fclean
```

Recompile everything:

```bash
make re
```

### Execution

Run the program with a list of integers:

```bash
./push_swap 4 67 3 87 23
```

You can also provide the numbers as a single quoted argument:

```bash
./push_swap "4 67 3 87 23"
```

The program prints the operations required to sort the stack.

### Available flags

| Flag | Description |
|---|---|
| `--simple` | Uses the Simple sorting strategy. |
| `--medium` | Uses the Medium sorting strategy. |
| `--complex` | Uses the Complex sorting strategy. |
| `--adaptive` | Automatically selects a strategy according to input disorder. |
| `--bench` | Displays benchmark information. |

The last sorting-mode flag provided determines the selected strategy.

Examples:

```bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
./push_swap --bench 5 4 3 2 1
./push_swap --adaptive --simple 5 4 3 2 1
```

You can combine benchmarking with a sorting strategy:

```bash
./push_swap --bench --complex 5 4 3 2 1
```

## Project Architecture

The project is organized into several modules:

| Directory | Responsibility |
|---|---|
| `src/parsing/` | Argument normalization, tokenization, validation, and number parsing. |
| `src/stack/` | Stack initialization, memory management, and stack operations. |
| `src/sort/` | Sorting algorithms, rank assignment, disorder calculation, and strategy selection. |
| `src/bench/` | Benchmark calculations and output. |
| `src/utils/` | General utility functions. |

### Stack representation

The project uses a circular-array representation for each stack.

Each stack stores:

- `data`: the allocated array of integers.
- `head`: the index of the current top element.
- `size`: the number of elements currently in the stack.
- `cap`: the allocated capacity.

This representation allows stack operations to be performed by updating indices rather than shifting every element in memory.

### Parsing and validation

Before sorting, the program normalizes its arguments and extracts integer tokens.

It validates the input to reject:

- Invalid characters.
- Duplicate numbers.
- Values outside the integer range.
- Invalid signs.
- Empty or whitespace-only arguments.

The parser ensures that only valid integer input reaches the sorting algorithms.

## Sorting Algorithms

The project implements three sorting strategies and one adaptive strategy.

### 1. Simple Sort

The Simple strategy repeatedly finds the smallest element in stack A and moves it to stack B.

Once only a small number of elements remain in A, the remaining elements are sorted directly. The elements stored in B are then pushed back to A.

The algorithm prioritizes simplicity and is intended for inputs with relatively low disorder.

**Complexity:** \(O(n^2)\) Push_swap operations in the worst case.

### 2. Medium Sort

The Medium strategy uses rank-based chunk sorting.

First, the input values are assigned ranks. Instead of working directly with potentially large or negative integers, the algorithm works with their relative positions in sorted order.

The algorithm then:

1. Calculates a chunk range based on the input size.
2. Iterates through stack A.
3. Pushes elements belonging to the current range into stack B.
4. Rotates the stacks to organize the pushed elements.
5. Restores stack A by repeatedly bringing the maximum element of B to its top and pushing it back to A.

This approach aims to reduce the number of operations compared with the Simple strategy.

**Complexity:** The exact worst-case Push_swap operation bound must be established for this implementation before claiming \(O(n\sqrt n)\).

### 3. Complex Sort

The Complex strategy uses binary radix sort.

It first assigns ranks to the input values. It then processes the binary representation of those ranks, one bit at a time.

For each bit:

1. If the current element has that bit set, it is rotated in stack A.
2. Otherwise, it is pushed to stack B.
3. After processing the elements, everything in B is pushed back to A.

The process repeats until all significant bits have been processed.

**Complexity:** \(O(n\log n)\) Push_swap operations.

### 4. Adaptive Sort

The Adaptive strategy calculates the disorder of the input and selects one of the three sorting strategies.

The disorder is calculated using the number of inversions:

\[
\text{Disorder} =
\frac{\text{Number of inversions}}
{\text{Total number of pairs}}
\]

An inversion is a pair of elements that appear in the wrong relative order.

The current implementation uses these thresholds:

| Disorder | Selected strategy |
|---|---|
| Below 20% | Simple |
| From 20% to below 50% | Medium |
| 50% or above | Complex |

The purpose is to select a strategy that suits the initial arrangement of the input rather than always using the same algorithm.

## Benchmarking

The `--bench` flag displays information about the sorting process.

The benchmark includes:

- Initial disorder percentage.
- Selected sorting strategy.
- Total number of operations.
- Number of times each operation was executed.

Example:

```text
[bench] disorder: 56.72%
[bench] strategy: Complex / O(n log n)
[bench] total_ops: 1084
[bench] sa: 0 sb: 0 ss: 0 pa: 384 pb: 384
[bench] ra: 316 rb: 0 rr: 0 rra: 0 rrb: 0 rrr: 0
```

This information makes it possible to compare the different strategies and understand how the initial disorder affects the selected algorithm.

## Resources

The following resources are useful for understanding the concepts used in this project:

- **42 subject PDF** – *push_swap* (version 1.2) – the official requirements.
- [GNU C Library Documentation](https://www.gnu.org/software/libc/manual/)
- [GNU Make Manual](https://www.gnu.org/software/make/manual/)
- [Wikipedia - Sorting Algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Wikipedia - Radix Sort](https://en.wikipedia.org/wiki/Radix_sort)
- [Big-O Notation](https://en.wikipedia.org/wiki/Big_O_notation)

## AI Usage

AI tools were used as learning and development assistants during the project.

They helped with:

- Understanding algorithms and data structures.
- Investigating edge cases and debugging issues.
- Improving documentation.

## Contributions

### hhdili
- Designed and implemented the stack management system using a circular array representation.
- Developed the stack operations and their underlying management logic.
- Improved the argument parsing and input validation mechanisms.
- Collaborated with my partner to design, discuss, and implement the sorting algorithms after carefully evaluating different approaches and strategies.

### [PARTNER_42_LOGIN]

- [Describe your partner's contributions.]

Both contributors participated in the development and validation of the project.

