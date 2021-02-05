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

const int N = 1500;

int n;
vector<array<int, 3>> edge;

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int a;
      cin >> a;
      if(i < j) {
        edge.push_back({a, i, j});
      }
    }
  }
  sort(all(edge));

  for(int i = 0; i < sz(edge); i++) {
    cout << edge[i][1] << " " << edge[i][2] << " " << edge[i][0] << endl;
  }

  return 0;
}
