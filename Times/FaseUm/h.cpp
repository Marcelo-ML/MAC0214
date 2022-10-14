#include <bits/stdc++.h>
using namespace std;
#define MAXN 11234
#define MAXM 1123456
#define pb push_back

vector<int> adj[MAXN];
vector<int> adj_rev[MAXN];
bool vis[MAXN];
vector<int> order;
vector<int> component;
vector<int> adj_scc[MAXN];
vector<int> adj_scc_rev[MAXN];
vector<int> root_nodes;
int roots[MAXN];
int n, m;

void dfs1(int v){
    vis[v] = 1;
    for(auto u : adj[v]){
        if(vis[u])
            continue;
        dfs1(u);
    }
    order.pb(v);
}

void dfs2(int v){
    vis[v] = 1;
    component.pb(v);

    for(auto u : adj_rev[v]){
        if(vis[u])
            continue;
        dfs2(u);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u-1].pb(v-1);
        adj_rev[v-1].pb(u-1);
    }
    memset(vis, 0, sizeof(vis));
    for(int v = 0; v < n; v++){
        if(!vis[v])
            dfs1(v);
    }

    reverse(order.begin(), order.end());
    memset(vis, 0, sizeof(vis));

    for(auto v : order){
        if(!vis[v]){
            dfs2(v);
            int root = component[0];
            for(auto u : component){
                roots[u] = root;
            }
            root_nodes.pb(root);
            component.clear();
        }
    }
    for(int v = 0; v < n; v++){
        for(auto u : adj[v]){
            int root_v = roots[v],
                root_u = roots[u];

            if (root_u != root_v){
                adj_scc[root_v].pb(root_u);
                adj_scc_rev[root_u].pb(root_v);
            }
        }
    }

    vector<int> nao_entra;
    vector<int> nao_sai;
    
    for(auto v : root_nodes){
        if(adj_scc[v].empty())
            nao_sai.pb(v);
        if(adj_scc_rev[v].empty())
            nao_entra.pb(v);
    }

    if(nao_entra.size() == 1 && nao_sai.size() == 1 && nao_entra[0] == nao_sai[0])
        cout << 0 << endl;

    else
        cout << max(nao_entra.size(), nao_sai.size()) << endl;
}
    
    

