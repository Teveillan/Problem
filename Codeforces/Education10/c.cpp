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


const int N = 3e5 + 100;
VI head[N];
int main()
{
	freopen("inc", "r", stdin);
    int n, m, x, y;
    while(cin >> n >> m) {
        FOR(i, 1, n) head[i].clear();
        map<int, int>s;
        FOR(i, 1, n) {
            scanf("%d", &x);
            s[x] = i;
        }

        while(m--) {
            scanf("%d%d", &x, &y);
            x = s[x], y = s[y];
            if(x > y) swap(x, y);
            head[y].pb(x);
        }
        LL ans = 0;
        int l = 0;
        FOR(i, 1, n) {
            REP(j, head[i].size()) l = max(l, head[i][j]);
            ans += (i - l);
        }
        cout << ans << endl;

    }
    return 0;
}

