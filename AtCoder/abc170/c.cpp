// We only fail when we stop trying
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

const int N = 105;

int n, x;
int arr[N];

int main()
{
  cin >> x >> n;
  set<int> s;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    s.insert(arr[i]);
  }
  int d = 1e9, ans;
  for(int i = 0; i < 300; i++) {
    if(s.find(i) == s.end()) {
      if(abs(i - x) < d) {
        d = abs(i - x);
        ans = i;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
