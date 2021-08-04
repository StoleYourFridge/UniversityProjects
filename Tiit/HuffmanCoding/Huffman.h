#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
using namespace std;

class Node
{
public:
    int amount;
    char c;
    Node* left, * right;

    Node(Node* LeftSon, Node* RightSon)
    {
        left = LeftSon;
        right = RightSon;
        amount = LeftSon->amount + RightSon->amount;
    }
    Node() {}
};

struct OverloadOfComparison
{
    bool operator()(const Node* left, const Node* right) const
    {
        return left->amount < right->amount;
    }
};

void FromTextToMap(string s, map<char, int>& m);
void CreatingPreviousNodes(list<Node*>& t, map<char, int> m);
Node* CreatingTree(list<Node*>& t);
void AssignmentCodeFunction(Node* root, vector<bool>& code, map<char, vector<bool> >& accordance);
void SymbolsAndTheirCodes(map <char, vector<bool> > accordance);
void TextInBinaryVersion(string s, map <char, vector<bool> > accordance);