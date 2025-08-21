/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */
function sortList(head: ListNode | null): ListNode | null {
  if (head === null || head.next === null) {
    return head;
  }

  let prev: ListNode | null = null;
  let slow: ListNode | null = head;
  let fast: ListNode | null = head;

  // find midpoint with slow-fast
  while (fast) {
    prev = slow;
    slow = slow?.next ?? null;
    fast = fast.next?.next ?? null;
  }

  // detach head
  prev!.next = null;
  return mergeList(sortList(head), sortList(slow));
}

function mergeList(
  head1: ListNode | null,
  head2: ListNode | null,
): ListNode | null {
  let newHead = head1;
  if ((!head1 && head2) || (head1 && head2 && head2.val < head1.val)) {
    newHead = head2;
    head2 = head2.next;
  } else if (head1) {
    head1 = head1.next;
  }

  let cur = newHead;
  while ((head1 || head2) && cur) {
    if (!head1 && head2) {
      cur.next = head2;
      head2 = head2.next;
    } else if (!head2 && head1) {
      cur.next = head1;
      head1 = head1.next;
    } else if (head1 && head2) {
      if (head1.val < head2.val) {
        cur.next = head1;
        head1 = head1.next;
      } else {
        cur.next = head2;
        head2 = head2.next;
      }
    }

    cur = cur.next;
  }

  return newHead;
}
