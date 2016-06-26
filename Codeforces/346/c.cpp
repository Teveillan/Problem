#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
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

int main()
{
	//freopen("in", "r", stdin);
    int n, m, x;
    while(cin >> n >> m) {
        set<int>s;
        VI vec;
        REP(i, n) {
            scanf("%d", &x);
            s.insert(x);
        }
        FOR(i, 1, 1e9) {
            if(i > m) break;
            if(s.find(i) == s.end()) {
                m -= i;
                vec.pb(i);
            }
        }
        cout << vec.size() << endl;

        REP(i, vec.size()) printf("%d ", vec[i]);
        puts("");
    }

    return 0;
}

