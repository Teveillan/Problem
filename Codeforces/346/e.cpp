#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
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
const int N = 1e6 + 100;

#define nn N //两边的点数均为nn
const int INF = 1e9;
int nx,ny;//建图时左边点从0到nx-1,右边点从nx到nx+ny-1
int cx[nn],cy[nn];
int dx[nn],dy[nn];
int dis;
int head[N];
bool bmask[nn];//记录右边是否匹配

struct Edge{
    int to, next;
}edge[N<<3];
int ip;

bool searchpath()
{
    queue<int>q;
    dis=INF;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    REP(i,nx)
    {
        if(cx[i]==-1)
        {
            q.push(i);
            dx[i]=0;
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(dx[u]>dis) break;

        for(int p=head[u]; p!=-1; p=edge[p].next)
        {
            int to=edge[p].to-nx;
            if(dy[to]==-1)
            {
                dy[to]=dx[u]+1;
                if(cy[to]==-1) dis=dy[to];
                else
                {
                    dx[ cy[to] ]=dy[to]+1;
                    q.push(cy[to]);
                }
            }
        }
    }
    return dis!=INF;
}

int find(int u)
{
    for(int p=head[u]; p!=-1; p=edge[p].next)
    {
        int to=edge[p].to-nx; //右边点要剪掉nx
        if(!bmask[to] && dy[to]==dx[u]+1)
        {
            bmask[to]=1;
            if(cy[to]!=-1 && dy[to]==dis) continue;
            if(cy[to]==-1 || find(cy[to]))
            {
                cy[to]=u;
                cx[u]=to;
                return 1;
            }
        }
    }
    return 0;
}

int match()
{
    memset(cx,-1,sizeof(cx));
    memset(cy,-1,sizeof(cy));
    int ret=0;
    while(searchpath())
    {
        memset(bmask,0,sizeof(bmask));
        REP(i,nx)
        {
            if(cx[i]==-1)   ret+=find(i);
        }
    }
    return ret;
}

void add(int u, int v) {
	edge[ip].to = v; edge[ip].next = head[u]; head[u]=ip++;
}

int main()
{
	freopen("in", "r", stdin);
    int n, m, x, y;
    while(cin >> n >> m) {
    	memset(head, -1, sizeof(head)); ip = 0;
    	nx = m; ny = n;
    	REP(i, m) {
    		scanf("%d%d", &x, &y);
    		add(i, x+m-1);
    		add(i, y+m-1);
    	}
        cout << n - match() << endl;
    }
    return 0;
}

