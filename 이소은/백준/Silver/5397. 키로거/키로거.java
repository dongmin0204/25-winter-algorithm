import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int i = 0; i < T; i++) {
            String input = br.readLine();
            LinkedList<Character> list = new LinkedList<>();
            int cursor = 0;

            for (int j = 0; j < input.length(); j++) {
                char c = input.charAt(j);
                switch (c) {
                    case '<':
                        if (cursor > 0) {
                            cursor--;
                        }
                        break;
                    case '>':
                        if (cursor < list.size()) {
                            cursor++;
                        }
                        break;
                    case '-':
                        if (cursor > 0) {
                            list.remove(--cursor); //커서 앞의 요소 삭제
                        }
                        break;
                    default:
                        list.add(cursor++, c); //현재 커서 위치에 문자 추가 후 커서 오른족으로 이동
                }

            }
            StringBuilder sb = new StringBuilder();
            for (char ch : list) {
                sb.append(ch);
            }
            System.out.println(sb.toString());

        }
    }
}
