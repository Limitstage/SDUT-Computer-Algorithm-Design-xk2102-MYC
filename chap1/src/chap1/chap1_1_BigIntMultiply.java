package chap1;
import java.util.Scanner;
public class chap1_1_BigIntMultiply 
{
    public static int divideConquer(int X, int Y, int n) {
        int sign = SIGN(X) * SIGN(Y);
        int x = Math.abs(X);
        int y = Math.abs(Y);
        if (x == 0 || y == 0) {
            return 0;
        } else if (n == 1) {
            return sign * x * y;
        } else {
            int A = (int) (x / Math.pow(10, n / 2));
            int B = x - A * (int) Math.pow(10, n / 2);
            int C = (int) (y / Math.pow(10, n / 2));
            int D = y - C * (int) Math.pow(10, n / 2);
            int AC = divideConquer(A, C, n / 2);
            int BD = divideConquer(B, D, n / 2);
            int ABDC = divideConquer((A - B), (D - C), n / 2) + AC + BD;
            return sign * (AC * (int) Math.pow(10, n) + ABDC * (int) Math.pow(10, n / 2) + BD);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x, y, n;
        System.out.println("请输入大整数A");
        x = scanner.nextInt();
        System.out.println("请输入大整数B");
        y = scanner.nextInt();
        System.out.println("请输入大整数A,B的位数");
        n = scanner.nextInt();
        System.out.printf("A和B的乘积为：%d", divideConquer(x, y, n));
    }

    public static int SIGN(int A) {
        return (A > 0) ? 1 : -1;
    }
}

