#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
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

const int N = 150 * 150 ;

int dp[2][151][N];

int main()
{
	freopen("in", "r", stdin);

    int n, m, s;
    while(cin >> n >> m >> s) {
        VI vec;
        REP(i, n) {
            int x;
            scanf("%d", &x);
            vec.pb(x);
        }
        s = min(s, n * (n + 1) / 2);

        REP(i, 2)
            FOR(j, 0, n)
                FOR(k, 0, s)
                    dp[i][j][k] = 1e9;
        if(n == 1) {
            cout << vec[0] << endl;
            continue;
        }
        int cur = 1, pre = 0;
        DWN(i, n-1, 1) {
            cur ^= 1, pre ^= 1;
            FOR(j, 0, n)
                FOR(k, 0, s)
                    dp[pre][j][k] = 1e9;
             dp[cur][1][0] = vec[i];
             dp[pre][1][0] = vec[i-1];

            FOR(j, 1, m)
                FOR(k, 0, s) {
                    dp[cur][j][k+1] = min(dp[cur][j][k+1], dp[cur][j][k]);
                    dp[pre][j+1][k] = min(dp[pre][j+1][k], vec[i-1] + dp[cur][j][k]);
                    if(k+j <= s)
                        dp[pre][j][k+j] = min(dp[pre][j][k+j], dp[cur][j][k]);
                }
        }

        int ans = 1e9;
        FOR(i, 0, s) ans = min(ans, dp[pre][m][i]);
        cout << ans << endl;
    }
    return 0;
}

