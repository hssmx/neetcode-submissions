class Solution {
public:
    int trap(vector<int>& h) {
        
        int n = h.size(), first_wall = 0, last_wall = 0;

        if(n <= 2) return 0;

        for(int i = n-1; i>=1; --i){
            if( h[i] >= h[i-1] ){
                last_wall = i;
                break;
            }
        }

        int before_last = last_wall;
        for(int i = last_wall; i >= 0; --i){
            if (h[i]>h[last_wall]){
                before_last = i;
                if( before_last > 0)
                    if (h[before_last] > h[before_last - 1]) break;
            }
        }

        for(int i = 0; i <= last_wall; ++i) {
            if( h[i] > 0 ){
                first_wall = i;
                break;
            }
        }

        int total_water = 0;
        int m = h[first_wall];
        vector<int> m_right = { h[n-1] };

        for( int i= n-1; i>0; --i)
        {
            m_right.push_back(max(m_right[n-1-i], h[i]));
        }

        for (int i = first_wall + 1; i < last_wall; i++){
            if(m < h[i]) m = h[i];  
            
            total_water += max(min(m, m_right[n-1-i])  - h[i], 0);
        }

        return total_water;
    }
};
