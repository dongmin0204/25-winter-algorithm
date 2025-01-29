import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int musicNum = sc.nextInt();
        int fret = sc.nextInt();

        Stack<Integer>[] stack = new Stack[7];

        for (int i = 0; i < 7; i++) {
            stack[i] = new Stack<>();
        }

        int nowLine, nowFret;
        int move = 0;
        for (int i = 0; i < musicNum; i++) {
            nowLine = sc.nextInt();
            nowFret = sc.nextInt();

            // 쳐야될 음이 낮아서 손을 떼야함
            while (!stack[nowLine].isEmpty() && stack[nowLine].peek() > nowFret) {
                stack[nowLine].pop();
                move++;
            }
            // 잡은 프렛 없음 or 쳐야될 음이 높아서 잡아야 함
            if (stack[nowLine].isEmpty() || stack[nowLine].peek() < nowFret) {
                stack[nowLine].push(nowFret);
                move++;
            }

        }
        System.out.println(move);

    }
}
