class Solution {
public:
    struct cmp {
        bool operator()(const pair<int, int>& a,
                        const pair<int, int>& b) const {
            if (a.first != b.first)
                return a.first > b.first;
            return a.second > b.second;
        }
    };
    using ll = long long;

    ll op(int y, int c, int add, set<pair<int, int>, cmp>& top,
          set<pair<int, int>, cmp>& rem, ll sum, int x) {

        if (top.find({c, y}) != top.end()) {
            sum -= (ll)c * y;
            top.erase({c, y});
        } else if (rem.find({c, y}) != rem.end()) {
            rem.erase({c, y});
        }

        top.insert({c + add, y});
        sum += (ll)(c + add) * y;

        auto it = --top.end();
        auto [lc, ly] = *it;
        if (top.size() > x) {
            top.erase({lc, ly});
            sum -= (ll)lc * ly;
            rem.insert({lc, ly});
        }
        if (!rem.empty()) {
            auto it1 = rem.begin();
            auto [fc, fy] = *it1;

            auto it = --top.end();
            auto [lc, ly] = *it;

            if (fc > lc || (fc == lc && fy > ly)) {
                top.erase({lc, ly});
                sum -= (ll)lc * ly;
                top.insert({fc, fy});
                rem.erase({fc, fy});
                rem.insert({lc, ly});
                sum += (ll)fc * fy;
            }
        }
        return sum;
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<ll> res;
        set<pair<int, int>, cmp> top, rem;
        ll sum = 0;
        unordered_map<int, int> count;

        for (int i = 0; i < n; i++) {
            int y = nums[i];
            int c = count[nums[i]];
            sum = op(y, c, 1, top, rem, sum, x);
            count[nums[i]]++;

            if (i >= k - 1) {
                res.push_back(sum);
                int removeY = nums[i - k + 1];
                int removeC = count[removeY];
                sum = op(removeY, removeC, -1, top, rem, sum, x);
                count[removeY]--;
            }
        }
        return res;
    }
};