#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

template<class T>
class Matrix{
  vector<vector<T>> mat;
public:
  Matrix(int r, int c){
    mat.resize(r, vector<T>(c, T()));
  }
  Matrix(int r, int c, T v){
    mat.resize(r, vector<T>(c, v));
  }
  Matrix(vector<vector<T>> mat){
    this->mat = mat;
  }
  const vector<T>& operator[](const int& i) const {
    return mat[i];
  }
  vector<T>& operator[](const int& i) {
    return mat[i];
  }
  Matrix& operator=(const Matrix& rhs) {
    this->mat = rhs.mat;
    return *this;
  }
  Matrix& operator=(vector<vector<T>> v) {
    this->mat = v;
    return *this;
  }
  Matrix operator+(const Matrix& rhs) const {
    Matrix sum(rhs.get_r(), rhs.get_c());
    for(int i = 0; i < get_r(); i++)
      for(int j = 0; j < get_c(); j++)
        sum[i][j] = mat[i][j] + rhs[i][j];
    return sum;
  }
  Matrix operator*(const Matrix& rhs) const {
    Matrix prod(get_r(), rhs.get_c());
    for(int i = 0; i < get_r(); i++)
      for(int j = 0; j < rhs.get_c(); j++){
        prod[i][j] = T();
        for(int k = 0 ; k < get_c() ; k++)
          prod[i][j] += mat[i][k] * rhs[k][j];
      }
    return prod;
  }
  Matrix operator^(long long p) const {
    Matrix a = *this;
    Matrix res(a.get_r(), a.get_c());
    for(int i = 0 ; i < get_r() ; i++)
      res[i][i] = 1;
    while(p){
      if(p & 1) res = res * a;
      a = a * a;
      p >>= 1;
    }
    return res;
  }
  int get_r() const {
    return this->mat.size();
  }
  int get_c() const {
    return this->mat[0].size();
  }
};

template<class T>
ostream& operator<<(ostream& cout, const Matrix<T>& mat){
  for(int i = 0 ; i < mat.get_r() ; i++){
    for(int j = 0 ; j < mat.get_c() ; j++)
      cout << mat[i][j] << " ";
    cout << endl;
  }
  return cout;
}

int main()
{
  int T, tc(1);
  cin >> T;
  while(T--){
    int n;
    string alp, s;
    cin >> n >> alp >> s;
    vector<int> f(s.size(), 0);
    for(int i = 1, k = 0; i < sz(s) ; i++){
      while(k > 0 && s[k] != s[i])
        k = f[k - 1];
      if(s[i] == s[k])
        ++k;
      f[i] = k;
    }
    Matrix<unsigned> mat(s.size(), s.size(), 0);
    for(int i = 0 ; i < sz(s) ; i++){
      for(int j = 0 ; j < sz(alp) ; j++){
        char c = alp[j];
        int k = i;
        while(k > 0 && s[k] != c)
          k = f[k - 1];
        if(s[k] == c)
          ++k;
        if(k < sz(s))
          mat[i][k]++;
      }
    }
    mat = (mat ^ n);
    unsigned ans = 0;
    for(int i = 0 ; i < sz(s) ; i++)
      ans += mat[0][i];
    printf("Case %d: %u\n", tc++, ans);
  }
  return 0;
}
