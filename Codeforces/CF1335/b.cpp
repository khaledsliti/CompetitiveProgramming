// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2001;

int main()
{
  int T;
  cin >> T;
  while(T--) {
    int n, a, b;
    cin >> n >> a >> b;
    string s = "";
    for(int i = 0; i < b ; i++)
      s += char('a' + i);
    while(s.size() < a) s.pb(s.back());
    for(int i = 0 ; i < n ; i++)
      cout << s[i % s.size()];
    cout << endl;
  }
  return 0;
}
