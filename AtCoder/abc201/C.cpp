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

string s;
int ans = 0;
int cur[10];

int calc(int i) {
  if(i >= 4) {
    int a = 0, b = 0;
    for(int i = 0; i < 10; i++) {
      a += s[i] == 'o';
      b += cur[i] > 0;
    }
    return a == b;
  }
  int r = 0;
  for(int j = 0; j <= 9; j++) {
    if(s[j] == 'o') {
      cur[j]++;
      r += calc(i + 1);
      cur[j]--;

    }
  }
  return r;
}

void gen(int i) {
  if(i >= sz(s)) {
    int sum = 0;
    for(char c: s) {
      sum += c == 'o';
    }
    if(sum <= 4) {
      memset(cur, 0, sizeof cur);
      ans += calc(0);
    }
    return;
  }
  if(s[i] == '?') {
    s[i] = 'o';
    gen(i + 1);
    s[i] = 'x';
    gen(i + 1);
    s[i] = '?';
  } else {
    gen(i + 1);
  }
}

int main()
{
  cin >> s;
  gen(0);
  cout << ans << endl;
  return 0;
}
