import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        if (s.matches("(100+1+|01)+"))
            System.out.println("SUBMARINE");
        else
            System.out.printf("NOISE");
    }
}