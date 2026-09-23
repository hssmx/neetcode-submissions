class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& ostrs) {
        std::vector<std::string> strs = ostrs;
        std::vector<int> indexes = {};

        

        int n = std::size(ostrs);
        
        for(int i=0; i<n; i++){
            indexes.push_back(i);
        }

        for(std::string& s : strs)
        {
            std::sort(s.begin(), s.end());
        }
        
        std::sort(indexes.begin(), indexes.end(), [&](int a, int b) {
            return strs[a] < strs[b]; 
        });

        std::sort(strs.begin(), strs.end());
        
        std::vector<std::vector<std::string>> grp = {};

        for (int j = 0; j<n; j++) {
            std::vector<std::string> insidegrp = {ostrs[indexes[j]]};
            for (int i = j+1; i<n; i++) {
                if(strs[j] == strs[i]) {
                    

                    insidegrp.push_back(ostrs[indexes[i]]);
                    j = i;
                }
                else {
                    break;
                }
            }
            grp.push_back(insidegrp);
        }
        return grp;
    }
};
