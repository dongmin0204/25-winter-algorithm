import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

    
        PriorityQueue<Integer> gifts = new PriorityQueue<>(Collections.reverseOrder());

        StringBuilder output = new StringBuilder();
        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            StringTokenizer st = new StringTokenizer(line);
            int a = Integer.parseInt(st.nextToken());

            if (a == 0) {
                if (gifts.isEmpty()) {
                    output.append("-1\n");
                } else {
                    output.append(gifts.poll()).append("\n");
                }
            } else {
                for (int j = 0; j < a; j++) {
                    if (st.hasMoreTokens()) {
                        gifts.add(Integer.parseInt(st.nextToken()));
                    }
                }
            }
        }
        System.out.print(output.toString());
    }
}
