// We only fail when we stop trying
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

const int N = 100006;

int n;
int arr[N];

void solve() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }
  vector<int> sol {arr[0]};
  for(int i = 1; i < n - 1; i++) {
    if((arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) || (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]))
      sol.push_back(arr[i]);
  }
  sol.push_back(arr[n - 1]);
  printf("%d\n", sz(sol));
  for(int i = 0; i < sz(sol); i++)
    printf("%d%c", sol[i], " \n"[i == sz(sol) - 1]);
}

int main()
{
  int T;
  scanf("%d", &T);
  while(T--)
    solve();
  return 0;
}
