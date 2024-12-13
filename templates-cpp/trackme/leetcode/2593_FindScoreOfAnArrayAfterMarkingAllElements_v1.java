import java.util.TreeSet;

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