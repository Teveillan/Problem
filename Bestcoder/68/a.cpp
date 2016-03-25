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

        int x[3], y[3];
double fun(int a, int b) {
    return sqrt((double)(x[a] - x[b]) * (x[a] - x[b]) + (double)(y[a] - y[b]) * (y[a] - y[b]));
}

int main()
{
	//freopen("in", "r", stdin);
    int casnum;
    cin >> casnum;
    while(casnum--) {
        cin >> x[0] >> y[0];
        x[0] = abs(x[0]), y[0] = abs(y[0]);

        x[1] = x[0] + y[0], y[1] = 0;
        y[2] = x[1], x[2] = 0;

        cout << fun(0, 1) * fun(0, 2) << endl;
    }
    return 0;
}

