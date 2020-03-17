// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e6 + 1;

int n;
int smf[N];

void pre() {
  for(int i = 1 ; i < N ; i++)
    smf[i] = i;
  for(int i = 2 ; i * i < N ; i++) {
    if(smf[i] == i) {
      for(int j = 2 * i ; j < N ; j += i)
        smf[i] = min(smf[i], j);
    }
  }
}

pair<int, int> factor(int a) {
  vector<pair<int, int>> pr;
  for(int i = a ; i > 1 ; i = smf[i]) {
    pr.push_back({smf[i], 0});
    int p = smf[i];
    while(i % p == 0)
      pr.back().second++, i /= p;
  }
  assert(sz(pr) <= 2);
  pr[0].second %= 2;
  pr[1].second %= 2;
  vector<int> r;
  for(int it = 0 ; it < 2 ; it++)
    if(pr[it].second)
      r.push_back(pr[it].first);
  return { sz(r) > 0 ? r[0] : -1, sz(r) > 1 ? r[1] : -1 };
}

int main()
{
  scanf("%d", &n);
  set<pair<int, int>> A;
  for(int i = 0 ; i < n ; i++) {
    int a; scanf("%d", &a);
    pair<int, int> p = factor(a);
    if(p.first == -1 || A.find(p) != A.end()) {
      cout << 1 << endl;
      return 0;
    }
    A.insert(p);
  }
  
  return 0;
}
