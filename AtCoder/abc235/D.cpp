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

const ll INF = 1e17;

ll get(ll x) {
  ll p = 1;
  while(p <= x) {
    p *= 10;
  }
  p /= 10;
  return (x - (x / p * p)) * 10 + (x / p);
}

int main()
{
  // cout << get(584) << endl;
  // return 0;

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  ll a, n;
  cin >> a >> n;
  map<ll, int> dist;
  queue<ll> q;
  q.push(n);
  dist[n] = 0;
  while(!q.empty()) {
    ll cur = q.front();
    q.pop();
    if(cur == 1) {
      break;
    }
    if(cur % a == 0) {
      ll nxt = cur / a;
      if(dist.count(nxt) == 0) {
        dist[nxt] = dist[cur] + 1;
        q.push(nxt);
      }
    }
    if(cur >= 10) {
      ll nxt = get(cur);
      if(to_string(nxt).size() == to_string(cur).size() && dist.count(nxt) == 0) {
        dist[nxt] = dist[cur] + 1;
        q.push(nxt);
      }
    }
  }
  if(dist.count(1)) cout << dist[1] << endl;
  else cout << -1 << endl;

  return 0;
}
