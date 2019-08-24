#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 505;

int n;
int arr[N][N];

void solve(int l, int r, int c)
{
  if(r - l + 1 <= 1)
    return;
  int mid = (l + r) / 2;
  for(int i = l ; i <= mid ; i++){
    for(int j = mid + 1 ; j <= r; j++){
      arr[i][j] = c;
    }
  }
  solve(l, mid, c + 1);
  solve(mid + 1, r, c + 1);
}

int main()
{
  cin >> n;
  solve(1, n, 1);
  for(int i = 1 ; i <= n ; i++){
    for(int j = i + 1; j <= n ; j++)
      cout << arr[i][j] << " ";
    cout << endl;
  }
  return 0;
}
