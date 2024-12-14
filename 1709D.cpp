/**
 *    author:  Phung Duc Minh
 *    created: 12.12.2024 18:38:31
**/

#include <bits/stdc++.h>

#define int long long

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

const int MAXN = 2e5 + 5;

int n, m, q, IT[4 * MAXN]; 
vector<int> vec;

void build(int idx, int left, int right) {
    if(left == right) {
        IT[idx] = vec[left];
        return;
    }
    int mid = (left + right) / 2;
    build(idx * 2 + 1, left, mid);
    build(idx * 2 + 2, mid + 1, right);
    IT[idx] = max(IT[idx * 2 + 1], IT[idx * 2 + 2]);
}

int query(int idx, int left, int right, int u, int v) {
    if(right < u || v < left) return -1e9 - 69;
    if(u <= left && right <= v) return IT[idx];
    int mid = (left + right) / 2;
    int q1 = query(idx * 2 + 1, left, mid, u, v);
    int q2 = query(idx * 2 + 2, mid + 1, right, u, v);
    return max(q1, q2);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        cin >> n >> m; 
        vec.resize(m);
        for(auto &x : vec) cin >> x;
        build(0, 0, m - 1);
        cin >> q;
        while(q--) {
            int x1, y1, x2, y2, k;
            cin >> x1 >> y1 >> x2 >> y2 >> k;
            x1--; y1--; x2--; y2--;
            int p = ((n - x1 - 1) / k) * k + x1;
            int l = min(y1, y2) + 1;
            int r = max(y1, y2) - 1;
            int qmax;
            if(l <= r)qmax = query(0, 0, m - 1, min(y1, y2) + 1, max(y1, y2) - 1);
            else qmax = -1e9 - 69;
            // cout << qmax << " " << p << "\n";
            if(abs(x1 - x2) % k == 0 && abs(y1 - y2) % k == 0 && 
                qmax <= p) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }
    return 0;
}
