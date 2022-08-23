#include <bits/stdc++.h>

using namespace std;


const int MAXN = 1e5 + 10;
int nd[4 * MAXN];
int a1[MAXN], a2[MAXN];
int N;

int query(int i, int l, int r, int ql, int qr){
	if(l > qr || ql > r) return 0;
	if(ql <=l && r <= qr) return nd[i];
	int m = (l + r) / 2;
	return query(2 * i, l, m, ql, qr) + query(2 * i + 1, m + 1, r, ql, qr);
}

int query (int ql, int qr) {
	return query(1, 1, N, ql, qr);
}

void update(int i, int l, int r, int pos, int val) {
	if(l == r) {
		nd[i]++;
		return;
	}
	int meio = (l + r) / 2;
	if(pos <= meio) update(2 * i, l, meio, pos, val);
	else update(2 * i + 1, meio + 1, r, pos, val);
	nd[i] = nd[2 * i] + nd[2 * i + 1];
}

void update (int pos) {
	update(1, 1, N, pos, 1);
}

int main(){
	cin >> N;
	for(int i = 1; i <= N; i ++)
		cin >> a1[i];
	for(int i = 1; i <= N; i ++)
		cin >> a2[i];

	long long inv1 = 0, inv2 = 0;

	for(int i = 1; i <= N; i ++){
		update(a1[i]);
		inv1 += query(a1[i] + 1, N);
	}

	memset(nd, 0, sizeof(nd));

	for(int i = 1; i <= N; i ++){
		update(a2[i]);
		inv2 += query(a2[i] + 1, N);
	}

	//cout << inv1 << " " << inv2 << endl;
	if(inv1 % 2 == inv2 % 2)
		cout << "Possible" << endl;
	else
		cout << "Impossible" << endl;
}
