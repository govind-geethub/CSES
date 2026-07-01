#include<bits/stdc++.h>
using namespace std;

// reverse the list add "1" to prefix and push it into the vector
// modify the original by adding "0" prefix
vector<string> grayCode(int n)
{
    if(n == 0) return {""};
    vector<string> gray = {"0", "1"};

    for(int bits=2; bits<=n; bits++)
    {
        int size = gray.size();
        for(int i=size-1; i>=0; i--)
        {
            // add new strings by adding 1 as prefix
            gray.push_back("1" + gray[i]);
        }

        for(int i=0; i<size; i++)
        {
            // updating the original strings with add 0 as prefix
            // to make the length of bits (modify)
            gray[i] = "0" + gray[i];
        }
    }

    return gray;
}

int main()
{
    int n;
    cin >> n;

    vector<string> ans = grayCode(n);
    for(string s : ans) cout << s << endl;
    return 0;
}