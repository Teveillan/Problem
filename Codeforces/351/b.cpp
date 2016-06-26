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
int ans[1010];
bool visit[1010];
int main()
{
//	freopen("in", "r", stdin);
    int n, k, a, b, c, d;
    while(cin >> n >> k >> a >> b >> c >> d) {
        if(n <= 4 || k < n + 1) {
            puts("-1");
            continue;
        }
        memset(ans, -1, sizeof(ans));
        ans[1] = a, ans[n] = b;
        ans[2] = c, ans[n-1] = d;

        memset(visit, 0, sizeof(visit));
        visit[a] = visit[b] = visit[c] = visit[d] = 1;

        int id = 0;
        FOR(i, 1, n) if(ans[i] == -1) {
            while(visit[++id]);
            ans[i] = id;
        }
        FOR(i, 1, n) printf("%d ", ans[i]);
        puts("");
        DWN(i, 2, 1) printf("%d ", ans[i]);
        FOR(i, 3, n-2) printf("%d ", ans[i]);
        DWN(i, n, n-1) printf("%d ", ans[i]);
        puts("");
    }

    return 0;
}

