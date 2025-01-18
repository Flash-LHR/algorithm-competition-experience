// 方法一
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if (k == 0) {
            return 1;
        }
        int n = nums.size();
        vector<int> sum(n, 0);
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if ((sum[j] | nums[i]) == sum[j]) {
                    break;
                }
                sum[j] |= nums[i];
                if (sum[j] >= k) {
                    ans = min(ans, i - j + 1);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

// 方法二【1】
class Solution {
private:
    int cnt[31];
public:
    void add(int &sum, int x) {
        sum |= x;
        for (int i = 30; i >= 0; i--) {
            if ((x >> i) & 1) {
                ++cnt[i];
            }
        }
    }

    void del(int &sum, int x) {
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            res <<= 1;
            res |= 1;
            if (((x >> i) & 1) && --cnt[i] == 0) {
                res ^= 1;
            }
        }
        sum &= res;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        memset(cnt, 0, sizeof(cnt));
        int sum = 0, ans = INT_MAX;
        for (int l = 0, r = 0; r < n; r++) {
            add(sum, nums[r]);
            while (l <= r && sum >= k) {
                ans = min(ans, r - l + 1);
                // cout << sum << ": " << l << " " << r << endl;
                del(sum, nums[l]);
                ++l;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

// 方法二【2】
struct Stack2 {
    vector<int> pre;
    vector<int> suf;
    int suf_or = 0;

    void push(int x) {
        suf_or |= x;
        suf.push_back(x);
    }

    int top() {
        int pre_or = pre.empty() ? 0 : pre.back();
        return pre_or | suf_or;
    }

    void pop() {
        if (pre.empty()) {
            while (!suf.empty()) {
                int t = pre.empty() ? 0 : pre.back();
                pre.push_back(t | suf.back());
                suf.pop_back();
            }
            suf_or = 0;
        }
        pre.pop_back();
    }

    bool empty() {
        return pre.empty() && suf.empty();
    }
};

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        Stack2 st;
        int ans = INT_MAX;
        for (int l = 0, r = 0; r < n; r++) {
            st.push(nums[r]);
            while (l <= r && st.top() >= k) {
                ans = min(ans, r - l + 1);
                st.pop();
                ++l;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

// 方法三
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> st(n + 1, vector<int>(31, 0));
        vector<int> Log(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            st[i][0] = nums[i - 1];
            if (i >= 2) {
                Log[i] = Log[i >> 1] + 1;
            }
        }

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 1; i <= n; i++) {
                if (i + (1 << j - 1) > n) {
                    break;
                }
                st[i][j] = st[i][j - 1] | st[i + (1 << j - 1)][j - 1];
            }
        }

        auto getOrSum = [&](int l, int r) -> int {
            int p = Log[r - l + 1];
            return st[l][p] | st[r - (1 << p) + 1][p];
        };

        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            int l = 1, r = i;
            while (l <= r) {
                int mid = (l + r) >> 1;
                int val = getOrSum(mid, i);
                if (val >= k) {
                    ans = min(ans, i - mid + 1);
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};