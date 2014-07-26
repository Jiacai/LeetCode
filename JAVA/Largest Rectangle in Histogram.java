public class Solution {
    public int largestRectangleArea(int[] height) {
        int[] h = Arrays.copyOf(height, height.length+1);
        Stack<Integer> stack = new Stack<Integer>();
        int max = 0;
        int i = 0;
        while (i < h.length)
        {
            if (stack.isEmpty() || h[i] >= h[stack.peek()])
            {
                stack.push(i);
                i++;
            }
            else
            {
                int t = stack.pop();
                int tmp = h[t] * (stack.isEmpty() ? i : (i - stack.peek() - 1));
                max = Math.max(tmp, max);
            }
        }
        return max;       
    }
}