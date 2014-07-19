public class Solution {
    public TreeNode sortedArrayToBST(int[] num) {
        return partialConvert(num, 0, num.length-1);
    }
     
    private TreeNode partialConvert(int[] num, int left, int right)
    {
        if (left > right) return null;
        if (left == right)
        {
            return new TreeNode(num[left]);
        }
        // else
        {
            int mid = (left + right) / 2;
            TreeNode node = new TreeNode(num[mid]);
            node.left = partialConvert(num, left, mid-1);
            node.right= partialConvert(num, mid+1, right);
            return node;
        }
    }
}