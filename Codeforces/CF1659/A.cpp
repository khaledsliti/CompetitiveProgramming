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



void solve() {
  int n, r, b;
  cin >> n >> r >> b;
  int tot = r / (b + 1);
  int rem = r % (b + 1);
  for(int i = 0; i < b + 1; i++) {
    for(int j = 0; j < tot; j++) {
      cout << "R";
    }
    if(rem > 0) {
      rem--;
      cout << "R";
    }
    if(i < b) {
      cout << "B";
    }
  }
  cout << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
