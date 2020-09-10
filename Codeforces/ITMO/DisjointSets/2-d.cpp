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

const int N = 3e5 + 5;

int n;
int anc[N];
int par[N];

void update(int a) {
  if(par[a] == a) return;
  int p = par[a];
  update(p);
  anc[a] += anc[p];
  par[a] = par[p];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int q;
  cin >> n >> q;
  
  for(int i = 0; i < n; i++) {
    anc[i] = 0;
    par[i] = i;
  }

  while(q--) {
    int t, a, b;
    cin >> t;
    if(t == 1) {
      cin >> a >> b;
      --a, --b;
      par[a] = b;
      anc[a] = 1;
    } else {
      cin >> a;
      --a;
      update(a);
      cout << anc[a] << endl;
    }
  }
  return 0;
}
