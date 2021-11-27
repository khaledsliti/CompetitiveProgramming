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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string a, b;
  cin >> a >> b;
  int c = 0;
  for(string x: {a, b}) {
    for(char cur: x) {
      c += cur == '#';
    }
  }
  if(c >= 3) cout << "Yes" << endl;
  else if(a[0] == b[1]) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}
