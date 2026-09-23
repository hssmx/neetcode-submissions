class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> counter;
        
        for(int num:nums){
            counter[num]++;
        }

        vector<pair<int, int>> vec(counter.begin(), counter.end());

        nth_element(vec.begin(), vec.begin() + (k - 1), vec.end(), 
            [](const auto& a, const auto& b) {
                return a.second > b.second;
        });


        vector<int> max_keys;
        for (int i = 0; i < k; ++i) {
            max_keys.push_back(vec[i].first);
        }
        
        return max_keys;
    }
};
