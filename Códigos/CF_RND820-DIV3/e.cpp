#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int i = 2;
    while(1){
        int len1, len2;
        cout << "? 1 " << i << endl;
        cin >> len1;
        if(len1 == -1){
            cout << "! " << i-1 << endl;
            return 0;
        }
        cout << "? " << i << " 1" << endl;
        cin >> len2;
        if(len1 != len2){
            cout << "! " << len1 + len2 << endl;
            return 0;
        }
        i++;
    }
}

