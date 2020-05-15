// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n;
int arr[N];

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> arr[i];
  unordered_map<int, int> cnt;
  long long ans = 0;
  for(int i = 0 ; i < n ; i++) {
    int v = i - arr[i];
    ans += cnt[v];
    cnt[i + arr[i]]++;
  }
  cout << ans << endl;
  return 0;
}
