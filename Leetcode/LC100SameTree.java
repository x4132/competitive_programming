import java.util.ArrayDeque;

public class LC100SameTree {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        ArrayDeque<TreeNode> queue1 = new ArrayDeque<>();
        ArrayDeque<TreeNode> queue2 = new ArrayDeque<>();
        if (p == null || q == null) {
            if (p == null && q == null) {
                return true;
            }
            return false;
        }
        if (p.val != q.val) {
            return false;
        }
        queue1.push(p);
        queue2.push(q);
        while (!queue1.isEmpty()) {
            TreeNode cur1 = queue1.pop();
            TreeNode cur2 = queue2.pop();
            boolean left1 = cur1.left != null;
            boolean left2 = cur2.left != null;
            boolean right1 = cur1.right != null;
            boolean right2 = cur2.right != null;

            if (left1 != left2 || (left1 && left2 && cur1.left.val != cur2.left.val)) {
                return false;
            } else if (left1 && left2) {
                queue1.push(cur1.left);
                queue2.push(cur2.left);
            }

            if (right1 != right2 || (right1 && right2 && cur1.right.val != cur2.right.val)) {
                return false;
            } else if (right1 && right2) {
                queue1.push(cur1.right);
                queue2.push(cur2.right);
            }
        }

        return true;
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}