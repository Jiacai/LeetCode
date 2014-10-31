#include <unordered_map>
using namespace std;
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int ans = 0;
        int size = points.size();
        if (size == 0) return 0;
        for (int i = 0; i < size; i++) {
            int duplicate = 1;
            unordered_map<float, int> mp;
            for (int j = 0; j < size; j++) {
                if (i == j) continue;
                if (points[i].x == points[j].x
                    && points[i].y == points[j].y) {
                    duplicate++;
                    continue;
                }
                float k = 0;
                if (points[i].x == points[j].x) k = INT_MAX;
                else {
                    k = (float) (points[i].y - points[j].y) / (points[i].x - points[j].x);
                }
                mp[k]++;
            }
            for (unordered_map<float, int>::iterator it = mp.begin(); it != mp.end(); it++) {
                if (it->second + duplicate > ans)
                    ans = it->second + duplicate;
            }
            if (mp.size() == 0 && duplicate > ans)
                ans = duplicate;
        }
        return ans;
    }
    
    int maxPoints_1(vector<Point> &points) {
        int size = points.size();
        int res = 0;
        for (int i = 0; i < size; i++) {
            unordered_map<double, int> count;
            int base = 0;
            int zero_cnt = 0;
            int local_max = 0;
            for (int j = 0; j < size; j++) {
                if (points[i].x == points[j].x && 
                    points[i].y == points[j].y) {
                    base++;
                    continue;
                }
                if (points[i].y == points[j].y) {
                    zero_cnt++;
                    local_max = max(zero_cnt, local_max);
                    continue;
                }
                double k = 1.0 * (points[i].x - points[j].x) 
                            / (points[i].y - points[j].y);
                count[k] += 1;
                local_max = max(count[k], local_max);
            }
            res = max(local_max + base, res);
        }
        return res;
    }
};
