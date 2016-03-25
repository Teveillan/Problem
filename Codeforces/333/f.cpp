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
const LL MOD = 1e17 + 7;
int node[N], v[N], n, sum, ans, t;
LL f[N];
char str[N];
VI head[N];
map<LL, int>m;
void update(int x, int value) {
     for(x = n-x+1; x<=n; x+=x&-x) node[x] += value;
}
int query(int x) {
    int ret = 0;
    for(x = n-x+1; x; x -= x&-x) ret += node[x];
    return ret;
}

void dfs(int cur, int pre) {
    f[cur] = (f[pre] * 27 + str[cur] - 'a' + 1) % MOD;
    int flag = ++t;
    for(int to: head[cur]) {
        if(to == pre) continue;
        dfs(to, cur);
    }
    if(m.count(f[cur])) update(m[f[cur]], -1);
    m[f[cur]] = flag;
    update(flag, 1);
    int tmp = query(flag);
    if(tmp + v[cur] > sum) sum = tmp + v[cur], ans = 1;
    else if(tmp + v[cur] == sum) ++ans;
}

int main()
{
	//freopen("in", "r", stdin);

    int x, y;
    while(cin >> n) {
        FOR(i, 1, n) scanf("%d", &v[i]);
        cin >> (str + 1);
        REP(i, n-1) {
            scanf("%d%d", &x, &y);
            head[x].pb(y);
            head[y].pb(x);
        }
        sum = ans = t = 0;
        dfs(1, 0);
        cout << sum << endl << ans << endl;
    }
    return 0;
}

