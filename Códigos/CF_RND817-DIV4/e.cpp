#include <bits/stdc++.h>

#define int long long
#define pii pair<int,int>
#define fs first
#define sc second
#define fr(i, n) for(int i = 0; i < n; i++)
#define frp(i, n) for(int i = 1; i <= n; i++)

#define MAXN 1010
using namespace std;

int areas[MAXN][MAXN];
int areas_acum[MAXN][MAXN];

signed main(){
    int t; cin >> t;
    vector<pii> rets = {};
    while(t--){
        while(!rets.empty()){
            pii now = rets.back();
            areas[now.fs][now.sc] = 0;
            rets.pop_back();
        }
        int n, q; cin >> n >> q;
        int maxh = 0, maxw = 0;
        fr(i, n){
            pii p; int h, w; cin >> h >> w;
            maxh = max(maxh, h); maxw = max(maxw, w);
            p.fs = h; p.sc = w;
            areas[h][w] += h*w;
            rets.push_back(p);
        }
        frp(i, MAXN-1) frp(j, MAXN-1){
            areas_acum[i][j] = areas[i][j] + areas_acum[i-1][j] + areas_acum[i][j-1] - areas_acum[i-1][j-1];
        }
        /*
        cout << endl;
        frp(i, maxh){
            frp(j, maxw){
                cout << areas[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
        frp(i, maxh){
            frp(j, maxw){
                cout << areas_acum[i][j] << " ";
            }
            cout << endl;
        }
        */
        fr(i, q){
            int hs, ws, hb, wb; cin >> hs >> ws >> hb >> wb;
            cout << areas_acum[hb-1][wb-1] + areas_acum[hs][ws] - areas_acum[hb-1][ws] - areas_acum[hs][wb-1] << endl;
        }
    }
}

