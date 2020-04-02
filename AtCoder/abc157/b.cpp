// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int A[3][3];
set<int> s;

bool check(int a, int b, int c) {
  return s.find(a) != s.end() && s.find(b) != s.end() && s.find(c) != s.end();
}

int main()
{
  for(int i = 0 ; i < 3 ; i++) {
    for(int j = 0 ; j < 3 ; j++)
      cin >> A[i][j];
  }
  int n;
  cin >> n;
  for(int i = 0 ; i < n ; i++) {
    int a; cin >> a;
    s.insert(a);
  }
  for(int i = 0 ; i < 3 ; i++) {
    if(check(A[i][0], A[i][1], A[i][2]) || check(A[0][i], A[1][i], A[2][i]))
      return cout << "Yes" << endl, 0;
  }
  if(check(A[0][0], A[1][1], A[2][2]) || check(A[0][2], A[1][1], A[2][0]))
    return cout << "Yes" << endl, 0;
  cout << "No" << endl;
  return 0;
}
