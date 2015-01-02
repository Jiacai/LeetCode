class TwoSum {
public:
    unordered_map<int, int> map;

	void add(int number) {
	    if (map.find(number) == map.end()) {
	        map[number] = 1;
	    } else {
	        map[number]++;
	    }
	}

	bool find(int value) {
	    for (auto iter = map.begin(); iter != map.end(); iter++) {
	        int a = iter->first;
	        int b = value - a;
	        if (map.find(b) == map.end()) {
	            continue;
	        }
	        if (a != b || iter->second >= 2) {
                return true;
            }
	    }
	    return false;
	}
};
