#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){_
    int T; cin >> T;
    int X;
    while(T --){
        cin >> X;
        if(X <= 100){
            cout << X << endl;
            continue;
        }
        if(X <= 1000){
            cout << X - 25 << endl;
            continue;
        }
        if(X <= 5000){
            cout << X - 100 << endl;
            continue;
        }
        cout << X - 500 << endl;
   }
   

}

