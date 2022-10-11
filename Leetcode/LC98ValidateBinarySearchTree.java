import java.util.ArrayDeque;

public class LC98ValidateBinarySearchTree {
    public boolean isValidBST(TreeNode root) {
        ArrayDeque<TreeNode> stack = new ArrayDeque<>();
        TreeNode cur = root;
        TreeNode prev = null;
        while (!stack.isEmpty() || cur != null) {
            if (cur != null) {
                stack.push(cur);
                cur = cur.left;
            } else {
                TreeNode next = stack.pop();
                if (prev != null && next.val <= prev.val) {
                    return false;
                }

                prev = next;
                cur = next.right;
            }
        }

        return true;
    }
}