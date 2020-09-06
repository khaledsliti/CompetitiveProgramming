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

void solve() {
  int cnt[10];
  for(int i = 0; i < 10; i++) {
    scanf("%d", &cnt[i]);
  }
  vector<string> ans;
  for(int i = 0; i < 10; i++) {
    if(cnt[i] <= 0) continue;
    cnt[i]--;
    for(int j = 0; j < 10; j++) {
      if(cnt[j] <= 0 || (i * 10 + j) % 4 != 0) continue;
      cnt[j]--;
      string t = "";
      for(int k = 9; k >= 0; k--) {
        for(int it = 0; it < cnt[k]; it++) {
          t += char('0' + k);
        }
      }
      t += char('0' + i);
      t += char('0' + j);
      ans.push_back(t);
      cnt[j]++;
    }
    cnt[i]++;
  }
  sort(all(ans));
  if(sz(ans) > 0) {
    string v = ans.back();
    reverse(all(v));
    while(sz(v) > 1 && v.back() == '0')
      v.pop_back();
    reverse(all(v));
    printf("%s\n", v.c_str());
    return;
  }
  bool y = false;
  for(int c : {8, 4, 0}) {
    if(cnt[c] > 0) {
      printf("%d\n", c);
      y = true;
      break;
    }
  }
  if(!y) puts("-1");
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
