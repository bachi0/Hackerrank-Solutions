#include <bits/stdc++.h>
#include<cmath>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int pickingNumbers(vector<int> a) {
    /*
    int size = a.size();
    int result = 0, count = 1;
    int temp = a[0];
    for(int i = 1; i < size; ++i)
    {
        if(temp == a[i] || temp + 1 == a[i])
        {
            count++;
        }
        else
        {
            if( count > result)
            {
                result = count;
            }
            count;
            temp = a[i];
        }
    }*/
    sort(a.begin(), a.end());
    int n = a.size();
    vector<int> counts(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (abs(a[j] - a[i]) <= 1)
                ++counts[i];
            else
                break;
        }
    }
    int result = *max_element(counts.begin(),counts.end());
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = pickingNumbers(a);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}