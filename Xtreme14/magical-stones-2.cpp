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
    Matrix R(n, n, T());
    for(int i = 0; i < R.N(); i++)
      R[i][i] = 1;
    return R;
  }
  friend Matrix operator+ (const Matrix& A, const Matrix& B) {
    Matrix R(A.N(), B.M());
    for(int i = 0; i < R.N(); i++)
      for(int j = 0; j < R.M(); j++)
        R[i][j] = A[i][j] + B[i][j];
    return R;
  }
  friend Matrix operator* (const Matrix& A, const Matrix& B) {
    Matrix R(A.n, B.m);
    for(int i = 0; i < R.n; i++)
      for(int j = 0; j < R.m; j++) {
        R[i][j] = T();
        for(int k = 0; k < A.m; k++)
          R[i][j] = (R[i][j] + A[i][k] * B[k][j]);
      }
    return R;
  }
  friend Matrix operator^ (const Matrix& A, long long p) {
    if(!p) return Matrix::identity(A.n);
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

const int N = 101;


int main()
{
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    Matrix<int> src = Matrix<int>::identity(n);
    Matrix<int> W(n, n, 0), B(n, n, 0);
    for(int i = 0; i < n; i++) {
      int x; cin >> x;
      W[i][--x] = 1;
    }
    for(int i = 0; i < n; i++) {
      int x; cin >> x;
      B[i][--x] = 1;
    }
    queue<Matrix<int>> q;
    q.push(src);
    while(q.empty() == false) {
      auto m = q.front(); q.pop();
      q.push(m * B);
      q.push(m * W);
    }
  }
  return 0;
}
