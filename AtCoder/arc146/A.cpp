// RedStone
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
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(all(a));
  reverse(all(a));
  while(sz(a) > 3) {
    a.pop_back();
  }
  reverse(all(a));
  string sol = "";
  do {
    string tmp = "";
    for(int i : a) {
      tmp += to_string(i);
    }
    sol = max(sol, tmp);
  } while(next_permutation(all(a)));
  cout << sol << endl;
  return 0;
}
