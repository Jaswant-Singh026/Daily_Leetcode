class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int, int> counts;
        for(char ch : s){
            counts[ch]++;
        }

        int n = s.length();
        vector<vector<char>> buckets(n + 1);
        for(auto& [ch, freq] : counts){
            buckets[freq].push_back(ch);
        }

        string result = "";
        for(int freq = n; freq > 0; freq--){
            for(char ch : buckets[freq]){
                result.append(freq, ch);
            }
        }
        return result;
    }
};