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



int main()
{
  int n;
  cin >> n;
  vector<vector<long long>> arr(n, vector<long long>(n, 0));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= i; j++) {
      if(j == 0 || j == i) arr[i][j] = 1;
      else arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
