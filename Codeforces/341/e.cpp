#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;

#define pb push_back
#define mp make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define DWN(i,h,l) for(int i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
LL dp[2][110];
LL g[2][110];
int main()
{
	freopen("in", "r", stdin);
    LL n, b, z, x;
    while(cin >> n >> b >> z >> x) {
        int f[10] = {0};
        int a;
        REP(i, n) {
            scanf("%d", &a);
            ++f[a];
        }
        FOR(i, 1, 9) f[i] %= MOD;

        int cur = 1, pre = 0;
        int cur1 = 1, pre1 = 0;
        memset(dp, 0, sizeof(dp));
        memset(g, 0, sizeof(g));

        REP(i, 10) dp[cur][i] = f[i];
        g[cur1][0] = 1;
        LL tmp = 1;
        bool flag = 0;
        while(b) {
            if(b & 1) {
                cur1 ^= 1, pre1 ^= 1;
                memset(g[cur1], 0, sizeof(g[cur1]));
                REP(i, x)
                    REP(j, x) {
                        int to = (i + j * tmp) % x;
                        g[cur1][to] = (g[cur1][to] + g[pre1][i] * dp[cur][j]) % MOD;
                    }
            }

            if(!flag) tmp = 10 % x, flag = 1;
            else {
                tmp = (tmp * tmp) % x;
            }
            cur ^= 1, pre ^= 1;
            memset(dp[cur], 0, sizeof(dp[cur]));
            REP(i, x)
                REP(j, x) {
                     int to = (i + j * tmp) % x;
                     dp[cur][to] = (dp[cur][to] + dp[pre][i] * dp[pre][j]) % MOD;
                }

            b >>= 1;
        }
        REP(i, x)
        cout << g[cur1][i] << endl;
        puts("###########");
        cout << "Answer: "  << g[cur1][z] << endl;

   }
    return 0;
}

