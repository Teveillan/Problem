#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
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

char str[100001];
int dp[21][1<<20], v[100000];

int main()
{
	freopen("in", "r", stdin);
    int n, m;
    while(cin >> n >> m) {
        REP(i, n) {
            scanf("%s", str);
            REP(j, m) if(str[j] == '1') v[j] |= (1<<i);
        }

        memset(dp, 0, sizeof(dp));
        REP(j, m) ++dp[0][v[j]];

        REP(i, n) {
            DWN(j, 20, 1)
                REP(mask, 1<<n)
                    dp[j][mask] += dp[j-1][mask ^ (1<<i)];
        }
        int ret = 1e9;
        REP(mask, 1<<n) {
            int tmp = 0;
            FOR(i, 1, n) tmp += min(i, n-i) * dp[i][mask];
            ret = min(ret, tmp);
        }
        cout << ret << endl;
    }

    return 0;
}

