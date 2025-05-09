#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int src,dest,weight;
    Edge(int src,int dest,int weight){
        this->src=src;
        this->dest=dest;
        this->weight=weight;
    }
};
int dis[1005];

int main() {
    int n,e;
    cin>>n>>e;
    vector<Edge> edge_list;
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        edge_list.push_back(Edge(a,b,c));
    }

    for(int i=0;i<n;i++){
        dis[i] = INT_MAX;
    }
    dis[0] = 0;

    for(int i=0;i<n-1;i++){
        for(auto u:edge_list){
            int a,b,c;
            a = u.src;
            b = u.dest;
            c = u.weight;
            if(dis[a]!=INT_MAX && dis[a]+c<dis[b]){
                dis[b] = dis[a]+c;
            }
        }
    }

    bool cycle = false;
    for(auto u:edge_list){
        int a,b,c;
        a = u.src;
        b = u.dest;
        c = u.weight;
        if(dis[a]!=INT_MAX && dis[a]+c<dis[b]){
            cycle = true;
            break;
        }
    }
    if(cycle){
        cout<<"Negative cycle detected\n";
    }
    else{
        cout<<"No negative cycle detected\n";
        for(int i=0;i<n;i++){
            cout<<dis[i]<<" ";
        }
    }
    

    return 0;
}