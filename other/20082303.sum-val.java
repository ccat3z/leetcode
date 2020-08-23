import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = in.nextInt();
        }
        int[] res =  new int[n];
        for (int i = 0; i < arr.length; i++) {
            res[i] = help(arr[i]);
        }
        for (int i = 0; i < res.length; i++) {
            System.out.println(res[i]);
        }
    }
    private static int help(int num) {
        int as = num / 10;
        int a = num % 10;
        if (as == 0) return a;
        return (a == 9) ? help(as) + a : help(as - 1) + a + 10;
    }
}