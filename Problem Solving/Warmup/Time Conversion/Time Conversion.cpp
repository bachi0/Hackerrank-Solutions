#include <bits/stdc++.h>
#include <string>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    string result;
    int h1 = (int)s[0] - '0';
    int h2 = (int)s[1] - '0';
    int h = (h1 * 10 + h2 % 10);
    
    if(s[8] == 'A')
    {
        if(h == 12)
        {
            result += "00";
            for(int i = 2; i < 8; i++)
                result +=s[i];
        }
        else
        {
            for(int i = 0; i < 8; i++)
                result += s[i];
        }
    }
    else
    {
        if(h == 12)
        {
            result += "12";
            for(int i = 2; i < 8; i++)
                result += s[i];
        }
        else
        {
            int hour = h+12;
            result += to_string(hour);
            for(int i = 2; i < 8; i++)
                result += s[i];
        }

    } 
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
