import java.util.ArrayDeque;
import java.util.HashSet;

public class LC55JumpGame {
    public boolean canJump(int[] nums) {
        ArrayDeque<Integer> queue = new ArrayDeque<>();
        HashSet<Integer> visited = new HashSet<Integer>();
        queue.add(0);
        while (!queue.isEmpty()) {
            int node = queue.poll();
            if (node == nums.length - 1) {
                return true;
            }
            for (int i = 1; i <= nums[node]; i++) {
                if ((node + i) > nums.length - 1) {
                    continue;
                }
                if ((node + i) == nums.length - 1) {
                    return true;
                }
                if (!visited.contains(node + i)) {
                    visited.add(node + i);
                    queue.add(node + i);
                }
            }
        }

        return false;
    }

    public static void main(String[] args) {
        LC55JumpGame lc55JumpGame = new LC55JumpGame();
        lc55JumpGame.canJump(new int[] {});
    }
}
