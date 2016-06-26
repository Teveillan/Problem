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
int v[2];
void out() {
    REP(i, 2) cout << v[i] << ' ';
    puts("");
}

void change() {
    swap(v[0], v[1]);
}
int main()
{
	//freopen("in", "r", stdin);
    v[0] = 0, v[1] = 1;
    out();
    change();
    out();


    return 0;
}

