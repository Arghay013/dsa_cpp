#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> v;

    set<int> st;

    for(int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;

        v.push_back({l, r});

        st.insert(l);
        st.insert(r);
    }

    map<int, int> mp;
    int cnt = 1;

    for(int x: st){
        mp[x] = cnt;
        cnt++;
    }

    for(int i = 0; i < v.size(); i++){
        v[i].first = mp[v[i].first];
        v[i].second = mp[v[i].second];

        // cout << v[i].first << " " << v[i].second << endl;
    }

    int arr[2*n+5] = {0};

    for(auto it: v){
        arr[it.first]++;
        arr[it.second]--;
    }

    int mx = 0;
    for(int i = 1; i <= 2*n; i++){
        arr[i] += arr[i-1];
        mx = max(mx, arr[i]);
    }

    cout << mx << endl;
    
    return 0;
}