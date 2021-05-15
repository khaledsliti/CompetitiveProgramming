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
  int n;
  cin >> n;
  vector<pair<int, string>> arr;
  for(int i = 0; i < n; i++) {
    string a; int b;
    cin >> a >> b;
    arr.push_back({b, a});
  }
  sort(all(arr));
  cout << arr[n - 2].second << endl;
  return 0;
}
