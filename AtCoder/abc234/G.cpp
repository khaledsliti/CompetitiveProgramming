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

const int Mod = 998244353;
const int N = 3e5 + 5;
const int INF = 1e9 + 5;

int n;
int arr[N];
int dp[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  stack<ll> max, min, max_v, min_v;
  ll max_sum = 0, min_sum = 0;
  dp[n] = 1;
  for(int i = n - 1; i >= 0; i--) {
    {
      ll sum_v = dp[i + 1];
      while(max.size() && max.top() <= arr[i]) {
        max_sum = (max_sum - max_v.top() * max.top()) % Mod;
        sum_v = (sum_v + max_v.top()) % Mod;
        max.pop(), max_v.pop();
      }
      max_sum = (max_sum + sum_v * arr[i] % Mod) % Mod;
      max.push(arr[i]);
      max_v.push(sum_v);
    }
    {
      ll sum_v = dp[i + 1];
      while(min.size() && min.top() >= arr[i]) {
        min_sum = (min_sum - min_v.top() * min.top()) % Mod;
        sum_v = (sum_v + min_v.top()) % Mod;
        min.pop(), min_v.pop();
      }
      min_sum = (min_sum + sum_v * arr[i] % Mod) % Mod;
      min.push(arr[i]);
      min_v.push(sum_v);
    }
    dp[i] = (max_sum - min_sum) % Mod;
  }

  if(dp[0] < 0)
    dp[0] += Mod;

  cout << dp[0] << endl;
  return 0;
}
