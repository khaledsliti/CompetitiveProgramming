// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e6 + 2;

struct item {
  char last;
  int cnt;
  int idx;
};

bool isv(char c) {
  for(char x : {'a', 'e', 'i', 'u', 'o'})
    if(x == c)
      return true;
  return false;
}

int n;
string s[N];
vector<item> v[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n;
  for(int i = 0 ; i < n ; i++) {
    cin >> s[i];
    int cnt = 0;
    char last;
    for(char c : s[i]) {
      if(isv(c))
        cnt++, last = c;
    }
    v[cnt].pb({last, cnt, i});
  }
  vector<pair<int, int>> A, B;
  for(int cnt = 1 ; cnt < N ; cnt++) {
    sort(v[cnt].begin(), v[cnt].end(), [](const item& a, const item& b) {
      return a.last < b.last;
    });
    vector<int> rem;
    for(int i = 0 ; i < sz(v[cnt]) ; i++) {
      if(i + 1 < sz(v[cnt]) && v[cnt][i].last == v[cnt][i + 1].last) {
        A.pb({v[cnt][i].idx, v[cnt][i + 1].idx});
        i++;
      } else {
        rem.pb({v[cnt][i].idx});
      }
    }
    for(int i = 0 ; i + 1 < sz(rem) ; i += 2)
      B.pb({rem[i], rem[i + 1]});
  }
  while(sz(A) >= sz(B) + 2)
    B.pb(A.back()), A.pop_back();
  int sol = min(sz(A), sz(B));
  cout << sol << endl;
  for(int i = 0 ; i < sol ; i++) {
    cout << s[B[i].first] << " " << s[A[i].first] << endl;
    cout << s[B[i].second] << " " << s[A[i].second] << endl;
  }
  return 0;
}
