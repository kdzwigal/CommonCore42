*This project has been created as part of the 42 curriculum by kdzwigal, pwarda.*

# Push_swap: Because Swap_push doesn't feel as natural

## Contents
- [Description](#description)
- [Contributors](#contributors)
- [Algorithms & Strategy](#Algorithms--strategy)
- [Instructions](#instructions)
- [Resources & AI Usage](#resources--ai-usage)

## Description
**Push_swap** is a C program containing 3 different sorting algorithms that sort numbers on a stack from smallest to largest. It uses a limited set of instructions, with the overarching goal of using the least actions possible. 

The program initialises with a `stack_a` containing a random set of integers and an empty `stack_b`. By employing a specific set of operations (swapping, pushing, and rotating), the algorithm generates the most efficient sequence of moves, sorting `stack_a` numbers in ascending order. This project applies complex sorting logic and optimised data manipulation in a restricted environment.

---

## Contributors
Kamil Dzwigala and Philip Warda worked collaboratively on this project, their contributions were as follows;

*   **kdzwigal**: 
    *   Implemented stack parsing, initialisation, and error handling.
    *   Implemented the Disorder Metric calculation.
    *   Developed the core `Push_swap` operation functions (`sa`, `pb`, `ra`, etc.).
    *   Designed and implemented the Complex ($O(n \log n)$) Turk, and Medium ($O(n \sqrt{n})$) sorting algorithms.
    *   Created the Adaptive Strategy routing logic, benchmarking mode (`--bench`), and strategy flags.
*   **pwarda**: 
    *   Designed and implemented the Simple ($O(n^2)$) sorting algorithm.
    *   Provided optimised `ft_printf` function for printing benchmark output.
    *   Improved function workflow in files and header file. 
    *   Wrote and edited README.md.

---

## Algorithms & Strategy
The program selects sorting strategy dynamically based on, either; user-provided flags `ie (--simple, --adaptive)` or program calculated input stack "disorder". 

### The Disorder Metric
Before operations are executed, stack disorder must be calculated. Value generated will be between `0.00` (perfectly sorted) and `1.00` (worst possible order). 

The disorder is defined by the ratio of inverted pairs to total possible pairs. An inversion occurs whenever a larger number precedes a smaller number in the stack.

$$ \text{Disorder} = \frac{\text{Number of Inversions}}{\text{Total Possible Pairs}} $$

### 1. Simple Strategy: Selection Sort
*   **Complexity:** $O(n^2)$
*   **Trigger:** `--simple` or Adaptive (Disorder < 0.2)
*   **Mechanism:** The algorithm searches `stack_a` for the smallest number. It calculates the shortest path (using `ra` or `rra`) to bring this number to the top, then pushes it to `stack_b` (`pb`). It repeats this until `stack_a` is empty, then pushes everything back to `stack_a` (`pa`).
*   **Justification:** Finding the minimum element requires an $O(n)$ scan, and this must be done $n$ times, resulting in a quadratic time complexity. In terms of Push_swap operations, it is inefficient for large datasets but highly effective for tiny arrays or arrays with very low disorder where the target elements are already near their correct positions.

### 2. Medium Strategy: Chunk-based Sort
*   **Complexity:** $O(n \sqrt{n})$
*   **Trigger:** `--medium` or Adaptive (0.2 $\le$ Disorder < 0.5)
*   **Mechanism:** The array is conceptually divided into $\approx \sqrt{n}$ chunks based on value ranges (percentiles). The algorithm scans `stack_a` and pushes elements to `stack_b` if they fall into the current chunk's range. Once `stack_a` is empty and `stack_b` contains the partitioned elements, we repeatedly find the maximum element in `stack_b` and push it back to `stack_a`. 
*   **Justification:** Dividing into $\sqrt{n}$ chunks reduces the depth we have to search/rotate for any given element. Pushing to `stack_b` takes $O(n)$ per chunk, and pushing back to `stack_a` involves searching subsets, effectively bounding the total operational complexity to the $O(n \sqrt{n})$ class.

### 3. Complex Strategy: The Turk Algorithm
*   **Complexity:** $O(n \log n)$
*   **Trigger:** `--complex` or Adaptive (Disorder $\ge$ 0.5)
*   **Mechanism:** This algorithm pushes elements from `stack_a` to `stack_b` while keeping `stack_b` sorted in descending order (treating the stack as a circular array). For every element in `stack_a`, it calculates the exact cost (in operations) to place it in its correct relative position in `stack_b`. It always executes the cheapest move. Once `stack_a` is empty (save for a few elements handled manually), everything in `stack_b` is pushed back to `stack_a`.
*   **Justification:** By dynamically calculating the cheapest operation utilizing simultaneous rotations (`rr`, `rrr`), the Turk algorithm drastically minimizes movement overhead. The operational cost scales logarithmically as the arrays are halved and pivoted iteratively, fitting comfortably within the rigorous operation limits (e.g., <5500 ops for 500 numbers).

### 4. Custom Adaptive Strategy
*   **Trigger:** `--adaptive` (Default behavior)
*   **Rationale:** Standard algorithms have distinct weaknesses. Selection sort is terrible for reverse-sorted data, and the Turk algorithm calculates unnecessary overhead for arrays that only have 2 misplaced elements. 
*   **Thresholds:**
    *   **Low Disorder (< 0.2):** The stack is nearly sorted. We use the Simple Strategy. The few inversions mean minimal rotations are required to extract the minimums, vastly outperforming Chunk/Turk algorithms which would needlessly dismantle and rebuild the almost-sorted stack.
    *   **Medium Disorder (0.2 $\le$ Disorder < 0.5):** The stack is somewhat randomized but retains sorted substructures. The Medium Chunk sort efficiently groups values without the heavy cost-calculation overhead of the Turk algorithm.
    *   **High Disorder ($\ge$ 0.5):** The stack is highly chaotic. The Complex Turk Algorithm is deployed to leverage cost-analysis, minimizing rotations over highly disparate values. 

---

## Instructions

### Compilation
The provided `Makefile` includes the standard rules required for 42 projects.
```bash
# Compiles the program "push_swap"
make

# Remove object files
make clean

# Remove object files and the executable
make fclean

# Recompiles entirely
make re

# Compiles the bonus program "checker" 
make bonus
```

### Execution
Run the program by passing a space-separated list of integers (the first argument becomes the top of the stack). 
```bash
./push_swap 4 67 3 87 23
```
To test error handling (duplicates, non-integers, out-of-bounds):
```bash
./push_swap 3 2 3
# Expected output: Error
```
### Advanced execution
The following commands allow you to immediately test push_swap, by generating random numbers which are pasted into "args.txt". The required series of moves needed for sorting are output to bench.txt.

These commands take argument `-i 0-9999` (generate integers from 0-9999) and `-n 500` (output quantity = 500 numbers), and create a file `args.txt` with those random numbers. Then `./push_swap` along with the relevant flags output will be pasted into `bench.txt`.
#### Examples
*This variation will print a wordcount to the console.*
```shell
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --simple $(cat args.txt) 2> bench.txt | wc -l
```
*This commnd will post the bench.txt to the console.*
```shell
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench --adaptive $(cat args.txt) 2> bench.txt && cat bench.txt
```
*This version will also run the checker program.*
```shell
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench --adaptive $(cat args.txt) 2> bench.txt | ./checker $(cat args.txt) && cat bench.txt
```
### Flags
To force a specific algorithm or view benchmark statistics, pass one of the following optional flags as the **first** argument:

| Flag | Description |
| :------- | :--- |
| <span style="white-space: nowrap">`--adaptive`</span> | **(Default)** Dynamically selects the algorithm based on the disorder metric. |
| `--simple` | Forces the use of the $O(n^2)$ algorithm (Selection Sort). |
| `--medium` | Forces the use of the $O(n \sqrt{n})$ algorithm (Chunk Sort). |
| <span style="white-space: nowrap">`--complex`</span> | Forces the use of the $O(n \log n)$ algorithm (Turk Algorithm).|
| `--bench` | Enables benchmark mode. Prints the operations to `stdout` and the performance metrics (Disorder %, Algorithm used, Total ops, and Breakdown of ops) to `stderr`. |

**Benchmark Example:**
```bash
$> ./push_swap --bench --complex 2 1 3 6 5 8 2> bench.txt ; cat bench.txt
[bench] disorder:  13.33%
[bench] strategy:  Complex / O(n log n)
[bench] total_ops:  14
[bench] sa:  1 sb:  0 ss:  0 pa:  6 pb:  6
[bench] ra:  0 rb:  1 rr:  0 rra:  0 rrb:  0 rrr:  0
```

---

## Resources & AI Usage

### References
*   **Push_swap visualizer:** Used extensively to debug stack rotations and identify infinite loops. 
*   **A.Y. Turk Algorithm Article:** "Push_Swap: The least amount of moves with two stacks" - provided the foundational mathematical theory for the complex sorting algorithm.

### AI Usage Declaration
In accordance with modern development practices, AI (ChatGPT) was utilised strictly as an educational and structural aid during this project:
1.  **Documentation Formatting:** Used to generate the initial structural template for this `README.md` and format the data into clean Markdown tables.
2.  **Concept Clarification:** Used to understand the bounds of Big-O notations strictly within the context of Push_swap operations (e.g., confirming why chunk-sorting simulates $O(n \sqrt{n})$ in physical stack rotations rather than CPU cycles).

*AI was not used to write the core logic, sorting algorithms, or cost-calculation functions.*
