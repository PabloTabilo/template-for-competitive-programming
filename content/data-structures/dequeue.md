---
title: "Dequeue"
---

# Dequeue

## What's a dequeue?

Is a generalize version of a queue with double Ended, where we can insert and delete elements at boths sides.

So, in any problem when we need to pop or push elements fast on $O(1)$ this data structure is very util.

## Problem - find longest special substring that occurs thrice I
You are given a string `s` that consists of lowercase English letters.

A string is called *special* if its made up of only a single character. For example, the string `abc` is not special, whereas the string `ddd`, `zz` and `f` are special.

Return the length of the longest special substrings of `s` which occurs at least thrice, or `-1` if no special substring occurs at least thrice.

A substrings is a contiguous non-empty sequence of characters within a string.

### Example test case 1:
Input: `s = "aaaa"`
Output: `2`

Explanation: 
* If $k = 1$, so i have `{{a}, {a}, {a}, {a}}`, and repeat more than 3 times. Its a factible answer.
* If $k = 2$, so i have `{{aa}, {aa}, {aa}}`, and repeat more than 3 times. Its a factible answer and the best at moment.
* If $k = 3$, so i have `{{aaa}, {aaa}}`, and repeat more than 3 times. Its not a factible answer.


### Thoughts
* Ok, the substring must be contiguous and not empty, so the combinations must be adjacents chars.
* If i need calculate combinations that are adjacent on a string may be i can use sliding windows
* Ok, but for sliding window if i wanna pop and push chars from front or end to my temporal contiguos substrings of size `k`, the time complexity gonna up if i try to insert elements or chars on front.
* Remember that the operation `+=` do it on a string, create a copy of the object. That's occupied time and memory.
* So if i only want get a track of the chars that are on my window, i can use a `deque<char>` and pop or push fast.


## References:
* link to the original problem: https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/description/