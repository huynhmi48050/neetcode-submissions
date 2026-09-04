class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        unordered_set <char> check;
        int result = 0;
        
        for (int right = 0; right < n; right++) {
            while (check.count(s[right])) {
                check.erase(s[left]);
                left++;
            }

            check.insert(s[right]);
            result = max(result, right - left + 1);
        }
        return result;
    }
};
