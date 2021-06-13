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

const int N = 2e5 + 5;

int n;
int arr[N];

void solve() {
  scanf("%d", &n);
  int sum = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", arr + i);
    sum += arr[i];
  }
  if(sum % n != 0) {
    printf("-1\n");
    return;
  }
  int l = 0, g = 0, need = sum / n;
  for(int i = 0; i < n; i++) {
    l += arr[i] > need;
  }
  cout << l << endl;
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--) {
    solve();
  }
  return 0;
}
