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

const int N = 110;
bool isprime[N];
VI vec;
void init() {
    memset(isprime, 1, sizeof(isprime));
    FOR(i, 2, 100) {
        FOR(j, 2, i / 2) if(i % j == 0) {
            isprime[i] = 0;
            break;
        }
        if(isprime[i]) vec.pb(i);
    }
}


int main()
{
	//freopen("in", "r", stdin);

    init();
    int id = -1;
    string s;
    REP(i, 4) {
        cout << vec[i] << endl;
        fflush(stdout);
        cin >> s;
        if(s == "yes") {
            id = i;
            break;
        }
    }
    string p = "prime", f = "composite";
    if(id == -1) {
        cout << p << endl;
        return 0;
    }

    cout << vec[id] * vec[id] << endl;
    fflush(stdout);
    cin >> s;
    if(s == "yes") {
        cout << f << endl;
        return 0;
    }

    for(int i = id + 1; id < vec.size() && vec[id] * vec[i] <= 100; ++i) {
        cout << vec[i] << endl;
        fflush(stdout);
        cin >> s;
        if(s == "yes")  {
            cout << f << endl;
            return 0;
        }
    }
    cout << p << endl;
    fflush(stdout);

    return 0;
}

