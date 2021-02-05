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
  string a, b;
  cin >> a >> b;
  int cnt = sz(b) - 1;
  int i = sz(a) - 1;
  string s = "";
  while(cnt--) {
    if(i >= 0) s += a[i--];
    else s += '0';
  }
  s += '.';
  if(i < 0) s += '0';
  else {
    while(i >= 0) {
      s += a[i--];
    }
  }

  reverse(all(s));
  while(s.back() == '0')
    s.pop_back();
  if(s.back() == '.')
    s.pop_back();

  cout << s << endl;
  return 0;
}
