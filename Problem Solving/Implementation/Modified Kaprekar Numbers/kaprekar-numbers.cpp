#include <bits/stdc++.h>
#include<string>

using namespace std;

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
    long long int squared;
    int counter = 0;
    int mid = 0;
    for(long i = p; i <= q; i++)
    {
        squared = i * i;
        string strI = to_string(i);
        string s = to_string(squared);
        mid = s.length() - strI.length();
        string left = s.substr(0, mid);
        string right = s.substr(mid);
        int left_num = left.empty()? 0: stoi(left);
        int right_num = right.empty()? 0 : stoi(right);
        // cout<<squared<<" "<<left_num<<" "<<right_num<<endl;
        if( left_num + right_num == i)
        {
            cout<<i<<" ";
            counter = 1;
        }
    }
    if(counter == 0)
    {
        cout<<"INVALID RANGE";
    }
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
