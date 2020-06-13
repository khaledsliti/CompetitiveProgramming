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

const int N = 301;

int n, m, rot;
int arr[N][N];

void solve(int r1, int c1, int r2, int c2) {
  if(r1 > r2 || c1 > c2) return;
  vector<int> val;
  for(int i = c1; i < c2; i++)
    val.push_back(arr[r1][i]);
  for(int i = r1; i < r2; i++)
    val.push_back(arr[i][c2]);
  for(int i = c2; i > c1; i--)
    val.push_back(arr[r2][i]);
  for(int i = r2; i > r1; i--)
    val.push_back(arr[i][c1]);
  vector<int> tmp;
  for(int i = 0; i < sz(val); i++)
    tmp.push_back(val[(i + rot) % sz(val)]);
  reverse(all(tmp));
  for(int i = c1; i < c2; i++)
    arr[r1][i] = tmp.back(), tmp.pop_back();
  for(int i = r1; i < r2; i++)
    arr[i][c2] = tmp.back(), tmp.pop_back();
  for(int i = c2; i > c1; i--)
    arr[r2][i] = tmp.back(), tmp.pop_back();
  for(int i = r2; i > r1; i--)
    arr[i][c1] = tmp.back(), tmp.pop_back();
  solve(r1 + 1, c1 + 1, r2 - 1, c2 - 1);
}

int main()
{
  cin >> n >> m >> rot;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> arr[i][j];
  solve(0, 0, n - 1, m - 1);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++)
      cout << arr[i][j] << " ";
    cout << endl;
  }
  return 0;
}
