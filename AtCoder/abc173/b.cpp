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

vector<string> v = { "AC", "WA", "TLE", "RE" };

int main()
{
  int n;
  cin >> n;
  map<string, int> cnt;
  for(int i = 0; i < n; i++) {
    string a;
    cin >> a;
    cnt[a]++;
  }
  for(int i = 0; i < sz(v); i++) {
    cout << v[i] << " x " << cnt[v[i]] << endl;
  }

  return 0;
}
