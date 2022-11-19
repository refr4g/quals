#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

void solve1(vector<pi>& arr, int& n, int& m) {
    int l, r, x, cnt;
    for(int i=0;i<m;i++) {
        cin >> l >> r >> x;
        cnt = 0;
        for(int j=l-1;j<r;j++) cnt += ( x >= arr[j].first && x <= arr[j].second);
        cout << cnt << '\n';
    }
}

void solve4(vector<pi>& arr, int& n, int& m) {
    vector<vector<int>> pr(n, vector<int>(21, 0));
    for(int i=0;i<n;i++) {
        if(i > 0) pr[i] = pr[i-1];
        for(int j=arr[i].first;j<=arr[i].second;j++) pr[i][j] += 1;
    }
    int l, r, x, cnt;
    for(int i=0;i<m;i++) {
        cin >> l >> r >> x;
        l--; r--;
        if(x > 20) {
            cout << 0 << '\n';
            continue;
        }
        if(l == 0) cnt = pr[r][x];
        else cnt = pr[r][x] - pr[l-1][x];
        cout << cnt << '\n';
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vector<pi> arr(n);
    bool pot4 = true;
    for(auto& i : arr) {
        cin >> i.first >> i.second;
        pot4 = pot4 && i.second <= 20;
    }
    if(n <= 1000 && m <= 1000) solve1(arr, n, m);
    else if(pot4) solve4(arr, n, m);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}