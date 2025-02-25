#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin >> n >> e;
    int adj_mat[n+2][n+2];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) adj_mat[i][j] = 0;
            else adj_mat[i][j] = INT_MAX;
        }
    }
    
    while(e--){
        int a,b,c;
        cin >> a >> b >> c;
        adj_mat[a][b] = min(c, adj_mat[a][b]);
    }
    
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(adj_mat[i][k] != INT_MAX 
                    && adj_mat[k][j] != INT_MAX 
                    && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
    bool cycle = false;
    for(int i=1;i<=n;i++){
        if(adj_mat[i][i]<0){
            cycle = true;
            break;
        }
    }
    if(cycle){
        cout<<"Negative cycle detected\n";
    }
    else{
        cout<<"No negative cycle detected\n";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<adj_mat[i][j]<<" ";
            }cout<<endl;
        }
    }
    
    
}