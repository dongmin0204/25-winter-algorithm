import java.io.*;
import java.util.*;

public class Main {
    static class Lecture implements Comparable<Lecture>{
        int start, end;

        public Lecture(int start, int end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(Lecture other) {
            if (this.start == other.start) {
                return this.end - other.end;
            }
            return this.start - other.start;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Lecture> lectures = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            lectures.add(new Lecture(start, end));
        }

        Collections.sort(lectures);
        PriorityQueue<Integer> roomEndTimes = new PriorityQueue<>();

        for (Lecture lecture : lectures) {
            if (!roomEndTimes.isEmpty() && roomEndTimes.peek() <= lecture.start) {
                roomEndTimes.poll();
            }
            roomEndTimes.add(lecture.end);
        }

        System.out.println(roomEndTimes.size());
    }
}
