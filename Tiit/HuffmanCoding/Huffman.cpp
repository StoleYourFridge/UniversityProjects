#include<iostream>
#include "Haffman.h"
using namespace std;


void FromTextToMap(string s, map<char, int>& m)
{
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        m[c]++;
    }
}

void CreatingPreviousNodes(list<Node*>& t, map<char, int> m)
{
    map <char, int> ::iterator i;
    for (i = m.begin(); i != m.end(); i++)
    {
        Node* p = new Node;
        p->c = i->first;
        p->amount = i->second;
        t.push_back(p);
    }
}

Node* CreatingTree(list<Node*>& t)
{
    while (t.size() != 1)
    {
        t.sort(OverloadOfComparison());

        Node* SonLeft = t.front();
        t.pop_front();

        Node* SonRight = t.front();
        t.pop_front();

        Node* parent = new Node(SonLeft, SonRight);
        t.push_back(parent);

    }
    return t.front();
}

void AssignmentCodeFunction(Node* root, vector<bool>& code, map<char, vector<bool> >& accordance)
{
    if (root->left != NULL)
    {
        code.push_back(0);
        AssignmentCodeFunction(root->left, code, accordance);
    }

    if (root->right != NULL)
    {
        code.push_back(1);
        AssignmentCodeFunction(root->right, code, accordance);
    }

    if (root->c) {
        accordance[root->c] = code;
    }

    if (code.size() != 0) code.pop_back();

}

void SymbolsAndTheirCodes(map <char, vector<bool> > accordance)
{
    map <char, vector<bool> > ::iterator trr;
    for (trr = accordance.begin(); trr != accordance.end(); trr++)
    {
        vector<bool> y = trr->second;

        cout << trr->first << " : ";
        for (int n = 0; n < y.size(); n++) cout << y[n];
        cout << endl;
    }
}

void TextInBinaryVersion(string s, map <char, vector<bool> > accordance)
{
    for (int i = 0; i < s.length(); i++)
    {

        char c = s[i];
        vector <bool> x = accordance[c];
        for (int n = 0; n < x.size(); n++)
            cout << x[n];
    }
}