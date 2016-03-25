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
int v[N];
int ans[N];
int solve(int n, int m) {
    int ret = -1;
    map<int, int>f;
     FOR(i, 1, n) {
        int x;
        scanf("%d", &x);

        if(f.find(x) != f.end()) ret = 2;
        f[x] = i;
     }
    FOR(j, 1, m) scanf("%d", &v[j]);

    FOR(i, 1, m) {
         if(f.find(v[i]) == f.end()) return 0;
         ans[i] = f[ v[i] ];
    }
    if(ret == 2) return 2;
    return 1;
}

int main()
{
	freopen("in", "r", stdin);

    int n, m;
    while(cin >> n >> m) {
        int ret = solve(n, m);
        if(ret == 0) puts("Impossible");
        else if(ret == 1) {
             puts("Possible");
             FOR(i, 1, m) {
                 printf("%d ", ans[i]);
             }
                puts("");
        } else {
            puts("Ambiguity");
        }
    }
    return 0;
}

