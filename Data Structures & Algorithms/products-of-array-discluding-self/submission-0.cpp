class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> results = {};
        int product = 1;
        vector<int> zeros = {};
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] == 0) zeros.push_back(i);

            else product *= nums[i];
        }

        if(zeros.size() >= 2){
            for(int i=0; i<nums.size(); ++i) results.push_back(0);
        }
        else {
            for(int i=0; i<nums.size(); ++i){
                if(zeros.size() != 0){
                    if (i != zeros[0]) results.push_back(0);
                    else results.push_back(product);
                }
                else results.push_back(product/nums[i]);
            }
        }
        return results;
    }
};
