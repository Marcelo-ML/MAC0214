#include <bits/stdc++.h>

using namespace std;

const int N = 0x7fffffff;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int candxor = 0;
        for(int i = 1; i <= n-3; i++)
            candxor = candxor ^ i;
        candxor = candxor ^ n;
        candxor = candxor ^ N;
        candxor = candxor ^ (N-1);
        int testxor = 0;
        if(candxor == 0){
            for(int i = 1; i <= n-3; i++){
                testxor = testxor ^ i;
                cout << i << " ";
            }
            testxor = testxor ^ n ^ N ^ (N-1);
            cout << n << " " << N << " " << (N-1) << endl;
        }
        if(candxor == 1){
            for(int i = 1; i <= n-3; i++){
                testxor = testxor ^ i;
                cout << i << " ";
            }
            testxor = testxor ^ (n^1) ^ N ^ (N-1);
            cout << (n^1) << " " << N << " " << (N-1) << endl;
        }
        else{
            for(int i = 1; i <= n-3; i++){
                testxor = testxor ^ i;
                cout << i << " ";
            }
            testxor = testxor ^ n ^ (N ^ candxor) ^ (N-1);
            cout << n << " " << (N^candxor) << " " <<  (N-1) << endl;
        }
        // cout << "testxor = " << testxor << endl;
    }
}

