import java.util.Arrays;

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