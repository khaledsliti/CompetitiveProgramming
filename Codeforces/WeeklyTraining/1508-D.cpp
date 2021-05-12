// Guess Who's Back
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

int n;
string s[3];

string build(const string& a, const string& b, char c) {
  int i = 0, j = 0;
  string res = "";
  while(i < sz(a) && j < sz(b)) {
    if(a[i] == b[j]) {
      res += a[i];
      i++, j++;
    } else if(a[i] != c) {
      res += a[i++];
    } else {
      res += b[j++];
    }
  }
  while(i < sz(a)) res += a[i++];
  while(j < sz(b)) res += b[j++];
  return res;
}

void solve() {
  cin >> n;
  for(int i = 0; i < 3; i++) {
    cin >> s[i];
  }
  for(char c: {'0', '1'}) {
    int cnt[3];
    for(int i = 0; i < 3; i++) {
      cnt[i] = 0;
      for(char cur: s[i]) {
        cnt[i] += cur == c;
      }
    }
    for(int i = 0; i < 3; i++) {
      for(int j = i + 1; j < 3; j++) {
        if(min(cnt[i], cnt[j]) >= n) {
          cout << build(s[i], s[j], c) << endl;
          return;
        }
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
