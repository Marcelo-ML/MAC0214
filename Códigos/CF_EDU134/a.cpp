#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define fs first
#define sc second

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        char s[4];
        for(int i = 0; i < 4; i ++) cin >> s[i];
        int diff = 1;
        if(s[1] != s[0])
            diff++;
        if(s[2] != s[0] && s[2] != s[1])
            diff++;
        if(s[3] != s[0] && s[3] != s[1] && s[3] != s[2])
            diff++;
        cout << diff-1 << endl;
    }
}

