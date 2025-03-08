#include <bits/stdc++.h>
using namespace std;
int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int isOK(int mid, int x) {
    if(arr[mid] < x) return 0;
    return 1;
}
int main() {
    int n = arr.size();
    int l = 0, r = n - 1;
    int x;
    cin>>x;
    while(l < r) {
        int mid = (l + r) / 2;
        // last '0' ber korar jonno
        // if(arr[mid] == 0) l = mid+1;
        if(isOK(mid, x) == 0) l = mid+1;
        else r = mid;
    }
    // 0, 0, 0, 0, 0, 1, 1, 1, 1
    int last_zero = l - 1;
    int first_one = l;
    cout << last_zero << " " << first_one << endl;
    return 0;
}