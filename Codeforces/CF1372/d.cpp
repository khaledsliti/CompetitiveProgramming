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

const int N = 4e5 + 5;

int n;
int arr[N];

int main()
{
  ios::sync_with_stdio(false);
  cin >> n;
  ll s = 0;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    s += arr[i];
  }
  ll best = 0;
  for(int it = 0; it < 2; it++) {
    ll cur = 0;
    for(int i = 0; i < n / 2 - 1; i++)
      cur += arr[2 * i];
    int r = (n / 2 - 1) * 2;
    for(int i = 0; i < n; i += 2, r = (r + 2) % n) {
      cur += arr[r];
      best = max(best, s - cur);
      cur -= arr[i];
    }
    int a0 = arr[0];
    for(int i = 0; i < n - 1; i++)
      arr[i] = arr[i + 1];
    arr[n - 1] = a0;
  }
  cout << best << endl;
  return 0;
}
