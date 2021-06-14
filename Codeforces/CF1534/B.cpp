// Guess Who's Back
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

const int N = 4e5 + 5;

int n;
int arr[N];

void solve() {
  scanf("%d", &n);
  arr[0] = arr[n + 1] = 0;
  for(int i = 1; i <= n; i++) {
    scanf("%d", arr + i);
  }
  long long score = 0;
  for(int i = 1; i <= n; i++) {
    int a = max(arr[i - 1], arr[i + 1]);
    if(arr[i] > a) {
      score += arr[i] - a;
      arr[i] = a;
    }
  }
  for(int i = 0; i <= n; i++) {
    score += abs(arr[i] - arr[i + 1]);
  }
  cout << score << endl;
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
