#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define ll long long
#define int long long
#define pii pair<int,int>
#define fs first
#define sc second
#define pb push_back
// #define endl '\n'

const int MOD = 1e9+7;
const int MAXN = 200010;

void solve(){
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++){
		char ch; cin >> ch;
		a[i] = ch-'0';
	}
	for(int i = 0; i < n; i++){
		char ch; cin >> ch;
		b[i] = ch-'0';
	}
	bool iguais = 1, opostas = 1;
	for(int i = 0; i < n; i++){
		if(a[i] == b[i])
			opostas = 0;
		else
			iguais = 0;
	}
	if(!iguais && !opostas){
		cout << "NO" << endl;
		return;
	}
	vector<pii> blocos1;
	int i = 0;
	while(i < n){
		if(!a[i]){
			i++;
			continue;
		}
		pii pp = {i+1,i+1};
		while(i < n-1 && a[i+1]){
			pp.sc++;
			i++;
		}
		i++;
		blocos1.pb(pp);
	}
//	for(auto x : blocos1)
//		cout << x.fs << ' ' << x.sc << endl;
	if(iguais){ // zerar a primeira com um número par de operações
		if(!(blocos1.size()&1)){
			cout << "YES" << endl << blocos1.size() << endl;
			for(auto x : blocos1){
				cout << x.fs << ' ' << x.sc << endl;
			}
			return;
		}

		cout << "YES" << endl << blocos1.size()+1 << endl;
		for(int i = 0; i < blocos1.size()-1; i++){
			pii x = blocos1[i];
			cout << x.fs << ' ' << x.sc << endl;
		}
		pii ultimo = blocos1[blocos1.size()-1];
		if(ultimo.fs == ultimo.second){
			if(ultimo.fs > 1){
				cout << ultimo.fs-1 << ' ' << ultimo.fs-1 << endl;
				cout << ultimo.fs-1 << ' ' << ultimo.sc << endl;
			}
			else{
				cout << ultimo.sc+1 << ' ' << ultimo.sc+1 << endl;
				cout << ultimo.fs << ' ' << ultimo.sc+1 << endl;
			}
		}
		else{
			cout << ultimo.fs << ' ' << ultimo.fs << endl;
			cout << ultimo.fs+1 << ' ' << ultimo.sc << endl;
		}
		return;
	}
	if(opostas){ // zerar a primeira com um número ímpar de operações
		if((blocos1.size()&1)){
			cout << "YES" << endl << blocos1.size() << endl;
			for(auto x : blocos1){
				cout << x.fs << ' ' << x.sc << endl;
			}
			return;
		}
		if(blocos1.size()==0){
			cout << "YES" << endl;
			cout << "3" << endl;
			cout << "1 1" << endl;
			cout << "2 2" << endl;
			cout << "1 2" << endl;
			return;
		}

		cout << "YES" << endl << blocos1.size()+1 << endl;
		for(int i = 0; i < blocos1.size()-1; i++){
			pii x = blocos1[i];
			cout << x.fs << ' ' << x.sc << endl;
		}
		pii ultimo = blocos1[blocos1.size()-1];
		if(ultimo.fs == ultimo.second){
			if(ultimo.fs > 1){
				cout << ultimo.fs-1 << ' ' << ultimo.fs-1 << endl;
				cout << ultimo.fs-1 << ' ' << ultimo.sc << endl;
			}
			else{
				cout << ultimo.sc+1 << ' ' << ultimo.sc+1 << endl;
				cout << ultimo.fs << ' ' << ultimo.sc+1 << endl;
			}
		}
		else{
			cout << ultimo.fs << ' ' << ultimo.fs << endl;
			cout << ultimo.fs+1 << ' ' << ultimo.sc << endl;
		}
		return;
	}
}

signed main(){_
	int t; cin >> t;
	while(t--) solve();
}

