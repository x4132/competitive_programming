public class LC1081SmallestSubsequence {
    public String smallestSubsequence(String s) {
        StringBuilder sb = new StringBuilder();
        int[] count = new int[26];
        boolean[] used = new boolean[26];
        char[] cs = s.toCharArray();

        for (char c : cs) {
            count[c - 'a']++;
        }

        for (char c : cs) {
            count[c - 'a']--;

            if (used[c - 'a'])
                continue;

            while (sb.length() > 0 && c < sb.charAt(sb.length() - 1) && count[sb.charAt(sb.length() - 1) - 'a'] > 0) {
                used[sb.charAt(sb.length() - 1) - 'a'] = false;

                sb.deleteCharAt(sb.length() - 1);
            }

            sb.append(c);
            used[c - 'a'] = true;
        }

        return sb.toString();
    }
}
