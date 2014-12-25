/*
CZA:
(3)*26*26
+(26)*26
+(1)
So this is a base26-base10 conversion
Then we see, after (x - 1) / 26, the problem becomes a sub problem
*/
class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n >= 1) {
            n--;
            result.push_back('A' + (n % 26));
            n /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
