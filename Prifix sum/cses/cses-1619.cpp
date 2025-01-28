#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    int arr[n+2];
    arr[0] = 0;

    map<int, int> count;
    count[0] = 1;

    int ans = 0;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];

        arr[i] += arr[i-1];

        ans += count[arr[i] - x];

        count[arr[i]]++;
    }

    cout << ans << endl;
    
    return 0;
}

// https://cses.fi/problemset/task/1619