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

struct Seg {
  int l, r;
  bool operator<(const Seg& other ) const {
    return r < other.r;
  }
};

int main()
{
  int n, x;
  cin >> x >> n;
  set<Seg> s;
  map<int, int> cnt;
  s.insert({0, x});
  cnt[x]++;
  for(int i = 0; i < n; i++) {
    int pos;
    cin >> pos;
    auto it = s.lower_bound({pos, pos});
    int l = it->l, r = it->r;
    if(!--cnt[r - l])
      cnt.erase(r - l);
    s.erase(it);
    cnt[pos - l]++;
    cnt[r - pos]++;
    s.insert({l, pos});
    s.insert({pos, r});
    cout << cnt.rbegin()->first << " ";
  }
  return 0;
}
