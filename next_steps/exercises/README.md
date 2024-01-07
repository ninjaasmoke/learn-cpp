## Exercises

A set of easy-intermediate level problems.

### Contents

- [Exercises](#exercises)
  - [Contents](#contents)
  - [1. Sum and Squares](#1-sum-and-squares)
  - [2. Orders and books](#2-orders-and-books)

### 1. Sum and Squares

[ex1.cpp](ex1.cpp) is a small program that uses hash maps (unordered maps) to find the numbers where perfect squares are also sum of sum numbers.
```
Exercise 1
The integer 36 has a peculiar property: it is a perfect square, and is also the sum of the integers from 1 through 8.
The next such number is 1225 which is 352, and the sum of the integers from 1 through 49.
Find the next number that is a perfect square and also the sum of a series 1...n.
This next number may be greater than 32767. You may use library functions that you know of, (or mathematical formulas) to make your program run faster.
It is also possible to write this program using for-loops to determine if a number is a perfect square or a sum of a series.
(Note: depending on your machine and your program, it can take quite a while to find this number.)
```   

I do not understand why they say it can take a while to find the number. I have a very old laptop and it takes less than a second to find the number. I am using a very simple algorithm to find the number. I am sure there are better algorithms out there. I am not sure if I am missing something.

Here are the stats

```
g++ -o ex1 ex1.cpp -Wall -Werror -ftime-report

Execution times (seconds)
 phase setup             :   0.01 ( 1%) usr     729 kB ( 2%) ggc
 phase parsing           :   0.43 (49%) usr   29912 kB (74%) ggc
 phase lang. deferred    :   0.11 (12%) usr    4636 kB (12%) ggc
 phase opt and generate  :   0.31 (35%) usr    4943 kB (12%) ggc
 |name lookup            :   0.06 ( 7%) usr    2533 kB ( 6%) ggc
 |overload resolution    :   0.09 (10%) usr    5324 kB (13%) ggc
 callgraph construction  :   0.01 ( 1%) usr     285 kB ( 1%) ggc
 ipa inlining heuristics :   0.01 ( 1%) usr       0 kB ( 0%) ggc
 df scan insns           :   0.02 ( 2%) usr      14 kB ( 0%) ggc
 df reg dead/unused notes:   0.01 ( 1%) usr      29 kB ( 0%) ggc
 preprocessing           :   0.09 (10%) usr     857 kB ( 2%) ggc
 parser (global)         :   0.10 (11%) usr   11435 kB (28%) ggc
 parser struct body      :   0.06 ( 7%) usr    4508 kB (11%) ggc
 parser function body    :   0.03 ( 3%) usr    1356 kB ( 3%) ggc
 parser inl. func. body  :   0.01 ( 1%) usr     695 kB ( 2%) ggc
 parser inl. meth. body  :   0.03 ( 4%) usr    2203 kB ( 5%) ggc
 template instantiation  :   0.23 (26%) usr   13472 kB (33%) ggc
 out of ssa              :   0.03 ( 4%) usr      17 kB ( 0%) ggc
 expand                  :   0.04 ( 4%) usr     580 kB ( 1%) ggc
 post expand cleanups    :   0.02 ( 3%) usr      63 kB ( 0%) ggc
 integrated RA           :   0.02 ( 3%) usr    2263 kB ( 6%) ggc
 LRA non-specific        :   0.04 ( 4%) usr      22 kB ( 0%) ggc
 thread pro- & epilogue  :   0.02 ( 2%) usr     189 kB ( 0%) ggc
 final                   :   0.04 ( 4%) usr     193 kB ( 0%) ggc
 initialize rtl          :   0.01 ( 1%) usr       4 kB ( 0%) ggc
 rest of compilation     :   0.04 ( 4%) usr     252 kB ( 1%) ggc
 TOTAL                 :   0.88             40231 kB
```

```

-----------------
Found it!
Sum: 1
Sum from 1 to: 1
Square: 1
Root: 1

-----------------

-----------------
Found it!
Sum: 36
Sum from 1 to: 8
Square: 36
Root: 6

-----------------

-----------------
Found it!
Sum: 1225
Sum from 1 to: 49
Square: 1225
Root: 35

-----------------

-----------------
Found it!
Sum: 41616
Sum from 1 to: 288
Square: 41616
Root: 204

-----------------

-----------------
Found it!
Sum: 1413721
Sum from 1 to: 1681
Square: 1413721
Root: 1189

-----------------

-----------------
Found it!
Sum: 48024900
Sum from 1 to: 9800
Square: 48024900
Root: 6930

-----------------

Execution time: 147 ms
```

---

### 2. Orders and books


[ex2.cpp](ex2.cpp) is a small program that uses hash maps (unordered maps) to find the orders and books that are in the orders.

