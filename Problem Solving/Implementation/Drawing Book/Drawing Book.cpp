#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
    int c1;
    if( n % 2 == 0)
    {
        n += 1;
    }
    if ( p <= (n/2))
    {
        c1 = p / 2 ;
    }
    else
    {
        c1 = (n - p)/2;
    }
    return c1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}
