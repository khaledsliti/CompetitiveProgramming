#include <bits/stdc++.h>
using namespace std;

namespace IO {
  const int BUFFER_SIZE = 1 << 15;
  char input_buffer[BUFFER_SIZE];
  int input_pos = 0, input_len = 0;
  
  char output_buffer[BUFFER_SIZE];
  int output_pos = 0;
  
  uint8_t lookup[100];
  
  void _update_input_buffer() {
    input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
    input_pos = 0;
  }
  
  inline char next_char(bool advance = true) {
    if (input_pos >= input_len)
      _update_input_buffer();
    return input_buffer[advance ? input_pos++ : input_pos];
  }
  
  inline bool isspace(char c) {
    return (unsigned char) (c - '\t') < 5 || c == ' ';
  }
  
  template<typename T>
  inline void read_int(T &number) {
    while (isspace(next_char(false)))
      next_char();
    bool negative = next_char(false) == '-';
    if (negative)
      next_char();
    number = 0;
    while (isdigit(next_char(false)))
      number = 10 * number + (next_char() - '0');
    if (negative)
      number = -number;
  }

  inline void read_char(char& ch, bool ignore_space = true) {
    if(ignore_space)
      while (isspace(next_char(false)))
        next_char();
    ch = next_char();
  }
  
  void _flush_output() {
    fwrite(output_buffer, sizeof(char), output_pos, stdout);
    output_pos = 0;
  }
  
  inline void write_char(char c) {
    if (output_pos == BUFFER_SIZE)
      _flush_output();
    output_buffer[output_pos++] = c;
  }
  
  template<typename T>
  inline void write_int(T number, char after = 0) {
    if (number < 0) {
      write_char('-');
      number = -number;
    }
    static char number_buffer[100];
    int length = 0;
    do {
      if (number < 10) {
        number_buffer[length++] = number + '0';
        number = 0;
      } else {
        uint8_t lookup_value = lookup[number % 100];
        number /= 100;
        number_buffer[length++] = (lookup_value & 15) + '0';
        number_buffer[length++] = (lookup_value >> 4) + '0';
      }
    } while (number != 0);
    for (int i = length - 1; i >= 0; i--)
      write_char(number_buffer[i]);
    if (after)
      write_char(after);
  }

  inline void write_string(string& str, char after = 0) {
    for(auto& c : str)
      write_char(c);
    if (after)
      write_char(after);
  }

  inline void write_string(string&& str, char after = 0) {
    for(auto& c : str)
      write_char(c);
    if (after)
      write_char(after);
  }
  
  void init() {
    // Make sure _flush_output() is called at the end of the program.
    bool exit_success = atexit(_flush_output) == 0;
    assert(exit_success);
    for (int i = 0; i < 100; i++)
      lookup[i] = (i / 10 << 4) + i % 10;
  }
}


#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 5;
const int BLOCK_SIZE = 320;

int n, k, q;
int arr[N];
int freq[1 << 20];
long long cur_ans;
long long ans[N];

struct query{
  int l, r, idx, block;
  bool operator<(const query& other) const {
    if(block != other.block)
      return l < other.l;
    return block & 1 ? r < other.r : r > other.r;
  }
} qr[N];

void add(int val)
{
  cur_ans += freq[val ^ k];
  freq[val]++;
}

void del(int val)
{
  freq[val]--;
  cur_ans -= freq[val ^ k];
}

int main()
{
  IO::init();
  IO::read_int(n); IO::read_int(q); IO::read_int(k);
  for(int i = 1 ; i <= n ; i++){
    IO::read_int(arr[i]);
    arr[i] ^= arr[i - 1];
  }
  for(int i = 0 ; i < q ; i++){
    int l, r;
    IO::read_int(l); IO::read_int(r);
    qr[i] = {--l, r, i, l / BLOCK_SIZE};
  }
  sort(qr, qr + q);
  int st = 0, en = -1;
  for(int i = 0 ; i < q ; i++){
    int l = qr[i].l, r = qr[i].r;
    while(st > l) add(arr[--st]);
    while(en < r) add(arr[++en]);
    while(st < l) del(arr[st++]);
    while(en > r) del(arr[en--]);
    ans[qr[i].idx] = cur_ans;
  }
  for(int i = 0 ; i < q ; i++)
    IO::write_int(ans[i], '\n');
  return 0;
}
