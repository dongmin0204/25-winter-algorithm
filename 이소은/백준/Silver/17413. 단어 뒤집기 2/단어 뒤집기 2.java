import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        Stack<Character> stack = new Stack<>();
        boolean inTag = false;
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            // 태그 밖에서는 문자를 스택에 쌓고, 공백을 만나면 스택을 비운 뒤 공백도 함께 추가
            if (ch == '<') {
                // 태그 시작 전에 스택에 쌓인 문자를 모두 빼고 뒤집어서 추가
                while (!stack.isEmpty()) {
                    sb.append(stack.pop());
                }
                inTag = true;
                sb.append(ch);
            } else if (ch == '>') {
                inTag = false;
                sb.append(ch);
            } else if (inTag) {
                sb.append(ch);
            } else {
                if (ch == ' ') {
                    while (!stack.isEmpty()) {
                        sb.append(stack.pop());
                    }
                    sb.append(ch);
                } else {
                    stack.push(ch);
                }
            }
        }

        // 마지막으로 스택에 남은 문자가 있다면 모두 빼서 추가
        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }

        System.out.println(sb.toString());
    }
}
