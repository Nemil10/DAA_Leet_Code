class Solution {
public:
    int power(int a, int b) {
        int ans = 1;

        while (b > 0) {
            if (b % 2 == 1) {
                ans = (ans * a) % 1337;
            }

            a = (a * a) % 1337;
            b = b / 2;
        }

        return ans;
    }

    int superPow(int a, vector<int>& b) {
        a = a % 1337;

        int ans = 1;

        for (int i = 0; i < b.size(); i++) {
            ans = power(ans, 10);
            ans = (ans * power(a, b[i])) % 1337;
        }

        return ans;
    }
};