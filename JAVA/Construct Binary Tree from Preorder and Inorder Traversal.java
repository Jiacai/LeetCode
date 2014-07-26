public class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder.length != inorder.length) return null;
        return buildTree(preorder, 0, preorder.length,
                inorder, 0, inorder.length);
         
    }
     
    private TreeNode buildTree(int[] preorder, int ps, int pe,
        int[] inorder, int is, int ie)
    {
        if (pe-ps == 0) return null;
        TreeNode node = new TreeNode(preorder[ps]);
        int c = -1;
        for (c = is; c < ie; c++)
        {
            if (inorder[c] == preorder[ps]) break;
        }
        // split into two parts
        int l_ps = ps+1;
        int l_pe = ps+1+c-is;
        int l_is = is;
        int l_ie = c;
        node.left = buildTree(preorder, l_ps, l_pe, inorder, l_is, l_ie);
        int r_ps = ps+1+c-is;
        int r_pe = pe;
        int r_is = c+1;
        int r_ie = ie;
        node.right = buildTree(preorder, r_ps, r_pe, inorder, r_is, r_ie);
        return node;
    }
}