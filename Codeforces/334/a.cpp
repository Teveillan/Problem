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
    int f[5] = {500,1000,1500,2000,2500};
    int m[5], w[5];
    int a, b;
    double sum = 0;
    REP(i, 5) cin >> m[i];
    REP(i, 5) cin >> w[i];
    cin >> a >> b;

    REP(i, 5) {
        sum += max(0.3 * f[i], (1.0 - (double)m[i]/250.0) * f[i] - 50.0 * w[i]);
    }
    sum += a * 100.0;
    sum -= b * 50.0;
    int ret = sum + 0.5;
    cout << ret << endl;

    return 0;
}

