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
const int N = 1e5 + 10;
double v[2][N], l[N], r[N], ans[2][N];
int main()
{
	freopen("in", "r", stdin);
    int n;
    while(cin >> n) {
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        REP(i, 2) FOR(j, 1, n) scanf("%lf", &v[i][j]);
        FOR(i, 1, n) r[i] = v[0][i] + r[i-1];
        DWN(i, n, 1) l[i] = v[1][i] + l[i+1];

        FOR(i, 1, n) {
            double tmp1 = r[i], tmp2 = 1 + r[i] - l[i+1];
            double tmp = tmp2 * tmp2 - 4.0 * tmp1;
            if(tmp <0) tmp = 0;
            ans[1][i] = (tmp2 +  sqrt(tmp)) / 2.0;
            ans[0][i] = tmp2 - ans[1][i];
        }

        REP(i, 2) {
            FOR(j, 1, n) printf("%1.7lf ", ans[i][j] - ans[i][j-1]);
            puts("");
        }
    }

    return 0;
}

