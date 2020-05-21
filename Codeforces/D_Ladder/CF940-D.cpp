// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 1e5 + 5;

int n;
int arr[N];
char s[N];

int main()
{
  int l = -1e9, r = 1e9;
  cin >> n;
  for(int i = 0; i < n;i ++)
    cin >> arr[i];
  for(int i = 0; i < n; i++) {
    cin >> s[i];
    s[i] -= '0';
  }
  for(int i = 4; i < n; i++) {
    if(s[i] && !(s[i - 1] | s[i - 2] | s[i - 3] | s[i - 4])) {
      int mx = -1e9;
      for(int j = 0; j <= 4; j++)
        mx = max(mx, arr[i - j]);
      l = max(l, mx + 1);
    }
    if(!s[i] && (s[i - 1] & s[i - 2] & s[i - 3] & s[i - 4])) {
      int mn = 1e9;
      for(int j = 0; j <= 4; j++)
        mn = min(mn, arr[i - j]);
      r = min(r, mn - 1);
    }
  }
  cout << l << " " << r << endl;
  return 0;
}
