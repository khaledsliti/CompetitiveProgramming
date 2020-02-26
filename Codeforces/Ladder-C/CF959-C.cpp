// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;

int n;

int main()
{
  cin >> n;
  if(n < 6){
    cout << -1 << endl;
  }else{
    cout << "1 2\n1 3\n1 4\n";
    for(int i = 5 ; i <= n ; i++)
      cout << "2 " << i << endl;
  }
  for(int i = 2 ; i <= n ; i++)
    cout << i - 1 << " " << i << endl;
  return 0;
}
