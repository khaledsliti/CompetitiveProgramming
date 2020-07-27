// We only fail when we stop trying
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

long long Limit = 1e10;
const int N = 2e6 + 1;
const int Mod = 1e9 + 7;

struct State {
  int occ;
  ll L, R;
  State(int occ, ll L, ll R): occ(occ), L(L), R(R) {}
  bool operator<(const State& other) const {
    if(L != other.L) return L < other.L;
    return R < other.R;
  }
};

vector<State> intervals;
vector<ll> pref;

ll calc(ll L, ll R, ll occ) {
  return occ * occ % Mod * ((R - L + 1) % Mod) % Mod;
}

int main()
{
  ios::sync_with_stdio(false);
  intervals.push_back(State(1, 1, 1));
  intervals.push_back(State(2, 2, 3));
  ll cur = 4;
  int idx = 1;
  for(int i = 3; cur <= Limit && i; i++) {
    while(intervals[idx].L > i || intervals[idx].R < i)
      idx++;
    intervals.push_back(State(i, cur, cur + intervals[idx].occ - 1));
    cur += intervals[idx].occ;
  }
  pref.resize(sz(intervals));
  for(int i = 0; i < sz(intervals); i++) {
    ll cnt = intervals[i].R - intervals[i].L + 1;
    ll v = intervals[i].occ;
    pref[i] = v * v % Mod * cnt % Mod;
    if(i > 0) {
      pref[i] = (pref[i] + pref[i - 1]) % Mod;
    }
  }
  // for(int i = 0; i < 50; i++)
  //   cout << intervals[i].L << " " << intervals[i].R << " " << intervals[i].occ << endl;
  int T;
  cin >> T;
  while(T--) {
    ll L, R;
    cin >> L >> R;
    int i = lower_bound(all(intervals), State(0, L + 1, 0)) - begin(intervals) - 1;
    int j = lower_bound(all(intervals), State(0, R + 1, 0)) - begin(intervals) - 1;
    ll ans = 0;
    if(j - 1 > i) {
      ans += pref[j - 1] - pref[i];
      ans %= Mod;
      ans = (ans + Mod) % Mod;
    }
    if(i == j) {
      // cout << intervals[i].occ << " " << L << " " << R << endl;
      ans += calc(L, R, intervals[i].occ);
    } else {
      ans = (ans + calc(L, intervals[i].R, intervals[i].occ)) % Mod;
      ans = (ans + calc(intervals[j].L, R, intervals[j].occ)) % Mod;
    }
    cout << ans << endl;
  }
  return 0;
}
