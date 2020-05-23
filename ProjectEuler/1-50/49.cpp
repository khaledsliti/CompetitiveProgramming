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

const int N = 1e7;

int n, k;
int pr[N];
int seen[N];
vector<array<int, 2>> sol;

void solve(int n) {
  if(seen[n]) return;
  vector<int> d;
  for(int a = n; a > 0; a /= 10) {
    d.push_back(a % 10);
  }
  sort(all(d));
  vector<int> primes;
  set<int> spr;
  do {
    int cur = 0;
    for(int i = 0; i < sz(d); i++)
      cur = cur * 10 + d[i];
    seen[cur] = 1;
    if(d[0] == 0) continue;
    if(pr[cur])
      primes.push_back(cur), spr.insert(cur);
  } while(next_permutation(all(d)));
  if(sz(primes) >= k) {
    for(int i = 0; i < sz(primes) && primes[i] < ::n; i++) {
      for(int j = i + 1; j < sz(primes); j++) {
        int diff = primes[j] - primes[i];
        bool fx = spr.find(primes[i] + 2 * diff) != spr.end();
        bool fy = spr.find(primes[i] + 3 * diff) != spr.end();
        if(k == 3 && fx) {
          sol.push_back({primes[i], diff});
        }
        if(k == 4 && fx && fy) {
          sol.push_back({primes[i], diff});
        }
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for(int i = 2; i < N; i++)
    pr[i] = 1;
  for(int i = 2; i * i < N; i++)
    if(pr[i]) {
      for(int j = i * i; j < N; j += i)
        pr[j] = 0;
    }
  cin >> n >> k;
  for(int i = 2; i < n; i++) {
    solve(i);
  }
  sort(all(sol));
  for(int i = 0; i < sz(sol); i++) {
    for(int j = 0; j < k; j++)
      cout << sol[i][0] + j * sol[i][1];
    cout << endl;
  }
  return 0;
}
