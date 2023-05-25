#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;

    try
    {
        cout << stoi(s) << endl;
    }
    catch (...)
    {
        cout << "Bad String" << endl;
    }

    return 0;
}
