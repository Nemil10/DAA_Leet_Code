class NumArray {
public:
    vector<int> nums;
    vector<int> bit;
    int n;

    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();

        bit.resize(n + 1, 0);

        for (int i = 0; i < n; i++) {
            add(i + 1, nums[i]);
        }
    }

    void add(int index, int val) {
        while (index <= n) {
            bit[index] += val;
            index += index & (-index);
        }
    }

    void update(int index, int val) {
        int change = val - nums[index];
        nums[index] = val;

        add(index + 1, change);
    }

    int sum(int index) {
        int ans = 0;

        while (index > 0) {
            ans += bit[index];
            index -= index & (-index);
        }

        return ans;
    }

    int sumRange(int left, int right) {
        return sum(right + 1) - sum(left);
    }
};