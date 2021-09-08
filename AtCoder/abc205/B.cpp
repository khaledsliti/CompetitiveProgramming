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

int main()
{
  int n; cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(all(arr));
  for(int i = 0; i < n; i++) {
    if(arr[i] != i + 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
