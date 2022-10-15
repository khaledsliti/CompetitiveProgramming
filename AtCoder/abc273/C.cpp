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
int ans[N];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);

  int d = 0;
  for(int i = n - 1; i >= 0; i--) {
    int j = i;
    while(j >= 0 && arr[i] == arr[j]) {
      j--;
    }
    ans[d] += i - j;
    d++;
    i = j + 1;
  }

  for(int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
