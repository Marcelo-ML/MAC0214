#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define int long long

void solve(){
	int n, q; cin >> n >> q;
	int L, R;
	vector<int> a;
	a.pb(0);
	for(int i = 0; i < n; i++){
		int x; cin >> x; a.pb(x);
	}
	cin >> L >> R;
	vector<int> psum (n+10);
	vector<int> pxor (n+10);
	partial_sum(a.begin(), a.end(), psum.begin());
	partial_sum(a.begin(), a.end(), pxor.begin(), bit_xor<int>());

	int lmax = 1, rmax = n;
	int valmax = (psum[rmax]-psum[lmax-1]) - (pxor[rmax]^pxor[lmax-1]);

	int piso, teto, meio;
	for(int i = 1; i <= n; i++){
		piso = i;
		teto = n;
		while(piso < teto){
			meio = (piso+teto)/2;
			if( (psum[teto]-psum[i-1]) - (pxor[teto]^pxor[i-1]) > 
				(psum[meio]-psum[i-1]) - (pxor[meio]^pxor[i-1]) ) 
				piso = meio+1;
			else
				teto = meio;
		}
		if( (psum[teto]-psum[i-1]) - (pxor[teto]^pxor[i-1]) > valmax ||
			( (psum[teto]-psum[i-1]) - (pxor[teto]^pxor[i-1]) == valmax && teto - i < rmax - lmax ) ){
			lmax = i;
			rmax = teto;
			valmax = valmax = (psum[rmax]-psum[lmax-1]) - (pxor[rmax]^pxor[lmax-1]);
		}
	}
	cout << lmax << ' ' << rmax << endl;
}

signed main(){_
	int q; cin >> q;
	while(q--) solve();
}

