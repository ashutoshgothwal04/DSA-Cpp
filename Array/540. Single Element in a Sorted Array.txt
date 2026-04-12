class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        // for(int i=0; i<n-1; i+=2){
        //      if(nums[i] != nums[i+1]) {
        //         return nums[i];
        //     }
        // }
        // return nums[n-1];

        /////// O(n) Ts


        // int res = 0;
        // for(int num : nums){
        //     res ^= num;
        // }
        // return res;

        int s = 0, e = n-1;
        while(s < e){
            int mid = s+(e-s)/2;
            if (nums[mid] == nums[mid ^ 1]) {
                s = mid + 1; // Pair is intact, move right
            } else {
                e = mid; // Pair is broken, single element is here or to the left
            }
        }
        return nums[s];
    }
};