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

const int N = 123457;
VI head[N];

bool visit[N], attacked[N], route[N];
int pre[N];
int len[N];

int bfs(int s) {
    memset(visit, 0, sizeof(visit));
    memset(pre, -1, sizeof(pre));
    memset(len, 0, sizeof(len));
    int t = 0;
    queue<int>que;
    que.push(s);
    len[s] = 0;
    while(!que.empty()) {
        int top = que.front();
        que.pop();
        visit[top] = 1;
        if(attacked[top])
        if(len[top] > len[t] || (len[top] == len[t] && top < t))
            t = top;
        for(int to: head[top]) {
            if(!visit[to]) {
                que.push(to);
                len[to] = len[top] + 1;
                pre[to] = top;
            }
        }
    }
    return t;
}

bool dfs(int cur, int t, int deep, int tmp_deep, int &total, int &once) {
    visit[cur] = 1;
    if(attacked[cur]) {
        total += deep - tmp_deep;
        tmp_deep = deep;
    }
    if(cur == t) once = deep;
    visit[cur] = 1;
    for(int to: head[cur]) {
        if(visit[to]) continue;
        if(dfs(to, t, deep + 1, tmp_deep, total, once))
            tmp_deep = deep;
    }
    return tmp_deep == deep;
}


int main()
{
	freopen("in", "r", stdin);

    int n, m;
    while(cin >> n >> m) {
        FOR(i, 1, n) head[i].clear();
        memset(attacked, 0, sizeof(attacked));

        REP(i, n-1) {
            int x, y;
            scanf("%d%d", &x, &y);
            head[x].pb(y);
            head[y].pb(x);
        }
        int s = -1, t = -1;
        REP(i, m) {
            int x;
            scanf("%d", &x);
            attacked[x] = 1;
            s = x;
        }
        if(m == 1) {
             cout << s << endl;
             cout << 0 << endl;
             continue;
        }

        s = bfs(s);
        t = bfs(s);
        int total = 0, once = 0;
        memset(visit, 0, sizeof(visit));
        dfs(s, t, 0, 0, total, once);
        //cout << "   " << total << ' ' << once << endl;
        cout << min(s, t) << endl;
        cout << total * 2 - once << endl;

    }
    return 0;
}

