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

string values = "23456789TJQKA";
string suits = "SDCH";
const int HandSize = 5;

struct Card {
  int value;
  int suit;
  friend istream& operator>> (istream& cin, Card& c) {
    string s;
    cin >> s;
    for(int i = 0; i < sz(values); i++)
      if(s[0] == values[i])
        c.value = i + 2;
    for(int i = 0; i < sz(suits); i++)
      if(s.back() == suits[i])
        c.suit = i;
    return cin;
  }
  // friend ostream& operator<< (ostream& cout, const Card& c) {
  //   cout << c.suit << "-"
  //   return cout;
  // }
};

class PokerHand {
  Card cards[HandSize];
  int HighCard() {
    int mx = 0;
    for(int i = 0; i < HandSize; i++)
      mx = max(mx, cards[i].value);
    return mx;
  }
  vector<vector<int>> GetBySuit() {
    vector<vector<int>> s(4);
    for(int i = 0; i < HandSize; i++) {
      s[cards[i].suit].push_back(cards[i].value);
    }
    return s;
  }
  bool RoyalFlush() {
    auto s = GetBySuit();
    for(int i = 0; i < sz(s); i++) {
      sort(all(s[i]));
      int msk = 0;
      for(int v : s[i])
        if(v >= 10)
          msk |= (1 << v - 10);
      if(msk == 31)
        return true;
    }
    return false;
  }
  bool StraightFlush() {
    sort(cards, cards + HandSize, [](const Card&a, const Card& b) {
      return a.value < b.value;
    });
    for(int i = 0; i + 1 < HandSize; i++)
      if(cards[i].suit != cards[i + 1].suit || cards[i].value != cards[i].value - 1)
        return false;
    return true;
  }
  bool FourOfAKing() {
    sort(cards, cards + HandSize, [](const Card&a, const Card& b) {
      return a.value < b.value;
    });
    for(int i = 0; i < HandSize - 3; i++) {
      bool same = true;
      for(int j = 1; j < 4; j++)
        same &= cards[i].value == cards[i + j].value;
      if(same) return true;
    }
    return false;
  }
  bool FullHouse() {
    return OnePair() && ThreeOfAKind();
  }
  bool Flush() {
    sort(cards, cards + HandSize, [](const Card&a, const Card& b) {
      return a.suit < b.suit;
    });
    return cards[0].suit = cards[HandSize - 1].suit;
  }
  bool Straight() {
    sort(cards, cards + HandSize, [](const Card&a, const Card& b) {
      return a.value < b.value;
    });
    bool good = true;
    for(int i = 0; i + 1 < HandSize; i++)
      good &= cards[i].value + 1 == cards[i + 1].value;
    return good;
  }
  bool ThreeOfAKind() {
    sort(cards, cards + HandSize, [](const Card&a, const Card& b) {
      return a.value < b.value;
    });
    return cards[0].value = cards[HandSize - 1].value;
  }
  vector<array<int, 2>> GetPairs() {
    vector<array<int, 2>> pairs;
    for(int i = 0; i < HandSize; i++) {
      for(int j = i + 1; j < HandSize; j++)
        if(cards[i].value == cards[j].value)
          pairs.push_back({i, j});
    }
    return pairs;
  }
  bool TwoPairs() {
    auto pairs = GetPairs();
    for(int i = 0; i < sz(pairs); i++)
      for(int j = i + 1; j < sz(pairs); j++) {
        int i1 = pairs[i][0], j1 = pairs[i][1];
        int i2 = pairs[j][0], j2 = pairs[j][1];
        if(i2 != i1 && i2 != j1 && j2 != i1 && j2 != j1)
          return true;
      }
    return false;
  }
  bool OnePair() {
    auto pairs = GetPairs();
    return sz(pairs);
  }
public:
  int rank, high;
  friend istream& operator>> (istream& cin, PokerHand& h) {
    for(int i = 0; i < HandSize; i++)
      cin >> h.cards[i];
    return cin;
  }
  void Process() {
    high = HighCard();
    rank = 0;
    if(RoyalFlush()) rank = 9;
    if(StraightFlush()) rank = 8;
    if(FourOfAKing()) rank = 7;
    if(FullHouse()) rank = 6;
    if(Flush()) rank = 5;
    if(Straight()) rank = 4;
    if(ThreeOfAKind()) rank = 3;
    if(TwoPairs()) rank = 2;
    if(OnePair()) rank = 1;
  }
  friend ostream& operator<< (ostream& cout, const PokerHand& h) {
    for(int i = 0; i < HandSize; i++)
      cout << h.cards[i].suit << "-" << h.cards[i].value << " ";
    return cout;
  }
};

int check(PokerHand a, PokerHand b) {
  a.Process();
  b.Process();
  cout << a.rank << " " << a.high << " -- " << b.rank << " " << b.high << endl;
  if(a.rank != b.rank) return a.rank > b.rank;
  return a.high > b.high;
}

int main()
{
  int n;
  cin >> n;
  int total = 0;
  PokerHand a, b;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    if(check(a, b)) cout << "Player 1" << endl;
    else cout << "Player 2" << endl;
  }
  return 0;
}
