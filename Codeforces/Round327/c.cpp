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


const int N = 5e5 + 100;
int v[N];
bool g[N];
int ans[N], result[N];

int gao(int ll, int rr, int n) {
        FOR(i, ll+1, rr-1) {
            if(i - ll < rr - i) {
                result[i] = v[ll];
                ans[i] = i - ll;
            } else {
                result[i] = v[rr];
                ans[i] = rr - i;
            }
        }
    return 0;
}



int solve(int n) {
    memset(ans, 0, sizeof(ans));
    FOR(i, 1, n) result[i] = v[i];


    int ll = 1;
    while(ll != n+1) {
        int rr = ll + 1;
        while(rr <= n && v[rr] != v[rr-1]) ++rr;
        if(gao(ll, rr-1, n) == -1) return -1;
        ll = rr;
    }
    int ret = 0;
    FOR(i, 1, n) ret = max(ret, ans[i]);
    return ret;
}


int main()
{
	//freopen("in", "r", stdin);

    int n;
    while(cin >> n) {
        FOR(i, 1, n) scanf("%d", &v[i]);

        int tmp = solve(n);
        cout << tmp << endl;
        if(tmp != -1) {
            FOR(i, 1, n) {
                if(i != 1) putchar(' ');
                printf("%d", result[i]);
            }
        }

        puts("");
    }
    return 0;
}

