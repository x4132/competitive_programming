import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;

public class S3_jeff {
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

        char[] nArr = n.toCharArray();
        char[] hArr = h.toCharArray();
        HashMap<Integer, ArrayList<String>> store = new HashMap<>();
        int total = 0;
        for (int i = 0; i < n.length(); i++) {
            int key = nArr[i]-'a'; 
            Integer value = nMap.get(key);
            if (value == null)
            {
                value = 0;
            }
            nMap.put(key, value + 1);
            
            int key2 = hArr[i] -'a';
            value = searchMap.get(key2);
            if (value == null)
            {
                value = 0;
            }
            searchMap.put(key2, value + 1);
        }

        if (checkMatch(nMap, searchMap)) {
            total++;
            String s = h.substring(0, n.length());
            ArrayList<String> strList = new ArrayList<String>();
            strList.add(s);
            store.put(s.hashCode(), strList);
        }

        for (int i = 1; i <= h.length() - n.length(); i++) {
            int key = hArr[i - 1] -'a';
            Integer value = searchMap.get(key);
            if (value == 1)
            {
                searchMap.remove(key);
            }
            else
            {
                searchMap.put(key,  value - 1);
            }

            int key2 = hArr[i + n.length() - 1] - 'a';
            value = searchMap.get(key2);
            if (value == null)
            {
                value = 0;
            }
            searchMap.put(key2, value+1);

            if(checkMatch(nMap, searchMap)) {
                String s = h.substring(i, i+n.length());
                if (!store.keySet().contains(s.hashCode())) {
                    ArrayList<String> strList = new ArrayList<String>();
                    strList.add(s);
                    store.put(s.hashCode(), strList);
                    total++;
                }
                else
                {
                    ArrayList<String> strList = store.get(s.hashCode());
                    if (! findStr(strList, s))
                    {
                        strList.add(s);
                        total++;
                    }
                }
            }
        }

        System.out.println(total);
    }

    static boolean findStr(ArrayList<String> list, String str)
    {
        for (String s:list)
        {
            if (s.equals(str))
            {
                return true;
            }
        }

        return false;
    }

    static boolean checkMatch(HashMap<Integer, Integer> a, HashMap<Integer, Integer> b) {
        for (Integer c : b.keySet()) {
            if (a.get(c) == null)
            {
                return false;
            }

            if (!b.get(c).equals(a.get(c))) {
                return false;
            }
        }

        return true;
    }
}