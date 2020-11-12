/**
 * Created by DearDeer on 2020/10/09
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        int flag = 1;
        if(dividend < 0) flag = -flag;
        if(divisor < 0) flag = -flag;
        
        dividend = abs(dividend);
        divisor = abs(divisor);

        long long ans = 0;
        long long sum = 0;
        while(sum < dividend) {
            sum += divisor;
            if(sum >= INT_MAX) return INT_MAX;
            ans++;
        }

        if(sum != dividend) {
            ans--;
        }

        return flag == 1 ? ans :-ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    
    return 0;
}