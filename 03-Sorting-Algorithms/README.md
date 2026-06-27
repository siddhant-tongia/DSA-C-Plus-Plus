# 03 — Sorting Algorithms

> Sorting is the gateway to efficient algorithms — once data is ordered, search, merge, and deduplication become trivial.

## 📋 Problems

| # | Problem | File | Difficulty | Approach | Time | Space |
|---|---------|------|-----------|----------|------|-------|
| 1 | Bubble Sort | `bubblesort.cpp` | Easy | Repeated Adjacent Swaps | O(n²) | O(1) |
| 2 | Insertion Sort | `insertionsort.cpp` | Easy | Shift & Insert in Sorted Prefix | O(n²) | O(1) |
| 3 | Selection Sort | `selectionsort.cpp` | Easy | Find Min & Swap to Front | O(n²) | O(1) |
| 4 | Sort 0s 1s 2s (Dutch National Flag) | `sort_012_DNF.cpp` | Medium | Three-Way Partitioning (DNF) | O(n) | O(1) |

## 📊 Sorting Algorithm Comparison

| Algorithm | Best | Average | Worst | Space | Stable? | Adaptive? | Notes |
|-----------|------|---------|-------|-------|---------|-----------|-------|
| **Bubble Sort** | O(n) | O(n²) | O(n²) | O(1) | ✅ Yes | ✅ Yes | Early termination if no swaps; simple but slow |
| **Insertion Sort** | O(n) | O(n²) | O(n²) | O(1) | ✅ Yes | ✅ Yes | Excellent for small / nearly-sorted data |
| **Selection Sort** | O(n²) | O(n²) | O(n²) | O(1) | ❌ No | ❌ No | Always makes O(n) swaps; not adaptive |
| **Dutch National Flag** | O(n) | O(n) | O(n) | O(1) | ✅ Yes | — | Specialised 3-way partition for {0, 1, 2} |

> 💡 *For reference, production sorts like **Merge Sort** (O(n log n), stable) and **Quick Sort** (O(n log n) avg, in-place) are covered in later modules.*

## 🧠 Key Concepts

- **Stability** — A stable sort preserves the relative order of equal elements. This matters when sorting by multiple keys (e.g., sort by name, then by age).
- **Adaptivity** — An adaptive sort runs faster on partially sorted input (e.g., Insertion Sort achieves O(n) on nearly-sorted data).
- **In-Place Sorting** — All algorithms here use O(1) extra space, modifying the array directly without auxiliary storage.
- **Dutch National Flag (DNF)** — Dijkstra's 3-pointer algorithm partitions an array into three sections in a single pass; frequently asked in interviews as "Sort Colors."
- **Swap Minimisation** — Selection Sort minimises the number of swaps (at most n), making it useful when write operations are expensive.

## 📌 Tips

- **Know When to Use What:** Insertion Sort beats all O(n²) sorts on small or nearly-sorted inputs — that's why hybrid sorts like TimSort use it for small partitions.
- **DNF Is a Must-Know:** The Dutch National Flag problem appears in FAANG interviews as LeetCode 75 ("Sort Colors") — practice the three-pointer invariant until it's muscle memory.
- **Don't Just Memorise — Visualise:** Trace through 5-element examples by hand for each sort to truly understand the invariant each algorithm maintains at every step.
