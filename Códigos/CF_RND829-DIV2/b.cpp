#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	int print[n];
	int atu = 1;
	for(int cont = 0; cont < n; cont++){
		print[atu] = cont+1;
		atu += 2;
		atu %= n;
		if(atu == 1)
			atu = 0;
	}
	for(int i = 0; i < n; i++){
		cout << print[i] << " ";
	}
	cout << endl;
}

int main(){
	int t; cin >> t;
	while(t--)
		solve();
}
