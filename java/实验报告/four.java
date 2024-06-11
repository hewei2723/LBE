import java.util.Scanner;

public class four {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("请输入一个整数: ");
        int number = scanner.nextInt();

        System.out.println("整数 " + number + " 的二进制位是: ");
        System.out.println(decimalToBinary(number));
    }

    public static String decimalToBinary(int number) {
        StringBuilder binary = new StringBuilder();

        for (int i = 31; i >= 0; i--) {
            int bit = (number >> i) & 1;
            binary.append(bit);
        }

        return binary.toString();
    }
}
