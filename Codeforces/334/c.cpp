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


const int N = 1e5 + 100;
int dp[N][2][2];
int r[N][2];
int main()
{
	freopen("in", "r", stdin);

    int n;
    string str;
    while(cin >> n >> str) {
        memset(dp, 0, sizeof(dp));
        memset(r, 0, sizeof(r));
        DWN(i, n, 1) {
            int flag1 = str[i-1] - '0', flag0 = flag1 ^ 1;
            r[i][flag1] = max(r[i+1][flag0] + 1, r[i+1][flag1]);
            r[i][flag0] = r[i+1][flag0];
        }

        int ret = 0;
        FOR(i, 1, n) {
             int flag = str[i-1] - '0';
             REP(j, 2)
                 REP(k, 2) {
                     dp[i][j][k] = dp[i-1][j][k];
                     if(k == flag) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k^1] + 1);
                 }
             REP(k, 2) {
                 if(k == flag) dp[i][1][k] = max(dp[i][1][k], dp[i-1][0][k] + 1);
                 dp[i][1][k] = max(dp[i][1][k], dp[i][0][k^1]);
             }
             REP(k, 2)
                dp[i][1][k] = max(dp[i][1][k], dp[i][0][k]);

            ret = max(ret, max(dp[i][1][0], dp[i][1][1]) + max(r[i+1][0], r[i+1][1])  );
        }
        cout << ret << endl;

    }
    return 0;
}

