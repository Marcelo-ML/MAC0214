#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree <pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int n;
ordered_set S;

void solve () {
	string x;
	int i = 0;
	while(cin >> x){
		i++;
		if(x[0] == '#') {
			// cout << (S.size() - 1) / 2 << "\n";
			cout << (*S.find_by_order((S.size()) / 2)).first << "\n";
			S.erase(*S.find_by_order((S.size()) / 2));
		}
		else {
			int y = stoi(x);
			// cout << "y :" << y << "\n";
			S.insert({y, i});
		}
	}
}

signed main (){
	 solve();
}
