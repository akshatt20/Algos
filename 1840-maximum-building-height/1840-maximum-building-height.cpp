class Solution {
public:
using ll=long long;
    int maxBuilding(int n, vector<vector<int>>& r) {
        r.push_back({1, 0});
        sort(r.begin(), r.end());
        if (r.back()[0] != n)
            r.push_back({n, n-1});

        int m = r.size();

        for (int i = 1; i < m; i++) {
            int dist = r[i][0] - r[i - 1][0];
            r[i][1] =min(r[i][1],r[i - 1][1] + dist);
        }
        for (int i = m - 2; i >= 0; i--) {
            int dist = r[i + 1][0] - r[i][0];
            r[i][1] =min(r[i][1],r[i + 1][1] + dist);
        }

        ll ans = 0;

        for (int i = 1; i < m; i++) {

            ll x1 = r[i - 1][0];
            ll h1 = r[i - 1][1];

            ll x2 = r[i][0];
            ll h2 = r[i][1];

            ll d = x2 - x1;
            ans = max(ans, (h1 + h2 + d) / 2);
        }

        return (int)ans;
    }
};