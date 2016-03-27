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

int dfn[N],low[N],fa[N];
int ss[N];
int top,time1,sig;
void dfs(int pos,int pre)
{
    cout << pos << endl;
    ss[++top]=pos;
    dfn[pos]=low[pos]=++time1;
    REP(i, head[pos].size())
    {
        int to = head[pos][i];
        if(to==pre) continue; 	 //点双连通 if(to==pre) continue;
        if(dfn[to]) low[pos]=min(low[pos],low[to]);
        else
        {
            dfs(to, pos); 	 //点双连通 dfs(to,pos)
            low[pos]=min(low[pos],low[to]);
            if(dfn[pos]<low[to]) //点双连通 dfn[pos]<=low[to]，根节点按题目特殊处理
            {
                ++sig;
                do
                {
                    fa[ ss[top] ]=sig;
                }while(ss[top]--!=to);
            }
        }
    }
}
void solve1(int n)
{
    memset(dfn,0,sizeof(dfn));
    time1=sig=top=0;
    FOR(i,1,n) if(!dfn[i]) dfs(i,-1);
}


bool solve(int a, int b, set<pii>&art) {
    if(fa[a] != fa[b]) return 0;
    for(set<pii>::iterator it = art.begin(); it != art.end(); ++it) {
        int x = (*it).first, y = (*it).second;
        if(fa[x] == fa[y] && fa[x] == fa[a]) return 1;
    }
    return 0;
}


int main()
{
	freopen("ine", "r", stdin);

    int n, m, x, y, z, a, b;
    while(cin >> n >> m) {
        FOR(i, 1, n) head[i].clear();
        set<pii>s, art;
        REP(i, m) {
            scanf("%d%d%d", &x, &y, &z);
            if(x > y) swap(x, y);
            head[x].pb(y);
            head[y].pb(x);
            if(z) art.insert(pii(x, y));
            s.insert(pii(x, y));
        }
        cin >> a >> b;
        if(a > b) swap(a, b);
        if(s.find(pii(a, b)) == s.end()) head[a].pb(b), head[b].pb(a);

        solve1(n);
        FOR(i, 1, n) cout << i << ' ' << fa[i] << endl;
        if(art.find(pii(a, b)) != art.end() || solve(a, b, art)) puts("YES");
        else puts("NO");
    }
    return 0;
}

