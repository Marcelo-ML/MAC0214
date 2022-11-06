#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define ll long long
#define int long long
#define pii pair<int,int>
#define fs first
#define sc second
#define pb push_back
#define endl '\n'

const int MOD = 998244353;
const int MAXN = 200010;

bool eh_primo[MAXN];
vector<int> primos;
void crivo(){
	memset(eh_primo, 1, sizeof(eh_primo));
	for(int i = 2; i < MAXN; i++){
		if(!eh_primo[i])
			continue;
		primos.pb(i);
		for(int j = 2; i*j < MAXN; j++){
			eh_primo[i*j] = 0;
		}
	}
}

int phi(int n){
	int resp = n;
	for(auto p : primos){
		if(n%p) continue;
		resp /= p;
		resp *= (p-1);
		while(!(n%p))
			n/=p;
	}
	if(n>1){
		resp /= n;
		resp *= (n-1);
	}
	return resp;
}

vector<int> div_primos(int n){
	vector<int> resp;
	for(int i = 0; i < primos.size(); i++){
		int p = primos[i];
		if(n == 1 || p > n)
			break;
		if(n % p) continue;
		resp.pb(p);
		while(!(n%p)) n/= p;
	}
	if(n>1)
		resp.pb(n);
	return resp;
}


int f(int k, int l, int m){
	// dados l|k, quero o número de x in {1..m} tais que mdc(k,x) = l
	// k = l*k0, x = l*x0 -> mdc(k0,x0) = 1
	// ou seja, tem a ver com o phi de (k/l)

	// quero o número de y in {1..(m/l)} tais que mdc((k/l),y) = 1
/*	
	int PHI = phi(k/l);
	int novom = m/l;
	
	// cobrir os y nos intervalos s*(k/l)+1 ... (s+1)*(k/l)
	int resp = PHI*(novom/(k/l));
	resp %= MOD;
	// já contei todo mundo até (novom/(k/l))*(k/l)
	for(int i = (novom/(k/l))*(k/l)+1; i <= novom; i++){
		if(__gcd(i,k/l) == 1)
		resp++;
	}
*/
	
	// vamos tentar fazer um inclusão-exclusão
	
	int resp = 0;
	vector<int> v = div_primos(k/l);
	for(int bm = 0; bm < (1<<v.size()); bm++){
		int sinal = 1;
		int fator = m/l;
		int produto = 1;
		for(int i = 0; i < v.size(); i++){
			if((1<<i)&bm){
				produto *= v[i];
				sinal *= (-1);
			}
		}
		fator /= produto;
		fator *= sinal;
		resp += fator;
	}
	return resp %= MOD;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n-1; i++)
		if(a[i] % a[i+1]){
			cout << 0 << endl;
			return;
		}

	int result = 1;
	for(int i = 0; i < n-1; i++){
//		cout << i << " : " << f(a[i],a[i+1],m) << endl;
		result *= f(a[i],a[i+1],m);
		result %= MOD;
	}

	cout << result << endl;
}

signed main(){_
	crivo();
	int t; cin >> t;
	while(t--) solve();
}

