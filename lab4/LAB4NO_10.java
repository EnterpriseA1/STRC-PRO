package lab4;

import java.util.*;

public class LAB4NO_10 {
    static int m, n, t;
    static int[][] road;
    static int[] moves;
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        m = scanner.nextInt();
        n = scanner.nextInt();
        t = scanner.nextInt();
        
        road = new int[t][m];
        moves = new int[t];
        for (int i = 0; i < t; i++) {
            for (int j = 0; j < m; j++) {
                road[i][j] = scanner.nextInt();
            }
        }
        if (backtrack(0, n - 1)) {
            for (int move : moves) {
                System.out.println(move);
            }
        } else {
            System.out.println("No solution found.");
        }
    }
    
static boolean backtrack(int time, int lane) {
        if (time == t) {
            return true;
        }
        if (isSafe(time, lane)) {
            moves[time] = 3;
            if (backtrack(time + 1, lane)) {
                return true;
            }
        }
        
        if (lane > 0 && isSafe(time, lane - 1)) {
            moves[time] = 1; 
            if (backtrack(time + 1, lane - 1)) {
                return true;
            }
        }

        if (lane < m - 1 && isSafe(time, lane + 1)) {
            moves[time] = 2;
            if (backtrack(time + 1, lane + 1)) {
                return true;
            }
        }
        return false;
    }
    static boolean isSafe(int time, int lane) {
        return road[time][lane] == 0;
    }
}
