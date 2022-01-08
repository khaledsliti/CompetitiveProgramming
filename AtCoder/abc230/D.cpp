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

int n, d;
pair<int, int> arr[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> d; d--;
  for(int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
  }
  sort(arr, arr + n, [](pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first) return a.first < b.first;
    return a.second < b.second;
  });
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans++;
    int mxL = arr[i].first;
    int mnR = arr[i].second;
    int j = i + 1;
    while(j < n && max(mxL, arr[j].first) - d <= min(mnR, arr[j].second)) {
      mnR = min(mnR, arr[j].second);
      mxL = max(mxL, arr[j].first);
      j++;
    }
    i = j - 1;
  }
  cout << ans << endl;
  
  return 0;
}
