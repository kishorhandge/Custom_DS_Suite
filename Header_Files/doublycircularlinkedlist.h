#pragma once

#include <iostream>

namespace dslib
{

    ///////////////////////////////////////////////////////////////
    //
    //      Doubly Circular Linked List Using Generic Approach
    //
    /////////////////////////////////////////////////////////////////
    
    template <class T>
    class DoublyCLLnode
    {
    public:
        T data;
        DoublyCLLnode<T> *next;
        DoublyCLLnode<T> *prev;

        DoublyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
    };

    template <class T>
    class DoublyCLL
    {
    private:
        DoublyCLLnode<T> *first;
        DoublyCLLnode<T> *last;
        int iCount;

    public:
        DoublyCLL();

        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();

        void Display() const;

        int CheckPerfect(T) const;
        void DisplayPerfect() const;

        int CheckPrime(T) const;
        void DisplayPrime() const;

        int EvenAdd() const;
        int SecMaximum() const;

        int CheckDigit(T) const;
        int SumDigit() const;

        bool Search(T) const;
        int CountEven() const;
        int CountOdd() const;
        int Frequency(T) const;

        void DisplayEven() const;
        void DisplayOdd() const;

        int FirstOcc(T) const;
        int LastOcc(T) const;

        int CountGreater(T) const;
        int CountSmaller(T) const;

        bool IsEmpty() const;

        void ReplaceNegative();
        void IncrementAll();

        void DisplayReverse(DoublyCLLnode<T> *) const;

        void CountDigit() const;

        bool IsPrime(T) const;
        int CountPrime() const;

        void ReplaceEven();

        int Difference() const;

        bool CheckAllPositive() const;

        void DisplayDivByThree() const;
        void DisplayDivByFive() const;

        int CountTwoDigit() const;

        void MakeAbsolute();

        void DisplayGreaterThanAvg() const;

        bool CheckSorted() const;

        void DisplayAlternate() const;

        int DisplayCount(int) const;

        int Count() const;

        void InsertAtPos(T, int);
        void DeleteAtPos(int);

        void ReplaceOdd();
        void MultiplyBtTwo();

