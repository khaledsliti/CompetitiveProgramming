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
  sort(arr, arr + n);
  ll ans = 0;
  priority_queue<int> pq;
  pq.push(arr[n - 1]);
  for(int i = n - 2; i >= 0; i--) {
    ans += pq.top();
    pq.pop();
    pq.push(arr[i]);
    pq.push(arr[i]);
  }
  cout << ans << endl;
  return 0;
}
