class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int maxlen = 0;
        int maxfreq = 0;
        int freq[26] = {0};

        while(r < s.size()){
            char ch = s[r];

            freq[ch - 'A']++;
            maxfreq = max(maxfreq, freq[ch - 'A']);

            if((r - l + 1) - maxfreq > k){
                freq[s[l] - 'A']--;
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};