/**
 * Created by DearDeer on 2021/03/27
 */
#include<bits/stdc++.h>
using namespace std;

// #define DEER 1
#define endl '\n'
typedef long long ll;

vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    if(n == 0) return {-1, -1};
    vector<int> ans;
    int l = 0, r = n - 1;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(nums[m] == target) r = m - 1;
        else if(nums[m] < target) l = m + 1;
        else if(nums[m] > target) r = m - 1;
    }
    ans.push_back(l < n && nums[l] == target ? l : -1);
    l = 0, r = n - 1;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(nums[m] == target) l = m + 1;
        else if(nums[m] < target) l = m + 1;
        else if(nums[m] > target) r = m - 1;
    }
    ans.push_back(r > 0 && nums[r] == target ? r : -1);
    return ans;
}

bool search(vector<int>& nums, int target) {
    const int n = nums.size();
    int l = 0, r = n - 1;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(nums[m] == target) return true;
        else if(nums[m] < nums[r]) {
            if(target > nums[m] && target < nums[r]) l = m + 1;
            else r = m - 1;
        }
        else if(nums[m] > nums[r]) {
            if(target > nums[l] && target < nums[m]) r = m - 1;
            else l = m + 1;
        }
        else if(nums[m] == nums[r]) r = m;
    }
    return l < n && nums[l] == target ? true : false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> nums{1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    int target = 2;
    // vector<int> ans = searchRange(nums, target);
    // for(int i : ans) cout << i << endl;
    // cout << search(nums, target);

    int n = nums.size();
    int l = 0, r = n - 1;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(nums[m] > nums[m + 1]) r = m - 1;
        else if(nums[m] < nums[m + 1]) l = m + 1;
        else if(nums[m] == nums[m + 1]) r = m - 1;
    }
    int pivot = l;
    cout << pivot << endl;
    l = 0, r = pivot;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(nums[m] == target) {
            cout << "find target at" << m << endl;
            break;
        }
        else if(nums[m] < target) l = m + 1;
        else if(nums[m] > target) r = m - 1;
    }
    cout << l << " " << r << endl;

    l = pivot + 1, r = n - 1;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(nums[m] == target) {
            cout << "find target at" << m << endl;
            break;
        }
        else if(nums[m] < target) l = m + 1;
        else if(nums[m] > target) r = m - 1;
    }
    cout << l << " " << r << endl;
    
    return 0;
}