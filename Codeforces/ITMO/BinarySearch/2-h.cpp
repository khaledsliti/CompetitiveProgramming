// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 105;

int hb, hs, hc;
int n, nb, ns, nc;
int pb, ps, pc;
long long r;
string s;

bool check(ll nh) {
  ll need_b = max(0LL, hb * nh - nb);
  ll need_s = max(0LL, hs * nh - ns);
  ll need_c = max(0LL, hc * nh - nc);
  return need_b * pb + need_s * ps + need_c * pc <= r;
}

int main()
{
  cin >> s; n = sz(s);
  cin >> nb >> ns >> nc;
  cin >> pb >> ps >> pc;
  cin >> r;

  for(int i = 0; i < n; i++) {
    if(s[i] == 'B') hb++;
    else if(s[i] == 'S') hs++;
    else hc++;
  }
  
  ll lo = 0, hi = 1e15, best = 0;
  while(lo <= hi) {
    ll mid = lo + (hi - lo) / 2;
    if(check(mid)) {
      best = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  cout << best << endl;
  return 0;
}
