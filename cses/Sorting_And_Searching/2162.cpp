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
int nxt[N];

int getNext(int i) {
  int j = (i + 1) % n;
  if(nxt[i] == j || nxt[i] == i) {
    return nxt[i];
  }
  return nxt[i] = nxt[j];
}

int main()
{
  cin >> n;
  for(int i = 0; i < n - 1; i++) {
    nxt[i] = i + 1;
  }
  nxt[n - 1] = 0;
  int cur = 1;
  for(int i = 0; i < n - 1; i++) {
    cout << cur + 1 << " ";
    nxt[cur] = nxt[(cur + 1) % n];
    cur = (cur + 2) % n;
  }
  cout << cur + 1 << endl;
  return 0;
}
