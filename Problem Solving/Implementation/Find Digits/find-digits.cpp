#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.
int findDigits(int n) {
    vector<int> solo;
    int temp = n, vari, count = 0;
    while(temp != 0)
    {
        vari = temp % 10;
        solo.push_back(vari);
        temp /= 10;
    }
    for(int i = 0; i < solo.size(); i++)
    {
        temp = solo[i];
        if( temp != 0 && n % temp == 0 )
        {
            count++;
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
