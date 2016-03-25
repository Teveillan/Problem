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
    int n;
    while(cin >> n) {
        VI vec;
        REP(i, n) {
            int x;
            scanf("%d", &x);
            int id = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
            if(id == vec.size()) vec.pb(x);
            else {
                vec[id] = x;
            }
        }
        cout << n - vec.size() << endl;
    }
    return 0;
}

