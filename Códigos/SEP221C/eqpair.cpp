#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t; cin >> t;
    while(t--){
        vector<int> nums = {};
        int n; cin >> n;
        while(n--){
            int a; cin >> a; nums.push_back(a);
        }
        sort(nums.begin(),nums.end());
        int result = 0;
        int equal = 0;
        int curr = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == curr){
                equal++;
                continue;
            }
            curr = nums[i];
            result += (equal*(equal-1))/2;
            // cout << "parcial " << i << " " << result << endl;
            equal = 1;
        }
        result += equal*(equal-1)/2;
        cout << result << endl;
    }
}

