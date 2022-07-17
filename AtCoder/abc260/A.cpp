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
  string s;
  cin >> s;
  map<char, int> f;
  for(char c: s) {
    f[c]++;
  }
  for(auto x: f) {
    if(x.second == 1) {
      cout << x.first << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
