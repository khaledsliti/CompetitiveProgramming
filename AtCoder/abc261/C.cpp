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



int main()
{
  int n;
  cin >> n;
  map<string, int> cnt;
  for(int i = 0; i <n ;i++) {
    string s; cin >> s;
    cnt[s]++;
    cout << s;
    if(cnt[s] > 1) {
      cout << "(" << cnt[s] - 1 << ")";
    }
    cout << endl;
  }
  return 0;
}
