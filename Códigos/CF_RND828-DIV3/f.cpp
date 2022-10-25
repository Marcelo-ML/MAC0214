#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;

int n, pos[MAXN];

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
    	pos[x] = i;
	}
	int l = pos[0];
	int r = pos[0];
	long long resp = 0;
	for(int mex = 1; mex < n; mex++){
		l = min(pos[mex-1], l);
		r = max(pos[mex-1], r);
		if(l < pos[mex] && pos[mex] < r)
			continue;
		if(pos[mex] < l){
			for(int i = pos[mex]+1; i <= l; i++){
				if(r-i+1 > 2*mex)
					continue;
				resp += min(2*mex - (r-i), n - r);
			}
		}
		if(pos[mex] > r){
			for(int i = pos[mex]-1; i >= r; i--){
				if(i-l+1 > 2*mex)
					continue;
				resp += min(2*mex - (i-l), l - (-1));
			}
		}
	}
	cout << resp+1 << endl;
}

int main(){
	int t; cin >> t;
	while(t--) solve();
}
