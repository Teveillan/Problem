#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define pb push_back
#define mp make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define DWN(i,h,l) for(int i=(h);i>=(l);--i)
#define MEM(arr, v) memset(arr, v, sizeof(arr))

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
const int N = 1e6 + 100;
LL dp[N];

int main()
{
	freopen("in", "r", stdin);
    LL n, l, k;
    while(cin >> n >> l >> k) {
        MEM(dp, 0);
        map<int, int>f;
        VI vec(n);
        vector<pii>q;
        REP(i, n) scanf("%d", &vec[i]), ++f[vec[i]];
        LL ret = 0;

        for(pii top: f) q.pb(top);
        for(int i = 1; i <= k && i * n <= l; ++i) {
            if(i == 1) FOR(j, 1, q.size()) dp[j] = 1;
            LL tmp = (l / n - i + 1) % MOD;
            FOR(j, 1, q.size()) {
                dp[j] = dp[j] * q[j - 1].second % MOD;
                (ret += dp[j] * tmp) %= MOD;
                dp[j] = (dp[j] + dp[j - 1]) % MOD;
            }
        }

        MEM(dp, 0);

        int m = l % n;
        f.clear();
        REP(i, m) ++f[vec[i]];
        if(m) {
            for(int i = 0; i < k && i * n + m <= l; ++i) {
                if(i == 0) {
                    for(pii top: f) {
                        pii tmp = pii(top.first, 0);
                        int id = lower_bound(q.begin(), q.end(), tmp) - q.begin() + 1;
                        dp[id] = top.second;
                    }
                    ret = (ret + m) % MOD;
                    DWN(j, q.size(), 1) (dp[j] += dp[j + 1]) %= MOD;
                } else {
                    DWN(j, q.size(), 1) {
                        dp[j] = dp[j] * q[j - 1].second % MOD;
                        ret = (ret + dp[j]) % MOD;
                        dp[j] = (dp[j] + dp[j + 1]) % MOD;
                    }
                }
            }
        }
        cout << ret << endl;
    }
    return 0;
}

