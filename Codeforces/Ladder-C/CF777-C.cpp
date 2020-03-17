// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n, m;
vector<vector<int>> arr;
vector<int> row;

int main()
{
  scanf("%d%d", &n, &m);
  arr.resize(n, vector<int>(m));
  row.resize(n);
  for(int i = 0 ; i < n ; i++) {
    row[i] = n;
    for(int j = 0 ; j < m ; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  for(int j = 0 ; j < m ; j++) {
    int idx = -1;
    for(int i = 0 ; i < n ; i++) {
      if(i == 0 || arr[i][j] < arr[i - 1][j])
        idx = i - 1;
      row[i] = min(row[i], idx);
    }
  }
  int q;
  scanf("%d", &q);
  while(q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    --l, --r;
    if(row[r] < l) printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}
