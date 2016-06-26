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

double dp[20][20];
double eps = 1e-6;

int main()
{
	//freopen("in", "r", stdin);
    int n, t;
    while(cin >> n >> t) {
        memset(dp, 0, sizeof(dp));
        dp[1][1] = t;
        FOR(i, 1, n) {
            FOR(j, 1, i) {
                if(dp[i][j] > 1 - eps) {
                    double tmp = (dp[i][j] - 1.0) / 2.0;
                    dp[i+1][j] += tmp;
                    dp[i+1][j+1] += tmp;
                    dp[i][j] = 1.0;
                }
            }
        }
        int ans = 0;
        FOR(i, 1, n) FOR(j, 1, i) if(dp[i][j] > 1.0 - eps) ++ans;
        cout << ans << endl;
    }

    return 0;
}

