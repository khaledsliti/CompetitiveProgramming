// We only fail when we stop trying
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

const int N = 1e5 + 5;

char s[N];
int cnt[26];

void solve() {
  memset(cnt, 0, sizeof cnt);
  scanf("%s", s);
  int n = strlen(s);
  for(int i = 0; i < n; i++)
    cnt[s[i] - 'a']++;
  scanf("%s", s);
  n = strlen(s);
  bool before = true;
  for(int i = 1; i < n; i++)
    if(s[i] != s[i - 1]) {
      before = s[i] > s[i - 1];
      break;
    }
  for(int i = 0; i < n; i++)
    cnt[s[i] - 'a']--;
  for(int i = 0; i < s[0] - 'a'; i++)
    while(cnt[i]-- > 0) printf("%c", char('a' + i));
  if(before) while(cnt[s[0] - 'a']-- > 0) printf("%c", s[0]);
  for(int i = 0; i < n; i++)
    cout << s[i];
  if(!before) while(cnt[s[0] - 'a']-- > 0) printf("%c", s[0]);
  for(int i = s[0] - 'a' + 1; i < 26; i++)
    while(cnt[i]-- > 0) printf("%c", char('a' + i));
  printf("\n");
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
    solve();
  return 0;
}
