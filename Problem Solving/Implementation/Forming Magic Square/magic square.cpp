#include <bits/stdc++.h>
#include<cmath>

using namespace std;

bool is_square(vector<int> v)
{
    int a[3][3];
    int s = 0; 
  
    for (int i = 0; i < 3; ++i)  
        for (int j = 0; j < 3; ++j)  
            a[i][j] = v[3 * i + j];        
  
    for (int j = 0; j < 3; ++j) 
        s += a[0][j]; 
    for (int i = 1; i <= 2; ++i) 
    { 
        int tmp = 0; 
        for (int j = 0; j < 3; ++j) 
            tmp += a[i][j]; 
        if (tmp != s) 
            return 0; 
    } 
    for (int j = 0; j < 3; ++j) 
    { 
        int tmp = 0; 
        for (int i = 0; i < 3; ++i) 
            tmp += a[i][j]; 
        if (tmp != s) 
            return 0; 
    }     
    int tmp = 0; 
    for (int i = 0; i < 3; ++i) 
        tmp += a[i][i]; 
    if (tmp != s) 
        return 0;     
    tmp = 0; 
    for (int i = 0; i < 3; ++i) 
        tmp += a[2 - i][i]; 
    if (tmp != s) 
        return 0; 
    return 1; 
}
int diff(vector<int> a, vector<int> b) 
{ 
    int res = 0; 
  
    for (int i = 0; i < 9; ++i) 
        res += abs(a[i] - b[i]); 
  
    return res; 
} 
void find_magic_squares(vector<vector<int> >& magic_squares) 
{ 
    vector<int> v(9); 
    for (int i = 0; i < 9; ++i) 
        v[i] = i + 1; 
    do { 
        if (is_square(v)) { 
            magic_squares.push_back(v); 
        } 
    } while (next_permutation(v.begin(), v.end())); 
} 

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) 
{
    int res = INT_MAX; 
    vector<int> v(9);
    int k = 0;
    vector<vector<int> > magic_squares; 
    find_magic_squares(magic_squares); 
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            v[k++] = s[i][j];
        }
    }
  
    for (int i = 0; i < magic_squares.size(); ++i) 
    { 
        res = min(res, diff(v, magic_squares[i])); 
    } 
    return res;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
