/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab8;

/**
 *
 * @author Kkhamwiset
 */
import java.util.*;

class Subway {
    int N, M, Q;
    List<List<Integer>> stations;
    List<Set<Integer>> lines; 
    
    public Subway(int N, int M) {
        this.N = N;
        this.M = M;
        this.stations = new ArrayList<>(M);
        this.lines = new ArrayList<>(N + 1);
        for (int i = 0; i <= N; i++) {
            lines.add(new HashSet<>());
        }
    }
    
    public void addLine(List<Integer> stationsOnLine, int lineIndex) {
        stations.add(stationsOnLine);
        for (int station : stationsOnLine) {
            lines.get(station).add(lineIndex);
        }
    }
    
    public int minChanges(int start, int end) {
        if (start == end) return 0;
        Queue<Integer> queue = new LinkedList<>();
        int[] changes = new int[N + 1];
        Arrays.fill(changes, -1);
        
        queue.offer(start);
        changes[start] = 0;
        
        while (!queue.isEmpty()) {
            int current = queue.poll();
            if (current == end) 
                return changes[current] - 1; 
            
            for (int line : lines.get(current)) {
                for (int nextStation : stations.get(line)) {
                    if (changes[nextStation] == -1) {
                        changes[nextStation] = changes[current] + 1;
                        queue.offer(nextStation);
                    }
                }
            }
        }
        
        return -1;
    }
}
public class LAB8NO7 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        Subway subway = new Subway(N, M);
        for (int i = 0; i < M; i++) {
            int Si = scanner.nextInt();
            List<Integer> stationsOnLine = new ArrayList<>(Si);
            for (int j = 0; j < Si; j++) {
                stationsOnLine.add(scanner.nextInt());
            }
            subway.addLine(stationsOnLine, i);
        }
        
        int Q = scanner.nextInt();
        for (int i = 0; i < Q; i++) {
            int Ai = scanner.nextInt();
            int Bi = scanner.nextInt();
            int result = subway.minChanges(Ai, Bi);
            if (result == -1) {
                System.out.println("impossible");
            } else {
                System.out.println(result);
            }
        }
    }

}
