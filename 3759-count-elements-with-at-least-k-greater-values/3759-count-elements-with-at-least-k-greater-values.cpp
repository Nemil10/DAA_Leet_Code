class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        
        if(k == 0)
            return nums.size();

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int x = nums[n - k];

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] < x)
                ans++;
                
        }

        return ans;
    }
};