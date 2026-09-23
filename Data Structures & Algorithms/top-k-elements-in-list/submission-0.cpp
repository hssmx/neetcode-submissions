class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> counter;
        
        for(int num:nums){
            counter[num]++;
        }

        std::vector<std::pair<int, int>> vec(counter.begin(), counter.end());
        vector<int> max_keys;

        std::nth_element(vec.begin(), vec.begin() + (k - 1), vec.end(), 
            [](const auto& a, const auto& b) {
                return a.second > b.second;
        });


        for (int i = 0; i < k; ++i) {
            max_keys.push_back(vec[i].first);
        }
        
        return max_keys;
    }
};
