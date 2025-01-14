#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,q;
    cin>>n>>q;
    vector<long long> v(n),ps(n+1,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=1; i<=n; i++){
        ps[i] = ps[i-1]+v[i-1];
    }
    while(q--){
        long long l,r;
        cin>>l>>r;
        cout<<ps[r]-ps[l-1]<<endl;
    }
    
    return 0;
}