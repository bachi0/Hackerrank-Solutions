#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long counts;
    int x = 0;
    int c = count(s.begin(), s.end(), 'a');
    int size = s.length();
    int diff = n % size;
    for(int i = 0; i < diff; i++)
        if(s[i] == 'a')
            x++;
    counts = c * (n / size) + x;
    return counts;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
