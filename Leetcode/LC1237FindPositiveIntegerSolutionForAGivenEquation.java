import java.util.ArrayList;
import java.util.List;
// This is the custom function interface.
// You should not implement it, or speculate about its implementation
interface CustomFunction {
         // Returns f(x, y) for any given positive integers x and y.
         // Note that f(x, y) is increasing with respect to both x and y.
         // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
         public int f(int x, int y);
};

public class LC1237FindPositiveIntegerSolutionForAGivenEquation {
    public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
        List<List<Integer>> results = new ArrayList<>();
        for (int i = 1; i < 1001; i++) {
            int start = 1;
            int end = 1001;
            while (start <= end) {
                int middle = (start + end) / 2;
                if (customfunction.f(i, middle) == z) {
                    ArrayList<Integer> a = new ArrayList<>();
                    a.add(i);
                    a.add(middle);
                    results.add(a);
                    break;
                } else if (customfunction.f(i, middle) < z) {
                    start = middle + 1;
                } else {
                    end = middle - 1;
                }
            }
        }

        return results;
    }
}
