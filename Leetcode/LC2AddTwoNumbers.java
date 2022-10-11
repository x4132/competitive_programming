public class LC2AddTwoNumbers {
    public static void main(String[] args) {
        Solution solution = new Solution();
        ListNode l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
        ListNode l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
        ListNode output = solution.addTwoNumbers(l1, l2);
        do {
            System.out.print(output.val);
        } while (output.next != null);
        System.out.println();
    }
}
class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        return add(l1, l2, 0);
    }

    public ListNode add(ListNode l1, ListNode l2, int carryIn) {
        ListNode result = new ListNode();
        if (l1 == null) l1 = new ListNode(0);
        if (l2 == null) l2 = new ListNode(0);
        int carryOut = 0;
        result.val = l1.val + l2.val + carryIn;
        if (result.val >= 10) {
            carryOut = (result.val / 10) % 10;
            result.val %= 10;
        }
        if (l1.next != null || l2.next != null) {
            result.next = add(l1.next, l2.next, carryOut);
        } else if (carryOut != 0) {
            result.next = new ListNode(carryOut);
        }
        return result;
    }
}