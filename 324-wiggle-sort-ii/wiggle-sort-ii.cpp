class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> v = nums;

        sort(v.begin(), v.end());

        int n = nums.size();
        int mid = (n + 1) / 2;
        int j = n - 1;
        int k = mid - 1;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                
                nums[i] = v[k];
                k--;
            }
            else {
                nums[i] = v[j];
                j--;
            }
        }
    }
};