class Solution { 
public: 
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) { 
        
        // x-axis overlap
        int x = min(rec1[2], rec2[2]) - max(rec1[0], rec2[0]);
        
        // y-axis overlap
        int y = min(rec1[3], rec2[3]) - max(rec1[1], rec2[1]);
        
        if(x > 0 && y > 0)
            return true;
        
        return false;
    } 
};