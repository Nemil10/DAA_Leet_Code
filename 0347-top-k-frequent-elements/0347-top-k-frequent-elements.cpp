class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         map<int, int> count;

        for(int i = 0; i < nums.size(); i++)
        {
            count[nums[i]]++;
        }

        vector<pair<int,int>> v;

        for(auto x : count)
        {
            v.push_back({x.second, x.first});
        }

        sort(v.begin(), v.end());

        vector<int> ans;

        for(int i = v.size()-1; i >= 0 && k > 0; i--)
        {
            ans.push_back(v[i].second);
            k--;
        }

        return ans;
        
    }
};