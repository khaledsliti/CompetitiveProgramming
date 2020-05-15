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

const int N = 1e7;

int smf[N];

int calc(int a, int b) {
  for(int n = 0; ; n++) {
    int cur = n * n + a * n + b;
    if(cur < 2 || smf[cur] != cur)
      return n;
  }
  return 0;
}

int main()
{
  for(int i = 1; i < N; i++)
    smf[i] = i;
  for(int i = 2; i * i < N; i++)
    if(smf[i] == i)
      for(int j = i * i; j < N; j += i)
        smf[j] = min(smf[j], i);
  int best = 0, ans_a, ans_b;
  for(int b = 2; b <= 1000; b++) {
    if(smf[b] != b) continue;
    for(int a = 2 - b; a < 1000; a++) {
      int cur = calc(a, b);
      if(best < cur) {
        best = cur;
        ans_a = a;
        ans_b = b;
      }
    }
  }
  cout << ans_a  << " " << ans_b << endl;
  cout << ans_a * ans_b << endl;
  return 0;
}
