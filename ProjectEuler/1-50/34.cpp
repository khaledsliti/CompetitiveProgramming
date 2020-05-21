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
const int N = 1e8;

int main()
{
  int fact[10];
  fact[0] = 1;
  for(int i = 1; i < 10; i++)
    fact[i] = i * fact[i - 1];
  ll sum = 0;
  for(int i = 3; i < N; i++) {
    int d = 0;
    for(int a = i; a > 0; a /= 10)
      d += fact[a % 10];
    if(d == i)
      sum += i;
  }
  cout << sum << endl;
  return 0;
}
