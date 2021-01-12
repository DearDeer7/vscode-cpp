/**
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * author: deardeer
 */
// Solution 1 DFS
// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         if(digits.empty()) return {};
//         vector<string> maps = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//         vector<string> ans;
//         string cur = "";

//         function<void(int)> dfs = [&] (int d) {
//             if(d == digits.size()) {
//                 ans.push_back(cur);
//                 return;
//             }

//             string map = maps[digits[d] - '0'];
//             for(char c : map) {
//                 cur.push_back(c);
//                 dfs(d + 1);
//                 cur.pop_back();
//             }
//         };

//         dfs(0);
//         return ans;
//     }
// };

// Solution 2 BFS
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> maps = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans = {""};
        
        for(auto digit : digits) {
            vector<string> tmp;
            for(string s : ans) {
                for(char c : maps[digit - '0']) {
                    tmp.push_back(s + c);
                }
            }
            ans.swap(tmp);
        }
        return ans;
    }
};