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

const int N = 26;

int cnt[N];

bool check(int len) {
  int mx = (len + 1) >> 1;
  for(int i = 0; i < N; i++) {
    if(cnt[i] > mx) {
      return false;
    }
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;
  int n = sz(s);
  for(auto c : s) {
    cnt[c - 'A']++;
  }
  s.clear();
  if(!check(n)) {
    cout << -1 << endl;
    return 0;
  }
  int last = -1;
  for(int it = 0; it < n; it++) {
    for(int i = 0; i < N; i++) {
      if(cnt[i] > 0 && last != i) {
        cnt[i]--;
        if(check(n - 1 - it)) {
          cout << char('A' + i);
          last = i;
          break;
        }
        cnt[i]++;
      }
    }
  }
  cout << endl;
  return 0;
}
