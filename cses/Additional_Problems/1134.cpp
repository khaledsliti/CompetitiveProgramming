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

int n;
int a[N];
int last[N];

int main()
{
  cin >> n;
  set<int> nodes;
  for(int i = 0; i < n; i++) {
    nodes.insert(i);
  }
  for(int i = 0; i < n - 2; i++) {
    cin >> a[i];
    a[i]--;
    nodes.erase(a[i]);
  }
  for(int i = 0; i < n - 2; i++) {
    last[a[i]] = i;
  }
  vector<array<int, 2>> sol;
  for(int i = 0; i < n - 2; i++) {
    sol.push_back({*nodes.begin(), a[i]});
    nodes.erase(nodes.begin());
    if(last[a[i]] == i) {
      nodes.insert(a[i]);
    }
  }
  assert(sz(nodes) == 2);
  sol.push_back({*nodes.begin(), *nodes.rbegin()});
  for(int i = 0; i < n - 1; i++)
    cout << sol[i][0] + 1 << " " << sol[i][1] + 1 << endl;
  return 0;
}
