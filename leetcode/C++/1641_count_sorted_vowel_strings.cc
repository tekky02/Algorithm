class Solution {
public:
  int countVowelStrings(int n) {
    int arr[5] = {1, 1, 1, 1, 1};
    int count = 1;
    while (count <= n) {
      for (int i = 3; i >= 0; --i) {
        arr[i] += arr[i + 1];
      }
      count++;
    }
    return arr[0];
  }
};
