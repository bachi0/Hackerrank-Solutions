import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Result {

    /*
     * Complete the 'cavityMap' function below.
     *
     * The function is expected to return a STRING_ARRAY.
     * The function accepts STRING_ARRAY grid as parameter.
     */

    public static List<String> cavityMap(List<String> grid) {
        List<String> result = new ArrayList<>();
        int n = grid.size();
        if(n <= 2)
        {
            return grid;
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                if(i == 0 || i == n - 1)
                {
                    result.add(grid.get(i));
                }
                else
                {
                    String temp = grid.get(i);;
                    char[] t = temp.toCharArray();
                    for(int j = 1; j < n - 1; j++)
                    {                     
                        int l = (int) grid.get(i).charAt(j - 1);
                        int r = (int) grid.get(i).charAt(j + 1);
                        int u = (int) grid.get(i - 1).charAt(j);
                        int b = (int) grid.get(i + 1).charAt(j);
                        int c = (int) grid.get(i).charAt(j);
                      if(l < c && r < c && u < c && b < c)
                        {
                            t[j] = 'X';
                        }
                    }
                    temp = String.valueOf(t);
                    result.add(temp);                
                }
            }
        }
        return result;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<String> grid = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String gridItem = bufferedReader.readLine();
            grid.add(gridItem);
        }

        List<String> result = Result.cavityMap(grid);

        for (int i = 0; i < result.size(); i++) {
            bufferedWriter.write(result.get(i));

            if (i != result.size() - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
