// Guess Who's Back
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
  if(n * 108 / 100 < 206) cout << "Yay!" << endl;
  else if(n * 108 / 100 == 206) cout << "so-so" << endl;
  else cout << ":(" << endl;
  return 0;
}
