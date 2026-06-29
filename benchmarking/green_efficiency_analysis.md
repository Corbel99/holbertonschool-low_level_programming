# Green Efficiency Analysis

## Measurement Methodology

The `time` command is used to see the total execution time of a program in the terminal. It displays three values: `real`, `user`, and `sys`. The `real` value is the total time from the start to the end of the program. The `user` value is the time spent running the program's own code. The `sys` value is the time used by the operating system while the program is running.

To get more precise results, the `clock()` function is used. It measures the execution time of specific parts of the program, making it easier to compare their performance.

To get more reliable results, the program is executed several times and the average execution time is calculated. Running the program more than once helps reduce small differences between each execution and gives more reliable results. This is a benchmarking method because it compares different solutions and helps find the most efficient one.

---

## Observed Performance Differences

The results show a clear difference in execution time between an algorithm that uses nested loops and another that uses only one loop. The three executions gave very similar results, showing that the measurements are consistent.

The average execution time shows that the algorithm with nested loops is about **31,700 times slower** than the algorithm with one loop. This shows that the way an algorithm is designed can have a big impact on a program's performance.

Big O also helps explain this difference. Nested loops make the program perform many more operations. As the amount of data increases, the difference becomes even bigger. A single-loop algorithm performs fewer operations and runs much faster.

---

## Relation Between Runtime and Energy Consumption

The measurements show that the naive algorithm takes an average of **0.485424 seconds** to run, while the single-loop algorithm takes only **0.0000153 seconds**. This means that the naive algorithm keeps the CPU busy for a much longer time.

This experiment does not directly measure power consumption. However, a program that uses the CPU for a longer time usually uses more resources. Improving a program's performance can reduce resource usage, which is one of the goals of **Green Tech**.

---

## Limitations of the Experiment

This experiment has some limitations. The results can change depending on the computer, the operating system, or other programs running in the background.

Also, the measurements were made on only one program with a fixed amount of data. These results give a good idea of the program's performance, but they may be different if the testing conditions change.

---

## Practical Engineering Takeaway

This project shows that the same problem can have different solutions, but they are not all equally efficient. Even if different algorithms give the same result, it is better to choose the one that uses fewer resources.

Benchmarking helps compare different methods and choose the most efficient one. This helps developers create faster and more efficient programs while making better use of available resources.
