import java.util.ArrayList;
import java.util.List;

public class LC22GenerateParentheses {
    public List<String> generateParenthesis(int n) {
        ArrayList<String> out = new ArrayList<>();
        generate(out, "", 0, 0, n);
        return out;
    }

    static void generate(ArrayList<String> out, String cur, int leftP, int rightP, int n) {
        if (cur.length() == n * 2) {
            out.add(cur);
            return;
        }

        if (leftP < n) {
            generate(out, cur + "(", leftP + 1, rightP, n);
        }
        if (rightP < leftP) {
            generate(out, cur + ")", leftP, rightP + 1, n);
        }
    }
}