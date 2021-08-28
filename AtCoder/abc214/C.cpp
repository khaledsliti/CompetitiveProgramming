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
int s[N], t[N];
int ans[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> t[i];
  }

  for(int i = 0; i < n; i++) {
    ans[i] = -1;
  }

  priority_queue<pair<int, int>> pq;

  for(int i = 0; i < n; i++) {
    pq.push({-t[i], i});
  }

  while(!pq.empty()) {
    int ti = -pq.top().first;
    int idx = pq.top().second;
    pq.pop();
    if(ans[idx] != -1) {
      continue;
    }
    ans[idx] = ti;
    pq.push({-ti - s[idx], (idx + 1) % n});
  }

  for(int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
