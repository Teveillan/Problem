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

int v[100100];
int main()
{
	//freopen("in", "r", stdin);

    int n;
    while(cin >> n) {
        map<int, int>m;
        int l = 0;
        int ans = 0;
        FOR(i, 1, n) {
            scanf("%d", &v[i]);
            ++m[ v[i] ];
            while(m.rbegin()->first - m.begin()->first > 1) {
                 ++l;
                 if(--m[ v[l] ] == 0) {
                     m.erase(v[l]);
                 }
            }
            ans = max(ans, i - l);
        }
        cout << ans << endl;
    }
    return 0;
}

