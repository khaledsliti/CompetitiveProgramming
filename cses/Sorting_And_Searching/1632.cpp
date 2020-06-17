// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 2e5 + 5;

int n, k;
pair<int, int> arr[N];

int main()
{
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    arr[i] = {a, b};
  }
  sort(arr, arr + n, [](const pair<int, int>& a, const pair<int, int>& b) {
    if(a.second != b.second) return a.second < b.second;
    return a.first > b.first;
  });
  multiset<int, greater<int>> members;
  for(int i = 0; i < k; i++) {
    members.insert(0);
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    auto it = members.lower_bound(arr[i].first);
    if(it == members.end()) continue;
    ans++;
    members.erase(it);
    members.insert(arr[i].second);
  }
  cout << ans << endl;
  return 0;
}
