// Guess Who's Back
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

const int N = 5007;

int n, k;
string s;

string get(int pref) {
  string r = s.substr(0, pref);
  while(sz(r) < k) {
    r = r + r;
  }
  while(sz(r) > k) r.pop_back();
  return r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k >> s;
  string ans = get(1);
  for(int i = 2; i <= n; i++) {
    ans = min(ans, get(i));
  }
  cout << ans << endl;
  return 0;
}
