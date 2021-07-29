#include <bits/stdc++.h>

using namespace std;

// Complete the timeInWords function below.
string timeInWords(int h, int m) {
    string s[] = {"one minute","two minutes","three minutes","four minutes","five minutes","six minutes","seven minutes","eight minutes","nine minutes","ten minutes","eleven minutes","twelve minutes","thirteen minutes","fourteen minutes","quarter","sixteen minutes","seventeen minutes","eighteen minutes","nineteen minutes","twenty minutes","twenty one minutes","twenty two minutes","twenty three minutes","twenty four minutes","twenty five minutes","twenty six minutes","twenty seven minutes","twenty eigh minutest","twenty nine minutes","half"};
    string hour[] = {"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve"};
    string time = "";
    if(m == 0)
    {
        time = hour[h - 1] + " o' clock";
    }
    else if(m >= 1 && m <=30)
    {
        time = s[m - 1] + " past " + hour[h - 1]; 
    }
    else 
    {
        int diff = 60 - m;
        time = s[diff - 1] + " to " + hour[h];
    }
    return time;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}
