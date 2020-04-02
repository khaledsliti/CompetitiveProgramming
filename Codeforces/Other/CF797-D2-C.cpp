// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

string s;
pair<char, int> mn[N];

int main()
{
  cin >> s;
  mn[sz(s)] = {'z' + 1, 0};
  for(int i = sz(s) - 1 ; i >= 0 ; i--) {
    mn[i] = min({s[i], i}, mn[i + 1]);
  }
  string t, r;
  for(int i = 0 ; i < sz(s) ;) {
    while(sz(t) && t.back() <= mn[i].first)
      r += t.back(), t.pop_back();
    while(i < sz(s) && mn[i].second != i)
      t.push_back(s[i]), i++;
    r += s[i];
    i++;
  }
  while(sz(t)) r += t.back(), t.pop_back();
  cout << r << endl;
  return 0;
}
