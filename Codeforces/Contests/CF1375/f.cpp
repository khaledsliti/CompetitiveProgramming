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

ll v[3], idx[3];

int main()
{
  for(int i = 0; i < 3; i++) {
    cin >> v[i];
    idx[i] = i;
  }
  sort(idx, idx + 3, [&](int a, int b) {
    return v[a] < v[b];
  });
  cout << "First" << endl;
  cout.flush();

repeat:
  cout << 2 * v[idx[2]] - v[idx[1]] - v[idx[0]] << endl; // 2 c - a - b
  cout.flush();

  int i; cin >> i;
  --i;
  if(i == idx[0]) { // 2c-b   b   c
    // c - b
    cout << v[idx[2]] - v[idx[1]] << endl;
    cout.flush();

    int r;
    cin >> r;
    assert(r == 0);
  } else if(i == idx[1]) {
    cout << v[idx[2]] - v[idx[0]] << endl;
    cout.flush();

    int r;
    cin >> r;
    assert(r == 0);
  } else {
    v[idx[2]] = 3 * v[idx[2]] - v[idx[0]] - v[idx[1]];
    goto repeat;
  }
  return 0;
}
