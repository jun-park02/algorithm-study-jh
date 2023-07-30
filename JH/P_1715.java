// 문제주소 : https://www.acmicpc.net/problem/1715
// 메모리, 응답시간 : 26244KB | 388ms

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class P_1715 {
    public static void main(String args[]) throws IOException {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            pq.add(Long.parseLong(br.readLine()));
        }
        
        long result = 0;

        while(pq.size() > 1) {
            long cardA = pq.poll();
            long cardB = pq.poll();

            result += (cardA + cardB);
            pq.add(cardA + cardB);
        }
        System.out.println(result);
    }
}
