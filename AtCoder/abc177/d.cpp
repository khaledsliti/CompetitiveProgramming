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

int n, m;
int par[N], siz[N];

int fs(int a) {
  return par[a] == a ? a : par[a] = fs(par[a]);
}

int main()
{
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    par[i] = i;
    siz[i] = 1;
  }
  int best = 1;
  while(m--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    a = fs(a), b = fs(b);
    if(a != b) {
      par[a] = b;
      siz[b] += siz[a];
      best = max(best, siz[b]);
    }
  }
  cout << best << endl;
  return 0;
}
