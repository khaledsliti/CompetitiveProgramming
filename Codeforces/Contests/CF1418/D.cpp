#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 1e5 + 5;

int n, q;
set<int> pt;
multiset<int> len;

int get() {
  if(sz(pt) >= 2) {
    int tot = *pt.rbegin() - *pt.begin();
    tot -= *len.rbegin();
    return tot;
  }
  return 0;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pt.insert(x);
  }
  int last = -1;
  for(int p : pt) {
    if(last != -1) {
      len.insert(p - last);
    }
    last = p;
  }

  cout << get() << endl;

  while(q--) {
    int t, x;
    cin >> t >> x;

    if(t == 0) {
      auto it = pt.lower_bound(x);
      auto r = it; r++;
      int nw = 0;
      int cnt = 0;

      if(r != pt.end()) {
        nw += *r - x;
        len.erase(len.find(*r - x));
        cnt++;
      }

      it = pt.lower_bound(x);

      if(it != pt.begin()) {
        auto l = it; l--;
        nw += x - *l;
        len.erase(len.find(x - *l));
        cnt++;
      }

      if(cnt == 2) {
        len.insert(nw);
      }

      pt.erase(x);
    } else {
      pt.insert(x);

      auto it = pt.find(x);
      it++;
      int nw = 0, cnt = 0;

      if(it != pt.end()) {
        nw += *it - x;
        len.insert(*it - x);
        cnt++;
      }

      it = pt.find(x);

      if(it != pt.begin()) {
        auto l = it; l--;
        nw += x - *l;
        len.insert(x - *l);
        cnt++;
      }

      if(cnt == 2) {
        len.erase(len.find(nw));
      }
    }

    cout << get() << endl;
  }
  return 0;
}
