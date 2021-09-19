import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        TreeMap<String, Integer> trees = new TreeMap<>();
        int totalCnt = 0;
        while (true) {
            String tree = br.readLine();
            if (tree == null)
                break;
            trees.merge(tree, 1, Integer::sum);
            totalCnt++;
        }
        for (String key : trees.keySet()) {
            bw.write(key);
            bw.write(" ");
            bw.write(String.format("%.4f\n", trees.get(key) * 100 / (float) totalCnt));
        }
        bw.close();
    }
}