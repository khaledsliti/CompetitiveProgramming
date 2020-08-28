// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e6 + 5;

int n;
char s[N];

int get(char c)
{
  return (c == '(') - (c == ')');
}

bool check()
{
  int b = 0;
  for(int i = 0 ; i < n ; i++)
    b += get(s[i]);
  return b == 0;
}

int main()
{
  scanf("%d%s", &n, &s);
  if(!check())
    return cout << -1 << endl, 0;
  int b = 0;
  int ans = 0;
  for(int i = 0 ; i < n ; i++) {
    b += get(s[i]);
    if(b < 0) {
      int j = i + 1;
      while(j < n && b < 0) {
        b += get(s[j]);
        j++;
      }
      j--;
      if(b < 0)
        return cout << -1 << endl, 0;
      ans += (j - i + 1);
      i = j;
    }
  }
  cout << ans << endl;
  return 0;
}
