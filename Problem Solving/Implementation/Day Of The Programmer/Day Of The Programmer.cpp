#include <bits/stdc++.h>
#include<string>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the dayOfProgrammer function below.
string dayOfProgrammer(int year) {
    string noleap = "13.09.";
    string leap = "12.09.";
    string date;
    if(year < 1918 && year >= 1700)
    {
        if(year % 4 == 0 )
        {
            date = leap + to_string(year);
            //return leap;
        }
        else
        {
            date = noleap + to_string(year);
            //return noleap; 
        }
    }
    else if(year > 1918 && year <=2700)
    {
        if((year%100 != 0 && year%4 == 0) || (year % 400 == 0))
        {
            date = leap + to_string(year);
            //return leap;
        }
        else
        {
            date = noleap + to_string(year);
            //return noleap;
        }     
    }
    else
    {
        date = "26.09." + to_string(year);
    }
    return date;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
