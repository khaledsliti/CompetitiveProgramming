// Guess Who's Back
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

int n;
int arr[N];
int par[N];

int fs(int x) {
  return x == par[x] ? x : par[x] = fs(par[x]);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for(int i = 0; i < N; i++) {
    par[i] = i;
  }

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int ans = 0;
  for(int i = 0; i < n / 2; i++) {
    int j = n - 1 - i;
    int x = fs(arr[i]), y = fs(arr[j]);
    if(x != y) {
      ans++;
      par[x] = y;
    }
  }
  cout << ans << endl;
  return 0;
}
