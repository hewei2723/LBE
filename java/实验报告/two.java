import java.util.Scanner;

public class two {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("请输入一个四位整数: ");
        int inputNumber = scanner.nextInt();

        int digit1 = inputNumber / 1000;
        int digit2 = (inputNumber / 100) % 10;
        int digit3 = (inputNumber / 10) % 10;
        int digit4 = inputNumber % 10;

        digit1 = (digit1 + 5) % 10;
        digit2 = (digit2 + 5) % 10;
        digit3 = (digit3 + 5) % 10;
        digit4 = (digit4 + 5) % 10;

        int temp = digit1;
        digit1 = digit4;
        digit4 = temp;

        temp = digit2;
        digit2 = digit3;
        digit3 = temp;

        int encryptedNumber = digit1 * 1000 + digit2 * 100 + digit3 * 10 + digit4;

        System.out.println("加密后的数字是: " + encryptedNumber);
    }
}