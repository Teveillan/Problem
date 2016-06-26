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

const int N = 505;
int dp[N][N];
int v[N];
int solve(int n) {
    memset(dp, 0x3f, sizeof(dp));
    if(n == 1) return 1;
    if(n == 2) return 1 + (v[0] != v[1]);
    REP(i, n) dp[i][i] = 1;
    REP(i, n - 1) dp[i][i+1] = 1 + (v[i] != v[i+1]);

    FOR(len, 2, n) REP(i, n - len) {
        dp[i][i+len] = dp[i+1][i+len-1] + (v[i] == v[i+len] ? 0 : 2);
        FOR(j, i, i + len - 1) dp[i][i+len] = min(dp[i][i+len], dp[i][j] + dp[j+1][i+len]);
    }
    return dp[0][n-1];
}

int main()
{
	freopen("in", "r", stdin);
    int n;
    while(cin >> n) {
        REP(i, n) scanf("%d", &v[i]);
        cout << solve(n) << endl;
    }

    return 0;
}

