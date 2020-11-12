class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};
        vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string curr;
        int sz = digits.size();
        function<void(int)> dfs = [&](int k) {
            if(k == sz) {
                ans.push_back(curr);
                return;
            } 
            for(int i = k; i < sz; ++i) {
                string ts = dict[digits[i] - 'a'];
                for (int j = 0; j < ts.size(); ++j) {
                    curr.push_back(ts[j]);
                    dfs(i + 1);
                    curr.pop_back();
                }
            }
        };
    }
};