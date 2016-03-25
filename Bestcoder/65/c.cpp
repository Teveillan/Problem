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

const int N = 5e4 + 100;
int node[N], n;
void update(int x, int value) {
    x = n - x + 1;
    for(;x<=n;x += x&-x) node[x] += value;
}
int query(int x) {
    int ret = 0;
    x = n - x + 1;
    for(;x;x -= x&-x) ret += node[x];
    return ret;
}
int v[N];
int ans[N];

int find(int x) {
    int l = 1, r = n, ret = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(n - mid  - query(mid) >= x) l = mid + 1, ret = mid;
        else r = mid - 1;
    }
    return ret;
}

int main()
{
	//freopen("in", "r", stdin);
    int casnum;
    cin >> casnum;
    while(casnum--) {
        memset(node, 0, sizeof(node));
        scanf("%d", &n);
        FOR(i, 1, n) scanf("%d", &v[i]);
        DWN(i, n, 1) {
            int num = v[i] - v[i-1];
                        ans[i] = find(num);
            update(ans[i], 1);
        }

        FOR(i, 1, n) {
             if(i != 1) putchar(' ');
             printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}

