#include<iostream>
using namespace std;

int n,q;
bool isPrime[100000001];
int prime[10000001];
int cnt;

void fun(){
    for(int i = 1 ; i <= n; i++) isPrime[i] = 1;
    isPrime[1] = 0;
    for(int i = 2; i <= n; i++){
        if(isPrime[i]){
            prime[++cnt] = i;
        }
        for(int j = 1; j <= cnt && i*prime[j] <= n; j++){
            isPrime[i*prime[j]] = 0;
            if(i % prime[j] == 0) break;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    fun();
    while(q--){
        int k;
        cin >> k;
//        for(int i = 1; i <= n ; i++){
//            if(isPrime[i]){
//                k--;
//                if(k==0){
//                    cout << i << endl;
//                    break;
//                }
//            }
//        }
        cout << prime[k] << '\n';
    }
    return 0;
}