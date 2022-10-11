import java.util.PriorityQueue;

public class LC1337TheKWeakestRowsInAMatrix {
    public int[] kWeakestRows(int[][] mat, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] == b[0] ? b[1] - a[1] : b[0] - a[0]);
        int[] output = new int[k];

        for (int i = 0; i < mat.length; i++) {
            pq.offer(new int[] { numOfSoldiers(mat[i]), i });
            if (pq.size() > k)
                pq.poll();
        }

        for (int i = k - 1; i >= 0; i--) {
            output[i] = pq.poll()[1];
        }

        return output;
    }

    int numOfSoldiers(int[] row) {
        int start = 0;
        int end = row.length - 1;
        while (start <= end) {
            int middle = (start + end) / 2;
            if (row[middle] == 0) {
                end = middle - 1;
            } else {
                start = middle + 1;
            }
        }

        return start;
    }

    public static void main(String[] args) {
        LC1337TheKWeakestRowsInAMatrix lc1337TheKWeakestRowsInAMatrix = new LC1337TheKWeakestRowsInAMatrix();
        lc1337TheKWeakestRowsInAMatrix.kWeakestRows(new int[][] { { 1, 1, 0, 0, 0 }, { 1, 1, 1, 1, 0 },
                { 1, 0, 0, 0, 0 }, { 1, 1, 0, 0, 0 }, { 1, 1, 1, 1, 1 } }, 3);
    }
}
