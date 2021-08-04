#include <iostream>

using namespace std;

struct Stack
{
    int info;
    Stack* next;
};

Stack* Push(Stack* begin, int val)
{
    Stack* t = new Stack;
    t->info = val;
    t->next = begin;
    return t;
}

void View(Stack* begin)
{
    Stack* t = begin;
    if (begin == NULL)
    {
        cout << "Stack is empty! " << endl;
        return;
    }
    cout << "Stack elements : " << endl;
    while (t != NULL)
    {
        cout << t->info << " ";
        t = t->next;
    }
    cout << endl;
}

Stack* pop(Stack* begin)
{
    Stack* t = begin;
    begin = begin->next;
    delete t;
    return begin;
}

void ClearingTheMemory(Stack** p)
{
    Stack* t;
    while (*p != NULL)
    {
        t = *p;
        *p = (*p)->next;
        delete t;
    }
}

void ClearingTheMemory2(Stack* p)
{
    Stack* t;
    while (p != NULL)
    {
        t = p;
        p = p->next;
        delete t;
    }
}

void Sort_p(Stack** p) {
    Stack* t = NULL, * t1, * r;
    if ((*p)->next->next == NULL) return;
    do {
        for (t1 = *p; t1->next->next != t; t1 = t1->next)
            if (t1->next->info > t1->next->next->info) {
                r = t1->next->next;
                t1->next->next = r->next;
                r->next = t1->next;
                t1->next = r;
            }   
        t = t1->next;
    } while ((*p)->next->next != t);
}

void Sort_info(Stack* p) {
    Stack* t = NULL, * t1;
    int r;
    do {
        for (t1 = p; t1->next != t; t1 = t1->next)
            if (t1->info > t1->next->info) {
                r = t1->info;
                t1->info = t1->next->info;
                t1->next->info = r;
            }
        t = t1;
    } while (p->next != t);
}

void MainTask(Stack* p)
{
    if (p == NULL)
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    Stack* ptr = p, * ptrmax = p, * ptrmin = p;
    int min = p->info, max = p->info;
    while (ptr != NULL)
    {
        if (ptr->info < min)
        {
            min = ptr->info;
            ptrmin = ptr;            
        }
        if (ptr->info > max)
        {
            max = ptr->info;
            ptrmax = ptr;           
        }
        ptr = ptr->next;
    }

    if (ptrmax == ptrmin) {
        cout << "All elements are equal!" << endl;
        return;
    }
    cout << endl << endl << "Maximum element : " << max << endl;
    cout << "Minimum element : " << min << endl << endl;
    Stack *pointone = NULL, * pointtwo = NULL;
    int delcounter = 0;
    ptr = p;
    while (ptr != NULL)
    {
        if (ptr == ptrmax || ptr == ptrmin) {
            pointone = ptr;
            break;
        }
        ptr = ptr->next;
    }
    cout << "---------" << endl << endl;
    if (pointone == ptrmax) pointtwo = ptrmin;
    else pointtwo = ptrmax;
    Stack* ptr2;
    ptr = pointone->next;
    while (ptr != pointtwo)
    {
        ptr2 = ptr;
        ptr = ptr->next;
        delete ptr2;
        delcounter++;
    }
    pointone->next = pointtwo;
    cout << "Amount of deleted elements : " << delcounter;
}

void MainTask2(Stack* p)
{
    int counter = 0;
    Stack* tmp = p;
    while (tmp!= NULL)
    {
        counter++;
        tmp = tmp->next;
    }
    if (counter < 3)
    {
        cout << "Amount of elements in stack is lower than 3!" << endl;
        return;
    }
    else cout << "Higher or equal 3" << endl;
    Stack* ptr = p->next, *ptr2, *ptr3;
    if (ptr->next->next == NULL)
    {
        ptr2 = ptr->next;
        delete ptr2;

        ptr->next = NULL;
    }
    else 
    {
        ptr2 = ptr->next->next;
        ptr3 = ptr->next;
        delete ptr3;
        ptr->next = ptr2;
    }
}

