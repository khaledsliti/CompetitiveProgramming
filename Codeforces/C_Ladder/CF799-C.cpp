// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n, a, b;
vector<array<int, 3>> A[2];

int solve(vector<array<int, 3>>& arr, int cost) {
  int best = 0;
  for(int i = 0 ; i < sz(arr) ; i++) {
    int idx = lower_bound(begin(arr), begin(arr) + i, array<int, 3>{cost - arr[i][0] + 1, 0, 0}) - begin(arr);
    if(idx > 0)
      best = max(best, arr[i][1] + arr[idx - 1][2]);
  }
  return best;
}

int main()
{
  scanf("%d%d%d", &n, &a, &b);
  for(int i = 0 ; i < n ; i++) {
    int b, c;
    char t;
    scanf("%d%d %c", &b, &c, &t);
    if(t == 'C') A[0].push_back({c, b, b});
    else A[1].push_back({c, b, b});
  }
  for(int it = 0 ; it < 2 ; it++) {
    sort(all(A[it]));
    for(int i = 1 ; i < sz(A[it]) ; i++) {
      A[it][i][2] = max(A[it][i - 1][2], A[it][i][2]);
    }
  }
  int best = 0;
  for(int i = sz(A[0]) - 1 ; i >= 0 ; i--) {
    if(A[0][i][0] <= a) {
      for(int j = sz(A[1]) - 1 ; j >= 0 ; j--) {
        if(A[1][j][0] <= b) {
          best = A[0][i][2] + A[1][j][2];
          break;
        }
      }
      break;
    }
  }
  for(int i = 0 ; i < 2 ; i++)
    best = max(best, solve(A[i], i == 0 ? a : b));
  cout << best << endl;
  return 0;
}
