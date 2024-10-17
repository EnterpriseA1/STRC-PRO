import java.util.*;

class MazeSolver {
    static class Position {
        int x, y, steps, wallsBroken;
        boolean usedBomb;

        public Position(int x, int y, int steps, boolean usedBomb, int wallsBroken) {
            this.x = x;
            this.y = y;
            this.steps = steps;
            this.usedBomb = usedBomb;
            this.wallsBroken = wallsBroken;
        }
    }

    static int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public static boolean isWithinBounds(int x, int y, int M, int N) {
        return x >= 0 && x < M && y >= 0 && y < N;
    }

    public static void solveMaze(int[][] maze, int M, int N, int rs, int cs, int re, int ce) {
        Queue<Position> queue = new LinkedList<>();
        queue.offer(new Position(rs, cs, 1, false, 0)); 
        boolean[][][] visited = new boolean[M][N][2]; 
        visited[rs][cs][0] = true; 

        int minSteps = Integer.MAX_VALUE;
        int wallsBrokenToReachExit = -1;   

        while (!queue.isEmpty()) {
            Position current = queue.poll();
            if (current.x == re && current.y == ce) {
                if (current.steps < minSteps) {
                    minSteps = current.steps;
                    wallsBrokenToReachExit = current.wallsBroken; 
                }
                continue; 
            }

            for (int[] direction : directions) {
                int newX = current.x + direction[0];
                int newY = current.y + direction[1];
                if (isWithinBounds(newX, newY, M, N)) {
                    if (maze[newX][newY] == 1 && !visited[newX][newY][current.usedBomb ? 1 : 0]) {
                        visited[newX][newY][current.usedBomb ? 1 : 0] = true;
                        queue.offer(new Position(newX, newY, current.steps + 1, current.usedBomb, current.wallsBroken));
                    }

                    if (maze[newX][newY] == 0 && !current.usedBomb && !visited[newX][newY][1]) {
                        visited[newX][newY][1] = true;
                        queue.offer(new Position(newX, newY, current.steps + 1, true, current.wallsBroken + 1)); 
                    }
                }
            }
        }

        if (minSteps == Integer.MAX_VALUE) {
            System.out.println("No path found.");
        } else {
            System.out.println(wallsBrokenToReachExit);
            System.out.println(minSteps);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int M = sc.nextInt();
        int N = sc.nextInt();
        int rs = sc.nextInt() - 1; 
        int cs = sc.nextInt() - 1;
        int re = sc.nextInt() - 1;
        int ce = sc.nextInt() - 1;

        int[][] maze = new int[M][N];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                maze[i][j] = sc.nextInt();
            }
        }

        solveMaze(maze, M, N, rs, cs, re, ce);
    }
}
