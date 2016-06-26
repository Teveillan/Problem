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

const int N = 1e5 + 100;
string str;
bool visit[N];
int v[N];

bool solve(int n) {
    memset(visit, 0, sizeof(visit));
    int id = 0;
    while(1) {
        if(visit[id]) return 0;
        visit[id] = 1;
        if(str[id] == '<') id -= v[id];
        else id += v[id];
        if(id < 0 || id >= n) return 1;
    }
}

int main()
{
	//freopen("in", "r", stdin);
    int n;
    while(cin >> n >> str) {
        REP(i, n) scanf("%d", &v[i]);
        if(solve(n)) puts("FINITE");
        else puts("INFINITE");
    }

    return 0;
}

