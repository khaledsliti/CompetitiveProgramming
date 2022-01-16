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

const int N = 1e6 + 5;

int n;
int arr[N];


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    int a; cin >> a;
    arr[a] = 1;
  }

  int ans = 0;
  for(int i = 0; i < N; i++) {
    ans -= arr[i];
  }
  for(int i = 1; i < N; i++) {
    int cur = 0;
    for(int j = i; j < N; j += i) {
      if(arr[j]) {
        cur = __gcd(cur, j);
      }
      if(cur == i) {
        ans++;
        break;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
