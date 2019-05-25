#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;

int n, m;
int A[N];
pair<int, int> BC[N];

int main()
{
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++){
    cin >> A[i];
  }
  sort(A, A + n);
  for(int i = 0 ; i < m ; i++)
    cin >> BC[i].second >> BC[i].first;
  sort(BC, BC + m);
  int idx = 0;
  long long ans = 0;
  for(int i = m - 1 ; i >= 0 ; i--){
    int cur = BC[i].first;
    int cnt = BC[i].second;
    while(idx < n && A[idx] < cur && cnt > 0){
      A[idx++] = cur;
      cnt--;
    }
  }
  for(int i = 0 ; i < n ; i++)
    ans += A[i];
  cout << ans << endl;
  return 0;
}