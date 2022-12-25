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
  vector<string> d {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
  string s; cin >> s;
  for(int i = 0; i < sz(d); i++) {
    if(s == d[i]) {
      cout << sz(d) - 1 - i + 1 << endl;
      return 0;
    }
  }
  return 0;
}
