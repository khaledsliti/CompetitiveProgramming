// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int n;
vector<pair<int, int>> A, B, Z;

int main()
{
  cin >> n;
  for(int i = 0 ; i < n ; i++) {
    int a;
    cin >> a;
    if(a > 0) A.pb({a, i + 1});
    else if(a == 0) Z.pb({a, i + 1});
    else B.pb({a, i + 1});
  }
  sort(all(B));
  if(sz(B) & 1) Z.push_back(B.back()), B.pop_back();
  for(int i = 1 ; i < sz(Z) ; i++)
    cout << "1 " << Z[i].second << " " << Z[0].second << endl;
  for(int i = 0 ; i < sz(B) ; i++)
    A.pb(B[i]);
  if(sz(Z) && sz(A))
    cout << "2 " << Z[0].second << endl;
  for(int i = 1 ; i < sz(A) ; i++)
    cout << "1 " << A[i].second << " " << A[0].second << endl;
  return 0;
}
