#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;

void solve(){
	int n; cin >> n;
	int a[n+10];
	int num_nonzero = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i])
			num_nonzero++;
	}
	
	if(num_nonzero&1){
		cout << -1 << endl;
		return;
	}

	queue<pair<int,int>> print;

	for(int i = 0; i < n; i++){
		int cur_nz = i;
		if(a[i] == 0){
			print.push({i,i});
			continue;
		}
		i++;
		while(!a[i])
			i++;
		int next_nz = i;
		if(a[next_nz] == a[cur_nz]){
			if(next_nz == cur_nz+1)
				print.push({cur_nz,next_nz});
			else{
				print.push({cur_nz,next_nz-2});
				print.push({next_nz-1,next_nz});
			}
		}
		else{
			print.push({cur_nz,next_nz-1});
			print.push({next_nz,next_nz});
		}
	}

	cout << print.size() << endl;
	while(!print.empty()){
		pair<int,int> aux = print.front();
		print.pop();
		cout << aux.first+1 << " " << aux.second+1 << endl;
	}
}

int main(){
	int t; cin >> t;
	while(t--) solve();
}
