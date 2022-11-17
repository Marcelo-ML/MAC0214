#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define dbg(x) cerr << #x << "=" << x << ' '
#define pii pair<int,int>

#define MAXN 1123

char grid[MAXN][MAXN];

bool vis[MAXN][MAXN];
int dist[MAXN][MAXN];

int dx[8] = {1 ,1, 1, 0, 0, -1, -1, -1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int maxtam = 0;

void dfs(int x, int y){
    if(dist[x][y] > maxtam) maxtam = dist[x][y];
    
    vis[x][y] = true;
    char c = grid[x][y];

    for(int k = 0; k < 8; k++){

        int new_x, new_y;
        new_x = x + dx[k];
        new_y = y + dy[k];

        if(!vis[new_x][new_y] && grid[new_x][new_y] == c + 1){

            dist[new_x][new_y] = dist[x][y] + 1;
            dfs(new_x, new_y);

        }
    }
}

signed main(){
    fastio();

    int n, m; cin >> n >> m;

    vector<pair<int, int>> mp[26];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;

            mp[c - 'A'].pb({i, j});

            grid[i][j] = c;
        }
    }

    for(int i = 0; i < 26; i++){
        for(auto x : mp[i]){
            if(!vis[x.first][x.second]) dfs(x.first, x.second);
        }
    }

    cout << maxtam + 1 << endl;

    return 0;
}

