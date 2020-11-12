// Author: DearDeer
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
#define MAX 0x3f3f3f3f
bool isPrime[100000001];
int prime[10000001];
int cnt;

//generate all prime numbers in [2,n] 
void generate(int n) {
    for(int i = 1; i < n; ++i)
        isPrime[i] = 1;
    isPrime[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if(isPrime[i]) {
            prime[++cnt] = i;
        }
        for (int j = 1; j <= cnt && i*prime[j] <= n; ++j) {
            isPrime[i * prime[j]] = 0;
            if(i % prime[j] == 0)
                break;
        }
    }
    
}

int gcd(int a,int b) { return b?gcd(b,a%b):a; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; 
    cin >> n;
    generate(n);
    for(int d : prime) {
        if(d != 0)
            cout << d << ' ';
    }
    return 0;
}