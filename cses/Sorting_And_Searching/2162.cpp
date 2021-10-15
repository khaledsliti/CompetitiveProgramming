// RedStone
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int N = 2e5 + 5;

void solve(vector<int> arr, int first) {
  if(!sz(arr)) {
    return;
  }
  vector<int> rem;
  int last;
  for(int i = 0; i < sz(arr); i++) {
    if(i >= first && (i - first) % 2 == 0) {
      cout << arr[i] + 1 << " ";
      last = true;
    } else {
      rem.push_back(arr[i]);
      last = false;
    }
  }
  solve(rem, last);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++) {
    arr[i] = i;
  }
  solve(arr, 1);
  return 0;
}
