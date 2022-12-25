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

// Region Debug
string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

template <typename A, typename B>
string to_string(const pair<A, B>& p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename T>
string to_string(const vector<T>& v) {
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (i > 0) res += ", ";
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(const pair<A, B>& p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
// End Region

const int Mod = 1e9 + 7;

template <typename T>
struct Matrix {
  int n, m;
  vector<vector<T>> mat;
  void Init(int n, int m) {
    this->n = n;
    this->m = m;
    mat.resize(n, vector<T>(m, T()));
  }
  const vector<T>& operator[](int r) const { return mat[r]; }
  vector<T>& operator[](int r) { return mat[r]; }
  inline int N() { return n; }
  inline int M() { return m; }
  T trace() const {
    T r = T();
    for (int i = 0; i < n; i++) r = r + mat[i][i];
    return r;
  }
  Matrix rotate() const {
    Matrix R;
    R.Init(m, n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) R[j][n - 1 - i] = mat[i][j];
    return R;
  }
  Matrix reflect() const {
    Matrix R(n, m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) R[i][m - 1 - j] = mat[i][j];
    return R;
  }
  static Matrix identity(int n) {
    Matrix R(n, n, T());
    for (int i = 0; i < R.N(); i++) R[i][i] = 1;
    return R;
  }
  friend Matrix operator+(const Matrix& A, const Matrix& B) {
    Matrix R(A.N(), B.M());
    for (int i = 0; i < R.N(); i++)
      for (int j = 0; j < R.M(); j++)
        R[i][j] = A[i][j] + B[i][j], R[i][j] %= Mod;
    return R;
  }
  friend Matrix operator*(const Matrix& A, const Matrix& B) {
    Matrix R(A.n, B.m);
    for (int i = 0; i < R.n; i++)
      for (int j = 0; j < R.m; j++) {
        R[i][j] = T();
        for (int k = 0; k < A.m; k++)
          R[i][j] = (R[i][j] + A[i][k] * B[k][j]) % Mod;
      }
    return R;
  }
  friend Matrix operator^(const Matrix& A, long long p) {
    if (!p) return Matrix::identity(A.n);
    if (p & 1) return A * (A ^ (p - 1));
    return (A * A) ^ (p >> 1);
  }
  friend ostream& operator<<(ostream& cout, const Matrix& A) {
    for (int i = 0; i < A.n; i++) {
      for (int j = 0; j < A.m; j++) cout << A.mat[i][j] << ' ';
      cout << '\n';
    }
    return cout;
  }
  void print() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << mat[i][j] << " ";
      }
      cout << endl;
    }
  }
};

bool check(vector<pair<int, int>> arr) {
  sort(all(arr));
  for (int j = 1; j < sz(arr); j++) {
    if (arr[j - 1].second > arr[j].first) {
      return false;
    }
  }
  return true;
}

bool check(Matrix<int> mat) {
  for (int i = 0; i < mat.n; i++) {
    vector<int> ids;
    for (int j = 0; j < mat.m; j++) {
      if (mat[i][j] == 0) continue;
      ids.push_back(mat[i][j]);
    }
    sort(all(ids));
    ids.resize(unique(all(ids)) - begin(ids));
    for (int j = 0; j < mat.m; j++) {
      mat[i][j] = lower_bound(all(ids), mat[i][j]) - begin(ids);
    }
  }

  // mat.print();

  vector<pair<int, int>> cols;
  for (int j = 0; j < mat.m; j++) {
    int mn = INT_MAX, mx = 0;
    for (int i = 0; i < mat.n; i++) {
      mn = min(mn, mat[i][j]);
      mx = max(mx, mat[i][j]);
    }
    cols.push_back({mn, mx});
  }

  return check(cols);
}

Matrix<int> mat;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  mat.Init(n, m);
  for (int i = 0; i < mat.n; i++) {
    for (int j = 0; j < mat.n; j++) {
      cin >> mat[i][j];
    }
  }

  for (int it = 0; it < 2; it++) {
    if (!check(mat)) {
      cout << "No" << endl;
      return 0;
    }
    mat = mat.rotate();
  }

  vector<pair<int, int>> rows;
  for (int i = 0; i < n; i++) {
    int mn = INT_MAX, mx = 0;
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == 0) continue;
      mn = min(mn, mat[i][j]);
      mx = max(mx, mat[i][j]);
    }
    rows.push_back(mp(mn, mx));
  }

  if (!check(rows)) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;

  return 0;
}
