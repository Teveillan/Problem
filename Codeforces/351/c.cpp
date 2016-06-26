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

const int N = 2e5 + 100;
double dp[51][N], v[N], sum[N], f[N], g[N];
int que[51][N], l[51], r[51];

double get(int num, int i) {
    return dp[num][i] - f[i] + sum[i] * g[i];
}

double slope(int num, int i, int j) {
    return (get(num, i) - get(num, j)) / (sum[i] - sum[j]);
}

int main()
{
	freopen("in", "r", stdin);
    int n, m;
    while(cin >> n >> m) {
        MEM(sum, 0), MEM(f, 0), MEM(g, 0), MEM(l, 0), MEM(r, 0);
        FOR(i, 1, n) {
            scanf("%lf", &v[i]);
            sum[i] = v[i] + sum[i-1];
            f[i] = sum[i] / v[i] + f[i-1];
            g[i] = 1.0 / v[i] + g[i-1];
        }
        que[0][r[0]++] = 0;
        FOR(i, 1, n) {
            DWN(j, m, 1) {
                if(r[j-1] == 0) continue;
                while(l[j-1] + 1 < r[j-1]) {
                    int a = que[j-1][l[j-1]], b = que[j-1][l[j-1] + 1];
                    if(get(j-1, a) - get(j-1, b) > g[i] * (sum[a] - sum[b])) l[j-1]++;
                    else break;
                }
                int k = que[j-1][ l[j-1] ];
                dp[j][i] = dp[j-1][k] + f[i] - f[k] - (sum[k] * (g[i] - g[k]));
                while(l[j] + 1 < r[j]) {
                    int a = que[j][r[j]-2], b = que[j][r[j] - 1];
                    if(slope(j, a, b) > slope(j, b, i)) r[j]--;
                    else break;
                }
                que[j][r[j]++] = i;
            }
        }
        printf("%.6lf\n", dp[m][n]);
    }
    return 0;
}

