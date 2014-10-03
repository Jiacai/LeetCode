/*
https://oj.leetcode.com/problems/reverse-words-in-a-string/
1. reverse line; 2. reverse words; 3. erase extra spaces;
*/

class Solution {
public:
    void reverseWords(string &s) {
        int N = s.size();
        // reverse line
        reverse(s, 0, N - 1);
        int i = 0;
        int j = 0;
        // reverse words
        while (true)
        {
            for (; i < N && s[i] == ' '; i++);
            if (i == N)
                break;
            // S[i] != ' '
            for (j = i + 1; j < N && s[j] != ' '; j++);
            // S[j] == ' ' || end()
            reverse(s, i, j - 1);
            i = j;
        }
        // remove extra spaces
        i = 0;
        j = 0;
        while (true)
        {
            for (; j < N && s[j] == ' '; j++);
            if (j == N)
                break;
            if (i != 0)
            {
                s[i++] = ' ';
            }
            while (j < N && s[j] != ' ')
            {
                s[i++] = s[j++];
            }
        }
        if (i != N)
            s.erase(s.begin() + i, s.end());
    }
     
    void reverse(string &s, int l, int r)
    {
        while (l < r)
        {
            swap(s[l++], s[r--]);
        }
    }
     
    void swap(char &a, char &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
};
