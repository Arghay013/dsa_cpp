// https://codeforces.com/problemset/problem/25/D

// Problem: Given a tree, we have to remove some edges and add some edges to make it a tree again.
// Solution: We can use DSU to solve this problem. We will keep track of the leader of each node and the size of the group of each leader.
#include<bits/stdc++.h>
using namespace std;
int par[1005];
int group_size[1005];
int cmp, mx;
int find(int node)   // O(logN)
{
    if(par[node] == -1) 
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if(group_size[leader1] >= group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
        mx = max(mx,group_size[leader1]);
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
        mx = max(mx,group_size[leader2]);
    }
    
}

int main()
{
    memset(par,-1,sizeof(par));
    // mx = 1;
    int n;
    cin >> n;
    // cmp = n;
    for(int i=1;i<=n;i++)
        group_size[i] = 1;

    vector<pair<int,int> > rmv, create;
    for(int i=1; i<n; i++)
    {
        int a,b;
        cin >> a >> b;
        int l1 = find(a);
        int l2 = find(b);
        if(l1 != l2)
        {
            dsu_union(a,b);
        }
        else
        {
            rmv.push_back({a,b});
        }
    }

    for(int i=2; i<=n; i++)
    {
        int l1 = find(1);
        int l2 = find(i);
        if(l1 != l2)
        {
            dsu_union(1,i);
            create.push_back({1,i});
        }
        
    }
    cout << rmv.size() << endl;
    for(int i=0; i<rmv.size(); i++)
    {
        cout << rmv[i].first << " " << rmv[i].second << " " << create[i].first << " " << create[i].second << endl;
    }
    
    return 0;
}