#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pi>> adj(n);
    int a, b, t;
    for(int i=0;i<m;i++) {
        cin >> a >> b >> t;
        adj[a-1].push_back({ b-1, t });
        adj[b-1].push_back({ a-1, t });
    }
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    vector<bool> vis(n, false);
    int src, dest;
    cin >> src >> dest;
    pq.push(make_pair(0, src - 1));
    while(!pq.empty()) {
        pi top = pq.top();
        pq.pop();

        if(vis[top.second]) continue;
        vis[top.second] = true;

        if(top.second == dest - 1) {
            cout << top.first << '\n';
            return;
        }

        for(auto& i : adj[top.second]) {
            if(vis[i.first]) continue;

            pq.push({top.first + (top.first % 2 != i.second), i.first });
        }
    }

    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}