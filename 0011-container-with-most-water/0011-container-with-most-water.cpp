class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int max_water=0;

        while(i<j){
            int h=min(height[i],height[j]);
            int width=j-i;
            int area = h*width;
            max_water=max(max_water,area);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }

        return max_water;

    }
};