class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        vector <int> key(26,0);
        int result = 0;
        int max_frequency = 0;

        for (int right = 0; right<n; right++) {
            int y = toupper(s[right]) - 'A';
            key[y] ++;

            // Find max frequency of variable:
            max_frequency = max(max_frequency, key[y]);
            int changes = right - left + 1 - max_frequency;
            
            // Make the k condition:
            if (changes <= k) {
                result = max(result, right - left + 1);
            }
            else {
                key[toupper(s[left]) - 'A'] --;
                left ++;
            }
        }
        return result;
    }
};
