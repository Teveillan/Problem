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

const int N = 110;
const int INF = 1e9;
char g[N][N];
int dp[N][N][2];


int main()
{
	//freopen("in", "r", stdin);
    int n, m;
    while(cin >> n >> m) {
        REP(i, n)
            REP(j, m)
                REP(k, 2)
                    dp[i][j][k] = INF;
        REP(i, n) scanf("%s", g[i]);
        REP(i, n) g[i][m] = 'b';
        REP(j, m) g[n][j] = 'b';

        REP(i, n) {
            REP(j, m) {
                if(i == 0 && j == 0) {
                    dp[i][j][1] = (g[i][j+1] != '.');
                    dp[i][j][0] = (g[i][j+1] != 'b') + (g[i+1][j] != '.');
                    continue;
                }
                if(i != 0) {
                    dp[i][j][1] = dp[i-1][j][0] + (g[i+1][j] != 'b') + (g[i][j+1] != '.');
                    dp[i][j][0] = dp[i-1][j][0] + (g[i+1][j] != '.');
                }
                if(j != 0) {
                    dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1] + (g[i][j+1] != '.'));
                    dp[i][j][0] = min(dp[i][j][0], dp[i][j-1][1] + (g[i][j+1] != 'b') + (g[i+1][j] != '.'));
                }
            }
        }

        cout << min(dp[n-1][m-1][0], dp[n-1][m-1][1]) - 1 << endl;
    }

    return 0;
}

