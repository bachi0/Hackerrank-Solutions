import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Result {
    public static int workbook(int n, int k, List<Integer> arr) {
        int pagecount = 1, curpage = 1, count = 0, t;
        for(int i = 0; i < n; i++)
        {
            t = arr.get(i);
            curpage = 1;
            while(t >= k)
            {
              t = t - k;
              if(pagecount > ((curpage - 1) * k) && pagecount <= (curpage * k))
              {
                  count++;
              }
              curpage += 1;
              pagecount += 1;  
            }
            if(t != 0)
            {
                if(pagecount > ((curpage - 1) * k) && pagecount <= arr.get(i))
                {
                    count++;
                }
                pagecount += 1;
            }
        }
        return count;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(firstMultipleInput[0]);

        int k = Integer.parseInt(firstMultipleInput[1]);

        String[] arrTemp = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        List<Integer> arr = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrTemp[i]);
            arr.add(arrItem);
        }

        int result = Result.workbook(n, k, arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
