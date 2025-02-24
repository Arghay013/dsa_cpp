#include<bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
int level[1005][1005];
pair<int, int> parent[1005][1005];
vector<pair<int,int>> d = {{0,1},{0,-1},{-1,0},{1,0}};
int n, m;

bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m) 
        return false;
    return true; 
}

void bfs(int si, int sj){
    queue<pair<int,int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;
    parent[si][sj] = {-1, -1}; 

    while(!q.empty()){
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for(int i = 0; i < 4; i++){
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if(valid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'D')){
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
                parent[ci][cj] = {par_i, par_j}; 
                
                if(grid[ci][cj] == 'D') return;
            }
        }
    }
}

void mark_path(int di, int dj) {
    pair<int, int> p = {-1, -1};
    while(parent[di][dj] != p){
        grid[di][dj] = 'X';
        int x = parent[di][dj].first; 
        int y = parent[di][dj].second;
        di = x;
        dj = y;
    }
}

int main(){
    cin>>n>>m;
    int si, sj, di, dj;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
            if(grid[i][j] == 'R') 
            { 
                si = i; 
                sj = j; 
            }
            if(grid[i][j] == 'D')
            { 
                di = i; 
                dj = j; 
            }
        }
    }

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    bfs(si, sj);

    if(level[di][dj] != -1){
        mark_path(di, dj);
        grid[si][sj] = 'R';
        grid[di][dj] = 'D';
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
