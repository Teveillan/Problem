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

VI head[30];
map<int, int>m;
int pos[300];

set<int>s[2];
bool solve(int l, int len, int end) {
        int cur = 0, pre = 0;
        bool flag = 1;
        while(l--) {
            cur ^= 1, pre ^= 0;
            s[cur].clear();
            REP(i, len) {
                int value = pos[i];
                s[cur].insert(value);
                for(set<int>::iterator it = s[pre].begin(); it != s[pre].end(); ++it) {
                     int tmp = (*it) | value;
                     if(tmp == end) return 1;
                     s[cur].insert(tmp);
                }
            }
        }
        return 0;
}


int main()
{
	freopen("in", "r", stdin);
    int casnum;
    cin >> casnum;
    while(casnum--) {
        int n, l;
        m.clear();
        cin >> n >> l;
        REP(i, n) head[i].clear();

        int id = 0;
        REP(i, n) {
            int num,x;
            scanf("%d", &num);
            while(num--) {
                 scanf("%d", &x);
                 head[i].pb(x);
                 if(m.find(x) == m.end()) m[x] = id++;
            }
        }

        memset(pos, 0, sizeof(pos));
        REP(i, n)
            REP(j, head[i].size()) {
                 int tmp = head[i][j];
                 pos[ m[tmp] ] |= (1<<i);
            }
        if(solve(l, m.size(), (1<<n) - 1)) puts("YES");
        else puts("NO");
    }
    return 0;
}

