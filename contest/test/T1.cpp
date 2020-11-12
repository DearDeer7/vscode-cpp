#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
typedef long long LL;
#define MAX 0x3f3f3f3f

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums(100);
    generate(nums.begin(), nums.end(), rand);
    for(int d : nums) cout << d << '\t';
    cout << endl;
    if(nums.size() and 1) cout << nums.size() << endl;
    return 0;
}
