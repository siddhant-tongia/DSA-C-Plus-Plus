# 05 — Advanced Array Techniques

> Where fundamentals meet ingenuity — these problems demand creative combinations of sorting, hashing, and pointer manipulation to achieve optimal solutions.

## 📋 Problems

| # | Problem | File | Difficulty | Approach | Time | Space |
|---|---------|------|-----------|----------|------|-------|
| 1 | Container With Most Water | `ContainerwithMostWaterProblem.cpp` | Medium | Two Pointer (Greedy Shrink) | O(n) | O(1) |
| 2 | Find the Duplicate Number | `FindDuplicate.cpp` | Medium | Floyd's Cycle Detection (Tortoise & Hare) | O(n) | O(1) |
| 3 | 4Sum Problem | `Four_sum.cpp` | Hard | Sort + Two Pointer (Nested Loops) | O(n³) | O(1) |
| 4 | Merge Sorted Array | `MergeSortedArray.cpp` | Easy | Back-Fill from End (Three Pointer) | O(m + n) | O(1) |
| 5 | Majority Element (Boyer-Moore) | `Moorevoting.cpp` | Easy | Boyer-Moore Voting Algorithm | O(n) | O(1) |
| 6 | Next Permutation | `NextPermutation.cpp` | Medium | 3-Step: Find Dip → Swap → Reverse | O(n) | O(1) |
| 7 | Subarray Sum Equals K | `SubArraySumEqualToK.cpp` | Medium | Prefix Sum + HashMap | O(n) | O(n) |
| 8 | 3Sum Problem | `Three_sum.cpp` | Medium | Sort + Two Pointer | O(n²) | O(1) |
| 9 | Two Sum | `Two_sum.cpp` | Easy | HashMap (Value → Index) | O(n) | O(n) |
| 10 | Maximum Subarray (Kadane's) | `kaden.cpp` | Medium | Kadane's Algorithm | O(n) | O(1) |
| 11 | Majority Element (Brute Force) | `majorityelement.cpp` | Easy | Nested Loop / Count Occurrences | O(n²) | O(1) |
| 12 | Majority Element II (Sorting) | `majorityelement2.cpp` | Medium | Sort + Linear Scan | O(n log n) | O(1) |

## 🧠 Key Concepts

- **Two-Pointer Mastery** — From Container With Most Water to 3Sum/4Sum, the two-pointer pattern on sorted data is arguably the most versatile technique in array problems.
- **Floyd's Cycle Detection** — Finding a duplicate in an array where values are in `[1, n]` by treating it as a linked list: `nums[i] → nums[nums[i]]`. The tortoise-and-hare approach finds the cycle entry in O(n) time, O(1) space.
- **Boyer-Moore Voting** — Finds the majority element (appears > n/2 times) in a single pass using a counter that cancels out non-majority elements. Elegant and O(1) space.
- **Next Permutation Algorithm** — A 3-step in-place transformation: (1) find the rightmost ascending pair, (2) swap with the smallest larger element to its right, (3) reverse the suffix. Used in combinatorics and interview problems.
- **Prefix Sum + HashMap** — Transforms "find subarrays with sum K" into a lookup problem: store cumulative sums and check if `prefixSum - K` exists in the map.
- **Back-Fill Merge** — Merging into an array with trailing space by filling from the end avoids shifting elements, achieving O(m + n) with O(1) extra space.
- **K-Sum Generalisation** — Two Sum → 3Sum → 4Sum follows a recursive pattern: fix one element, reduce to (K-1)Sum. The base case is always Two Pointer on a sorted array.

## 📌 Tips

- **Pattern Recognition Is Key:** Most "hard" array problems are combinations of 2–3 standard techniques (sort + two pointer + hashmap). Train yourself to decompose problems into known patterns.
- **Space-Time Tradeoff:** Compare brute force → sorting → hashing approaches for the same problem (e.g., Majority Element has O(n²), O(n log n), and O(n) solutions) to understand when each is appropriate.
- **Duplicate Handling:** In K-Sum problems, skipping duplicate values after fixing an element is critical to avoid duplicate triplets/quadruplets — interviewers specifically watch for this.
