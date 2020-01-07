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
  s[n++] = {d, 0};
  sort(s, s + n);
  long long have = k;
  int cur_pos = 0;
  priority_queue<int> pq;
  int ans = 0;
  for(int i = 0 ; i < n ; i++){
    int dist = s[i].first - cur_pos;
    cur_pos = s[i].first;
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
