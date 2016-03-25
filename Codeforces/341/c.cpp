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
int l[N], r[N];

double get(int id, int p) {
    int tmp1 = (l[id] - 1) / p, tmp2 = r[id] / p;
    return (double)(tmp2 - tmp1) / (double)(r[id] - l[id] + 1);
}

double dp[2][2][2];

int main()
{
	//freopen("in", "r", stdin);
    int n, p;
    while(cin >> n >> p) {
        REP(i, n) scanf("%d%d", &l[i], &r[i]);
        double ans = 0;
        REP(i, n) {
            int id0 = i, id1 = (i + 1) % n;
            ans += 1.0 - (1.0 - get(id0, p)) * (1.0 - get(id1, p));
        }
        printf("%.7lf\n", ans * 2000.0);
    }
    return 0;
}

