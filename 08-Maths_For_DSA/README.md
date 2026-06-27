# 08 — Maths for DSA

> Mathematics is the backbone of efficient algorithms. From number theory to prime sieves, these foundational concepts appear repeatedly in competitive programming and technical interviews.

## 📋 Problems

| # | Problem | File | Difficulty | Approach | Time | Space |
|---|---------|------|-----------|----------|------|-------|
| 1 | Armstrong Number Check | `Armstrong.cpp` | Easy | Digit Extraction + Power Sum | O(D) | O(1) |
| 2 | Count Digits in a Number | `DigitInNumber.cpp` | Easy | Repeated Division by 10 | O(D) | O(1) |
| 3 | GCD / HCF | `GCD.cpp` | Easy | Euclidean Algorithm | O(log(min(A,B))) | O(1) |
| 4 | LCM using GCD | `LCM.cpp` | Easy | LCM = (A × B) / GCD(A, B) | O(log(min(A,B))) | O(1) |
| 5 | Prime Number Check | `PrimeCheck.cpp` | Easy | Trial Division up to √N | O(√N) | O(1) |
| 6 | Reverse a Number | `ReverseNumber.cpp` | Easy | Digit Extraction + Rebuild | O(D) | O(1) |
| 7 | Sieve of Eratosthenes | `SieveofEratosthenes.cpp` | Medium | Sieve (Mark Composites) | O(N log log N) | O(N) |

> **D** = number of digits, **N** = input number, **A, B** = input values

## 🧠 Key Concepts

- **Euclidean Algorithm**: `GCD(a, b) = GCD(b, a % b)` — one of the most elegant and efficient algorithms in mathematics, running in O(log(min(a, b))).
- **LCM–GCD Relationship**: `LCM(a, b) = (a * b) / GCD(a, b)` — always compute GCD first to avoid overflow; use `a / GCD(a, b) * b` instead.
- **Sieve of Eratosthenes**: Precompute all primes up to N in O(N log log N) — essential for problems involving multiple prime queries.
- **Trial Division**: Check divisibility only up to √N — if no factor is found, the number is prime. Skip even numbers after checking 2 for a 2× speedup.
- **Digit Manipulation**: Extract digits using `n % 10` and remove them with `n /= 10` — the fundamental loop for reverse, digit count, and Armstrong checks.

## 📌 Tips

- **Overflow Guard**: When computing LCM, always divide before multiplying (`a / gcd * b`) to prevent integer overflow with large values.
- **Sieve vs. Trial Division**: Use the Sieve when you need to check primality for many numbers; use trial division for one-off checks. Know when to apply each.
- **Modular Arithmetic**: Many competitive programming problems require results modulo 10⁹+7 — practice applying `mod` at every multiplication step to stay within bounds.
