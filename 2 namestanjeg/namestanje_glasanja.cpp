#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binary(vector<int>& a, int& br) {
    int l = 0, r = a.size() - 1, m;
    while(l <= r) {
        m = l + (r - l) / 2;
        if(a[m] == br) return m;
        else if(a[m] < br) l = m + 1;
        else r = m - 1;
    }

    return -1;
}

void findAns(vector<int> a, int br) {
    int fnd = binary(a, br);
    int res = (fnd == -1);
    if(fnd == -1) a.push_back(br);
    sort(a.begin(), a.end());
    fnd = binary(a, br);
    int n = a.size();
    int med = n / 2 + 1 - n % 2;
    if(fnd == med) {
        cout << res << '\n';
        return;
    }
    res += (abs(2*fnd - n) - (fnd < med));
    cout << res << '\n';
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n); for(auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    for(int i=0;i<q;i++) {
        int pom; cin >> pom;
        findAns(a, pom);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}