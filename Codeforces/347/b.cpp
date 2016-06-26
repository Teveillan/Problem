#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
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
	freopen("in", "r", stdin);
    map<int, int>m;
    FOR(i, 1989, 2100) {
        int f = 10;
        while(m.find(i % f) != m.end()) f *= 10;
        m[i % f] = i;
        cout << i << ' ' << i % f << endl;
    }
    int n, x;
    char str[100];
    cin >> n;
    while(n--) {
        scanf("%s", str);
        sscanf(str + 4, "%d", &x);
        cout << m[x] << endl;
    }

    return 0;
}

