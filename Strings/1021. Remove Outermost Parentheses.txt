// class Solution {
// public:
//     string removeOuterParentheses(string s) {
//         int cnt = 0;
//         string ans = "";
//         for(int i=0; i<s.length(); i++){
//             if(s[i] == ')') cnt--;
//             if(cnt != 0) ans.push_back(s[i]);
//             if(s[i] == '(') cnt++;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     string removeOuterParentheses(string S) {
//         string res;
//         int opened = 0;
//         for (char c : S) {
//             if (c == '(' && opened++ > 0) res += c;
//             if (c == ')' && opened-- > 1) res += c;
//         }
//         return res;
//     }
// };

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int cnt = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                // If cnt is greater than 0, it means this '(' is not an
                // outermost parenthesis
                if (cnt > 0) {
                    result.push_back(s[i]); // Add the character to the result
                }
                cnt++; // Increase the cnt for '('
            } else {
                cnt--; // Decrease the cnt for ')'
                // If cnt is greater than 0, it means this ')' is not an
                // outermost parenthesis
                if (cnt > 0)
                    result.push_back(s[i]); // Add the character to the result
            }
        }
        return result;
    }
};