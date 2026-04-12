class Solution {
public:
    int findPivort(vector<int>& nums, int n) {
        int s = 0, e = n - 1;
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] > nums[e]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return e;
    }

    int binarySearch(int s, int e, vector<int>& nums, int k) {
        int idx = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == k) {
                idx = mid;
                break;
            } else if (nums[mid] < k) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return idx;
    }

    int search(vector<int>& nums, int k) {
        int n = nums.size();

        int pivortIdx = findPivort(nums, n);

        int idx = binarySearch(0, pivortIdx - 1, nums, k); // left sorted
        if (idx != -1)
            return idx;

        idx = binarySearch(pivortIdx, n - 1, nums, k); // right sorted

        return idx;
    }
};