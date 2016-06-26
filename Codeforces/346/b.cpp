#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
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

vector<pair<int, string> > head[10010];
int main()
{
	freopen("in", "r", stdin);

    int n, m, team, score;
    char str[100];
    while(cin >> n >> m) {
        FOR(i, 1, m) head[i].clear();

        REP(i, n) {
            scanf("%s%d%d", str, &team, &score);
            head[team].pb(make_pair(score, string(str)));
        }
        FOR(i, 1, m) sort(head[i].begin(), head[i].end()), reverse(head[i].begin(), head[i].end());

        FOR(i, 1, m) {
            int l = 0, ll = 0;
            while(l < head[i].size() && head[i][l].first == head[i][ll].first)
                l++;
            if(l < 2) {
                ll = l;
                while(l < head[i].size() && head[i][l].first == head[i][ll].first)
                    l++;
            }
            if(l != 2) puts("?");
            else {
                cout << head[i][0].second << ' ' << head[i][1].second << endl;
            }

        }
    }

    return 0;
}

