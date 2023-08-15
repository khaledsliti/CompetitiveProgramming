// RedStone
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

vector<string> s;

string build(int a) {
  string cur;
  while(a > 0) {
    cur.push_back(char('0' + a % 10));
    a /= 10;
  }
  string ret;
  for (int i = 0; i < 9; i++) {
    if (i == 1) {
      ret += ret[0];
      continue;
    }
    if (i == 5) {
      ret += ret[4];
      continue;
    }
    if (i == 8) {
      ret += ret[6];
      continue;
    }
    ret += cur.back();
    cur.pop_back();
  }
  return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 100000; i <= 999999; i++) {
    s.push_back(build(i));
  }

  sort(all(s));

  int n;
  cin >> n;
  cout << s[--n] << endl;

  return 0;
}
