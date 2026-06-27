# 01 — Fundamentals and Math

> Master the building blocks of computational thinking — every algorithm you'll ever write stands on these foundations.

## 📋 Problems

| # | Problem | File | Difficulty | Approach | Time | Space |
|---|---------|------|-----------|----------|------|-------|
| 1 | Binary to Decimal Conversion | `binaryTOdecimal.cpp` | Easy | Positional Notation / Power of 2 | O(log n) | O(1) |
| 2 | Decimal to Binary Conversion | `decimalTObinary.cpp` | Easy | Repeated Division by 2 | O(log n) | O(log n) |
| 3 | Check Even or Odd | `even_odd.cpp` | Easy | Modulo / Bitwise AND | O(1) | O(1) |
| 4 | Factorial of a Number | `factorial.cpp` | Easy | Iterative / Recursive | O(n) | O(1) / O(n) |
| 5 | Fibonacci Series | `fibonacci.cpp` | Easy | Iterative / Recursion | O(n) | O(1) |
| 6 | Largest of Three Numbers | `largest_of_three.cpp` | Easy | Conditional Comparison | O(1) | O(1) |
| 7 | Multiplication Table | `multiplication_table.cpp` | Easy | Simple Loop | O(n) | O(1) |
| 8 | Power of a Number | `power.cpp` | Medium | Fast Exponentiation (Binary Exp.) | O(log n) | O(1) |
| 9 | Prime Number Check | `prime_check.cpp` | Easy | Trial Division up to √n | O(√n) | O(1) |

## 🧠 Key Concepts

- **Number Systems** — Understanding binary ↔ decimal conversion is critical for bit manipulation problems down the line.
- **Recursion vs Iteration** — Factorial and Fibonacci serve as the classic introduction to recursive thinking and stack behaviour.
- **Fast Exponentiation** — Computing `a^b` in O(log b) using the binary representation of the exponent; a technique reused in modular arithmetic and competitive programming.
- **Primality Testing** — Checking divisibility only up to √n is the first optimisation most programmers learn; it scales to sieve-based approaches later.
- **Bitwise Operations** — Using `n & 1` instead of `n % 2` introduces the idea that low-level bit tricks can replace arithmetic operations.

## 📌 Tips

- **Interview Staple:** Interviewers often use Fibonacci or Factorial to test your understanding of recursion, memoization, and stack overflow risks — always mention the iterative alternative.
- **Edge Cases Matter:** For prime checks, remember that `0` and `1` are *not* prime, and `2` is the only even prime — handling these edges cleanly shows attention to detail.
- **Think in Bits:** Practice converting numbers by hand; comfort with binary representation pays dividends in bit manipulation, networking, and systems design questions.
