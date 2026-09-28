class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int lastSeen[3] = {-1, -1, -1};

        for(int i = 0; i < s.length(); i++){
            int index = s[i] - 'a';
            lastSeen[index] = i;

            count += min({lastSeen[0],lastSeen[1],lastSeen[2]}) + 1;
        }
        return count;
    }
};