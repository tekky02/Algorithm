class Trie {
  bool is_end_;
  char character_[26] = {0};
  Trie *child_node_[26] = {nullptr};

public:
  /** Initialize your data structure here. */
  Trie() : is_end_{false} {}

  /** Inserts a word into the trie. */
  void insert(string word) {
    Trie *node = this;
    for (auto w : word) {
      if (node->character_[w - 'a'] == 0) {
        node->character_[w - 'a'] = w;
        node->child_node_[w - 'a'] = new Trie;
      }
      node = node->child_node_[w - 'a'];
    }
    node->is_end_ = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    Trie *node = this;
    for (auto w : word) {
      if (node->character_[w - 'a'] == 0) {
        return false;
      }
      node = node->child_node_[w - 'a'];
    }
    if (node->is_end_) {
      return true;
    } else {
      return false;
    }
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    Trie *node = this;
    for (auto p : prefix) {
      if (node->character_[p - 'a'] == 0) {
        return false;
      }
      node = node->child_node_[p - 'a'];
    }
    return true;
  }
};

/**
 ** Your Trie object will be instantiated and called as such:
 ** Trie* obj = new Trie();
 ** obj->insert(word);
 ** bool param_2 = obj->search(word);
 ** bool param_3 = obj->startsWith(prefix);
 **/
