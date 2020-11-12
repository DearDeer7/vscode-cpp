// unordered_map
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> cnts;
        int sz = nums.size();
        if(sz <= 2) return nums[0];
        for(int i : nums) {
            cnts[i]++;
            if(cnts[i] > sz / 2) {
                return i;
            }
        }
        return -1;
    }
};

// map 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> cnts;
        int sz = nums.size();
        if(sz <= 2) return nums[0];
        for(int i : nums) {
            cnts[i]++;
            if(cnts[i] > sz / 2) {
                return i;
            }
        }
        return -1;
    }
};

// randomization
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sz = nums.size();
        if(sz <= 2) return nums[0];
        srand(time(nullptr));
        while(true) {
            int majority = nums[rand() % sz];
            int cnt = 0;
            for(int num : nums) {
                if(num == majority && (++cnt > sz / 2)) return num;
            }
        }
        return -1;
    }
};

// Moore Voting 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sz = nums.size();
        if(sz <= 2) return nums[0];
        int cnt = 0, majority = nums[0];
        for(int num : nums) {
            if(majority == num) cnt++;
            else if(--cnt == 0) {
                cnt = 1;
                majority = num; 
            }
        }
        return majority;
    }
};

// sorting
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sz = nums.size();
        if(sz <= 2) return nums[0];
        sort(nums.begin(), nums.end());
        return nums[sz / 2];
    }
};

// partial sorting
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sz = nums.size();
        if(sz <= 2) return nums[0];
        nth_element(nums.begin(), nums.begin() + sz / 2, nums.end());
        return nums[sz / 2];
    }
};

// divide and conquer
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sz = nums.size();
        if(sz <= 2) return nums[0];
        return majorityElement(nums, 0, sz - 1).first;
    }

    pair<int, int> majorityElement(vector<int>& nums, int l, int r) {
        if(l == r) return {nums[l], 1};
        int mid = l + (r - l) / 2;
        auto ml = majorityElement(nums, l, mid);
        auto mr = majorityElement(nums, mid + 1, r);
        if(ml.first == mr.first) return {ml.first, ml.second + mr.second};
        if(ml.second > mr.second) return {ml.first, ml.second + count(nums.begin() + mid + 1, nums.begin() + r, ml.first)};
        return {mr.first, mr.second + count(nums.begin() + l, nums.begin() + mid, mr.first)};
    }
};