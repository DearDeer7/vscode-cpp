/**
 * https://leetcode.com/problems/letter-case-permutation/
 * author: deardeer
 */
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        
        function<void(int)> dfs = [&] (int s) {
            if(s == S.size()) {
                ans.push_back(S);
                return;
            }
            dfs(s + 1);
            if(!isalpha(S[s])) return;
            S[s] ^= (1 << 5); // toggle(S[i]) 'a' - 'A' = 32
            dfs(s + 1);
            S[s] ^= (1 << 5);
        };

        dfs(0);
        return ans;
    }
};