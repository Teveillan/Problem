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
const int N = 1e6 + 100;
int ans[N];
int main()
{
	freopen("in", "r", stdin);
    int n, m, x, y;
    while(cin >> n >> m) {
        int a = 0, b = 1;
        while(m--) {
            scanf("%d", &x);
            if(x == 1) {
                scanf("%d", &y);
                a = (a + y + n) % n;
                b = (b + y + n) % n;
            } else {
                a ^= 1, b ^= 1;
            }
        }
        int nn = n / 2;
        int id = a, v = 0;
        while(nn--) {
            ans[id] = v;
            id = (id + 2) % n;
            v = (v + 2) % n;
        }
        nn = n /2; id = b, v = 1;
        while(nn--) {
             ans[id] = v;
             id = (id + 2) % n;
             v = (v + 2) % n;
        }
        REP(i, n) printf("%d ", ans[i] + 1);
        puts("");
    }

    return 0;
}

