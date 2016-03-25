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

const int N = 201;
int v[N];
bool g[N][N], dp[N][N];
bool isprime[500];
void init() {
     memset(isprime, 1, sizeof(isprime));
     FOR(i, 2, 400)
         FOR(j, 2, i-1) {
             if(i % j == 0) {
                isprime[i] = 0;
                break;
             }
         }
}

bool solve(int n) {
    FOR(i, 1, n) if(!dp[i][i]) {
        cout << i << ' ' << v[i] << endl;
        return 0;
    }
    return 1;
}
int main()
{
	freopen("in", "r", stdin);
    int casnum, n, x, y;
    cin >> casnum;
    init();
    while(casnum--) {
        cin >> n;
        FOR(i, 1, n) scanf("%d", &v[i]);
        FOR(i, 1, n)
            FOR(j, 1, i-1)
                if(isprime[ v[i] + v[j] ])
                    g[i][j] = g[j][i] = dp[i][j] = dp[j][i] = 1;

        FOR(k, 1, n) {
             FOR(i, 1, n)
                 FOR(j, 1, i) {
                    if(i != j && dp[i][j] && dp[j][k])
                        dp[i][j] = 1;
                    if(dp[i][j] && dp[i][k] && dp[j][k])
                        dp[k][k] = 1;
                 }

        }

        FOR(i, 1, n)
            FOR(j, 1, i-1)
                cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        if(solve(n)) puts("YES");
        else puts("NO");
    }
    return 0;
}

