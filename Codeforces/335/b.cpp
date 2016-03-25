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

const int N = 510;
bool visit[N][N];

int main()
{
	freopen("in", "r", stdin);
    int n, m, x, y;
    while(cin >> n >> m >> x >> y) {
        memset(visit, 0, sizeof(visit));
        int num = 0;
        string str;
        cin >> str;
        VI ans;
        REP(i, str.size()) {
            if(!visit[x][y]) {
                ans.pb(1);
                visit[x][y] = 1;
                ++num;
            } else ans.pb(0);

            cout << x << ' ' << y << ' ' << ans.back() << ' ' << str[i] << endl;
            if(str[i] == 'L') y = min(y+1, m);
            if(str[i] == 'R') y = max(y-1, 1);
            if(str[i] == 'D') x = max(x-1, 1);
            if(str[i] == 'U') x = min(x+1, n);
        }
        REP(i, ans.size()) printf("%d ", ans[i]);
        cout << n * m - num << endl;
    }
    return 0;
}

