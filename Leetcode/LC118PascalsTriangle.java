import java.util.List;
import java.util.ArrayList;

public class LC118PascalsTriangle {
    public List<List<Integer>> generate(int numRows) {
        
        List<List<Integer>> result = new ArrayList<>();
        if (numRows == 0) return result;
        result.add(new ArrayList<>());
        result.get(0).add(1);
        if (numRows == 1) return result;
        result.add(new ArrayList<>());
        result.get(1).add(1);
        result.get(1).add(1);
        for (int i = 2; i < numRows; i++) {
            ArrayList<Integer> temp = new ArrayList<>();
            temp.add(1);
            for (int x = 1; x < i; x++) {
                 temp.add(result.get(i - 1).get(x - 1) + result.get(i - 1).get(x));
            }
            temp.add(1);

            result.add(temp);
        }

        return result;
    }
}
