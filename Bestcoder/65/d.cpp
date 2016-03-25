#pragma comment(linker, "/STACK:1024000000,1024000000")
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

const int N = 5e5 + 100;
int dp[N][11];
int f[N][11];
VI head[N];

LL n, k, A, B;
void dfs1(int cur) {
    dp[cur][0] = 1;
    REP(i, head[cur].size()) {
        int to = head[cur][i];
        dfs1(to);
        REP(j, k) dp[cur][j+1] += dp[to][j];
    }
}

void dfs2(int cur) {
    REP(i, head[cur].size()) {
        int to = head[cur][i];
        REP(j, k) {
            if(j == 0) f[to][j + 1] = 1;
            else {
                f[to][j+1] = f[cur][j] + dp[cur][j] - dp[to][j-1];
            }
        }
        dfs2(to);
    }
}

int main()
{
	freopen("in", "r", stdin);
    int casnum;
    cin >> casnum;
    while(casnum--) {
        memset(dp, 0, sizeof(dp));
        memset(f, 0, sizeof(f));
        FOR(i, 1, n) head[i].clear();
        cin >> n >> k >> A >> B;

        FOR(i, 2, n) {
            LL fa = (A * i + B) % (i - 1) + 1;
            head[fa].pb(i);
        }

        dfs1(1);
        dfs2(1);
        int ans = 0;
        FOR(i, 1, n) {
            int tmp = 0;
            FOR(j, 0, k) tmp += dp[i][j] + f[i][j];
            ans ^= tmp;
        }
        cout << ans << endl;
    }
    return 0;
}

