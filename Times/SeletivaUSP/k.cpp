#include <bits/stdc++.h>
using namespace std;
#define MAXN 212345
#define endl '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

int X[MAXN], Y[MAXN], T[MAXN], V[MAXN];
int N, B;
vector<int> vec;

signed main(){_
	cin >> N >> B;
	vec.push_back(0);
	for(int j = 0; j < N; j++)
		cin >> X[j] >> Y[j] >> T[j] >> V[j];
	for(int i = 0; i < N; i++){
		if(Y[i] < X[i])
			continue;
		int delta = Y[i] - X[i];
		if(delta <= T[i])
			continue;
		// delta > T[i]
		if(T[i] * B < Y[i])
		//---------
		//até onde o trem chega no tempo
			continue; 
		vec.push_back(V[i]);
	}
	sort(vec.begin(),vec.end(),greater<>());
	int ind_lucro_max = 0, lucro_max = 0;
	for(int i = 0; i < vec.size(); i++){
		int lucro_atual = vec[i] * (i + 1);
		if(lucro_atual >= lucro_max){
			ind_lucro_max = i;
			lucro_max = lucro_atual;
		}
	}
	cout << vec[ind_lucro_max] << endl;
	return 0;
}

