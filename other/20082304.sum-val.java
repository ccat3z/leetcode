import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int nn = in.nextInt();
        for (int i = 0; i < nn; i++) {
            long n = in.nextLong();
            System.out.println(help(n));
        }
    }
    public static long help(long n) {
        long sum = 0;
        while (n != 0) {
            long temp = n % 10;
            n = n / 10;
            if (temp == 9) sum += 9;
            else {
                if (n == 0) sum += temp;
                else {
                    n -= 1;
                    sum += 9 + temp + 1;
                }
            }
        }
        return sum;
    }
}