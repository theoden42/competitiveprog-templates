#include <bits/stdc++.h>
using namespace std;

template<int ALPHABET = 2>
struct bit_trie {
  struct trie_node {
    array<int, ALPHABET> child;
    int words_here = 0, starting_with = 0;

    trie_node() {
      memset(&child[0], -1, ALPHABET * sizeof(int));
    }
  };

  static const int ROOT = 0, NUM_LEN = 31;

  vector<trie_node> nodes = {trie_node()};

  bit_trie(int total_length = -1) {
    if(total_length >= 0) {
      nodes.reserve(total_length);
    }
  }

  int get_or_create_child(int node, int c) {
    if(nodes[node].child[c] < 0) {
      nodes[node].child[c] = int(nodes.size());
      nodes.emplace_back();
    }

    return nodes[node].child[c];
  }

  int build(int num, int delta) {
    int node = ROOT;

    for(int i = NUM_LEN - 1; i>= 0; i--) {
      int bit = num >> i & 1;
      nodes[node].starting_with += delta;
      node = get_or_create_child(node, bit);
    }

    nodes[node].starting_with += delta;
    return node;
  }

  int add(int num) {
    int node = build(num, 1);
    nodes[node].words_here++;
    return node;
  }

  int remove(int num) {
    int node = build(num, -1);
    nodes[node].words_here--;
    return node;
  }

  int get_max(int x) { // max xor value for i ^ x
    int node = ROOT; 
    int ans = 0;
    for(int i = NUM_LEN - 1; i >= 0; i--) {
      int bit = x >> i & 1;
      if(nodes[node].child[!bit] >= 0 && nodes[nodes[node].child[!bit]].starting_with > 0) {
        ans <<= 1;
        ans++;
        node = nodes[node].child[!bit];
      } else if(nodes[node].child[bit] >= 0 && nodes[nodes[node].child[bit]].starting_with > 0) {
        ans <<= 1;
        node = nodes[node].child[bit];
      } else {
        return -1;
      }
    }

    return ans;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4};
  bit_trie<2> trie(4);

  for(auto x : nums) trie.add(x);
  cout << trie.get_max(4) << endl;
  trie.remove(3);
  cout << trie.get_max(4) << endl;
}
