#include <bits/stdc++.h>
#include<string>
#include <algorithm>
using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    int length = s.length();
    int k;
    double sq = sqrt(length);
    int row = floor(sq);
    int col = ceil(sq);
    if(row * col < length)
    {
        row += 1;
    }
    if(length == 1)
        return s;
    //cout<<sq<<" "<<row<<" "<<col<<"\n";
    vector<string> seq(row);
    string result = "";
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(s[k] == '\0')
                seq[i] += ' ';
            else
                seq[i] += s[k++];
            
        }
        //cout<<seq[i]<<"\n";
    }
    for(int i = 0; i < col; i++)
    {
        for(int j = 0; j < row; j++)
        {
            if(seq[j][i] == ' ')
                break;
            else
                result += seq[j][i];
        }
        if(i != col - 1)
            result += " ";
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
