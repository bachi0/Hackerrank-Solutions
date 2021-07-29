#include <bits/stdc++.h>
using namespace std;
vector<int> Multiply( int x, vector<int> result, int &count)
{
    int carry = 0;
    vector<int> tempRes;
    for(int i = 0; i < count; i++)
    {
        int prod = (result[i] * x) + carry;
        tempRes.push_back(prod % 10);
        carry = prod / 10;

    }
    while(carry)
    {
        tempRes.push_back(carry % 10);
        carry = carry/10;
        count++;
    }
    return tempRes;
}
// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    vector<int> result;
    int counter = 1;
    result.push_back(1);
    for(int i = 2; i <= n; i++)
    {
        result = Multiply(i, result, counter);
    }
    for(int j = result.size() - 1; j >= 0; j--)
    {
        cout<<result[j];
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
