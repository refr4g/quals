#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
const int N = 200000;

vector<pi> merge(vector<pi>& a, vector<pi>& b) {
    vector<pi> r;
    int i, j; i = j = 0;
    while(i < a.size() && j < b.size()) {
        if(a[i].first < b[j].first) r.push_back(a[i++]);
        else if(a[i].first > b[j].first) r.push_back(b[j++]);
        else {
            if(a[i].second < b[j].second) r.push_back(a[i++]);
            else r.push_back(b[j++]);
        }
    }
    for(;i<a.size();i++) r.push_back(a[i]);
    for(;j<b.size();j++) r.push_back(b[j]);
    return r;
}

void build(vector<pi>* seg, vector<pi>& arr, int ind, int l, int r) {
    if(l == r) {
        seg[ind].assign(1, arr[l]);
        return;
    }
    int m = l + (r - l) / 2;
    build(seg, arr, 2*ind, l, m);
    build(seg, arr, 2*ind + 1, m+1, r);

    seg[ind] = merge(seg[2*ind], seg[2*ind+1]);
}

int query1(vector<pi>* seg, int ind, int tl, int tr, int l, int r, int x) {
    if(r < tl || l > tr) return 0;
    if(tl >= l && tr <= r) {
        return upper_bound(seg[ind].begin(), seg[ind].end(), make_pair(x,x)) - lower_bound(seg[ind].begin(), seg[ind].end(), make_pair(x,x));
    }
    int m = tl + (tr - tl) / 2;
    return (query1(seg, 2*ind, tl, m, l, r, x) + query1(seg, 2*ind+1, m+1, tr, l, r, x));
}

void solve1(vector<pi>& arr, int& n, int& m) {
    int l, r, x, cnt;
    for(int i=0;i<m;i++) {
        cin >> l >> r >> x;
        cnt = 0;
        for(int j=l-1;j<r;j++) cnt += ( x >= arr[j].first && x <= arr[j].second);
        cout << cnt << '\n';
    }
}

void solve2(vector<pi>& arr, int& n, int& m) {
    int l, r, x, cnt;
    vector<pi>* seg = new vector<pi>[4*n + 1];
    build(seg, arr, 1, 0, n - 1);
    for(int i=0;i<m;i++) {
        cin >> l >> r >> x;
        cout << query1(seg, 1, 0, n - 1, l-1, r-1, x) << '\n';
    }
    delete[] seg;
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
    bool pot4 = true, pot2 = true;
    for(auto& i : arr) {
        cin >> i.first >> i.second;
        pot4 = pot4 && i.second <= 20;
        pot2 = pot2 && i.first == i.second;
    }
    if(n <= 1000 && m <= 1000) solve1(arr, n, m);
    else if(pot4) solve4(arr, n, m);
    else if(pot2) solve2(arr, n, m);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}