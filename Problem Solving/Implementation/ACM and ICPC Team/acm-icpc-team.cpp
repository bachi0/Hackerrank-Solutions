#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the acmTeam function below.
vector<int> acmTeam(vector<string> topic, int m) 
{
    int size = topic.size();
    int count = 0, res = 1;
    vector<int> result;
    vector<int> temp;
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            count = 0;
            for(int k = 0; k < m; k++)
            {
                if(topic[i][k] == '1' || topic[j][k] == '1')
                {
                    count++;
                }
            }
           temp.push_back(count);
        }
    }
    sort(temp.begin(), temp.end());
    int t = temp.size();
    result.push_back(temp[t - 1]);
    for(int x = t - 2; x > 0; x--)
    {
        if(temp[t-1] == temp[x])
        {
            res++;
        }
        else 
        {
            break;
        }
    }
    result.push_back(res);
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++) {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic,m);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
