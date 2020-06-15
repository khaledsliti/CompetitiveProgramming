// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 2e5 + 5;

int n, r;
int sol[N];
array<int, 3> cus[N];

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    cus[i] = {a, b, i};
  }
  sort(cus, cus + n);
  r = 0;
  set<pair<int, int>> room;
  for(int i = 0; i < n; i++) {
    int idx = cus[i][2];
    int a =  cus[i][0], b = cus[i][1];
    if(room.empty() || room.begin()->first > a)
      room.insert({0, ++r});
    int t = room.begin()->second;
    sol[idx] = t;
    room.erase(room.begin());
    room.insert({b + 1, t});
  }
  cout << r << endl;
  for(int i = 0; i < n; i++)
    cout << sol[i] << " ";
  cout << endl;
  return 0;
}
