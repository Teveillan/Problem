#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
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

double get_dis(double x1, double y1, double x2, double y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

bool check(double x1, double y1, double x2, double y2, double v, double t, double vx, double vy) {
    LL tx = x1 + t * vx, ty = y1 + t * vy;
    LL dis = get_dis(tx, ty, x2, y2);
    return (LL)v * t * v * t >= dis;
}

double solve(double x1, double y1, double x2, double y2, double v, double vx, double vy, double t) {
    double l = 0, r = 1e9;
    while(r - l > 1e-7) {
        double mid = (l + r) / 2.0;
        if(get_dis(x1 + (mid-t) * vx, y1 + (mid-t) * vy, x2, y2) < v * mid * v * mid) r = mid;
        else l = mid;
    }
    return l;
}


int main()
{
	freopen("in", "r", stdin);

    int x1, x2, y1, y2;
    while(cin >> x1 >> y1 >> x2 >> y2) {
        int v, t;
        cin >> v >> t;
        int vx, vy, wx, wy;
        cin >> vx >> vy >> wx >> wy;
        if(check(x1, y1, x2, y2, v, t, vx, vy)) {
            printf("%.7lf\n", solve(x1, y1, x2, y2, v, vx, vy, 0));
        } else {
            printf("%.7lf\n", solve(x1+t*vx, y1+t*vy, x2, y2, v, wx, wy, t) );
        }
    }
    return 0;
}

