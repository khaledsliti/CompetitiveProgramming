#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

string get(string a) {
  string r = "";
  for(char c: a) {
    if(c != 'b') {
      r += c;
    }
  }
  return r;
}

bool check(string a, string b, char x) {
  int cnt_a = 0, cnt_b = 0;
  int i = 0, j = 0;
  while(true) {
    while(i < sz(a) && a[i] != 'b') {
      if(a[i] == x) {
        cnt_a++;
      }
      i++;
    }
    while(j < sz(b) && b[j] != 'b') {
      if(b[j] == x) {
        cnt_b++;
      }
      j++;
    }
    if(i == sz(a)) {
      break;
    }
    if(cnt_a < cnt_b) {
      return false;
    }
    i++;
    j++;
  }
  return true;
}

bool check(string a, string b) {
  if(!check(a, b, 'a')) return false;
  reverse(all(a)); reverse(all(b));
  return check(a, b, 'c');
}

void solve() {
  int n; cin >> n;
  string a, b;
  cin >> a >> b;
  string x = get(a), y = get(b);
  if(x == y && check(a, b)) cout << "YES" << endl;
  else cout << "NO" << endl;
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
