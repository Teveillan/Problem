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

const int N = 5010;

int v[N], num[N], ans[N];
int main()
{
	freopen("in", "r", stdin);
    int n;
    while(cin >> n) {
        MEM(ans, 0);
        FOR(i, 1, n) scanf("%d", &v[i]);
        FOR(i, 1, n) {
            memset(num, 0, sizeof(num));
            int tmp_num = -1, tmp_id = -1;
            FOR(j, i, n) {
                ++num[v[j]];
                if(num[v[j]] > tmp_num || (num[v[j]] == tmp_num && v[j] < tmp_id)) tmp_num = num[v[j]], tmp_id = v[j];
                ++ans[tmp_id];
            }
        }
        FOR(i, 1, n) printf("%d ", ans[i]);
        puts("");
    }

    return 0;
}

