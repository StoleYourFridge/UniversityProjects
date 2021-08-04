#include "Haffman.h"

int main()
{
    string s;
    cout << "Enter text you want to be encoded : " << endl;
    getline(cin, s);

    map <char, int> m;
    FromTextToMap(s, m);

    list <Node*> t;
    CreatingPreviousNodes(t, m);
    Node* root = CreatingTree(t);
    vector<bool> code;
    map <char, vector<bool> > accordance;
    
    AssignmentCodeFunction(root, code, accordance);

    cout << "All the sumbols in binary version : " << endl << endl;
    SymbolsAndTheirCodes(accordance);
    cout << endl << "-------------------------------------------" << endl;

    cout << "All the text in binary version  : " << endl << endl;

    TextInBinaryVersion(s, accordance);
    cout << endl;

    return 0;
}
