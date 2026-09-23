class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0, cnt = 0;
        int m = s.size(), n = t.size();
        int sIndex = -1, minlen = INT_MAX;
        vector<int> hash(256, 0);
        if(n > m) return "";

        for(int i = 0; i < n; i++){
            hash[t[i]]++;
        }
        while(r < m){
            if(hash[s[r]] > 0){
                cnt++;
            }
            hash[s[r]]--;

            while(cnt == n){
                if((r - l + 1) < minlen){
                    minlen = r - l + 1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) 
                   cnt --;

                l++;   
            }
            r++;
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minlen);
    }
};