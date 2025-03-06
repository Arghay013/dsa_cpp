#include <bits/stdc++.h>
using namespace std;

#define intt long long

int a[11][11];
int n, m;
int solve(int x, int y) {
    if(x == n - 1 && y == m - 1){
        return a[x][y];
    }

    int op1 = -1e8;
    int op2 = -1e8;

    if(x + 1 < n){
        op1 = solve(x + 1, y);
    }
    if(y + 1 < m){
        op2 = solve( x, y + 1);
    }

    return a[x][y] + max(op1, op2);
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    cout << solve(0, 0) << endl;
    return 0;
}