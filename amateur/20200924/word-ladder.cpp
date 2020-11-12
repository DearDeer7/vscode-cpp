class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return 0;

        queue<string> q{beginWord};
        int ans = 0;
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                string curr = q.front(); q.pop();
                for (int i = 0; i < curr.size(); ++i) {
                    for(int j = -1; j <= 1; j += 2) {
                        curr[i] += j;
                        if(curr[i] > 'z')
                            curr[i] = 'a';
                        else if(curr[i] < 'a')
                            curr[i] = 'z';
                        if(!dict.count(curr))
                            continue;
                        dict.erase(curr);
                        q.push(curr);
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};