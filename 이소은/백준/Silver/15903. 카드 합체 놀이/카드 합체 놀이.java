import java.io.*;
import java.util.*;

public class Main {
    static PriorityQueue<Long> pq = new PriorityQueue<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        for(int i=0; i<n; i++) {
            pq.add(Long.valueOf(st.nextToken()));
        }

        for (int i = 0; i < m; i++) {
            Long a = pq.poll();
            Long b = pq.poll();
            if (a == null || b == null) break;
            pq.add(a + b);
            pq.add(a + b);
        }


        long ans = 0;


        while(!pq.isEmpty()) {
            ans+=pq.poll();
        }
        System.out.println(ans);
    }
}