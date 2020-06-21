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

const int N = 2e5 + 5;

int n;
int arr[N];

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  ll sum = 0;
  for(int i = 1; i < n; i++) {
    sum += max(0, arr[i - 1] - arr[i]);
    arr[i] = max(arr[i], arr[i - 1]);
  }
  cout << sum << endl;
  return 0;
}
