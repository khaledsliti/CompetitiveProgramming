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

const int N = 1e7 + 5;
int isp[N];

int main()
{
  int cnt = 0, last = -1;
  for(int i = 2; i < N && cnt <= 1e4; i++) {
    if(!isp[i]) {
      cnt++;
      last = i;
      for(int j = i * 2 ; j < N ; j += i)
        isp[j] = 1;
    }
  }
  cout << last << endl;
  return 0;
}
