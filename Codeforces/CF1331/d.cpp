// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  string s;
  while(cin >> s) {
    long long d = 13;
    for(int i = 1 ; i < 7 ; i++) {
      d = (d * 16 % 10 + s[i] - '0') % 10;
    }
    cout << (d & 1) << endl;
  }
  return 0;
}
