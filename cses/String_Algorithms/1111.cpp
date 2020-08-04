// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;



int main()
{
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  string t = "#";
  for(char c: s)
    t.push_back(c), t.push_back('#');
  swap(s, t);
  vector<int> p(sz(s), 0);
  int c = 0, r = 0;
  int mxLen = 0, st;
  for(int i = 0; i < sz(s); i++) {
    if(i < r) {
      int i1 = 2 * c - i;
      p[i] = min(r - i, p[i1]);
    }
    int a = i - p[i] - 1;
    int b = i + p[i] + 1;
    while(a >= 0 && b < sz(s) && s[a] == s[b])
      p[i]++, a--, b++;
    if(i + p[i] > r)
      c = i, r = i + p[i];
    if(mxLen < 2 * p[i] + 1) {
      mxLen = 2 * p[i] + 1;
      st = i - p[i];
    }
  }
  t.clear();
  for(int i = 0; i < mxLen; i++)
    if(s[st + i] != '#')
      t += s[st + i];
  cout << t << endl;
  return 0;
}
