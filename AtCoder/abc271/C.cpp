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

const int N = 3e5 + 5;

int n;
set<int> s;

bool check(int cnt) {
  int have = 0, need = 0;
  for(int i = 1; i <= cnt; i++) {
    if(s.find(i) != s.end()) {
      have++;
    } else {
      need++;
    }
  }
  return need <= (n - have) / 2;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n ;i++) {
    int x;
    cin >> x;
    s.insert(x);
  }
  int low = 0, high = n, ans = 0;
  while(low <= high) {
    int mid = (low + high) >> 1;
    if(check(mid)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
