#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

bool is_pow2(int a){
    if(a == 1) return true;
    if(a % 2 == 1) return false;
    return is_pow2(a/2);
}

int main(){_
    int T; cin >> T;
    
    int a, b;
    while(T --){
        cin >> a >> b;
        if(a == 0 || b == 0){
            if(a == 0 && b == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            continue;
        }
        if(a < b){
            int aux = a; a = b; b = aux;
        }
        int ratio = a / b;
        if(ratio * b == a && is_pow2(ratio))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

}

