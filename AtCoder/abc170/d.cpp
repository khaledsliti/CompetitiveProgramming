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

const int N = 2e5 + 5;
const int V = 1e6 + 5;

int n;
int arr[N];
int fr[V];


int main()
{
  cin >> n;
  map<int, int> s;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    s[arr[i]]++;
  }
  int ans = n;
  for(int i = 0; i < n; i++) {
    if(s[arr[i]] > 1 || arr[i] != 1 && s.count(1)) {
      ans--;
      continue;
    }
    bool good = false;
    for(int d = 2; d * d <= arr[i]; d++) {
      if(arr[i] % d == 0) {
        if(s.count(d) || s.count(arr[i] / d))
          good = true;
      }
    }
    if(good) ans--;
  }
  cout << ans << endl;
  return 0;
}
