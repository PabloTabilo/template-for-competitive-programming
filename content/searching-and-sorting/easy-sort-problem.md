---
title: "Easy Sort Problem"
weight: 1
---
# Starting with Sorting Problems
Let's start by looking at this LeetCode problem to help you understand the core concepts. Together we'll explore the different techniques and data structures you can use to solve it effectively.

## 2593 - Find Score of An Array After Marking All Elements
* Level `medium`.

### Problem statement
You are given an array `nums` consisting of positive integers.

Starting with `score = 0`, apply the following algorithm:

Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
Add the value of the chosen integer to score.
Mark the chosen element and its two adjacent elements if they exist.
Repeat until all the array elements are marked.
Return the score you get after applying the above algorithm.

Example 1:

Input: nums = [2,1,3,4,5,2]
Output: 7
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
- 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
- 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
Our score is 1 + 2 + 4 = 7.
Example 2:

Input: nums = [2,3,5,1,3,2]
Output: 5
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,5,1,3,2].
- 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [2,3,5,1,3,2].
- 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
Our score is 1 + 2 + 2 = 5.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106

### Thoughts

#### Approach 1
```java
class Solution {
    static class Pair implements Comparable<Pair>{
        int num;
        int index;
        Pair(int num, int index){
            this.num = num;
            this.index = index;
        }
        @Override
        public int compareTo(Pair other){
            if(this.num != other.num){
                return Integer.compare(this.num, other.num);
            }
            return Integer.compare(this.index, other.index);
        }
    }
    public long findScore(int[] nums) {
        long ans = 0;
        TreeSet<Pair> set = new TreeSet<>();
        int n = nums.length;
        for(int i=0;i<n;i++){
            set.add(new Pair(nums[i], i));
        }
        while(!set.isEmpty()){
            Pair p = set.pollFirst();
            ans += (long) p.num;
            int idx = p.index;
            if(idx + 1 < n){
                set.remove(new Pair(nums[idx+1],idx+1));
            }
            if(idx - 1 >= 0){
                set.remove(new Pair(nums[idx-1],idx-1));
            }
        }
        return ans;
    }
}
```

#### Approach 2
```java
class Solution {
    public long findScore(int[] nums) {
        long ans = 0;
        int n = nums.length;
        int [][] sorted = new int[n][2];
        boolean [] marked = new boolean[n];
        for(int i=0;i<n;i++){
            sorted[i][0] = nums[i];
            sorted[i][1] = i;
        }
        Arrays.sort(sorted, (arr1, arr2) -> arr1[0] - arr2[0]);
        for(int i=0;i<n;i++){
            int num = sorted[i][0];
            int idx = sorted[i][1];
            if(!marked[idx]){
                ans += (long) num;
                marked[idx] = true;
                if(idx-1 >= 0){
                    marked[idx-1]=true;
                }
                if(idx+1 < n){
                    marked[idx+1]=true;
                }
            }
        }
        return ans;
    }
}
```

### Submissions Results
![Sumbissions Results](images/searchingAndSorting_EasySortProblem_SubmissionResults_1.PNG)

### References:
* Problem: https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/
* `TreeSet` data structure on java: https://docs.oracle.com/javase/8/docs/api/java/util/TreeSet.html