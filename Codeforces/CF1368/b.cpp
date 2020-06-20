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

ll k;
string s = "codeforces";
int cnt[10];

int main()
{
  int n = 10;
  cin >> k;
  for(int i = 0; i < n; i++)
    cnt[i] = 1;
  ll tot = 1;
  while(tot < k) {
    int At = 0;
    for(int i = 0; i < n; i++)
      if(cnt[At] > cnt[i])
        At = i;
    tot /= cnt[At];
    cnt[At]++;
    tot *= cnt[At];
  }
  for(int i = 0; i < n; i++)
    while(cnt[i]--)
      cout << s[i];
  cout << endl;
  return 0;
}
