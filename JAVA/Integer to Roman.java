public class Solution {
    public String intToRoman(int num) {
        char[] roman = new char[] {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        StringBuilder sb = new StringBuilder();
        int scale = 1000;
        for (int i = 6; i >= 0; i -= 2)
        {
            if (num == 0) break;
            int c = num / scale;           
            if (c <= 3)
            {
                for (int j = 0 ; j < c; j++)
                {
                    sb.append(roman[i]);
                }
            }
            else if (c == 4)
            {
                sb.append(roman[i]);
                sb.append(roman[i+1]);
            }
            else if (c == 5)
            {
                sb.append(roman[i+1]);
            }
            else if (c <= 8)
            {
                sb.append(roman[i+1]);
                for (int j = 0 ; j < c-5; j++)
                {
                    sb.append(roman[i]);
                }
            }
            else if (c == 9)
            {
                sb.append(roman[i]);
                sb.append(roman[i+2]);
            }
            num = num - c * scale;
            scale = scale / 10;
        }
        return sb.toString();
    }
}