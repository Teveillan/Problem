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


int main()
{
	//freopen("in", "r", stdin);

    int x[3], y[3], f[3];
    REP(i, 3) cin >> x[i];
    REP(i, 3) cin >> y[i];
    REP(i, 3) f[i] = x[i] - y[i];
    sort(f, f+3);

    REP(i, 3)
        REP(j, i) {
             int tmp = min(-f[j], f[i] / 2);
             tmp = max(tmp, 0);
             f[j] += tmp;
             f[i] -= tmp * 2;
        }
    bool flag=0;
    REP(i, 3) if(f[i] < 0) flag = 1;
    if(!flag) puts("Yes");
    else puts("No");
    return 0;
}

