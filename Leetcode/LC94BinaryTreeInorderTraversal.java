import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;

public class LC94BinaryTreeInorderTraversal {
    public List<Integer> inorderTraversal(TreeNode root) {
        ArrayList<Integer> output = new ArrayList<>();
        if (root == null) {
            return output;
        }
        output.add(root.val);
        ArrayDeque<TreeNode> stack1 = new ArrayDeque<>();
        ArrayDeque<Integer> stack2 = new ArrayDeque<>();
        stack1.add(root);
        stack2.add(0);
        while (!stack1.isEmpty()) {
            TreeNode cur = stack1.pop();
            int pos = stack2.pop();
            if (cur.left != null) {
                output.add(pos, cur.left.val);
                stack1.push(cur.left);
                stack2.push(pos);
                pos++;
            }

            if (cur.right != null) {
                output.add(pos + 1, cur.right.val);
                stack1.push(cur.right);
                stack2.push(pos + 1);
            }
        }

        return output;
    }
}