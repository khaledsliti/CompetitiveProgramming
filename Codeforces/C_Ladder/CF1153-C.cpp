// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 3e5 + 5;

int n;
char s[N];

void bad()
{
  cout << ":(" << endl;
  exit(0);
}

int main()
{
  scanf("%d%s", &n, s);
  if(n & 1)
    bad();
  int open = 0, close = 0, q = 0;
  for(int i = 0 ; i < n ; i++) {
    if(s[i] == '(') open++;
    if(s[i] == ')') close++;
    if(s[i] == '?') q++;
  }
  open = n / 2 - open;
  close = n / 2 - close;
  if(open < 0 || close < 0 || open + close != q)
    bad();
  for(int i = 0 ; i < n ; i++)
    if(s[i] == '?')
      if(open)
        s[i] = '(', open--;
      else
        s[i] = ')';
  int pref = 0;
  for(int i = 0 ; i < n ; i++) {
    if(i && pref == 0)
      bad();
    pref += (s[i] ==  '(') - (s[i] == ')');
    if(pref < 0)
      bad();
  }
  if(pref)
    bad();
  cout << s << endl;
  return 0;
}
