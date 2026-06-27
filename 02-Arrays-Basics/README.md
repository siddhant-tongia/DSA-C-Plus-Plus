# 02 — Arrays Basics

> Arrays are the backbone of nearly every coding interview — learn to manipulate them efficiently, and half the battle is won.

## 📋 Problems

| # | Problem | File | Difficulty | Approach | Time | Space |
|---|---------|------|-----------|----------|------|-------|
| 1 | Two Sum / Pair Sum | `pairsum.cpp` | Easy | Two Pointer | O(n log n) | O(1) |
| 2 | Pair Sum II (Sorted Array) | `pairsum2.cpp` | Easy | Two Pointer on Sorted Input | O(n) | O(1) |
| 3 | Product of Array Except Self | `productofarrayitself.cpp` | Medium | Prefix & Suffix Products | O(n) | O(n) |
| 4 | Squares of a Sorted Array | `square_of_array.cpp` | Easy | Two Pointer (Merge from ends) | O(n) | O(n) |
| 5 | Best Time to Buy & Sell Stock | `stock.cpp` | Easy | Single Pass / Track Min Price | O(n) | O(1) |
| 6 | Maximum Subarray Sum | `subarray.cpp` | Medium | Kadane's Algorithm | O(n) | O(1) |
| 7 | Subarray Sum Equals K | `subarray2.cpp` | Medium | Prefix Sum + HashMap | O(n) | O(n) |

## 🧠 Key Concepts

- **Two-Pointer Technique** — Reduces brute-force O(n²) pair searches to O(n) on sorted data by converging pointers from both ends.
- **Prefix / Suffix Products** — Building cumulative arrays lets you answer range queries and "except self" problems without division.
- **Kadane's Algorithm** — The gold standard for Maximum Subarray Sum: maintain a running sum and reset when it drops below zero.
- **Prefix Sum + HashMap** — Storing cumulative sums in a hash map enables O(n) solutions for "subarray sum equals K" by checking if `prefixSum - K` was seen before.
- **Greedy Single-Pass** — The stock problem demonstrates how tracking a running minimum and computing profit at each step yields an optimal O(n) solution.

## 📌 Tips

- **Sort First, Think Later:** Many array problems become dramatically simpler after sorting — always consider whether sorting the input unlocks a two-pointer approach.
- **HashMap = O(1) Lookups:** When brute force involves nested loops searching for a complement, a hash map almost always collapses it to linear time.
- **Edge Cases to Watch:** Empty arrays, single-element arrays, all-negative arrays (Kadane's), and duplicate values (Pair Sum) are where most bugs hide.
