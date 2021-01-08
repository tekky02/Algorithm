class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    std::vector<int> lastIndex(256, -1);
    int prev = 0;
    for (int cur = 0; cur < s.size(); ++cur) {
      prev = std::max(prev, lastIndex[s[cur]] + 1);
      res = std::max(res, cur - prev + 1);
      lastIndex[s[cur]] = cur;
    }
    return res;
  }
};
