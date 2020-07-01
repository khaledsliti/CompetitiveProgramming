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

const int N = 200009;

int n;
int a[N], b[N];

int main()
{
  cin >> n;
  int x = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    x ^= a[i];
  }
  for(int i = 0; i < n; i++)
    cout << (x ^ a[i]) << " ";
  cout << endl;
  return 0;
}
