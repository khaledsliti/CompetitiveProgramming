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

const int N = 15;

int n, k;
string s[N];

int main()
{
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int ans = 0;
  for(int msk = 0; msk < (1 << n); msk++) {
    vector<int> cnt(26, 0);
    for(int i = 0; i < n; i++) {
      if(msk & (1 << i)) {
        for(char c: s[i]) {
          cnt[c - 'a']++;
        }
      }
    }
    int cur_ans = 0;
    for(int i = 0; i < 26; i++) {
      cur_ans += cnt[i] == k;
    }
    ans = max(ans, cur_ans);
  }
  cout << ans << endl;
  return 0;
}
