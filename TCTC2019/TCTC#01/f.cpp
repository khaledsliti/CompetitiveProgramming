
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) begin(x), end(x)

const int N = 1e5 + 5;

int n, d, k;
pair<int, int> s[N];

int main()
{
  scanf("%d%d%d", &n, &d, &k);
  for(int i = 0 ; i < n ; i++){
    int x, y;
    scanf("%d%d", &x, &y);
    s[i] = {d - x, y};
  }
  s[n++] = {0, 0};
  s[n++] = {d, 0};
  sort(s, s + n);
  int have = k;
  priority_queue<int> pq;
  int ans = 0;
  for(int i = 1 ; i < n ; i++){
    int dist = s[i].first - s[i - 1].first;
    while(dist > have && !pq.empty())
      have += pq.top(), pq.pop(), ans++;
    if(dist <= have)
      have -= dist, pq.push(s[i].second);
    else
      return cout << -1 << endl, 0;
  }
  cout << ans << endl;
  return 0;
}
