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

LL dp[2][10][10][7];
LL ans[2][10][10][7];

const int MOD = 1e9 + 7;

LL solve(LL l, LL k) {
    if(l < 1) return 1;
    memset(dp, 0, sizeof(dp));
    memset(ans, 0, sizeof(ans));
    int cur = 1, pre = 0;
    int ans_cur = 1, ans_pre = 0;

    REP(i, 10)
        dp[cur][i][i][i%7] = 1;

    LL tmp = 10 % 7;
    bool flag = 0;
    while(l) {
        if(l&1) {

        if(!flag) {
            REP(i, 10)
                REP(j, 10)
                    REP(k, 7)
                        ans[ans_cur][i][j][k] = dp[cur][i][j][k];
            flag = 1;
        } else {
            ans_cur ^= 1, ans_pre ^= 1;
            memset(ans[ans_cur], 0, sizeof(ans[ans_cur]));
            REP(i, 10)
                REP(j, 10)
                    if(i + j != k)
                        REP(a, 10)
                            REP(b, 10)
                                REP(c, 7)
                                    REP(d, 7)
                                        ans[ans_cur][a][b][(c*tmp+d)%7] = (ans[ans_cur][a][b][(c*tmp+d)%7] + ans[ans_pre][a][i][c] * dp[cur][j][b][d]) % MOD;
        }
        }

        l >>= 1;
        if(!l) break;
        puts("##########");
        cur ^= 1, pre ^= 1;
        memset(dp[cur], 0, sizeof(dp[cur]));

        REP(i, 10)
            REP(j, 10)
                if(i + j != k)
                    REP(a, 10)
                        REP(b, 10)
                            REP(c, 7)
                                REP(d, 7)
                                    dp[cur][a][b][(c*tmp+d)%7] = (dp[cur][a][b][(c*tmp+d)%7] + dp[pre][a][i][c] * dp[pre][j][b][d]) % MOD;
        if(k < 10)
            REP(b, 10)
                REP(d, 7)
                    dp[cur][0][b][d] = (dp[cur][0][b][d] + dp[pre][k][b][d]) % MOD;

        tmp = tmp * tmp % 7;
    }
    LL ret = 0;
    REP(i, 10)
        REP(j, 10)
            ret = (ret + ans[ans_cur][i][j][0]) % MOD;
    cout << ret << endl;
    return ret;
}

int main()
{
	freopen("in", "r", stdin);

    int casnum;
    cin >> casnum;
    while(casnum--) {
         LL l, r, k;
         cin >> l >> r >> k;
        LL ret = solve(r, k) - solve(l-1, k);
        if(ret < 0) ret += MOD;
        cout << ret << endl;
    }
    return 0;
}

