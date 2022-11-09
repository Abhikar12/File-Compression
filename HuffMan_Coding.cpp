#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
typedef long long int li;
typedef long double ld;
using namespace std;

class Node
{
public:
    char c;
    int freq;
    Node *left, *right;

    Node(char c, int freq, Node *left, Node *right)
    {
        this->c = c;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};

struct comparatorFunc
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

void encodeHuffMann(Node *root, string str, map<char, string> &HuffMannCodes)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        HuffMannCodes[root->c] = str;
    }

    encodeHuffMann(root->left, str + '0', HuffMannCodes);
    encodeHuffMann(root->right, str + '1', HuffMannCodes);
}

string decodeString(Node *root, string encodedString)
{
    string ans = "";
    Node *curr = root;
    for (int i = 0; i < encodedString.size(); i++)
    {
        if (encodedString[i] == '0')
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
        if (curr->left == NULL && curr->right == NULL)
        {
            ans += curr->c;
            curr = root;
        }
    }
    return ans;
}

void makingHuffMannCode(string input)
{
    map<char, int> frequencies;
    for (auto i : input)
    {
        frequencies[i]++;
    }

    priority_queue<Node *, vector<Node *>, comparatorFunc> HuffmannTree;

    for (auto x : frequencies)
    {
        Node *newNode = new Node(x.first, x.second, NULL, NULL);
        HuffmannTree.push(newNode);
    }

    while (HuffmannTree.size() != 1)
    {
        Node *left = HuffmannTree.top();
        HuffmannTree.pop();
        Node *right = HuffmannTree.top();
        HuffmannTree.pop();

        Node *newNode = new Node('$', left->freq + right->freq, left, right);
        HuffmannTree.push(newNode);
    }

    Node *root = HuffmannTree.top();

    map<char, string> HuffMannCodes;
    encodeHuffMann(root, "", HuffMannCodes);

    // printing huffmann codes of each character
    for (auto i : HuffMannCodes)
    {
        cout << i.first << " ->";
        for (auto j : i.second)
        {
            cout << j;
        }
        cout << endl;
    }
    // to get our encoded string
    string encodedString = "";
    for (auto c : input)
    {
        encodedString += HuffMannCodes[c];
    }

    // we have obtained our encoded string, no to decode this string back to the original string, we will make a decode function
    string decodedString = decodeString(root, encodedString);
    cout << endl;
    cout << "The Original String -->>  :" << endl;
    cout << input << endl;
    cout << endl;
    cout << "The Encoded String -->>  :" << endl;
    cout << encodedString << endl;
    cout << endl;
    cout << "The Decoded Strring -->> : " << endl;
    cout << decodedString << endl;

    // to find compression rate
    int lengthOfOriginalString = 8 * (input.length()); // chars take 8 bytes
    int lengthOfReducedString = ceil(encodedString.length() / 8);
    double compression = (double)lengthOfReducedString / lengthOfOriginalString;
    cout << endl;
    cout << "The String has been compressed upto " << compression * 100 << "% of the original string" << endl;
}

signed main()
{
    string s;
    cout << endl;
    cout << "Enter The Input String -->> " << endl;
    getline(cin, s);
    makingHuffMannCode(s);
}

/* output -

Enter The Input String -->>
File Compression System Using Huffman Coding in C++
  ->101
+ ->11110
C ->0111
F ->110110
H ->100101
S ->110111
U ->111010
a ->111110
d ->111111
e ->0110
f ->11010
g ->11100
i ->010
l ->111011
m ->0011
n ->000
o ->1000
p ->00101
r ->00100
s ->1100
t ->100110
u ->100111
y ->100100

The Original String -->>  :
File Compression System Using Huffman Coding in C++

The Encoded String -->>  :
11011001011101101101010111100000110010100100011011001100010100000010111011110010011001001100110001110111101011000100001110010110010110011111010110100011111110000101011110001111110100001110010101000010101111111011110

The Decoded Strring -->> :
File Compression System Using Huffman Coding in C++

The String has been compressed upto 6.37255% of the original string

*/