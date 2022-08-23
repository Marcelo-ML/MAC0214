#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TVector{
	ll x;
	ll y;
	inline ll operator ^ (TVector v) const{
		return x*v.y-y*v.x;
	}
	inline TVector operator - (TVector v) const{
		return {x - v.x, y - v.y};
	}
};

struct TLine{ // p + lambda * v
	TVector v;
	TVector p;
};

bool iguais(TLine l1, TLine l2){
	return ((l1.v ^ l2.v) == 0) && (((l1.p - l2.p) ^ l1.v) == 0);
}

int main(){
	ll W, N; cin >> W >> N;
	TLine retas[N+10];
	for(ll i = 0; i < N; i ++){
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		retas[i].v = {x1-x2, y1-y2};
		retas[i].p = {x1, y1};
	}

	ll diferentes = 0;
	bool todas_paralelas = 1;
	bool vis[N + 10];
	memset(vis, 0, sizeof(vis));

	for(int i = 0; i < N; i ++){
		if(vis[i]) continue;
		else{
			vis[i] = 1;
			for(int j = i + 1; j < N; j ++){
				if(iguais(retas[i], retas[j])){
					// cout << i << " igual a " << j << endl;
					vis[j] = 1;
				}
			}
			diferentes ++;
			continue;
		}
	}

	for(int i = 0; i < N; i ++){
		if(retas[0].v ^ retas[i].v)
			todas_paralelas = 0;
	}
	// if(todas_paralelas) cout << "asdad" << endl;
	// cout << diferentes << endl;
	ll add = 0;
	ll regioes = 0;
	if(todas_paralelas){
		regioes = diferentes + 1;
		if(regioes < W){
			add ++;
			regioes *= 2;
		}
		while(regioes < W){
			regioes += 2;
			add ++;
		}
	}
	else{
		regioes = 2*diferentes;
		while(regioes < W){
			regioes += 2;
			add ++;
		}
	}

	cout << add << endl;
}




