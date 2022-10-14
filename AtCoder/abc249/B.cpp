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
  map<char, int> cnt;
  for(char c: s) {
    cnt[c]++;
  }
  int l = 0;
  for(char c = 'a'; c <= 'z'; c++) {
    if(cnt[c] > 1) {
      cout << "No" << endl;
      return 0;
    }
    if(cnt[c]) {
      l = 1;
    }
  }
  int u = 0;
  for(char c = 'A'; c <= 'Z'; c++) {
    if(cnt[c] > 1) {
      cout << "No" << endl;
      return 0;
    }
    if(cnt[c]) {
      u = 1;
    }
  }
  if(!l || !u) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}
