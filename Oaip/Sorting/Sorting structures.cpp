#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct product {
	char name[100];
	int amount;
	int manufactory;
};

const char NameOfFile[100] = "Products.txt";

void writefile(vector<product>a)
{
    ofstream fout(NameOfFile, ios::out);
        if (!fout.is_open()) cout << "File does not exist!" << endl;
        else
        {
            for (int i = 0; i < a.size(); i++)
            {
                fout << a[i].name << " "
                    << a[i].amount << " "
                    << a[i].manufactory;
                if (i < a.size() - 1) fout << endl;
            }
        }
        fout.close();
}

void readfromfile(vector<product>&a)
{
    ifstream fin(NameOfFile, ios::in);
    if (!fin.is_open()) cout << "File does not exist!" << endl;
    else 
    {
        while (!fin.eof())
        {
            product test;
            fin >> test.name
                >> test.amount
                >> test.manufactory;
            a.push_back(test);
        }
    }

    fin.close();
}

void add(vector<product>&a) 
{
    product test; 
    cout << "Enter products name : " << endl;
    cin >> test.name;
    cout << "Enter amount of products : " << endl;
    cin >> test.amount; 
    cout << "Enter manufactory number : " << endl;
    cin >> test.manufactory;
    a.push_back(test);
    cout << "Product created! " << endl;
}

void show(vector<product>a) 
{
    cout <<  "---------------------------------------------------------" << endl << "List of products : " << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << endl;
        cout << "Product number " << i + 1 << endl;
        cout << "Products name : " << a[i].name <<  endl;      
        cout << "Amount of products : "<< a[i].amount << endl;   
        cout << "Manufactory number : " << a[i].manufactory << endl;
        cout << endl;
    }
    cout << "---------------------------------------------------------" << endl << endl;
}

void Quick_Sort (vector<product> &a, int begin, int end)
{
    int left, right, x;
    product y;
   left = begin;
   right = end;
   x = a[(left + right) / 2].amount;
    do {
         while (a[left].amount > x)  left++;
         while (x > a[right].amount) right--;
         if (left <= right) {
             y = a[left];
             a[left] = a[right];
             a[right] = y;
             left++;
             right--;
         }
    } while (left <= right);
    if (begin < right) Quick_Sort(a, begin, right);
    if (left < end) Quick_Sort(a, left, end);

} 

void DirectSelection(vector<product>&a)
{
    int i_max, j;
    product r;
    for (int i = 0; i < a.size(); i++) {
        i_max = i;
        for (j = i + 1; j < a.size(); j++)
            if (a[i_max].amount < a[j].amount) i_max = j;
        if (i_max != i) {
            r = a[i_max];    a[i_max] = a[i];     a[i] = r;
        }
    }
}

void LinearSearch(vector<product>a, int b)
{ 
    int i, kod = 0;
    for (i = 0; i < a.size(); i++)
        if (a[i].amount == b) {
            kod++;
            cout << "---------------------------------------------------" << endl;
            cout << "Products name : " << a[i].name << endl;
            cout << "Amount of products : " << a[i].amount << endl;
            cout << "Manufactory number : " << a[i].manufactory << endl;
            cout << "---------------------------------------------------" << endl;
        }
    if (kod == 0) cout << "Nothing found!" << endl << endl;
}

void BinarySearch(vector<product>a, int x)
{
    int i_max, j;
    product r;
    for (int i = 0; i < a.size(); i++) {
        i_max = i;
        for (j = i + 1; j < a.size(); j++)
            if (a[i_max].amount < a[j].amount) i_max = j;
        if (i_max != i) {
            r = a[i_max];    a[i_max] = a[i];     a[i] = r;
        }
    }

    int q = 0, e = a.size() - 1, m;
    while (q < e) {
        m = (q + e) / 2;
        if (x < a[m].amount) q = m + 1;
        else e = m;
    }
    if (a[q].amount == x)
    {
        cout << "---------------------------------------------------" << endl;
        cout << "Products name : " << a[q].name << endl;
        cout << "Amount of products : " << a[q].amount << endl;
        cout << "Manufactory number : " << a[q].manufactory << endl;
        cout << "---------------------------------------------------" << endl;
    }
    else cout << "Nothing found!" << endl;
}

void MainTask (vector<product>a)
{
    int manufactorynumber;
    cout << "Enter number of manufactory : ";
    cin >> manufactorynumber;
    
    int i_max, j;
    product r;
    for (int i = 0; i < a.size(); i++) {
        i_max = i;
        for (j = i + 1; j < a.size(); j++)
            if (a[i_max].amount < a[j].amount) i_max = j;
        if (i_max != i) {
            r = a[i_max];    a[i_max] = a[i];     a[i] = r;
        }
    }
    int sign = 0;
    for  (int i = 0;  i  < a.size() ;  i ++)
    {
        if (a[i].manufactory == manufactorynumber)
        {
            sign++;
                if (sign == 1) cout << "List of products : " << endl; 
            cout << a[i].name << " :: amount : " << a[i].amount <<  endl;
        }
        
    }

    if (sign == 0) cout << "Nothing found!" << endl;

    cout << endl;
}



int main()
{
    vector<product>list; 
    list.reserve(15);
    readfromfile(list);
    int choise; 
    bool endsign = true;
    do
    {
        cout << " What do you want to do? " << endl;
        cout << "1) Add product : " << endl;
        cout << "2) Show list of products : " << endl; 
        cout << "3) To do search : " << endl;
        cout << "4) To do main task : " << endl;
        cout << "5) To sort : " << endl;
        cout << "6) To finish : " << endl;

    cin >> choise;
    
        switch (choise)
        {
        case 1:
            add(list);
            cout << endl;
            break;
        case 2:
            show(list);
            cout << endl;
            break;
        case 3:  
            int choise4;
            int choise5;
            cout << "Choose type of searching : " << endl << "1)LinearSearch :: 2)BinarySearch " << endl;
            cin >> choise5;
            cout << "Enter amount of elements you search : " << endl;
            cin >> choise4;
            switch (choise5)
            {
            case 1:
                cout << endl;
                LinearSearch(list, choise4);
                cout << endl;
                break;

            case 2:
                cout << endl;
                BinarySearch(list, choise4);
                cout << endl;
                break;
            default: cout << "Enter correct information : " << endl;
                break;
            }

            break;
        case 4:
            MainTask(list);
            break;

        case 5: 

            int choise3;
            cout << "Choose type of sorting : " << endl << "1) QuickSort and 2)DirectSelection " << endl;
            cin >> choise3;
            switch (choise3)
            {
            case 1:
                Quick_Sort(list, 0, list.size() - 1);
                show(list);
                cout << "Sorted from highest to lowest" << endl;
                break;
            case 2:
                DirectSelection(list);
                show(list);
                cout << "Sorted from highest to lowest" << endl;
                break;

            default: cout << "Enter correct information : " << endl;
                break;
            }
            show(list);
            break;
        case 6: endsign = false;
            cout << "Have a nice day! " << endl;
            break;
        default:
            cout << "Enter correct information : " << endl;
            break;        
        }
    } while (endsign);

    writefile(list);
	return 0;
}


