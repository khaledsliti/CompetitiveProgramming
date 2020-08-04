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

const int A = 128;
const int N = 2e6 + 5;


int n, st;
char s[N];

int least_rotation() {
  n = strlen(s);
  for(int i = 0; i < n; i++)
    s[i + n] = s[i];
  n <<= 1;
  s[n] = 0;
  vector<int> f(n, 0);
  int st = 0;
  for(int j = 1, k = 0; j < n; j++) {
    while(k > 0 && s[j] != s[st + k]) {
      if(s[j] < s[st + k]) st = j - k;
      k = f[k - 1];
    }
    if(s[j] == s[st + k]) k++;
    else if(s[j] < s[st + k]) st = j - k;
    f[j - st] = k;
  }
  return st;
}

int main()
{
  scanf("%s", s);
  int st = least_rotation();
  for(int i = 0; i < n / 2; i++) {
    printf("%c", s[st + i]);
  }
  printf("\n");
  return 0;
}
