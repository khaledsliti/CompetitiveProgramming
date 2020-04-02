// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 5;

int n, k;
int arr[N];

int main()
{
  cin >> k >> n;
  for(int i = 0 ; i < n ; i++)
    cin >> arr[i];
  int best = arr[n - 1] - arr[0];
  for(int i = 0 ; i < n - 1; i++) {
    best = min(best, arr[i] + k - arr[i + 1]);
  }
  cout << best << endl;
  return 0;
}
