import java.util.ArrayList;
import java.util.List;

/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
public class LCBinaryTree145 {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> out = new ArrayList<Integer>();
        if (root == null)
            ;
        else if (root.left == null && root.right == null) {
            out.add(root.val);
        } else if (root.left != null && root.right != null) {
            out = postorderTraversal(root.left);
            out.addAll(postorderTraversal(root.right));
            out.add(root.val);
        } else if (root.left != null) {
            out = postorderTraversal(root.left);
            out.add(root.val);
        } else {
            out = postorderTraversal(root.right);
            out.add(root.val);
        }

        return out;
    }
}