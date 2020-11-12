// slanting traverse 2D table
#include<iostream>
using namespace std;

int main(){
    int matrix[3][3] = {
        1,2,3,
        4,5,6,
        7,8,9
    };
    int n = 3;
    // 斜着遍历数组
//    for (int l = 1; l <= n; l++) {
//        for (int i = 0; i <= n - l; i++) {
//            int j = l + i - 1;
//            cout << matrix[i][j] << ' ';
//            cout << i << ',' << j                                                                                                                                                                                                                  << ' ';
//        }
//        cout << endl;
//    }
    for(int id = 0; id <= n ;++id){
        for(int i = 0; i < n-id; ++i){
            int j = i +id;
//            cout << i << ',' << j << ' ';
            cout << matrix[i][j] << ' ';
        }
        cout <<endl;
    }
    return 0;
}
