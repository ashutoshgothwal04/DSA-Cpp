#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums) {
    int xor1 = 0, xor2 = 0;
    int n = nums.size();  // Correctly determining the range

    for (int i = 0; i <= n; i++) {  // Loop goes up to n
        xor1 ^= i;
    }
    for (int num : nums) {
        xor2 ^= num;
    }
    return xor1 ^ xor2;
}

int main() {
    vector<int> arr = {0, 1, 3, 4, 5, 2, 7}; // Missing number is 6
    cout << "Missing Number: " << missingNumber(arr);
    return 0;
}
