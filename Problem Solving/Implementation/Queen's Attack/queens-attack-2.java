import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the queensAttack function below.
    static int queensAttack(int n, int k, int r_q, int c_q, int[][] obstacles) 
    {
        int t = n - r_q;
        int b = r_q - 1;
        int r = n - c_q;
        int l = c_q - 1;
        int tl = Math.min(n - r_q, c_q - 1);
        int tr = n - Math.max(r_q, c_q);
        int bl = Math.min(r_q , c_q) - 1;
        int br = Math.min(r_q - 1, n - c_q);
        
        for(int i = 0; i < k; i++)
        {
            int x = obstacles[i][0];
            int y = obstacles[i][1];
            
            if(x == r_q)
            {
                if(y > c_q)
                {
                    t = Math.min(t, y - c_q - 1);
                }
                else
                {
                    b = Math.min(b, c_q - y - 1);
                }
            }
            else if(y == c_q)
            {
                if(x > r_q)
                {
                    r = Math.min(r, x - r_q - 1);
                }
                else
                {
                    l = Math.min(l, r_q - x - 1);
                }
            }
            else if(Math.abs(x - r_q) == (Math.abs(y - c_q)))
            {
                if(y > c_q && x > r_q)
                {
                    tr = Math.min(tr, y - c_q - 1);
                }
                else if(y > c_q && x < r_q)
                {
                    br = Math.min(br, y - c_q - 1);
                }
                else if(y < c_q && x > r_q)
                {
                    tl = Math.min(tl, c_q - y - 1);
                }
                else if(y < c_q && x < r_q)
                {
                    bl = Math.min(bl, c_q - y - 1);
                }
            }
        }    
        return (t + r + l + b + tr + tl + br + bl);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nk = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nk[0]);

        int k = Integer.parseInt(nk[1]);

        String[] r_qC_q = scanner.nextLine().split(" ");

        int r_q = Integer.parseInt(r_qC_q[0]);

        int c_q = Integer.parseInt(r_qC_q[1]);

        int[][] obstacles = new int[k][2];

        for (int i = 0; i < k; i++) {
            String[] obstaclesRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 2; j++) {
                int obstaclesItem = Integer.parseInt(obstaclesRowItems[j]);
                obstacles[i][j] = obstaclesItem;
            }
        }

        int result = queensAttack(n, k, r_q, c_q, obstacles);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
