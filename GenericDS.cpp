#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeS            //structure for Singlly Linear & Singly Circular
{
    T data;
    struct nodeS *next;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
struct nodeD              //structure for Doubly Linear & Doubly Circular
{
    T data;
    struct nodeD *next;
    struct nodeD *prev;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
class SinglyLL
{
    public :
        struct nodeS<T> *first;
        int iCount ;

    SinglyLL();
    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
SinglyLL<T> :: SinglyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T> :: Display()
{
    cout<<"The elements of Linkedlist are "<<"\n";
    
    nodeS<T> * temp = first;

    while (temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";    

}

template <class T>
int SinglyLL<T> ::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T> ::InsertFirst(T no)
{
    nodeS<T> * newn = new nodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T> ::InsertLast(T no)
{
    nodeS<T> * newn = new nodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        nodeS<T> * temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;

}

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos)
{   
    int iCount = Count();

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        nodeS<T> * temp = first;
        nodeS<T> * newn = new nodeS<T>;

        newn-> data = no;
        newn-> next = NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp -> next = newn;
        
        iCount++;
    }
}

template <class T>
void SinglyLL<T> ::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        nodeS<T> *temp = first;

        first = first->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T> ::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        nodeS<T> *temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T> ::DeleteAtPos(int iPos)
{
    int iCount = Count();

    if((iPos<1) || (iPos>iCount))
    {
        cout<<"Invalid Position\n";
        return ;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        nodeS<T> *temp1 = first;
        nodeS<T> *temp2= first;

        for(int iCnt = 1; iCnt<iPos-1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;

        iCount--;
    }
    

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
    public :
        struct nodeS<T> *first;
        struct nodeS<T> *last;
        int iCount ;

    SinglyCL();
    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
        

};

template <class T>
SinglyCL<T> :: SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T> ::InsertFirst(T no)
{
    nodeS<T> *newn  = new nodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    last->next = first;
    iCount++;
}

template <class T>
void SinglyCL<T> ::InsertLast(T no)
{
    nodeS<T> *newn  = new nodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;

    }
    else
    {
        last->next = newn;
        newn->next = first;
        last = newn;
    }
    last->next = first;
    iCount++;
}

template <class T>
void SinglyCL<T> ::InsertAtPos(T no, int iPos)
{
    nodeS<T> *newn = new nodeS<T>;
    newn->data = no;
    newn->next = NULL;
    int Cnt = 0;

    Cnt = Count();

    if(iPos<1  || iPos>Cnt+1)
    {
        cout<<"Invalid Position\n";
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == Cnt+1)
    {
        InsertLast(no);
    }
    else
    {   
        nodeS<T> *temp =first;

        for(int iCnt = 1; iCnt<iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
        last->next = first;
    }
    
}

template <class T>
void SinglyCL<T> ::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        nodeS<T> *temp = first;

        first = first->next;
        delete temp;
    }
    last->next = first;
    iCount--;
}

template <class T>
void SinglyCL<T> ::DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else
    {
        nodeS<T> *temp = first;

        while(temp->next != last)
        {
            temp = temp->next;
        }
        delete last;
        last = temp;

    }
    last->next = first;
    iCount--;
}

template <class T>
void SinglyCL<T> ::DeleteAtPos(int iPos)
{
    int Cnt = 0;

    Cnt = Count();

    if(iPos<1  || iPos>Cnt)
    {
        cout<<"Invalid Position\n";
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == Cnt)
    {
        DeleteLast();
    }
    else
    {   
        nodeS<T> *temp  = first;
        nodeS<T> *tempX  = NULL;

        for(int iCnt = 1; iCnt<iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        tempX = temp->next;
        temp->next = temp->next->next; 
        delete tempX;

        last->next = first;
        iCount--;
    }

}

template <class T>
void SinglyCL<T> :: Display()
{   
    nodeS<T> *temp  = first;

    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }while(first != temp);

    cout<<"\n";
}

template <class T>
int SinglyCL<T> ::Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
    public :
        struct nodeD<T> *first;
        int iCount ;

    DoublyLL();
    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

};

