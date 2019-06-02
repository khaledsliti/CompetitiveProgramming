#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 3e5 + 5;

int n;
int a[N], b[N];
vector<int> A, B;

int main()
{
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++){
    scanf("%d%d", a + i, b + i);
    if(a[i] < b[i]) A.pb(i);
    else B.pb(i);
  }
  sort(A.begin(), A.end(), [&](int i, int j){ return b[i] > b[j]; });
  sort(B.begin(), B.end(), [&](int i, int j){ return b[i] < b[j]; });
  vector<int>& ans = sz(A) > sz(B) ? A : B;
  printf("%d\n", sz(ans));
  for(int i = 0 ; i < sz(ans) ; i++)
    printf("%d ", ans[i] + 1);
  return 0;
}