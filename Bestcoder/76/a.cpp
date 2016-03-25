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

int v[400];
int main()
{
	//freopen("in", "r", stdin);

    int casnum;
    cin >> casnum;
    while(casnum--) {
        int n;
        cin >> n;
        REP(i, n) scanf("%d", &v[i]);
        int num = 0;
        REP(i, n)
            REP(j, n)
                if(v[i] > v[j])
                    ++num;
        double ans = (double)num / (n * (n - 1));
        printf("%.6lf\n", ans);
    }

    return 0;
}

