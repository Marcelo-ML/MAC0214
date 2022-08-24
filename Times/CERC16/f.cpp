#include <bits/stdc++.h>
using namespace std;
#define MAXN 112345

int a1[MAXN], a2[MAXN];
bool vis1[MAXN], vis2[MAXN];
int tot;

void desimpilha1(int i){
    while(i != 0){
    if(vis1[i]) return;
        vis1[i] = 1;
        tot++;
        i = a1[i];
    }
}

void desimpilha2(int i){
    while(i != 0){
    if(vis2[i]) return;
        vis2[i] = 1;
        tot++;
        i = a2[i];
    }
}

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a1[i];
    for(int i = 1; i <= n; i ++)
        cin >> a2[i];
    for(int ii = 1; ii <= n; ii ++){
        int i = ii;
        if(vis1[i] && vis2[i]) continue;
        if(!vis1[i] && !vis2[i]){
            while(a1[i] == a2[i] && a1[i] != 0){
                vis1[i] = 1;
                vis2[i] = 1;
                i = a1[i];
            }
            desimpilha1(a1[i]);
            desimpilha2(a2[i]);
            continue;
        }
        if(!vis1[i]){
            desimpilha1(a1[i]);
            continue;
        }
        if(!vis2[i]){
            desimpilha2(a2[i]);
            continue;
        }
    }
    cout << tot << endl;
}
