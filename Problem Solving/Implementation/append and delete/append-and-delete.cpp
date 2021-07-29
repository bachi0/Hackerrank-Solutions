#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    int clength = 0;
    int slength = s.length();
    int tlength = t.length();
    int n = min(slength,tlength);
    for(int i = 0; i < n; i++)
    {
        if(s.at(i) == t.at(i))
            clength++;
        else
            break;
    }
    if( (slength + tlength - 2 * clength) > k)
        return "No";
    else if( (slength + tlength - 2 * clength)%2 == k % 2)
        return "Yes";
    else if( (slength + tlength - k) < 0)
        return "Yes";
    else
        return "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
