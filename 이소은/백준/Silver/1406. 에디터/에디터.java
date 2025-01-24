import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.ListIterator;

public class Main {
    public static void main(String[] args) throws IOException {
        LinkedList<String> editor = new LinkedList<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        for (int i = 0; i < line.length(); i++) {
            editor.add(String.valueOf(line.charAt(i)));
        }

        ListIterator<String> it = editor.listIterator(editor.size());
        int cmdCount = Integer.parseInt(br.readLine());
        for (int i = 0; i < cmdCount; i++) {
            String cmd = br.readLine();
            char type = cmd.charAt(0);

            switch (type) {
                case 'P':
                    it.add(String.valueOf(cmd.charAt(2)));
                    break;
                case 'L':
                    if (it.hasPrevious()) it.previous();
                    break;
                case 'B':
                    if (it.hasPrevious()) {
                        it.previous();
                        it.remove();
                    }
                    break;
                case 'D':
                    if (it.hasNext()) it.next();
                    break;
            }
        }
        
        StringBuilder sb = new StringBuilder();
        for (String s : editor) {
            sb.append(s);
        }
        System.out.println(sb.toString());
    }
}
