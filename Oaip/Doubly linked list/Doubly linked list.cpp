#include <iostream>
using namespace std;

struct Queue
{
    int info;
    Queue* next, * prev;
};

Queue* Create(int val)
{
    Queue* t = new Queue;
    t->next = NULL;
    t->prev = NULL;
    t->info = val;
    return t;
}

Queue* PushFront(Queue* begin, int val)
{
    Queue* t = new Queue;
    t->info = val;
    t->next = begin;
    t->prev = NULL;
    return t;
}

Queue* PushBack(Queue* end, int val)
{
    Queue* t = new Queue;
    t->info = val;
    t->prev = end;
    t->next = NULL;
    return t;
}

Queue* Pop(Queue* begin)
{
    Queue* tmp = begin;
    begin = begin->next;
    delete tmp;
    return begin;
}

void ViewBack(Queue* end)
{
    Queue* t = end;
    if (end == NULL)
    {
        cout << "Queue is empty! " << endl;
        return;
    }
    cout << "Queue elements : " << endl;
    while (t != NULL)
    {
        cout << t->info << " ";
        t = t->prev;
    }
    cout << endl;
}

void ViewFront(Queue* begin)
{
    Queue* t = begin;
    if (t == NULL)
    {
        cout << "Queue is empty! " << endl;
        return;
    }
    cout << "Queue elements : " << endl;
    while (t != NULL)
    {
        cout << t->info << " ";
        t = t->next;
    }
    cout << endl;
}



void ClearingTheMemory(Queue** begin, Queue** end)
{
    Queue* t;
    while (*begin != NULL)
    {
        t = *begin;
        *begin = (*begin)->next;
        delete t;
    }
    *end = NULL;
}

void Sort_info(Queue* p)
{
    if (p == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }
    else if (p->next == NULL && p->prev == NULL) cout << "There is only one element " << endl;  return;
    Queue* t = NULL, * t1;
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

void MainTask(Queue* begin)
{
    if (begin == NULL)
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    Queue* ptr = begin, * ptrmax = begin, * ptrmin = begin;
    int min = begin->info, max = begin->info;
    while (ptr != NULL)
    {
        if (ptr->info < min)
        {
            min = ptr->info;
            ptrmin = ptr;
        }
        ptr = ptr->next;
    }
    cout << endl;
    ptr = begin;
    while (ptr != NULL)
    {
        if (ptr->info > max)
        {
            max = ptr->info;
            ptrmax = ptr;
        }
        ptr = ptr->next;
    }
    cout << endl;
    if (ptrmax == ptrmin) {
        cout << "All elements are equal!" << endl;
        return;
    }
    cout << endl << endl << "Maximum element : " << max << endl;
    cout << "Minimum element : " << min << endl << endl;
    Queue* pointone = NULL, * pointtwo = NULL;
    int delcounter = 0;
    ptr = begin;
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
    Queue* ptr2;
    ptr = pointone->next;
    while (ptr != pointtwo)
    {
        ptr2 = ptr;
        ptr = ptr->next;
        delete ptr2;
        delcounter++;
    }
    pointone->next = pointtwo;
    pointtwo->prev = pointone;
    cout << "Amount of deleted elements : " << delcounter;
}

int main()
{
    srand(time(NULL));
    Queue* begin = NULL, * end = NULL;
    int choise, amount, el;
    bool stopitem = true;
    do {
        cout << "What do you want? " << endl;
        cout << "1)Create new queue by pushing elements back" << endl
            << "2)Create new queue by pushing elements front" << endl
            << "3)To fill up new queue by random elements " << endl
            << "4)To add new element by pushing element back" << endl
            << "5)To add new element by pushing element front" << endl
            << "6)To show all queue by viewing back " << endl
            << "7)To show all queue by viewing front " << endl
            << "8) To sort " << endl
            << "9) To do main task " << endl
            << "10) To finish the program" << endl;
        cin >> choise;
        switch (choise)
        {
        case 1:
            ClearingTheMemory(&begin, &end);
            cout << "Enter amount of Queue elements : " << endl;
            cin >> amount;
            cout << "Enter queue elements : " << endl;
            for (int i = 0; i < amount; i++)
            {
                cin >> el;
                if (i == 0)  begin = end = Create(el);
                else {
                    Queue* t = PushBack(end, el);
                    end->next = t;
                    end = t;
                }
            }
            cout << endl << "Queue created! " << endl;
            cout << endl << endl;
            break;
        case 2:
            ClearingTheMemory(&begin, &end);
            cout << "Enter amount of queue elements : " << endl;
            cin >> amount;
            cout << "Enter queue elements : " << endl;
            for (int i = 0; i < amount; i++)
            {
                cin >> el;
                if (i == 0) begin = end = Create(el);
                else {
                    Queue* t = PushFront(begin, el);
                    begin->prev = t;
                    begin = t;
                }
            }
            cout << endl << "Queue created! " << endl;
            cout << endl << endl;
            break;
        case 3:
            ClearingTheMemory(&begin, &end);
            int max, min;
            cout << "Enter amount of Queue elements : " << endl;
            cin >> amount;
            cout << "Enter border numbers for Queue elements :" << endl;
            cout << "Min number : ";
            cin >> min;
            cout << "Max number : ";
            cin >> max;
            for (int i = 0; i < amount; i++)
            {
                el = min + rand() % (max - min + 1);
                if (i == 0) begin = end = Create(el);
                else {
                    Queue* t = PushBack(end, el);
                    end->next = t;
                    end = t;
                }
            }
            cout << endl << "Queue created! " << endl;
            cout << endl << endl;
            break;
        case 4:
            cout << "Enter element : " << endl;
            cin >> el;
            if (begin == NULL && end == NULL) begin = end = Create(el);
            else {
                Queue* t = PushBack(end, el);
                end->next = t;
                end = t;
            }
            cout << "Element included!" << endl;
            break;
        case 5:
            cout << "Enter element : " << endl;
            cin >> el;
            if (begin == NULL && end == NULL) begin = end = Create(el);
            else {
                Queue* t = PushFront(begin, el);
                begin->prev = t;
                begin = t;
            }
            cout << "Element included!" << endl;
            break;
        case 6:
            ViewBack(end);
            break;
        case 7:
            ViewFront(begin);
            break;
        case 8:
            Sort_info(begin);
            cout << "Sorting is done" << endl;
            break;
        case 9:
            MainTask(begin);
            cout << endl << endl;
            break;
        case 10: cout << "The end::" << endl;
            stopitem = false;
            ClearingTheMemory(&begin, &end);
            break;

        default:  cout << "Enter something possible to work with :::" << endl;
            break;
        }
    } while (stopitem);
    return 0;
}




