#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin >> n >> e;
    int adj[n+2][n+2];
    memset(adj,0,sizeof(adj));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)adj[i][j]=1;
        }
        cout<<endl;
    }
    for(int i=1;i<=e;i++){
        int a,b;
        cin >> a >> b;
        adj[a][b]=1;
        adj[b][a]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}