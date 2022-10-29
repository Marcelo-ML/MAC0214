#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;
const int MAXN = 200010;

int fastexpo(int b, int expo){
	if(expo == 0)
		return 1;
	int resp = fastexpo(b,expo/2);
	resp *= resp;
	resp %= MOD;
	if(expo&1)
		resp*=b;
	return resp%MOD;
}

int inverso(int x){
	return fastexpo(x, MOD-2);
}

void solve(){
	int n; cin >> n;
	
	int a[n+10];
	int num_zeros = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(!a[i])
			num_zeros++;
	}
	int esperado[MAXN];
	esperado[num_zeros] = 0;
	int a_somar = n*(n-1)/2;
	for(int k = num_zeros-1; k >= 0; k--){
		a_somar = (n*(n-1))/2;
		a_somar %= MOD;
		a_somar *= inverso(num_zeros-k);
		a_somar %= MOD;
		a_somar *= inverso(num_zeros-k);
		a_somar %= MOD;
		esperado[k] = esperado[k+1] + a_somar;
		esperado[k] %= MOD;
	}
	int zeros_no_comeco = 0;
	for(int i = 0; i < num_zeros; i++){
		if(!a[i])
			zeros_no_comeco++;
	}
	cout << esperado[zeros_no_comeco] << endl;
}

signed main(){
	int t; cin >> t;
	while(t--) solve();
}
