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

const int N = 1e5 + 100;
int dp[N][111], f[N][111];
int w[N];
VI head[N];

void dfs(int cur, int pre) {
    FOR(i, 0, 101) dp[cur][i] = 0, f[cur][i] = (i<=w[cur]?1:1e6);

    for(int to: head[cur]) {
        if(to == pre) continue;
        dfs(to, cur);

        DWN(i, 100, 1) {
            f[cur][i] = min(f[cur][i] + dp[to][i-1], dp[cur][i] + f[to][i+1]);
            f[cur][i] = min(f[cur][i], f[cur][i+1]);
        }
        f[cur][0] = min(f[cur][0] + f[to][0], dp[cur][0] + f[to][1]);
        f[cur][0] = min(f[cur][0], f[cur][1]);

        dp[cur][0] = min(f[cur][0], dp[cur][0] + f[to][0]);
        FOR(i, 1, 100) {
            dp[cur][i] = min(dp[cur][i-1], dp[cur][i] + dp[to][i-1]);
        }
    }
}

int main() {
	//freopen("in", "r", stdin);

    int n;
    while(cin >> n) {
        FOR(i, 1, n) head[i].clear();
        FOR(i, 1, n) scanf("%d", &w[i]);

        REP(i, n-1) {
             int x, y;
             scanf("%d%d", &x, &y);
             head[x].pb(y);
             head[y].pb(x);
        }
        if(n == 1) {
             puts("1");
             continue;
        } else {
            dfs(1, 0);
            cout << f[1][0] << endl;
        }
    }
    return 0;
}
