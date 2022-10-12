#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string a, b; cin >> a >> b;
        int ta = a.size(), tb = b.size();
        if(a[ta-1] == 'S'){
            if(b[tb-1] != 'S'){
                cout << "<" << endl;
                continue;
            }
            if(ta < tb){
                cout << ">" << endl;
                continue;
            }
            if(ta == tb){
                cout << "=" << endl;
                continue;
            }
            if(ta > tb){
                cout << "<" << endl;
                continue;
            }
        }
        if(a[ta-1] == 'M'){
            if(b[tb-1] == 'M'){
                cout << "=" << endl;
                continue;
            }
            if(b[tb-1] == 'S'){
                cout << ">" << endl;
                continue;
            }
            if(b[tb-1] == 'L'){
                cout << "<" << endl;
                continue;
            }
        }
        if(a[ta-1] == 'L'){
            if(b[tb-1] != 'L'){
                cout << ">" << endl;
                continue;
            }
            if(ta < tb){
                cout << "<" << endl;
                continue;
            }
            if(ta == tb){
                cout << "=" << endl;
                continue;
            }
            if(ta > tb){
                cout << ">" << endl;
                continue;
            }
        }
    }
}


