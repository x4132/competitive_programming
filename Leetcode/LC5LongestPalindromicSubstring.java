import java.util.ArrayDeque;

public class LC5LongestPalindromicSubstring {
    public String longestPalindrome(String s) {
        char[] sChars = s.toCharArray();
        ArrayDeque<Node> nodes = new ArrayDeque<>();

        int maxStart = 0;
        int maxEnd = 0;

        for (int i = 0; i < s.length() - 1; i++) {
            nodes.add(new Node(i, i));
            if (sChars[i] == sChars[i + 1]) {
                nodes.add(new Node(i, i + 1));
            }
        }
        nodes.add(new Node(s.length() - 1, s.length() - 1));

        while (!nodes.isEmpty()) {
            Node n = nodes.poll();
            if (n.start > 0 && n.end < s.length() - 1 && sChars[n.start - 1] == sChars[n.end + 1]) {
                n.start--;
                n.end++;
                nodes.add(n);
            } else {
                if ((n.end - n.start) > (maxEnd - maxStart)) {
                    maxStart = n.start;
                    maxEnd = n.end;
                }
            }
        }

        return s.substring(maxStart, maxEnd + 1);
    }
}

class Node {
    int start;
    int end;

    Node(int start, int end) {
        this.start = start;
        this.end = end;
    }
}