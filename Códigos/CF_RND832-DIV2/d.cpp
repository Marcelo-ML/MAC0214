#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define endl '\n'

void solve(){
	int n, q; cin >> n >> q;
	vector<int> a (n);
	vector<int> pxor (n);
	for(int i = 0; i < n; i++) cin >> a[i];
//	for(int i = 0; i < n; i++)
//		cout << a[i] << ' '; cout << endl;


	partial_sum(all(a), pxor.begin(), bit_xor<int>());
//	for(int i = 0; i < n; i++)
//		cout << pxor[i] << ' '; cout << endl;

	auto get_xor = [&](int l, int r){return pxor[r]^(l ? pxor[l-1] : 0);};
	map<int,vector<int>> m[2];
	// m[j][i] guarda o vetor das posições de paridade j onde o pxor é igual a i
	
	for(int i = 0; i < n; i++){
		m[i&1][pxor[i]].pb(i);
	}

	vector<int> naozeros;
	for(int i = 0; i < n; i++){
		if(a[i])
			naozeros.pb(i);
	}

	while(q--){
		int _l, _r; cin >> _l >> _r;
		_l--; _r--;
		auto pos_prox_nao_zero = lower_bound(all(naozeros), _l);
		if(pos_prox_nao_zero == naozeros.end() || *pos_prox_nao_zero > _r){
			cout << 0 << endl;
			continue;
		}
		
		int gx = get_xor(_l, _r);
		if(gx){
			cout << -1 << endl;
			continue;
		}

		if((_r-_l+1)&1){
			cout << 1 << endl;
			continue;
		}
		
		if(!a[_l] || !a[_r]){
			cout << 1 << endl;
			continue;
		}

		// caso em que o tamanho é ímpar e eu tenho que operar nas duas pontas
		// basta ver se pxor[j] para algum _l < j < _r é igual ao pxor[_l-1] com
		// j-_l par

		vector<int> &candidatos = m[_l&1][_l ? pxor[_l-1] : 0];
//		for(auto x : candidatos) cout << x << ' '; cout << endl;
		auto prox = lower_bound(all(candidatos), _l+1);
		if(prox == candidatos.end() || *prox > _r){
			cout << -1 << endl;
			continue;
		}

		cout << 2 << endl;
	}		
}	

signed main(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
}

