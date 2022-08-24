#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAXN 100010

int a[4*MAXN];
vector<int> resp;

void printa(int tam){
    for(int i = 1; i <= tam; i ++){
        cout << a[i] << " ";
    } cout << endl;
}

int main(){
    string s;
    cin >> s;
    int tam = s.size();
    for(int i = 0; i < tam; i ++){
        (s[i] == '1') ? a[i + 1] = 1 : a[i+1] = 0;
    }

    for(int i = 1; i < tam; i += 3){
        if(a[i] != a[i+1] || a[i] != a[i+2]){
            if(a[i] != a[i+1]){
                if(a[i+1] != a[i+2]){
                    continue;
                }
                else{
                    resp.pb(i);
                    a[i] = 1-a[i];
                    a[i+1] = 1-a[i+1];
                }
            }
            else{
                resp.pb(i+1);
                a[i+2] = 1-a[i+2];
                a[i+1] = 1-a[i+1];
            }
        }
        else{
            if(i == 1){
                resp.pb(i);
                a[i] = 1-a[i];
                a[i+1] = 1-a[i+1];
            }
            else{
                if(a[i] == a[i-1]){
                    resp.pb(i);
                    a[i] = 1-a[i];
                    a[i+1] = 1-a[i+1];
                }
                else{
                    resp.pb(i+1);
                    a[i+2] = 1-a[i+2];
                    a[i+1] = 1-a[i+1];
                }
            }
        }
        // printa(tam);
    }

    cout << resp.size();
    if(resp.size()) cout << endl;
    for(int i = 0; i < resp.size(); i++)
        cout << resp[i] << " ";
    cout << endl;
}
