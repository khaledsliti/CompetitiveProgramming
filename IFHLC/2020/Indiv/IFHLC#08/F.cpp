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

vector<string> notes = { "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#" };
vector<int> steps = { 2, 2, 1, 2, 2, 2 };

vector<set<string>> sets;

void createSets() {
  for(int i = 0; i < sz(notes); i++) {
    sets.push_back({notes[i]});
    int cur = i;
    for(int j = 0; j < sz(steps); j++) {
      cur = (cur + steps[j]) % sz(notes);
      sets.back().insert(notes[cur]);
    }
  }
}

int main()
{
  set<string> cur;
  int t;
  cin >> t;
  while(t--) {
    string tmp;
    cin >> tmp;
    cur.insert(tmp);
  }

  createSets();

  vector<string> sol;
  for(int i = 0; i < sz(sets); i++) {
    bool good = true;
    for(auto note : cur) {
      if(sets[i].find(note) == sets[i].end()) {
        good = false;
        break;
      }
    }
    if(good) sol.push_back(notes[i]);
  }
  
  if(sz(sol)) {
    for(int i = 0; i < sz(sol); i++) {
      if(i > 0) cout << " ";
      cout << sol[i];
    }
    cout << endl;
  } else {
    cout << "none" << endl;
  }

  return 0;
}
