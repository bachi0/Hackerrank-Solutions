import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Result {

    /*
     * Complete the 'biggerIsGreater' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING w as parameter.
     */
    public static void swap(char ch[], int x, int y)
    {
        char temp = ch[x];
        ch[x] = ch[y];
        ch[y] = temp;
    }
    public static String biggerIsGreater(String w) {
        char[] ch = w.toCharArray();
        int n = ch.length;
        int endindex = 0;
        for(endindex = n - 1; endindex > 0; endindex--)
        {
            if(ch[endindex] > ch[endindex - 1])
            {
                break;
            }
        }
        if(endindex == 0)
        {
            return "no answer";
        }
        else
        {
            int first = ch[endindex - 1];
            int second = endindex;
            for(int startindex = endindex + 1; startindex < n; startindex++)
            {
                if(ch[startindex] > first && ch[startindex] < ch[second])
                {
                    second = startindex;
                }
            }
            swap(ch, endindex - 1, second);
            Arrays.sort(ch, endindex, n);
            String result = new String(ch);
            return result;
        }
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int T = Integer.parseInt(bufferedReader.readLine().trim());

        for (int TItr = 0; TItr < T; TItr++) {
            String w = bufferedReader.readLine();

            String result = Result.biggerIsGreater(w);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedReader.close();
        bufferedWriter.close();
    }
}
