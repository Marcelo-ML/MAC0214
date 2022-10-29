#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define int long long

void solve(){
	int n, q; cin >> n >> q;
	vector<int> a;
	a.pb(0);
	for(int i = 0; i < n; i++){
		int x; cin >> x; a.pb(x);
	}
	vector<int> psum (n+10);
	vector<int> pxor (n+10);
	partial_sum(a.begin(), a.end(), psum.begin());
	partial_sum(a.begin(), a.end(), pxor.begin(), bit_xor<int>());

	vector<int> nao_zeros;
	nao_zeros.pb(0);
	for(int i = 1; i <= n; i++){
		if(a[i]) nao_zeros.pb(i);
	}
//	for(auto x : nao_zeros) cout << x << ' ';
//	cout << "bazukka" << endl;

	for(int ii = 0; ii < q; ii++){
		int L, R; cin >> L >> R;
		int lmax = L, rmax = R;
		int valmax = (psum[rmax]-psum[lmax-1]) - (pxor[rmax]^pxor[lmax-1]);
		if(valmax == 0){
			cout << L << ' ' << L << endl;
			continue;
		}

		int piso, teto, meio;
		int achei = lower_bound(nao_zeros.begin(), nao_zeros.end(),L) - nao_zeros.begin();
		// cout << "L: " << L << " -> j: " << j << endl;
		for(int j = achei ; j < nao_zeros.size() && j - achei < 40; j++){
			int i = nao_zeros[j];
		//	cout << "i: " << i << endl;
			piso = i;
			teto = R;
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
				valmax = (psum[rmax]-psum[lmax-1]) - (pxor[rmax]^pxor[lmax-1]);
			}
		}
		int i = L;
			piso = i;
			teto = R;
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
				valmax = (psum[rmax]-psum[lmax-1]) - (pxor[rmax]^pxor[lmax-1]);
			}

		cout << lmax << ' ' << rmax << endl;
	}
}

signed main(){_
	int t; cin >> t;
	while(t--) solve();
}

