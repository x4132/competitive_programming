import java.util.ArrayList;
import java.util.List;

public class LC119PascalsTriangleII {
    public List<Integer> getRow(int rowIndex) {
        List<List<Integer>> output = new ArrayList<>();
        output.add(new ArrayList<>());
        output.get(0).add(1);
        if (rowIndex == 0) return output.get(0);
        output.add(new ArrayList<>());
        output.get(1).add(1);
        output.get(1).add(1);
        for (int i = 2; i <= rowIndex; i++) {
            output.add(new ArrayList<>());
            output.get(i).add(1);
            for (int x = 1; x < i - 1; x++) {
                output.get(i).add(output.get(i - 1).get(x - 1) + output.get(i - 1).get(x));
            }
            output.get(i).add(1);
        }

        return output.get(rowIndex);
    }
}
