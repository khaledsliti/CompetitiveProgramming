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
const int L = 21;

int n, l[N];
vector<int> arr;
int sp[N][L];

void precompute()
{
    l[1] = 0;
    for(int i=2;i<=n;i++)
        l[i] = 1 + l[i/2];
    for(int i=0;i<n;i++){
        sp[i][0] = arr[i];
    }
    for(int j = 1 ; j <= l[n] ; j++)
        for(int i = 0; i+(1<<j) <= n ; i++){
            sp[i][j] = __gcd(sp[i][j-1], sp[i+(1<<(j-1))][j-1]);
        }
}

int GCD(int s,int e)
{
    int Log = l[e-s+1];
    return __gcd(sp[s][Log], sp[e-(1<<Log)+1][Log]);
}

int d[N], dn;

void div(int x) {
  dn = 0;
  for(int a = 1; a <= sqrt(x); a++) {
    if(x % a == 0) {
      d[dn++] = a;
      if(x / a != a) {
        d[dn++] = x / a;
      }
    }
  }
}


int main()
{
  cin >> n;
  arr.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  precompute();
  int at = 0;
  int ans = 0;
  vector<int> sol(n);
  for(int i = 0; i < n; i++) {
    div(arr[i]);
    bool ok = true;
    for(int j = 0; j < dn && ok; j++) {
      if(i - d[j] + 1 >= at && GCD(i - d[j] + 1, i) == d[j]) {
        ok = false;
      }
    }
    if(!ok) {
      ans++;
      at = i + 1;
    }
    sol[i] = ans;
  }
  for(int x: sol) cout << x << " ";
  cout << endl;
  return 0;
}