Stack* MainTask3(Stack* p)
{
    int counter = 0;
    Stack* tmp = p;
    while (tmp != NULL)
    {
        counter++;
        tmp = tmp->next;
    }
    if (counter < 3)
    {
        cout << "Amount of elements in stack is lower than 3!" << endl;
        return p;
    }
    Stack* tmp2 = p, *tmpprev = NULL;
    while (tmp2->next->next->next != NULL)
    {    
        tmpprev = tmp2;
        tmp2 = tmp2->next;
    }
    if (tmpprev == NULL)
    {
        tmpprev = tmp2->next;
        delete tmp2;
        return tmpprev;
    }
    else 
    {
        tmpprev->next = tmp2->next;
        delete tmp2;
        return p;
    }
}

void MainTask4(Stack*p)
{
    Stack* tmp;
    while (p != NULL && p->next != NULL)
    {
        tmp = p->next;
        p->next = p->next->next;
        p = p->next;
        delete tmp; 
    }
}

void MainTask5(Stack** p)
{
    if ((*p)->next->next == NULL)
    {
        cout << "There is two elements!! " << endl;
        return;
    }    
    Stack *t = *p, *r = *p;
    while (t->next->next != NULL)
    {
        t = t->next;
    }
    r = t->next;
    Stack* first = *p;
    *p = (*p)->next;
    t->next = first;
    first->next = r;
}

int main()
{
    srand(time(NULL));
    Stack* begin = NULL;
    int choise, amount, el;
    bool stopitem = true;
    do {
        cout << "What do you want? " << endl;
        cout << "1)Create new stack " << endl
            << "2)To fill up by random elements " << endl
            << "3)To add new element " << endl
            << "4)To show all stack " << endl
            << "5) To sort 1th type " << endl
            << "6) To sort 2th type " << endl
            << "7) To do main task 1" << endl
            << "8) To do main task 3" << endl
            << "9) to clear stack" << endl
            << "10) to do main task 4" << endl
            << "11) To do main task 5" << endl
            << "12) To finish program" << endl;
        cin >> choise;
        switch (choise)
        {
        case 1:
            if (begin != NULL) ClearingTheMemory(&begin);
            cout << "Enter amount of stack elements : " << endl;
            cin >> amount;
            cout << "Enter stack elements : " << endl;
            for (int i = 0; i < amount; i++)
            {
                cin >> el;
                begin = Push(begin, el);
            }
            cout << "Stack created!" << endl;
            break;
        case 2:
            if (begin != NULL) ClearingTheMemory(&begin);
            int max, min;
            cout << "Enter amount of stack elements : " << endl;
            cin >> amount;
            cout << "Enter border numbers for stack elements :" << endl;
            cout << "Min number : ";
            cin >> min;
            cout << "Max number : ";
            cin >> max;
            for (int i = 0; i < amount; i++)
            {
                el = min + rand() % (max - min + 1);
                begin = Push(begin, el);
            }
            cout << endl << "Stack created! " << endl;
            break;
        case 3:
            cout << "Enter element you want to include : " << endl;
            cin >> el;
            begin = Push(begin, el);
            cout << "Element entered" << endl;
            break;
        case 4:
            View(begin);
            break;
        case 5:

            begin = Push(begin, 999);
            Sort_p(&begin);
            begin = pop(begin);
            cout << "Sorting is done" << endl;
            break;
        case 6:
            Sort_info(begin);
            cout << "Sorting is done" << endl;
            break;
        case 7:
            MainTask(begin);
            cout << endl << endl;
            break;
        case 8:
            begin = MainTask3(begin);
            cout << endl << endl;
            break;
        case 9:
            ClearingTheMemory(&begin);
            /*if (begin == NULL) cout << "NULL" << endl;
            else cout << " ne NULL" << endl;*/
            break;
        case 10: cout << "The end::" << endl;
            MainTask4(begin);
            break;
        case 11: 
            MainTask5(&begin);
            break;
        case 12:
                stopitem = false;
            ClearingTheMemory(&begin);
            break;
        default:  cout << "Enter something possible to work with :::" << endl;
            break;
        }

    } while (stopitem);
    return 0;
}


