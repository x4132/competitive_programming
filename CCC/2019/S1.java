import java.io.BufferedReader;
import java.io.InputStreamReader;

public class S1 {
    public static void main(String[] args) throws Exception {
        int[][] arr = new int[2][2];
        int[] carry = new int[2];
        arr[0][0] = 1;
        arr[0][1] = 2;
        arr[1][0] = 3;
        arr[1][1] = 4;

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        char[] input = reader.readLine().trim().toCharArray();

        for (int i = 0; i < input.length; i++) {
            if (input[i] == 'H') {
                carry = arr[0];
                arr[0] = arr[1];
                arr[1] = carry;
            } else {
                carry = new int[] { arr[0][0], arr[1][0] };
                arr[0][0] = arr[0][1];
                arr[1][0] = arr[1][1];

                arr[0][1] = carry[0];
                arr[1][1] = carry[1];
            }
        }

        System.out.println(arr[0][0] + " " + arr[0][1]);
        System.out.println(arr[1][0] + " " + arr[1][1]);
    }
}