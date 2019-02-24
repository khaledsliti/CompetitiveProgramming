/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://codeforces.com/contest/1109/problem/B

  Idea:
    If all letter of the string are the same (except the middle if its length is odd) so we have no solution.
    Otherwise, we can find a solution by performing at most two operations.
    Let's say that the given string is the following format: a...b.......b...a, where a and b are different characters
    So we can cut this string after the first b and befor the last b (a...b | ... | b...a), 
    and one possible solution can be (b...a + ... + b...a)
    Finally, we need to check if we can find a solution with only one operation and we can do it in O(N^2).

  Compexity:
    Time: O(N^2)
    Memory: O(N)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
typedef long long ll;

const int p = 1e9 + 7;
const int N = 5005;
const int base = 26;

int n;
string s;

int main()
{
  cin >> s;
  n = sz(s);
  int pos = 0;
  for(int i = 1 ; i < n / 2 && !pos ; i++){
    if(s[i] != s[0])
      pos = 1;
  }

  if(!pos)
    return cout << "Impossible" << endl, 0;

  for(int i = 1 ; i < n ; i++){
    string a = s.substr(0, i);
    string b = s.substr(i, n - i);
    string r = b + a;
    string rr = r;
    reverse(rr.begin(), rr.end());
    if(r != s && r == rr)
      return cout << 1 << endl, 0;
  }

  cout << 2 << endl;
  return 0;
}
