// We only fail when we stop trying
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

const int N = 1e5 + 5;

int n, m;
int par[N];

int fs(int x) {
  return x == par[x] ? par[x] : par[x] = fs(par[x]);
}

int main()
{
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    par[i] = i;
  while(m--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    a = fs(a), b = fs(b);
    if(a != b) {
      par[a] = b;
    }
  }
  vector<int> nodes;
  for(int i = 0; i< n ;i++)
    if(fs(i) == i)
      nodes.push_back(i + 1);
  cout << sz(nodes) - 1 << endl;
  for(int i = 1; i < sz(nodes); i++)
    cout << nodes[i - 1] << " " << nodes[i] << endl;
  return 0;
}
