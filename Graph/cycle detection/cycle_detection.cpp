#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
bool vis[105];
bool cycle;
queue<int> q;
int parent[105];
void bfs(int s){
    vis[s] = true;
    q.push(s);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto child : adj_list[node]){
            if(vis[child] && parent[node]!=child){
                cycle = true;
            }
            if(!vis[child]){
                q.push(child);
                vis[child] = true;
                parent[child] = node;
            }
        }
    }
}


int main(){
    int n,e;
    cin >> n >> e;
    while(e--){
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    cycle = false;
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    for(int i=0; i<n; i++){
        if(!vis[i])bfs(i);
    }

    if(cycle)cout<<"Cycle detected!"<<endl;
    else cout<<"No cycles detected!"<<endl;
}