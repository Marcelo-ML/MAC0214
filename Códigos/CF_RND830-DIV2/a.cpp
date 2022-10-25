#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	int a[n+5];
	for(int i = 1; i <= n; i++) cin >> a[i];
	int GCD = a[1];
	for(int i = 1; i <= n; i++)
		GCD = __gcd(GCD, a[i]);
	// GCD é trocado por __gcd(GCD, i1, i2, ..., ik)
	// então o custo é no máximo 3 (posso escolher os dois últimos)
	// o custo pode ser 0? pode ser 1? pode ser 2?
	if(GCD == 1){
		cout << 0 << endl;
		return;
	}
	int newGCD = __gcd(GCD, n);
	if(newGCD == 1){
		cout << 1 << endl;
		return;
	}
	newGCD = __gcd(GCD, n-1);
	if(newGCD == 1){
		cout << 2 << endl;
		return;
	}
	cout << 3 << endl;
}

int main(){
	int t; cin >> t;
	while(t--) solve();
}
