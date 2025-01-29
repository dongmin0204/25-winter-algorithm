import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {


    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        String s = br.readLine();

        Stack<Character> stack = new Stack<>();
        int count = 0;

        for (int i = 0; i < N; i++) {
            while(!stack.isEmpty() && count < K && stack.peek() < s.charAt(i)) {
                count++;
                stack.pop();
            } stack.push(s.charAt(i));
        }

        for (int i = count; i < K; i++) {
            stack.pop();
        }

        StringBuilder sb = new StringBuilder();

        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }
        System.out.println(sb.reverse());


    }
}