        void DisplayEvenPosition() const;
        void DisplayOddPosition() const;
    };

    
////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DoublyCL (Constructor)
//  Input:              NA
//  Output:             NA
//  Description:        Initializes empty Doubly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyCLL<T>::DoublyCLL()
{
    cout << "Object Of DoublyCL gets created\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertFirst
//  Input:              Data of node
//  Output:             NA
//  Description:        Inserts node at first position in Doubly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    if ((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertLast
//  Input:              Data of node
//  Output:             NA
//  Description:        Inserts node at last position in Doubly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode<T> *newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    if ((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertAtPos
//  Input:              Data of node, Position
//  Output:             NA
//  Description:        Inserts node at given position in Doubly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertAtPos(T no, int pos)
{
    DoublyCLLnode<T> *newn = NULL;
    DoublyCLLnode<T> *temp = NULL;

    int iCnt = 0;

    if (pos < 1 || pos > this->iCount + 1)
    {
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == this->iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLnode<T>(no);

        temp = this->first;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DeleteFirst
//  Input:              NA
//  Output:             NA
//  Description:        Deletes first node from Doubly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    DoublyCLLnode<T> *temp = NULL;

    if ((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if (this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;

        delete temp;

        this->last->next = this->first;
        this->first->prev = this->last;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DeleteLast
//  Input:              NA
//  Output:             NA
//  Description:        Deletes last node from Doubly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if ((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if (this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;
        delete this->last->next;

        this->last->next = this->first;
        this->first->prev = this->last;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DeleteAtPos
//  Input:              Position
//  Output:             NA
//  Description:        Deletes node at given position from Doubly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    DoublyCLLnode<T> *temp = NULL;
    DoublyCLLnode<T> *target = NULL;

    int iCnt = 0;

    if (pos < 1 || pos > this->iCount)
    {
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == this->iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;

        delete target;
        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Display
//  Input:              NA
//  Output:             Displays linked list
//  Description:        Displays all nodes of Doubly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::Display()const
{
    if (this->first == NULL && this->last == NULL)
    {
        return;
    }

    DoublyCLLnode<T> *temp = this->first;

    do
    {
        cout << "| " << temp->data << " |<=>";
        temp = temp->next;
    } while (temp != this->last->next);

    cout << "\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CheckPerfect
//  Input:              Number
//  Output:             Integer (1 or 0)
//  Description:        Checks whether given number is Perfect or not
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::CheckPerfect(T iNo)const
{
    int iSum = 0;

    for (int iCnt = 1; iCnt <= (iNo / 2); iCnt++)
    {
        if (iNo % iCnt == 0)
        {
            iSum = iSum + iCnt;
        }
    }

    if (iSum == iNo)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayPerfect
//  Input:              NA
//  Output:             Displays perfect elements
//  Description:        Displays all perfect numbers from linked list
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DisplayPerfect()const
{
    DoublyCLLnode<T> *temp = NULL;
    temp = this->first;

    cout << "Perfect Elements are:\n";

    if (temp == NULL)
    {
        return;
    }

    do
    {
        if (CheckPerfect(temp->data))
        {
            cout << "| " << temp->data << " |->";
        }
        temp = temp->next;
    } while (temp != this->first);

    cout << "NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CheckPrime
//  Input:              Number
//  Output:             Integer (1 or 0)
//  Description:        Checks whether given number is Prime or not
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::CheckPrime(T iNo)const
{
    int iCount = 0;

    for (int iCnt = 2; iCnt <= (iNo / 2); iCnt++)
    {
        if (iNo % iCnt == 0)
        {
            iCount++;
        }
    }

    if (iCount == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayPrime
//  Input:              NA
//  Output:             Displays prime elements
//  Description:        Displays all prime numbers from linked list
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DisplayPrime()const
{
    DoublyCLLnode<T> *temp = NULL;
    temp = this->first;

    cout << "Prime Elements are:\n";

    if (temp == NULL)
    {
        return;
    }

    do
    {
        if (CheckPrime(temp->data))
        {
            cout << "| " << temp->data << " |->";
        }
        temp = temp->next;
    } while (temp != this->first);

    cout << "NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      EvenAdd
//  Input:              NA
//  Output:             Integer
//  Description:        Returns summation of all even elements from linked list
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::EvenAdd()const
{
    int iAdd = 0;

    DoublyCLLnode<T> *temp = NULL;
    temp = this->first;

    if (temp == NULL)
    {
        return iAdd;
    }

    do
    {
        if (temp->data % 2 == 0)
        {
            iAdd = iAdd + temp->data;
        }
        temp = temp->next;
    } while (temp != this->first);

    return iAdd;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      SecMaximum
//  Input:              NA
//  Output:             Integer
//  Description:        Returns second maximum element from linked list
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::SecMaximum()const
{
    int iMaxi = 0;
    int SecMaxi = iMaxi;

    DoublyCLLnode<T> *temp = NULL;
    temp = this->first;

    if (temp == NULL)
    {
        return SecMaxi;
    }

    do
    {
        if (temp->data > iMaxi)
        {
            SecMaxi = iMaxi;
            iMaxi = temp->data;
        }
        else if (SecMaxi < temp->data && temp->data != iMaxi)
        {
            SecMaxi = temp->data;
        }
        temp = temp->next;
    } while (temp != this->first);

    return SecMaxi;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CheckDigit
//  Input:              Number
//  Output:             Integer
//  Description:        Returns summation of digits of given number
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::CheckDigit(T iNo)const
{
    int iSum = 0;
    int iDigit = 0;

    while (iNo != 0)
    {
        iDigit = iNo % 10;
        iSum = iSum + iDigit;
        iNo = iNo / 10;
    }
    return iSum;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      SumDigit
//  Input:              NA
//  Output:             Integer
//  Description:        Returns summation of digits of all elements in linked list
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::SumDigit()const
{
    int iSum = 0;

    DoublyCLLnode<T> *temp = NULL;
    temp = this->first;

    if (temp == NULL)
    {
        return iSum;
    }

    do
    {
        iSum = iSum + CheckDigit(temp->data);
        temp = temp->next;
    } while (temp != this->first);

    return iSum;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Search
//  Input:              Number
//  Output:             Boolean
//  Description:        Searches given element in linked list
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool DoublyCLL<T>::Search(T iNo)const
{
    DoublyCLLnode<T> *temp = NULL;
    temp = this->first;

    if (temp == NULL)
    {
        return false;
    }

    do
    {
        if (temp->data == iNo)
        {
            return true;
        }
        temp = temp->next;
    } while (temp != this->first);

    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CountEven
//  Input:              NA
//  Output:             Integer
//  Description:        Returns count of even elements in linked list
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::CountEven()const
{
    DoublyCLLnode<T> *temp = NULL;
    int Count = 0;

    temp = this->first;

    if (temp == NULL)
    {
        return Count;
    }

    do
    {
        if ((temp->data) % 2 == 0)
        {
            Count++;
        }
        temp = temp->next;
    } while (temp != this->first);

    return Count;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CountOdd
//  Input:              NA
//  Output:             Integer
//  Description:        Returns count of odd elements in linked list
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::CountOdd()const
{
    DoublyCLLnode<T> *temp = NULL;
    int Count = 0;

    temp = this->first;

    if (temp == NULL)
    {
        return Count;
    }

    do
    {
        if ((temp->data) % 2 == 1)
        {
            Count++;
        }
        temp = temp->next;
    } while (temp != this->first);

    return Count;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Frequency
//  Input:              Number
//  Output:             Integer
//  Description:        Returns frequency of given element in linked list
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::Frequency(T iNo)const
{
    DoublyCLLnode<T> *temp = NULL;
    int Count = 0;

    temp = this->first;

    if (temp == NULL)
    {
        return Count;
    }

    do
    {
        if ((temp->data) == iNo)
        {
            Count++;
        }
        temp = temp->next;
    } while (temp != this->first);

    return Count;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayEven
//  Input:              NA
//  Output:             Displays even elements
//  Description:        Displays all even elements from linked list
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DisplayEven()const
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    if (temp == NULL)
    {
        cout << "NULL\n";
        return;
    }

    do
    {
        if ((temp->data) % 2 == 0)
        {
            cout << "| " << temp->data << " |->";
        }
        temp = temp->next;
    } while (temp != this->first);

    cout << "NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayOdd
//  Input:              NA
//  Output:             Displays odd elements
//  Description:        Displays all odd elements from linked list
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DisplayOdd()const
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    if (temp == NULL)
    {
        cout << "NULL\n";
        return;
    }

    do
    {
        if ((temp->data) % 2 == 1)
        {
            cout << "| " << temp->data << " |->";
        }
        temp = temp->next;
    } while (temp != this->first);

    cout << "NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      FirstOcc
//  Input:              Number
//  Output:             Integer
//  Description:        Returns first occurrence position of given element
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::FirstOcc(T iNo)const
{
    DoublyCLLnode<T> *temp = NULL;
    int iPos = 1;

    temp = this->first;

    if (temp == NULL)
    {
        return -1;
    }

    do
    {
        if ((temp->data) == iNo)
        {
            return iPos;
        }

        temp = temp->next;
        iPos++;
    } while (temp != this->first);

    return -1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      LastOcc
//  Input:              Number
//  Output:             Integer
//  Description:        Returns last occurrence position of given element
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::LastOcc(T iNo)const
{
    DoublyCLLnode<T> *temp = NULL;
    int iPos = 1;
    int Lastpos = 0;

    temp = this->first;

    if (temp == NULL)
    {
        return Lastpos;
    }

    do
    {
        if ((temp->data) == iNo)
        {
            Lastpos = iPos;
        }

        temp = temp->next;
        iPos++;
    } while (temp != this->first);

    return Lastpos;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CountGreater
//  Input:              Number
//  Output:             Integer
//  Description:        Returns count of elements greater than given number
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::CountGreater(T iNo)const
{
    DoublyCLLnode<T> *temp = NULL;
    int Count = 0;

    temp = this->first;

    if (temp == NULL)
    {
        return Count;
    }

    do
    {
        if ((temp->data) > iNo)
        {
            Count++;
        }

        temp = temp->next;
    } while (temp != this->first);

    return Count;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CountSmaller
//  Input:              Number
//  Output:             Integer
//  Description:        Returns count of elements smaller than given number
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::CountSmaller(T iNo)const
{
    DoublyCLLnode<T> *temp = NULL;
    int Count = 0;

    temp = this->first;

    if (temp == NULL)
    {
        return Count;
    }

    do
    {
        if ((temp->data) < iNo)
        {
            Count++;
        }

        temp = temp->next;
    } while (temp != this->first);

    return Count;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      IsEmpty
//  Input:              NA
//  Output:             Boolean
//  Description:        Checks whether linked list is empty
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool DoublyCLL<T>::IsEmpty()const
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    if (temp == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      ReplaceNegative
//  Input:              NA
//  Output:             NA
//  Description:        Replaces all negative elements by zero
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::ReplaceNegative()
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    if (temp == NULL)
    {
        return;
    }

    do
    {
        if ((temp->data) < 0)
        {
            temp->data = 0;
        }

        temp = temp->next;
    } while (temp != this->first);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      IncrementAll
//  Input:              NA
//  Output:             NA
//  Description:        Displays all elements after incrementing by 1
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::IncrementAll()
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    if (temp == NULL)
    {
        return;
    }

    do
    {
        cout << "| " << temp->data + 1 << " |->";
        temp = temp->next;
    } while (temp != this->first);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayReverse
//  Input:              Node pointer
//  Output:             Displays list in reverse order
//  Description:        Displays elements of linked list in reverse using recursion
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DisplayReverse(DoublyCLLnode<T> *temp)const
{
    while (temp == NULL)
    {
        return;
    }

    DisplayReverse(temp->next);
    cout << "| " << temp->data << " |->";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CountDigit
//  Input:              NA
//  Output:             Displays digits of each element
//  Description:        Displays number of digits in each node
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::CountDigit()const
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    if (temp == NULL)
    {
        return;
    }

    int Count = 0;
    int iNo = 0;

    do
    {
        Count = 0;
        iNo = temp->data;

        if (iNo == 0)
        {
            Count = 1;
        }
        else
        {
            while (iNo != 0)
            {
                iNo = iNo / 10;
                Count++;
            }
        }

        cout << " \n"
             << temp->data << "-" << Count;

        temp = temp->next;

    } while (temp != this->first);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      IsPrime
//  Input:              Number
//  Output:             Boolean
//  Description:        Checks whether given number is Prime or not
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool DoublyCLL<T>::IsPrime(T iNo)const
{
    int iCnt = 0;

    for (iCnt = 2; iCnt < (iNo / 2); iCnt++)
    {
        if ((iNo % iCnt) == 0)
        {
            return false;
        }
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CountPrime
//  Input:              NA
//  Output:             Integer
//  Description:        Returns count of prime numbers from linked list
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::CountPrime()const
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    if (temp == NULL)
    {
        return 0;
    }

    int Count = 0;

    do
    {
        if (IsPrime(temp->data) == true)
        {
            Count++;
        }

        temp = temp->next;

    } while (temp != this->first);

    return Count;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      ReplaceEven
//  Input:              NA
//  Output:             NA
//  Description:        Replaces all even elements by zero
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::ReplaceEven()
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    if (temp == NULL)
    {
        return;
    }

    do
    {
        if (((temp->data) % 2) == 0)
        {
            temp->data = 0;
        }

        temp = temp->next;

    } while (temp != this->first);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      ReplaceOdd
//  Input:              NA
//  Output:             NA
//  Description:        Replaces all odd elements by 1
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::ReplaceOdd()
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    if (temp == NULL)
    {
        return;
    }

    do
    {
        if (((temp->data) % 2) == 1)
        {
            temp->data = 1;
        }

        temp = temp->next;

    } while (temp != this->first);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      MultiplyBtTwo
//  Input:              NA
//  Output:             NA
//  Description:        Displays all elements after multiplying by 2
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::MultiplyBtTwo()
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    if (temp == NULL)
    {
        return;
    }

    do
    {
        cout << "| " << (temp->data) * 2 << " |->";
        temp = temp->next;
    } while (temp != this->first);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayEvenPosition
//  Input:              NA
//  Output:             Displays elements at even positions
//  Description:        Displays all elements present at even positions
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DisplayEvenPosition()const
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    if (temp == NULL)
    {
        return;
    }

    int Count = 0;

    do
    {
        if (Count % 2 == 0)
        {
            cout << "| " << (temp->data) << " |->";
        }
        Count++;
        temp = temp->next;
    } while (temp != this->first);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayOddPosition
//  Input:              NA
//  Output:             Displays elements at odd positions
//  Description:        Displays all elements present at odd positions
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DisplayOddPosition()const
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    if (temp == NULL)
    {
        cout << "NULL\n";
        return;
    }

    int Count = 0;

    do
    {
        if (Count % 2 == 1)
        {
            cout << "| " << (temp->data) << " |->";
        }
        Count++;
        temp = temp->next;
    } while (temp != this->first);

    cout << "NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Difference
//  Input:              NA
//  Output:             Integer
//  Description:        Returns difference between maximum and minimum elements
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::Difference()const
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    if (temp == NULL)
    {
        return 0;
    }

    int iMax = temp->data;
    int iMin = temp->data;

    do
    {
        if ((temp->data) > iMax)
        {
            iMax = temp->data;
        }

        if ((temp->data) < iMin)
        {
            iMin = temp->data;
        }

        temp = temp->next;

    } while (temp != this->first);

    return (iMax - iMin);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CheckAllPositive
//  Input:              NA
//  Output:             Boolean
//  Description:        Checks whether all elements are positive
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool DoublyCLL<T>::CheckAllPositive()const
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    if (temp == NULL)
    {
        return true;
    }

    do
    {
        if ((temp->data) < 0)
        {
            return false;
        }

        temp = temp->next;

    } while (temp != this->first);

    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayDivByThree
//  Input:              NA
//  Output:             Displays elements
//  Description:        Displays elements divisible by 3
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DisplayDivByThree()const
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    if (temp == NULL)
    {
        cout << "NULL\n";
        return;
    }

    do
    {
        if (((temp->data) % 3) == 0)
        {
            cout << "| " << temp->data << " |->";
        }

        temp = temp->next;

    } while (temp != this->first);

    cout << "NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayDivByFive
//  Input:              NA
//  Output:             Displays elements
//  Description:        Displays elements divisible by 5
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DisplayDivByFive()const
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    if (temp == NULL)
    {
        cout << "NULL\n";
        return;
    }

    do
    {
        if (((temp->data) % 5) == 0)
        {
            cout << "| " << temp->data << " |->";
        }

        temp = temp->next;

    } while (temp != this->first);

    cout << "NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CountTwoDigit
//  Input:              NA
//  Output:             Integer
//  Description:        Returns count of two-digit elements
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::CountTwoDigit()const
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    if (temp == NULL)
    {
        return 0;
    }

    int iNo = 0;
    int Count = 0;
    int iTwoCnt = 0;
    int iDigit = 0;

    do
    {
        Count = 0;
        iNo = temp->data;

        while (iNo != 0)
        {
            iDigit = iNo % 10;
            Count++;
            iNo = iNo / 10;
        }

        if (Count == 2)
        {
            iTwoCnt++;
        }

        temp = temp->next;

    } while (temp != this->first);

    return iTwoCnt;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      MakeAbsolute
//  Input:              NA
//  Output:             NA
//  Description:        Converts all elements to absolute values
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::MakeAbsolute()
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    if (temp == NULL)
    {
        return;
    }

    do
    {
        if ((temp->data) < 0)
        {
            temp->data = -(temp->data);
        }
        else
        {
            temp->data;
        }

        temp = temp->next;

    } while (temp != this->first);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayGreaterThanAvg
//  Input:              NA
//  Output:             Displays elements
//  Description:        Displays elements greater than average
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DisplayGreaterThanAvg()const
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    if (temp == NULL)
    {
        return;
    }

    int Count = 0;
    float fAvg = 0.0f;
    int iSum = 0;

    do
    {
        iSum = iSum + temp->data;
        Count++;
        temp = temp->next;

    } while (temp != this->first);

    if (Count == 0)
    {
        return;
    }

    fAvg = (float)(iSum) / Count;

    temp = this->first;

    do
    {
        if ((temp->data) > fAvg)
        {
            cout << "| " << temp->data << " |->";
        }

        temp = temp->next;

    } while (temp != this->first);

    cout << "NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CheckSorted
//  Input:              NA
//  Output:             Boolean
//  Description:        Checks whether linked list is sorted
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool DoublyCLL<T>::CheckSorted()const
{
    if (this->first == NULL || this->first->next == this->first)
    {
        return true;
    }

    DoublyCLLnode<T> *temp = NULL;
    temp = this->first;

    do
    {
        if (temp->next != this->first)
        {
            if ((temp->data) > (temp->next->data))
            {
                return false;
            }
        }

        temp = temp->next;

    } while (temp != this->first);

    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayAlternate
//  Input:              NA
//  Output:             Displays elements
//  Description:        Displays alternate elements
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DisplayAlternate()const
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    if (temp == NULL)
    {
        cout << "NULL\n";
        return;
    }

    int Count = 1;

    do
    {
        if (Count % 2 == 1)
        {
            cout << "| " << temp->data << " |->";
        }

        Count++;
        temp = temp->next;

    } while (temp != this->first);

    cout << "NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayCount
//  Input:              Position
//  Output:             Integer
//  Description:        Returns count of nodes at given positional interval
//  Author:             Kishor Suryabhan Handge
//  Date:               18-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::DisplayCount(int pos)const
{
    DoublyCLLnode<T> *temp = NULL;

    temp = this->first;

    if (temp == NULL)
    {
        return 0;
    }

    int Count = 0;
    int iPos = 1;

    do
    {
        if ((iPos % pos) == 0)
        {
            Count++;
        }

        iPos++;
        temp = temp->next;

    } while (temp != this->first);

    return Count;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Count
//  Input:              NA
//  Output:             Integer
//  Description:        Returns number of nodes in Doubly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::Count()const
{
    return this->iCount;
}

}