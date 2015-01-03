// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:

    char local[4];
    int idx = 0;
    int size = 0;

    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int i = 0;
        while (idx < size && i < n) {
            buf[i++] = local[idx++];
        }
        while (n - i >= 4) {
            int cnt = read4(buf + i);
            i += cnt;
            if (cnt < 4) {
                return i;
            }
        }
        size = read4(local);
        idx = 0;
        while (idx < size && i < n) {
            buf[i++] = local[idx++];
        }
        return i;
    }
};
