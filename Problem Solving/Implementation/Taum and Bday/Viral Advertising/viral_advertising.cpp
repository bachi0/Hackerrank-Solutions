#include <bits/stdc++.h>
#include<cmath>
using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {
    int person = 5;
    int likes = 0, share;
    for(int i = 1; i <= n; i++)
    {
        likes += floor(person/2);
        share = floor(person/2);
        person =share * 3; 
    }
    return likes;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
