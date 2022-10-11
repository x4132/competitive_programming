public class LC74SearchA2DMatrix {
    public boolean searchMatrix(int[][] matrix, int target) {
        int start = 0;
        int end = matrix.length * matrix[0].length - 1;

        while (start <= end) {
            int middle = (start + end) / 2;

            if (matrix[middle / matrix[0].length][middle % matrix[0].length] == target) {
                return true;
            } else if (matrix[middle / matrix[0].length][middle % matrix[0].length] > target) {
                end = middle - 1;
            } else {
                start = middle + 1;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        LC74SearchA2DMatrix lc74SearchA2DMatrix = new LC74SearchA2DMatrix();
        int[][] matrix = {{1, 1}};
        int target = 2;
        lc74SearchA2DMatrix.searchMatrix(matrix, target);
    }
}
