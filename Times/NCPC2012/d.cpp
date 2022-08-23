#include <bits/stdc++.h>
using namespace std;

string s;
int x;

void solve(){
	cin >> x >> s;

	int M = 0, W = 0;

	bool troca = false;
	for (int r = 0; r < s.size(); r++) {
		if (s[r] == 'M') {
			M++;
			if(abs(M - W) <= x) {
				troca = false;
			}
			else {
				if(troca) {
					cout << r << "\n";
					return;
				}
				else {
					M--;
					if(r + 1 < s.size()) swap(s[r], s[r + 1]);
					troca = true;
					r--;
				}
			}
		}
		else {
			W++;
			if(abs(M - W) <= x) {
				troca = false;
			}
			else {
				if(troca) {
					cout << r << "\n";
					return;
				}
				else {
					W--;
					if(r + 1 < s.size()) swap(s[r], s[r + 1]);
					troca = true;
					r--;
				}
			}
		}
	}
	cout << s.size() << "\n";
}

signed main () {
	solve();
}
