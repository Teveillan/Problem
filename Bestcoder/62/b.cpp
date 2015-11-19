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

double get(double x1, double y1, double x2, double y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

bool solve(vector<double>x, vector<double>y) {
    REP(i, 5) {
        double result = abs(get(x[0], y[0], x[1], y[1])
                - get(x[i], y[i], x[(i+1)%5], y[(i+1)%5]));
        cout << i << ' ' << result << endl;
        if(result > 1e-1) return 0;
    }
    return 1;
}


int main()
{
	freopen("in", "r", stdin);

    int casnum;
    cin >> casnum;
    while(casnum--) {
         int n = 5;
         vector<double>vecx, vecy;
         double xx = 0, yy = 0;
         REP(i, n) {
            double x, y;
            scanf("%lf%lf", &x, &y);
            xx += x;
            yy += y;
            vecx.pb(x);
            vecy.pb(y);
         }
         xx /= 5.0, yy /= 5.0;
         if(solve(vecx, vecy)) puts("Yes");
         else puts("No");
    }

    return 0;
}

