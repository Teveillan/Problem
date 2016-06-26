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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int get_dir(int x, int y) {
    if(y > 0) return 0;
    if(x > 0) return 1;
    if(y < 0) return 2;
    if(x < 0) return 3;
    return -1;
}


int main()
{
	freopen("in", "r", stdin);

    int n, x, y;
    while(cin >> n) {
        VI X, Y;
        REP(i, n) {
            scanf("%d%d", &x, &y);
            X.pb(x), Y.pb(y);
        }
        cin >> x >> y;

        int ans = 0;
        REP(i, n) {
            int x0 = X[i], y0 = Y[i];
            int x1 = X[(i+1)%n], y1 = Y[(i+1)%n];
            int x2 = X[(i+2)%n], y2 = Y[(i+2)%n];

            int dir = get_dir(x1-x0, y1-y0);
            int tmp = dx[dir] * (x2 - x1) + dy[dir] * (y2 - y1);
            if(tmp < 0) ++ ans;
        }
        cout << ans << endl;
    }

    return 0;
}

