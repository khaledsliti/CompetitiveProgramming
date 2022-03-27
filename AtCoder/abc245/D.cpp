// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

const int N = 301;

int n, m;
long long A[N];
long long C[N + N];
long long B[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for(int i = 0; i <= n; i++) {
    cin >> A[i];
  }
  for(int i = 0; i <= n + m; i++) {
    cin >> C[i];
  }

  for(int i = m; i >= 0; i--) {
    B[i] = C[n + i];
    for(int j = i + 1; j <= m; j++) {
      B[i] -= B[j] * A[n + i - j];
    }
    B[i] /= A[n];
  }

  for(int i = 0; i <= m; i++) {
    cout << B[i] << " ";
  }
  cout << endl;
  return 0;
}
