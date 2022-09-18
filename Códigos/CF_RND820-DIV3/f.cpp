#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.size();
        int w, M; cin >> w >> M;
        int acum[n + 10];
        acum[0] = 0;
        for(int i = 1; i <= n; i++)
            acum[i] = (acum[i-1] + (s[i-1]-'0'))%9;
        vector<int> m[10];
        // m[i] guarda os começos de substring que deixam resto i
        for(int i = 1; i <= n - w + 1; i++){
            int resto = (acum[i+w-1] - acum[i-1] + 90) % 9;
            m[resto].pb(i);
        }
        while(M--){
            int l, r, k; cin >> l >> r >> k;
            int v = (acum[r] - acum[l-1] + 90) % 9;
            int L1 = 1234567, L2 = 1234567;
            for(int a = 0; a <= 8; a++){
                for(int b = 0; b <= 8; b++){
                    if((a*v + b) % 9 != k)
                        continue;
//                  cout << a << " " << v << " " << b << " <- a, v, b" << endl;
                    if(a == b){
                        if(m[a].size() <= 1)
                            continue;
                        if((m[a][0] < L1) || (m[a][0] == L1 && m[a][1] < L2)){
                            L1 = m[a][0];
                            L2 = m[a][1];
                        }
                    }
                    if(m[a].empty() || m[b].empty())
                        continue;
                    if(m[a][0] < L1 || m[a][0] == L1 && m[b][0] < L2){
                        if(a == b) continue;
                        L1 = m[a][0];
                        L2 = m[b][0];
                    }
                }
            }
            if(L1 == 1234567)
                cout << "-1 -1";
            else
                cout << L1 << " " << L2;
            cout << endl;
        }
    }
}

