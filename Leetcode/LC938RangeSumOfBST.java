import java.util.ArrayDeque;

public class LC938RangeSumOfBST {
    public int rangeSumBST(TreeNode root, int low, int high) {
        ArrayDeque<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        int sum = 0;
        while (!queue.isEmpty()) {
            TreeNode cur = queue.pop();

            if (cur.val >= low && cur.val <= high) {
                sum += cur.val;
            }
            if (cur.left != null)
                queue.push(cur.left);
            if (cur.right != null)
                queue.push(cur.right);
        }

        return sum;
    }
}