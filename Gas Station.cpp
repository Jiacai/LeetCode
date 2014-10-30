class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start = -1;
        int size = gas.size();
        int remaining = 0;
        int min_val = 0;
        int min_idx = -1;
        bool hasSolution = false;
        for (int i = 0; i < size; i++) {
            remaining = remaining + gas[i] - cost[i];
            if (remaining >= 0) {
                hasSolution = true;
            } else {
                hasSolution = false;
                if (remaining < min_val) {
                    min_val = remaining;
                    min_idx = i;
                }
            }
        }
        if (!hasSolution) {
            return -1;
        } else {
            return (min_idx + 1) % size;
        }
    }
    
     int canCompleteCircuit_1(vector<int> &gas, vector<int> &cost) {
        int N = gas.size();
        int res = 0, min = gas[0] - cost[0], sum = min;
        for (int i = 1; i < N; ++i)
        {
            sum += gas[i] - cost[i];
            if (sum < min) {
                min = sum;
                res = i;
            }
        }
        return sum >= 0 ? (res + 1) % N : -1;
    }
};
