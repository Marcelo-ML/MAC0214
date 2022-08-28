#include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
#define fs first
#define sc second


using namespace std;
  
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n+10], b[n+10];
        a[0] = 0; b[0] = 0;
        for(int i = 1; i <= n; i ++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i ++){
            cin >> b[i];
        }
        int pa = 1, pb = 1;
        while(pa <= n){
            while(b[pb] < a[pa])
                pb++;
            cout << b[pb] - a[pa] << " ";
            pa++;
        }
        cout << endl;

        pa = n, pb = n;
        stack<int> pilha;
        while(pa >= 1){
            if(a[pa+1] > b[pa])
                pb=pa;
            pilha.push(b[pb] - a[pa]);
            pa--;
        }
        while(!pilha.empty()){
            cout << pilha.top() << " ";
            pilha.pop();
        }
        cout << endl;
    }
}
