#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

bool is_prime(int x){
    if(x == 1) return false;
    for(int i = 2; i * i <= x; i ++)
        if(x % i == 0)
            return false;
    return true;
}

bool is_good(int X){ // X = u*v with u, v >= 3
    if(X < 9) return false;
    if(is_prime(X))
        return false;
    if(X % 2 == 0 && is_prime(X/2)) return false;
    return true;
}

int main(){_
    int T; cin >> T;
    int X;
    while(T --){
        cin >> X;
        if(is_good(X + 4))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

