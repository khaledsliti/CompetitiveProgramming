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
  int n, x;
  cin >> n >> x;
  string s;
  cin >> s;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'o') {
      x++;
    } else {
      x = max(0, x - 1);
    }
  }
  cout << x << endl;
  return 0;
}
