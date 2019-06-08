/********************************************************************************************************
  Author: RedStone

  Problem link:
    https://atcoder.jp/contests/arc064/tasks/arc064_b

  Idea:
    First observation: if the string contains at 3 distinct characters or greater then the current player can always move.
    We are sure that we can find three distinct consecutive characters, so we can remove the one in the middle.
    Second Observation: if the first character and last character are equal and the length of the given string is even,
    then the current play can always move.
    Proof: the only case where the player can not move is when the string is in the form abab..,
    so if the length is odd and the first is the last then we are sure that the string contains at least three distinct characters.
    Lemma: If the conditions of the second observation are met the first player will win.
    Here it is easy to prove that because after two turns the same conditions are met so the first player can always move.
    Third observation: if the first and the last characters are not the same, then the first player wins if and only if the length of the string is odd.
    If these conditions are met then the string will contain at least three distinct characters

  Complexity:
    Time: O(N)
    Memory: O(N)
********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int main()
{
  string s;
  while(cin >> s){
    char a = s[0];
    char b = s[s.size() - 1];
    int n = s.size();
    if ((a == b && n % 2 == 0) || (a != b && n % 2 == 1))
      cout << "First" << endl;
    else
      cout << "Second" << endl;
  }
  return 0;
}
