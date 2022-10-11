import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;

public class S3 {
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String n = reader.readLine();
        String h = reader.readLine();
        if (n.length() > h.length()) {
            System.out.println("0");
            return;
        }
        HashMap<Integer, Integer> nMap = new HashMap<>();
        HashMap<Integer, Integer> searchMap = new HashMap<>();
        for (int i = 0; i < 26; i++) {
            nMap.put(97 + i, 0);
            searchMap.put(97 + i, 0);
        }

        char[] nArr = n.toCharArray();
        char[] hArr = h.toCharArray();
        ArrayList<String> store = new ArrayList<>();
        StringBuilder s = new StringBuilder();
        int total = 0;
        for (int i = 0; i < n.length(); i++) {
            nMap.put((int) nArr[i], nMap.get((int)nArr[i]) + 1);
            searchMap.put((int) hArr[i], searchMap.get((int)hArr[i]) + 1);
            s.append(hArr[i]);
        }

        if (checkMatch(nMap, searchMap)) {
            total++;

            store.add(s.toString());
        }

        for (int i = 1; i <= h.length() - n.length(); i++) {
            searchMap.put((int)hArr[i - 1], searchMap.get((int)hArr[i - 1]) - 1);
            searchMap.put((int)hArr[i + n.length() - 1], searchMap.get((int)hArr[i + n.length() - 1]) + 1);
            s.delete(0, 1);
            s.append(hArr[i + n.length() - 1]);
            if(checkMatch(nMap, searchMap)) {
                if (!store.contains(s.toString())) {
                    store.add(s.toString());
                    total++;
                }
            }
        }

        System.out.println(total);
    }

    static boolean checkMatch(HashMap<Integer, Integer> a, HashMap<Integer, Integer> b) {
        for (Integer c : a.keySet()) {
            if (!a.get(c).equals(b.get(c))) {
                return false;
            }
        }

        return true;
    }
}
