class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int l = 0, r = 0;
        int maxlen = 0;

        while(r < fruits.size()){
            basket[fruits[r]]++;

            while(basket.size() > 2){
                basket[fruits[l]]--;
                if(basket[fruits[l]] == 0){
                    basket.erase(fruits[l]);
                }
                l++;
            }
            maxlen = max(maxlen, r -  l + 1);
            r++;
        }
        return maxlen;
    }
};