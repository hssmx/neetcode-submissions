class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for(string str:strs){
            result += str + "\r\n";
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        size_t start = 0;
        string delimiter = "\r\n";
        size_t end = s.find(delimiter);

        while (end != std::string::npos) {
            result.push_back(s.substr(start, end - start));
            
            start = end + delimiter.length();
            
            end = s.find(delimiter, start);
        }

        return result;
    }
};
