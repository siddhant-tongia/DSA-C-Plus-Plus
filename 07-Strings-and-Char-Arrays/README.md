# 07 — Strings and Char Arrays

> Strings are everywhere — from parsing input to pattern matching in interviews. Master these fundamental operations and unlock the gateway to advanced text processing algorithms.

## 📋 Problems

| # | Problem | File | Difficulty | Approach | Time | Space |
|---|---------|------|-----------|----------|------|-------|
| 1 | Valid Palindrome | `Palindrome.cpp` | Easy | Two Pointers + Filter Non-Alphanumeric | O(N) | O(1) |
| 2 | Permutation in String | `PermutationInString.cpp` | Medium | Sliding Window + Frequency Count | O(N) | O(1) |
| 3 | Remove All Occurrences of Substring | `RemoveAllOccurrences.cpp` | Medium | String Search + Erase / Stack-Based | O(N × M) | O(N) |
| 4 | Reverse String | `ReverseString.cpp` | Easy | Two Pointers (In-Place Swap) | O(N) | O(1) |
| 5 | Reverse Words in a String | `ReverseWordInString.cpp` | Medium | Reverse Entire String + Reverse Each Word | O(N) | O(N) |
| 6 | String Compression (Run-Length Encoding) | `StringCompression.cpp` | Medium | Two Pointers + In-Place Write | O(N) | O(1) |

> **N** = length of string, **M** = length of substring/pattern

## 🧠 Key Concepts

- **Two-Pointer Technique**: Ideal for in-place string manipulation — reversals, palindrome checks, and compression without extra space.
- **Sliding Window**: Fixed-size window with frequency arrays is the go-to approach for anagram/permutation detection in strings.
- **Character Frequency Arrays**: Use `int freq[26]` for lowercase-only problems — faster and more cache-friendly than hash maps.
- **In-Place Modification**: Many string problems reward solutions that modify the string in-place to achieve O(1) auxiliary space.
- **ASCII Manipulation**: Leverage `tolower()`, `isalnum()`, and character arithmetic (`ch - 'a'`) for clean, efficient code.

## 📌 Tips

- **Sliding Window Mastery**: For "permutation in string" style problems, maintain a frequency match count to avoid re-comparing entire arrays every iteration — this brings the comparison from O(26) to O(1) per step.
- **Edge Cases First**: Always consider empty strings, single-character strings, strings with only spaces, and strings with all identical characters before coding.
- **`string::erase` is Expensive**: Repeated `erase()` calls on `std::string` are O(N) each — prefer stack-based or two-pointer approaches for better amortized performance.
