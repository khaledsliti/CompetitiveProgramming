#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int mod = 1e9 + 7;

long long a, b, m;
long long ans[55];

void solve(long long n)
{
  long long rem = b - (1LL << (n - 2)) * (a + 1);
  vector<long long> val;
  for(long long i = n - 3 ; i >= 0 ; i--){
    long long q = min(m - 1, rem / (1LL << i));
    val.push_back(q + 1);
    rem -= q * (1LL << i);
  }
  val.push_back(rem + 1);
  long long sum = a;
  cout << n << " ";
  cout << a;
  for(int i = 0 ; i < sz(val) ; i++){
    long long cur = sum + val[i];
    cout << " " << cur;
    sum += cur;
  }
  cout << endl;
}

void solve()
{
  cin >> a >> b >> m;
  if(a == b){
    cout << "1 " << a << endl;
    return;
  }
  for(long long n = 2 ; (1LL << (n - 2)) * (a + 1LL) <= b ; n++){
    if(b >= (1LL << (n - 2)) * (a + 1LL) && b <= (1LL << (n - 2)) * (a + m)){
      solve(n);
      return;
    }
  }
  cout << "-1\n";
}

int main()
{
  int q;
  cin >> q;
  while(q--)
    solve();
  return 0;
}
