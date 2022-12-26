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

const int Mod = 1e9 + 7;
const int N = 1e5 + 5;

int n;
int x[N], k[N];

int mpow(int a, int b, int mod) {
  if (!b) {
    return 1;
  }
  int r = mpow(a, b >> 1, mod);
  r = (1LL * r * r) % mod;
  if (b & 1) {
    r = (1LL * r * a) % mod;
  }
  return r;
}

int inverse(int a, int mod) {
  if (a == 1) {
    return 1;
  }
  return (mod - (1LL * (mod / a) * inverse(mod % a, mod)) % mod + mod) % mod;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> k[i];
  }

  int numDiv = 1;
  for (int i = 0; i < n; i++) {
    numDiv = 1LL * numDiv * (k[i] + 1) % Mod;
  }
  cout << numDiv << " ";

  int sumDiv = 1;
  for (int i = 0; i < n; i++) {
    sumDiv = (1LL * sumDiv * (mpow(x[i], k[i] + 1, Mod) - 1) % Mod) % Mod;
    sumDiv = 1LL * sumDiv * inverse(x[i] - 1, Mod) % Mod;
  }
  if (sumDiv < 0) {
    sumDiv += Mod;
  }
  cout << sumDiv << " ";

  int found = 0;
  int p = 1;
  for (int i = 0; i < n; i++) {
    int e = k[i] + 1;
    if (e % 2 == 0 && !found) {
      found = 1;
      e /= 2;
    }
    p = (1LL * p * e) % (Mod - 1);
  }
  if (!found) {
    for (int i = 0; i < n; i++) {
      k[i] >>= 1;
    }
  }
  int number = 1;
  for (int i = 0; i < n; i++) {
    number = 1LL * number * mpow(x[i], k[i], Mod) % Mod;
  }
  int prodDiv = mpow(number, p, Mod);
  cout << prodDiv << endl;

  return 0;
}
