#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 205;

char s[N];

int mod(char* s, int m)
{
  if(*s == '-') ++s;
  long long rem = 0;
  while(*s){
    rem = (rem * 10 + *s - '0') % m;
    ++s;
  }
  return rem;
}

int main()
{
  int T, tc = 1;
  scanf("%d", &T);
  while(T--){
    int b;
    scanf("%s %d", s, &b);
    printf("Case %d: %s\n", tc++, mod(s, b) ? "not divisible" : "divisible");
  }
  return 0;
}
