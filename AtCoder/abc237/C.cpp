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
  string s; cin >> s;
  int st = 0, en = 0;
  while(st < sz(s) && s[st] == 'a') st++;
  if(st == sz(s)) {
    cout << "Yes" << endl;
    return 0;
  }
  for(int i = sz(s) - 1; i >= 0; i--) {
    if(s[i] != 'a') {
      break;
    }
    en++;
  }
  if(st > en) {
    cout << "No" << endl;
    return 0;
  }
  int diff = en - st;
  while(diff--) {
    s.pop_back();
  }
  bool ok = true;
  for(int i = 0; i < sz(s) / 2; i++) {
    if(s[i] != s[sz(s) - 1 - i]) {
      ok = false;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
