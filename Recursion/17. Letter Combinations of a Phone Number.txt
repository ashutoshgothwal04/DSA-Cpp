class Solution {
public:
    void solve(string digits, string output, int idx, string mapping[], vector<string> &ans) {
        // base case 
        if (idx == digits.length()) {
            ans.push_back(output);
            return;
        }

        int num = digits[idx] - '0'; // convert ASCII char to int
        string value = mapping[num];

        for (int i = 0; i < value.length(); i++) {
            output.push_back(value[i]);   // ✅ push character, not string
            solve(digits, output, idx + 1, mapping, ans);
            output.pop_back();            // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        string output;
        int index = 0;
        string mapping[10] = {
            "",    // 0
            "",    // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs",// 7
            "tuv", // 8
            "wxyz" // 9
        };

        vector<string> ans;
        if (digits.empty()) return ans;

        solve(digits, output, index, mapping, ans);
        return ans;
    }
};
