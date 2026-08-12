class Solution {
public:

    int solve(string s, int k, int l, int r)
    {
        if(l > r)
            return 0;

        int count[26] = {0};

        for(int i = l; i <= r; i++)
        {
            count[s[i] - 'a']++;
        }

        for(int i = l; i <= r; i++)
        {
            if(count[s[i] - 'a'] < k)
            {
                int left = solve(s, k, l, i - 1);
                int right = solve(s, k, i + 1, r);

                return max(left, right);
            }
        }

        return r - l + 1;
    }

    int longestSubstring(string s, int k)
    {
        return solve(s, k, 0, s.length() - 1);
    }
};