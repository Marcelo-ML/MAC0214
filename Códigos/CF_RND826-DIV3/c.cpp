#include <bits/stdc++.h>
using namespace std;

int n;

int can_split(int a[], int first_block_end){
    int block_value = 0;
    for(int i = 0; i <= first_block_end; i++){
        block_value += a[i];
    }
    int longest_segment = first_block_end+1;
    int curr_block_value = 0;
    int last_block_end = first_block_end;
    for(int j = first_block_end + 1; j < n; j++){
        curr_block_value += a[j];

        if(curr_block_value == block_value){
            longest_segment = max(longest_segment, j - last_block_end);
            curr_block_value = 0;
            last_block_end = j;
        }

        if(curr_block_value > block_value)
            return -1;
    }
    if(curr_block_value != 0)
        return -1;
    return longest_segment;
}


int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        int a[n+10];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int resp = 10000;
        int attat;
        for(int i = 0; i < n; i++){
            if(can_split(a, i) != -1){
                if(can_split(a, i) < resp)
                    attat = i;
                resp = min(resp, can_split(a, i));
            }
        }
        cout << resp << endl;
    }
}




