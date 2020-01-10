#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
typedef pair<int, int> point;

const int N = 2001;

int n;
point a, b;
point pt[N];
long long mn[N];

long long dist(const point& a, const point& b) {
  return 1LL * (a.f - b.f) * (a.f - b.f) + 1LL * (a.s - b.s) * (a.s - b.s);
}

int main()
{
  cin >> n >> a.f >> a.s >> b.f >> b.s;
  for(int i = 0 ; i < n ; i++)
    cin >> pt[i].f >> pt[i].s;
  sort(pt, pt + n, [](const point& x, const point& y){
    return dist(a, x) < dist(a, y);
  });
  mn[n] = 0;
  for(int i = n - 1 ; i >= 0 ; i--)
    mn[i] = max(dist(pt[i], b), mn[i + 1]);
  long long best = mn[0];
  long long cur = 0;
  for(int i = 0 ; i < n; i++){
    cur = max(cur, dist(a, pt[i]));
    best = min(best, cur + mn[i + 1]);
  }
  cout << best << endl;
  return 0;
}
