#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the plusMinus function below.
void plusMinus(vector<int> arr) {
    double size =  arr.size();
    double pos_count = 0, neg_count = 0, zero_count = 0;
    if(size < 1 || size > 100)
    {
        exit(0);
    }
    else
    {
        for(int arr_itr = 0; arr_itr < size; arr_itr++)
        {
            if(arr[arr_itr] < -100 || arr[arr_itr] > 100)
            {
                exit(0);
            }
            else
            {
                if(arr[arr_itr] < 0)
                {
                    neg_count++;
                }
                else if(arr[arr_itr] > 0)
                {
                    pos_count++;
                }
                else
                {
                    zero_count++;
                }
            }
        }
    }
    double pos = pos_count / size;
    double neg = neg_count / size;
    double zero = zero_count / size;
    cout<<fixed<<setprecision(6)<<pos<<"\n";
    cout<<fixed<<setprecision(6)<<neg<<"\n";
    cout<<fixed<<setprecision(6)<<zero<<"\n";


}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    plusMinus(arr);

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
