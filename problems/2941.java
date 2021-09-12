import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        String s = sc.nextLine();
        String[] croatia = {"c=","c-","dz=","d-","lj","nj","s=","z="};

        for(int i=0;i<8;i++) {
            s=s.replace(croatia[i],"a");
        }
        System.out.println(s.length());
    }
}
