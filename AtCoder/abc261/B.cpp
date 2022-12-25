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
  int n;
  cin >> n;
  vector<string> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    if(a[i][i] != '-') {
      cout << "incorrect" << endl;
      return 0;
    }
    for(int j = 0; j < i; j++) {
      bool ok = (a[i][j] == 'D' && a[j][i] == 'D') || (a[i][j] == 'W' && a[j][i] == 'L') || (a[i][j] == 'L' && a[j][i] == 'W');
      if(!ok) {
        cout << "incorrect" << endl;
        return 0;
      }
    }
  }
  cout << "correct" << endl;
  return 0;
}
