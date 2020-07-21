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
 
 
const ll Inf = 2e18;
 
 
template <typename T>
class Matrix {
  int n, m;
  vector<vector<T>> mat;
public:
  Matrix(int n): n(n), m(n) { mat.resize(n, vector<T>(m, T())); }
  Matrix(int n, int m): n(n), m(m) { mat.resize(n, vector<T>(m, T())); }
  Matrix(int n, int m, T v): n(n), m(m) { mat.resize(n, vector<T>(m, v)); }
  const vector<T>& operator[](int r) const { return mat[r]; }
  vector<T>& operator[](int r) { return mat[r]; }
  inline int N() { return n; }
  inline int M() { return m; }
  T trace() const {
    T r = T();
    for(int i = 0; i < n; i++)
      r = r + mat[i][i];
    return r;
  }
  Matrix rotate() const {
    Matrix R(m, n, T());
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        R[j][n - 1 - i] = mat[i][j];
    return R;
  }
  Matrix reflect() const {
    Matrix R(n, m);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        R[i][m - 1 - j] = mat[i][j];
    return R;
  }
  static Matrix identity(int n) {
    Matrix R(n, n, Inf);
    // for(int i = 0; i < R.N(); i++)
    //   R[i][i] = 0;
    return R;
  }
  friend Matrix operator* (const Matrix& A, const Matrix& B) {
    Matrix R(A.n, B.m);
    for(int i = 0; i < R.n; i++)
      for(int j = 0; j < R.m; j++) {
        R[i][j] = Inf;
        for(int k = 0; k < A.m; k++)
          R[i][j] = min(R[i][j], A[i][k] + B[k][j]);
      }
    return R;
  }
  friend Matrix operator^ (const Matrix& A, long long p) {
    if(p == 1) return A;
    if(p == 2) return A * A;
    if(p & 1) return A * (A ^ (p - 1));
    return (A * A) ^ (p >> 1);
  }
  friend ostream& operator<<(ostream& cout, const Matrix& A) {
    for(int i = 0; i < A.n; i++) {
      for(int j = 0; j < A.m; j++)
        cout << A.mat[i][j] << ' ';
      cout << '\n';
    }
    return cout;
  }
};
 
const int N = 105;
 
 
int n;
Matrix<ll> g(N);
 
int main()
{
  int m, k;
  cin >> n >> m >> k;
  g = Matrix<ll>::identity(n);
  while(m--) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    g[a][b] = min(g[a][b], (ll)c);
  }
  g = g ^ k;
  ll ans = g[0][n - 1];
  if(ans >= Inf) ans = -1;
  cout << ans << endl;
  return 0;
}