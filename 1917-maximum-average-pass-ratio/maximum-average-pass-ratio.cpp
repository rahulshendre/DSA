class Solution {
public:
    double change(double n, double d) {
        double curr = (n + 1) / (d + 1);
        double prev = n / d;
        return curr - prev;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> q;
        double res = 0.0;
        for (auto v : classes) {
            double n = v[0], d = v[1];
            res += (n / d);
            q.push({change(n, d), {n, d}});
        }
        while (extraStudents--) {
            double cng = q.top().first, n = q.top().second.first,
                   d = q.top().second.second;
            q.pop();
            res += cng;
            n += 1.0, d += 1.0;
            q.push({change(n, d), {n, d}});
        }
        return res / classes.size();
    }
};