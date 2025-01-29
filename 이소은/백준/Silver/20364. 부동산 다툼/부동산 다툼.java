import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int Q = Integer.parseInt(input[1]);

        boolean[] occupied = new boolean[N + 1];

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < Q; i++) {
            int request = Integer.parseInt(br.readLine());
            int conflict = 0;

            for (int k = request; k > 0; k /= 2) {
                if (occupied[k]) {
                    conflict = k;
                }
            }

            if (conflict == 0) {
                occupied[request] = true;
            }

            sb.append(conflict).append("\n");
        }

        System.out.print(sb.toString());
    }
}
