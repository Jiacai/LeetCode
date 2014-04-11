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
};