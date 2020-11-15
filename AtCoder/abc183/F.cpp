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

int n, q;
int c[N];
map<int, int>* class_data[N];
int par[N], siz[N];

int fs(int x) {
  return par[x] == x ? x : fs(par[x]);
}

void merge(int a, int b) {
  a = fs(a), b = fs(b);
  if(a == b) return;
  if(siz[b] >= siz[a])
    swap(a, b);
  siz[a] += siz[b];
  par[b] = a;
  for(auto p: (*class_data[b])) {
    (*class_data[a])[p.first] += p.second;
  }
}

int get(int a, int c) {
  if(class_data[a]->count(c) > 0) {
    return (*class_data[a])[c];
  }
  return 0;
}

int main()
{
  scanf("%d%d", &n, &q);
  for(int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
    class_data[i] = new map<int, int>();
    class_data[i]->insert({c[i], 1});
  }

  for(int i = 0; i < n; i++) {
    par[i] = i;
    siz[i] = 1;
  }

  while(q--) {
    int t, a, b;
    cin >> t >> a >> b;
    if(t == 1) {
      merge(--a, --b);
    } else {
      a = fs(--a);
      printf("%d\n", get(a, b));
    }
  }
  
  return 0;
}
