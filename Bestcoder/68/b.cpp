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

int fa[100100];
int sum[100100];
int find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

int main()
{
	//freopen("in", "r", stdin);
    int casnum;
    cin >> casnum;
    while(casnum--) {
         int n;
         cin >> n;
         FOR(i, 1, n) fa[i] = i, sum[i] = 1;
         REP(i, n-1) {
             int u, v, c;
             scanf("%d%d%d", &u, &v, &c);
             int uu = find(u), vv= find(v);
             if(c == 1) continue;
             if(uu != vv) {
                 fa[uu] = vv;
                 sum[vv] += sum[uu];
             }
         }
         int ans = 0;
         FOR(i, 1, n) ans^=sum[find(i)];
         cout << ans << endl;
    }
    return 0;
}

