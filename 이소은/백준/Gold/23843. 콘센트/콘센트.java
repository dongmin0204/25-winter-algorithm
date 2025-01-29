import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static PriorityQueue<Integer> device = new PriorityQueue<>(Collections.reverseOrder()); // 전자기기 내림차순
    static PriorityQueue<Integer> socket = new PriorityQueue<>(); // 콘센트 오름차순 (충전 시간 저장)

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()); // 전자기기 개수
        int M = Integer.parseInt(st.nextToken()); // 콘센트 개수

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            device.add(Integer.valueOf(st.nextToken()));
        }

        // 처음 콘센트 할당
        for (int i = 0; i < M && !device.isEmpty(); i++) {
            socket.add(device.poll());
        }

        // 나머지 기기 충전
        while (!device.isEmpty()) {
            int shortestTime = socket.poll(); // 가장 빨리 끝나는 콘센트의 충전 시간
            int nextDeviceTime = device.poll(); // 다음 기기의 충전 시간
            socket.add(shortestTime + nextDeviceTime); // 콘센트에 기기 충전 시간 추가
        }

        int time = 0;
        // 모든 콘센트 중 가장 늦게 끝나는 시간 찾기
        while (!socket.isEmpty()) {
            time = Math.max(time, socket.poll());
        }

        System.out.println(time);
    }
}
