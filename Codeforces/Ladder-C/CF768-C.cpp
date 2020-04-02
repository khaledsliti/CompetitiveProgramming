// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1 << 10;

int fr[N];
int tmp[N];

int main()
{
  int n, k, x;
  scanf("%d%d%d", &n, &k, &x);
  for(int i = 0 ; i < n ; i++) {
    int a; scanf("%d", &a);
    fr[a]++;
  }
  while(k--) {
    bool first = true;
    for(int i = 0 ; i < N ; i++) {
      if(!fr[i]) continue;
      int c = fr[i];
      if(first) {
        tmp[i ^ x] += (c + 1) / 2;
        tmp[i] += c / 2;
      } else {
        tmp[i ^ x] += c / 2;
        tmp[i] += (c + 1) / 2;
      }
      first ^= c & 1;
    }
    for(int i = 0 ; i < N ; i++)
      fr[i] = tmp[i], tmp[i] = 0;
  }
  for(int i = N - 1 ; i >= 0 ; i--)
    if(fr[i]) {
      cout << i << " ";
      break;
    }
  for(int i = 0 ; i < N ; i++)
    if(fr[i]) {
      cout << i << endl;
      break;
    }
  return 0;
}
