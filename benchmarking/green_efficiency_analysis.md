# Green Tech Efficiency & Benchmarking Lab

## Performance Analysis Report

### Introduction

The purpose of this project was to compare two different algorithms that solve the same problem and see which one performs better. Even if two programs give exactly the same result, they do not always take the same amount of time to finish. This is why benchmarking is useful. It allows us to measure the execution time of each solution and compare them.

This project is also related to Green Computing. A program that finishes faster usually keeps the processor busy for a shorter time. It does not directly measure electricity consumption, but execution time can still give an idea of how many computing resources are used. Because of that, runtime is used in this project as an indicator of efficiency.

---

### Measurement Methodology

Two different methods were used to measure performance.

The first one was the Linux `time` command. It provides three values:

- **real**: the total execution time.
- **user**: the time spent running the program on the CPU.
- **sys**: the time spent by the operating system.

Example:

```text
real    0m0.076s
user    0m0.079s
sys     0m0.000s
```

The second method uses the C function `clock()`. Instead of measuring the whole program, it measures only the part of the code that we want to benchmark.

To make the measurements easier to compare, each algorithm was executed 100,000,000 times. The variable `result` was declared as `volatile` so that the compiler would not optimize the loop away.

The benchmark was repeated three times. Doing several runs helps reduce small differences that can happen because of background programs or the operating system.

---

### Experimental Results

The project compares two approaches.

The first one is a naive algorithm that uses nested loops.

The second one is a single-pass algorithm that only goes through the data once.

The execution times were:

Run 1:
- Naive algorithm: 0.484466 s
- Single-pass algorithm: 0.000015 s

Run 2:
- Naive algorithm: 0.487200 s
- Single-pass algorithm: 0.000015 s

Run 3:
- Naive algorithm: 0.484607 s
- Single-pass algorithm: 0.000016 s

Average:
- Naive algorithm: 0.485424 s
- Single-pass algorithm: 0.0000153 s

The three executions gave almost the same results, which means the measurements are consistent. On average, the naive algorithm is about 31,700 times slower than the single-pass version.

---

### Instrumentation Results

The execution time of each part of the program was also measured.

```text
TOTAL       : 0.000221 s
BUILD_DATA  : 0.000089 s
PROCESS     : 0.000083 s
REDUCE      : 0.000048 s
```

These measurements show how much time is spent in each stage of the program. This makes it easier to identify which part takes the longest time and where future optimizations could be made.

---

### Performance Analysis

The difference between the two algorithms comes from the number of operations they perform.

The naive solution uses nested loops. This means that some operations are repeated many times. As the amount of data grows, the execution time increases quickly.

The single-pass algorithm is simpler. It only reads the data once and avoids unnecessary work. Because of that, it finishes much faster while producing the same result.

This shows that choosing a better algorithm often has a much bigger impact than trying to make small optimizations in the code.

---

### Runtime as an Energy Indicator

This project does not measure the actual electrical energy used by the computer.

Instead, execution time is used as an indicator. In general, if a program finishes faster, the processor stays active for a shorter period of time. This usually means fewer computing resources are used. It is not an exact measurement of energy consumption, but it is still useful when comparing two algorithms that solve the same problem.

---

### Limitations

Like every benchmark, this experiment has some limitations.

The results depend on the computer, the processor, the operating system and the compiler options. Background applications can also influence the execution time. In addition, the tests were performed with only one dataset. Using different data or another computer could produce different results.

---

### Conclusion

This experiment shows that two algorithms can solve the same problem while having very different execution times.

The benchmark clearly shows that the single-pass algorithm is much faster than the naive solution. Even though both programs produce the same output, the second algorithm requires much less processing time.

This project also shows why algorithm choice is important. Improving the algorithm can have a much greater effect than making small changes to the code. From a Green Computing point of view, reducing execution time can also help reduce the use of computing resources.