template <class T>
DoublyLL<T> :: DoublyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T> :: Display()
{
    nodeD<T> *temp = first;

    while(temp != NULL)
    {   
        cout<<"| "<<temp->data<<" |<->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int DoublyLL<T> ::Count()
{
    return iCount  ;
}

template <class T>
void DoublyLL<T> ::InsertFirst(T no)
{
    nodeD<T> *newn = new nodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;


    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T> ::InsertLast(T no)
{
    nodeD<T> *newn = new nodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;


    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        nodeD<T> *temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;

}

template <class T>
void DoublyLL<T> ::InsertAtPos(T no, int iPos)
{
    nodeD<T> *newn = new nodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    int Cnt = 0;
    Cnt = Count();

    if(iPos<1 || iPos>Cnt+1)
    {
        cout<<"Invalid Position\n";
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == Cnt+1)
    {
        InsertLast(no);
    }
    else
    {
        nodeD<T> *temp = first;

        for(int iCnt = 1; iCnt<iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyLL<T> ::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        nodeD<T> *temp = first;

        first = first->next;
        delete temp;

        first->prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T> ::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        nodeD<T> *temp = first;
        nodeD<T> *tempX = NULL;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        tempX = temp;
        temp = temp->prev;
        temp->next = NULL;

        delete tempX;

    }
    iCount--;
}

template <class T>
void DoublyLL<T> ::DeleteAtPos(int iPos)
{
    int Cnt = 0;
    Cnt = Count();

    if(iPos<1 || iPos>Cnt)
    {
        cout<<"Invalid Position\n";
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == Cnt)
    {
        DeleteLast();
    }
    else
    {
        nodeD<T> *temp = first;
        nodeD<T> *tempX = NULL;

        for(int iCnt = 1; iCnt<iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        tempX = temp->next;

        temp->next = temp->next->next;

        delete tempX;
        

        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
    public :
        struct nodeD<T> *first;
        struct nodeD<T> *last;
        int iCount ;

    DoublyCL();
    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);   

};

template <class T>
DoublyCL<T> :: DoublyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T> :: Display()
{
    nodeD<T> *temp = first;

    for(int iCnt = 1; iCnt<=iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<" |<->";
        temp = temp->next;
    }
    cout<<" NULL\n";
}

template <class T>
int DoublyCL<T> ::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T> ::InsertFirst(T no)
{
    nodeD<T> *newn = new nodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
        
    }
    last->next = newn;
    first->prev = last;
    iCount++;
}

template <class T>
void DoublyCL<T> ::InsertLast(T no)
{
    nodeD<T> *newn = new nodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }
    last->next = newn;
    first->prev = last;
    iCount++;
}

template <class T>
void DoublyCL<T> ::InsertAtPos(T no, int iPos)
{
    nodeD<T> *newn = new nodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    int Cnt = Count();

    if(iPos<1 || iPos>Cnt+1)
    {
        cout<<"Invalid Position\n";
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == Cnt+1)
    {
        InsertLast(no);
    }
    else
    {
        nodeD<T> *temp = first;

        for(int iCnt = 1; iCnt<iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
    last->next = first;
    first->prev = last;
}

template <class T>
void DoublyCL<T> ::DeleteFirst()
{
    if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

template <class T>
void DoublyCL<T> ::DeleteLast()
{
    if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

template <class T>
void DoublyCL<T> ::DeleteAtPos(int iPos)
{
    
    int Cnt = Count();

    if(iPos<1 || iPos>Cnt)
    {
        cout<<"Invalid Position\n";
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == Cnt)
    {
        DeleteLast();
    }
    else
    {
        nodeD<T> *temp = first;
        nodeD<T> *tempX = NULL;

        for(int iCnt = 1; iCnt<iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;

        temp->next->prev = temp;

        iCount--;
    }
    last->next = first;
    first->prev = last;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    SinglyLL <int>obj1;
    SinglyCL <int>obj2;
    DoublyLL <int>obj3;
    DoublyCL <int>obj4;

    int iRet1 = 0;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.InsertLast(101);
    obj1.InsertLast(111);

    obj1.InsertAtPos(55,4);

    obj1.Display();
    iRet1 = obj1.Count();
    cout<<"The count is : "<<iRet1<<endl;

    obj1.DeleteAtPos(4);
    obj1.DeleteFirst();
    obj1.DeleteLast();

    obj1.Display();
    iRet1 = obj1.Count();
    cout<<"The count is : "<<iRet1<<endl;


    int iRet2 = 0;
    obj2.InsertFirst(51);
    obj2.InsertFirst(21);
    obj2.InsertFirst(11);

    obj2.Display();
    iRet2 = obj2.Count();
    cout<<"The count is "<<iRet2<<endl;;

    obj2.InsertLast(101);
    obj2.InsertLast(111);

    obj2.Display();
    iRet2 = obj2.Count();
    cout<<"The count is "<<iRet2<<endl;

    obj2.InsertAtPos(55,4);
    obj2.Display();
    iRet2 = obj2.Count();
    cout<<"The count is "<<iRet2<<endl;

    obj2.InsertAtPos(55,5);
    obj2.Display();
    iRet2 = obj2.Count();
    cout<<"The count is "<<iRet2<<endl;

    obj2.DeleteFirst();
    obj2.DeleteLast();
    obj2.Display();
    iRet2 = obj2.Count();
    cout<<"The count is "<<iRet2<<endl;

    obj2.DeleteAtPos(3);
    obj2.Display();
    iRet2 = obj2.Count();
    cout<<"The count is "<<iRet2<<endl;

    obj2.DeleteAtPos(3);
    obj2.Display();
    iRet2 = obj2.Count();
    cout<<"The count is "<<iRet2<<endl;

    int iRet3 = 0;
    obj3.InsertFirst(51);
    obj3.InsertFirst(21);
    obj3.InsertFirst(11);

    obj3.Display();
    iRet3 = obj3.Count();
    cout<<"The count is "<<iRet3<<endl;

    obj3.InsertLast(101);
    obj3.InsertLast(111);

    obj3.Display();
    iRet3 = obj3.Count();
    cout<<"The count is "<<iRet3<<endl;

    obj3.InsertAtPos(55,3);

    obj3.Display();
    iRet3 = obj3.Count();
    cout<<"The count is "<<iRet3<<endl;

    obj3.DeleteFirst();
    obj3.Display();
    iRet3 = obj3.Count();
    cout<<"The count is "<<iRet3<<endl;

    obj3.DeleteLast();
    obj3.Display();
    iRet3 = obj3.Count();
    cout<<"The count is "<<iRet3<<endl;

    obj3.DeleteAtPos(2);
    obj3.Display();
    iRet3 = obj3.Count();
    cout<<"The count is "<<iRet3<<endl;

    int iRet4 = 0;
    obj4.InsertFirst(51);
    obj4.InsertFirst(21);
    obj4.InsertFirst(11);

    obj4.Display();
    iRet4 = obj4.Count();
    cout<<"The count is : "<<iRet4<<endl;

    obj4.InsertLast(101);
    obj4.InsertLast(111);
    obj4.Display();
    iRet4 = obj4.Count();
    cout<<"The count is : "<<iRet4<<endl;

    obj4.InsertAtPos(55,4);
    obj4.Display();
    iRet4 = obj4.Count();
    cout<<"The count is : "<<iRet4<<endl;

    obj4.DeleteFirst();
    obj4.Display();
    iRet4 = obj4.Count();
    cout<<"The count is : "<<iRet4<<endl;

    obj4.DeleteLast();
    obj4.Display();
    iRet4 = obj4.Count();
    cout<<"The count is : "<<iRet4<<endl;

    obj4.DeleteAtPos(3);
    obj4.Display();
    iRet4 = obj4.Count();
    cout<<"The count is : "<<iRet4<<endl;

    return 0;
}