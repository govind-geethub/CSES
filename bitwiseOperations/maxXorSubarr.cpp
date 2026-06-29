#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Node
{
    Node* links[2] = {NULL};

    bool keyExist(int bit)
    {
        return (links[bit] != NULL);
    }

    Node* get(int bit)
    {
        return links[bit];
    }

    void put(int bit, Node* newNode)
    {
        links[bit] = newNode;
    }
};

class Trie
{
    private:
    Node* root;
    public:
    Trie()
    {
        root = new Node(); 
    }

    void insert(int num)
    {
        Node* temp = root;
        for(int i=31; i>=0; i--)
        {
            int bit = (num >> i) & 1;
            if( !temp->keyExist(bit) )
            {
                temp->put(bit, new Node());
            }
            temp = temp->get(bit);
        }
    }

    ll getMaxXor(int num)
    {
        ll maxNum = 0;
        Node* temp = root;
        for(int i=31; i>=0; i--)
        {
            int bit = (num >> i) & 1;

            int opp = 1 - bit;
            if(temp->keyExist(opp))
            {
                maxNum = maxNum | (1LL << i);
                temp = temp->get(opp);
            }

            else temp = temp->get(bit);
        }

        return maxNum;
    }
};

// creating a prefix xor trie
// to calculate the max xor subarray
ll maxXor(int n, vector<int> &v)
{
    Trie trie;
    trie.insert(0);

    ll prefix = 0;
    ll maxi = 0;
    
    // prefix[l,r] = prefix[l-1] ^ prefix[r]
    for(int i=0; i<n; i++)
    {
        prefix = prefix ^ v[i];
        maxi = max(maxi, trie.getMaxXor(prefix));   // best prefix xor
        trie.insert(prefix);
    }

    return maxi;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    cout << maxXor(n,v) << endl;
    return 0;
}