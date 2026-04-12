Q: Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (int val : nums) {
            if (st.find(val) != st.end()) {
                return true;
            }
            st.insert(val);
        }
        return false;
    }
};