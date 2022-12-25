// RedStone
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

const int N = 2e5 + 5;

bool isS(int a) {
  int x = sqrt(a);
  return x * x == a;
}

vector<int> sq;
int smf[N];

int main()
{
  int n; cin >> n;
  for(int i = 1; i * i <= n; i++) {
    sq.push_back(i * i);
  }
  for(int i = 0; i < N; i++) {
    smf[i] = i;
  }
  for(int i = 2; i < N; i++) {
    if(smf[i] == i) {
      for(int j = i + i; j < N; j += i) {
        smf[j] = min(smf[j], i);
      }
    }
  }

  long long ans = 0;

  for(int i = 1; i <= n; i++) {
    long long f = 1;
    for(int a = i; a > 1;) {
      int p = smf[a];
      int c = 0;
      while(smf[a] == p) {
        c++;
        a /= p;
      }
      if(c & 1) {
        f *= p;
      }
    }
    ans += lower_bound(all(sq), n / f + 1) - begin(sq);
  }

  cout << ans << endl;
  return 0;
}
