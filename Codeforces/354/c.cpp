#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
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

int solve(int n, int k, string &s, char tmp) {
    ++k;
    queue<int>que;
    que.push(-1);
    int ret = 0;
    REP(i, n) {
        if(s[i] != tmp) que.push(i);
        while(que.size() > k) que.pop();
        ret = max(ret, i - que.front());
    }
    return ret;
}


int main()
{
	freopen("in", "r", stdin);
    int n, k;
    string s;
    while(cin >> n >> k >> s) {
        int ret = 0;
        ret = max(ret, solve(n, k, s, 'a'));
        ret = max(ret, solve(n, k, s, 'b'));
        cout << ret << endl;
    }

    return 0;
}

