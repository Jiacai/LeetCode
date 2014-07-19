public class Solution {
    public String multiply(String num1, String num2) {
        int ans[] = new int[num1.length()+num2.length()];
        int len1 = num1.length();
        int len2 = num2.length();
        for (int i = 0; i < len1; i++)
        {
            for (int j = 0; j < len2; j++)
            {
                ans[i+j] += (num1.charAt(len1-i-1) - '0') * 
                            (num2.charAt(len2-j-1) - '0');
            }
        }
        for (int i = 0; i < len1+len2; i++)
        {
            if (ans[i] >= 10)
            {
                ans[i+1] += ans[i] / 10;
                ans[i] = ans[i] % 10;
            }
        }
        StringBuffer sb = new StringBuffer();
        int i = len1+len2-1;
        while (i >= 0 && ans[i] == 0)
        {
            i--;
        }
        for (; i >= 0; i--)
        {
            sb.append(ans[i]);
        }
        String result = sb.toString();
        if (result.length() == 0) return "0";
        else return result;
    }
}