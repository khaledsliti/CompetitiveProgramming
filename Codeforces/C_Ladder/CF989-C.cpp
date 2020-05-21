// We only fail when we stop trying
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define D(x) cerr << #x << " = " << (x) << '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

char s[50][50];

void populate(int r, int c, int tot, char ch) {
  for(int i = r ; tot > 0 ; i += 2) {
    for(int j = 0 ; j < 12 && tot > 0 ; j++) {
      s[i][c + 2 * j] = ch;
      tot--;
    }
  }
}

int main()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  for(int i = 0 ; i < 25 ; i++)
    for(int j = 0 ; j < 25 ; j++)
      s[i][j] = 'A';
  for(int i = 25 ; i < 50 ; i++)
    for(int j = 0 ; j < 25 ; j++)
      s[i][j] = 'B';
  for(int i = 0 ; i < 25 ; i++)
    for(int j = 25 ; j < 50 ; j++)
      s[i][j] = 'C';
  for(int i = 25 ; i < 50 ; i++)
    for(int j = 25 ; j < 50 ; j++)
      s[i][j] = 'D';
  populate(1, 1, b - 1, 'B');
  populate(26, 1, a - 1, 'A');
  populate(1, 26, d - 1, 'D');
  populate(26, 26, c - 1, 'C');
  cout << "50 50\n";
  for(int i = 0 ; i < 50 ; i++) {
    for(int j = 0 ; j < 50 ; j++)
      cout << s[i][j];
    cout << endl;
  }
  return 0;
}
