public class Solution {
    public String addBinary(String a, String b) {
        int carrior = 0;
        ArrayList<Character> list = new ArrayList<Character>();
        int lenA = a.length();
        int lenB = b.length();
        for (int i = 0; i < lenA || i < lenB; i++)
        {
            if (i >= lenA)
            {
                int r = carrior + b.charAt(lenB-i-1) - '0';
                carrior = r / 2;
                r = r % 2;
                list.add((char)(r + '0'));
            }
            else if (i >= lenB)
            {
                int r = carrior + a.charAt(lenA-i-1) - '0';
                carrior = r / 2;
                r = r % 2;
                list.add((char)(r + '0'));
            }
            else
            {
                int r = carrior + a.charAt(lenA-i-1) + b.charAt(lenB-i-1) - '0' - '0';
                carrior = r / 2;
                r = r % 2;
                list.add((char)(r + '0'));
            }
        }
        if (carrior != 0) list.add((char)(carrior + '0'));
        StringBuffer sb = new StringBuffer();
        for (int j = list.size() - 1; j >= 0; j--)
        {
            sb.append(list.get(j));
        }
        return sb.toString();
    }
}