// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

int main()
{
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
      cin >> v[i];
    }
    bool yes = true;
    for(int i = 0; i < n; i++)
      yes &= v[i] & 1;
    if(yes) puts("YES");
    else puts("NO");
  }
  return 0;
}
