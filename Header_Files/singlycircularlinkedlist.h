#pragma once

#include <iostream>

namespace dslib
{

///////////////////////////////////////////////////////////////
//
//        Singly Circular Linked List Using Generic Approach
//
/////////////////////////////////////////////////////////////////

template <class T>
class SinglyCLLnode
{
public:
    T data;
    SinglyCLLnode<T> *next;

    SinglyCLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

template <class T>
class SinglyCL
{
private:
    SinglyCLLnode<T> *first;
    SinglyCLLnode<T> *last;
    int iCount;

public:
    SinglyCL();

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

    void DisplayReverse(SinglyCLLnode<T> *) const;

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
//  Function Name:      SinglyCL (Constructor)
//  Input:              NA
//  Output:             NA
//  Description:        Initializes empty Singly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyCL<T>::SinglyCL()
{
    cout << "Inside Constructor Of SinglyCL:\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertFirst
//  Input:              Data of node
//  Output:             NA
//  Description:        Inserts node at first position in Singly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T> *newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if ((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
        this->last->next = this->first;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
        this->last->next = this->first;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertLast
//  Input:              Data of node
//  Output:             NA
//  Description:        Inserts node at last position in Singly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    SinglyCLLnode<T> *newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if ((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }

    this->last->next = this->first;
    this->iCount++;
}
 

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DeleteFirst
//  Input:              NA
//  Output:             NA
//  Description:        Deletes first node from Singly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::DeleteFirst()
{
    SinglyCLLnode<T> *temp = NULL;

    if ((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if ((this->first) == (this->last))
    {
        delete (this->first);
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        delete temp;
        this->last->next = this->first;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DeleteLast
//  Input:              NA
//  Output:             NA
//  Description:        Deletes last node from Singly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::DeleteLast()
{
    SinglyCLLnode<T> *temp = NULL;

    if ((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if ((this->first) == (this->last))
    {
        delete (this->first);
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        while (temp->next != this->last)
        {
            temp = temp->next;
        }

        delete (this->last);
        this->last = temp;
        this->last->next = this->first;
    }

    this->iCount--;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Display
//  Input:              NA
//  Output:             Displays linked list
//  Description:        Displays all nodes of Singly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::Display() const
{
    SinglyCLLnode<T> *temp = this->first;

    if (first == NULL && last == NULL)
    {
        return;
    }

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
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::CheckPerfect(T iNo)  const
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
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::DisplayPerfect() const
{
    SinglyCLnode<T> *temp = NULL;
    temp = this->first;

    if(first == NULL)
    {
        return;
    }

    cout << "Perfect Elements are:\n";

    do
    {
        if (CheckPerfect(temp->data))
        {
            cout << "| " << temp->data << " |->";
        }
        temp = temp->next;

    }while(temp != first);

    cout << "(Back to First)\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CheckPrime
//  Input:              Number
//  Output:             Integer (1 or 0)
//  Description:        Checks whether given number is Prime or not
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::CheckPrime(T iNo) const
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
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::DisplayPrime()  const
{
    SinglyCLnode<T> *temp = NULL;
    temp = this->first;

    if(first == NULL)
    {
        return;
    }

    cout << "Prime Elements are:\n";

    do
    {
        if (CheckPrime(temp->data))
        {
            cout << "| " << temp->data << " |->";
        }
        temp = temp->next;

    }while(temp != first);

    cout << "(Back to First)\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      EvenAdd
//  Input:              NA
//  Output:             Integer
//  Description:        Returns summation of all even elements from linked list
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::EvenAdd()  const
{
    int iAdd = 0;

    SinglyCLnode<T> *temp = NULL;
    temp = this->first;

    if(first == NULL)
    {
        return 0;
    }

    do
    {
        if (temp->data % 2 == 0)
        {
            iAdd = iAdd + temp->data;
        }
        temp = temp->next;

    }while(temp != first);

    return iAdd;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      SecMaximum
//  Input:              NA
//  Output:             Integer
//  Description:        Returns second maximum element from linked list
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::SecMaximum()  const
{
    int iMaxi = 0;
    int SecMaxi = iMaxi;

    SinglyCLnode<T> *temp = NULL;
    temp = this->first;

    if(first == NULL)
    {
        return 0;
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

    }while(temp != first);

    return SecMaxi;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CheckDigit
//  Input:              Number
//  Output:             Integer
//  Description:        Returns summation of digits of given number
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::CheckDigit(T iNo)  const
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
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::SumDigit()  const
{
    int iSum = 0;

    SinglyCLnode<T> *temp = NULL;
    temp = this->first;

    if(first == NULL)
    {
        return 0;
    }

    do
    {
        iSum = iSum + CheckDigit(temp->data);

        temp = temp->next;

    }while(temp != first);

    return iSum;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Search
//  Input:              Number
//  Output:             Boolean
//  Description:        Searches given element in linked list
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool SinglyCL<T>::Search(T iNo)  const
{
    SinglyCLnode<T> *temp = NULL;
    temp = this->first;

    if(first == NULL)
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

    }while(temp != first);

    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CountEven
//  Input:              NA
//  Output:             Integer
//  Description:        Returns count of even elements in linked list
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::CountEven()  const
{
    SinglyCLnode<T> *temp = NULL;
    int Count = 0;

    temp = this->first;

    if(first == NULL)
    {
        return 0;
    }

    do
    {
        if ((temp->data) % 2 == 0)
        {
            Count++;
        }

        temp = temp->next;

    }while(temp != first);

    return Count;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CountOdd
//  Input:              NA
//  Output:             Integer
//  Description:        Returns count of odd elements in linked list
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::CountOdd()  const
{
    SinglyCLnode<T> *temp = NULL;
    int Count = 0;

    temp = this->first;

    if(first == NULL)
    {
        return 0;
    }

    do
    {
        if ((temp->data) % 2 == 1)
        {
            Count++;
        }

        temp = temp->next;

    }while(temp != first);

    return Count;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Frequency
//  Input:              Number
//  Output:             Integer
//  Description:        Returns frequency of given element in linked list
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::Frequency(T iNo)  const
{
    SinglyCLnode<T> *temp = NULL;
    int Count = 0;

    temp = this->first;

    if(first == NULL)
    {
        return 0;
    }

    do
    {
        if ((temp->data) == iNo)
        {
            Count++;
        }

        temp = temp->next;

    }while(temp != first);

    return Count;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayEven
//  Input:              NA
//  Output:             Displays even elements
//  Description:        Displays all even elements from linked list
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::DisplayEven()  const
{
    SinglyCLnode<T> *temp = NULL;

    temp = this->first;

    if(first == NULL)
    {
        return;
    }

    do
    {
        if ((temp->data) % 2 == 0)
        {
            cout << "| " << temp->data << " |->";
        }

        temp = temp->next;

    }while(temp != first);

    cout << "(Back to First)\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayOdd
//  Input:              NA
//  Output:             Displays odd elements
//  Description:        Displays all odd elements from linked list
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::DisplayOdd()  const
{
    SinglyCLnode<T> *temp = NULL;

    temp = this->first;

    if(first == NULL)
    {
        return;
    }

    do
    {
        if ((temp->data) % 2 == 1)
        {
            cout << "| " << temp->data << " |->";
        }

        temp = temp->next;

    }while(temp != first);

    cout << "(Back to First)\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      FirstOcc
//  Input:              Number
//  Output:             Integer
//  Description:        Returns first occurrence position of given element
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::FirstOcc(T iNo)  const
{
    SinglyCLnode<T> *temp = NULL;
    int iPos = 1;

    temp = this->first;

    if(first == NULL)
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

    }while(temp != first);

    return -1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      LastOcc
//  Input:              Number
//  Output:             Integer
//  Description:        Returns last occurrence position of given element
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::LastOcc(T iNo)  const
{
    SinglyCLnode<T> *temp = NULL;
    int iPos = 1;
    int Lastpos = 0;

    temp = this->first;

    if(first == NULL)
    {
        return -1;
    }

    do
    {
        if ((temp->data) == iNo)
        {
            Lastpos = iPos;
        }

        temp = temp->next;
        iPos++;

    }while(temp != first);

    return Lastpos;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CountGreater
//  Input:              Number
//  Output:             Integer
//  Description:        Returns count of elements greater than given number
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::CountGreater(T iNo)  const
{
    SinglyCLnode<T> *temp = NULL;
    int Count = 0;

    temp = this->first;

    if(first == NULL)
    {
        return 0;
    }

    do
    {
        if ((temp->data) > iNo)
        {
            Count++;
        }

        temp = temp->next;

    }while(temp != first);

    return Count;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CountSmaller
//  Input:              Number
//  Output:             Integer
//  Description:        Returns count of elements smaller than given number
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::CountSmaller(T iNo) const
{
    SinglyCLnode<T> *temp = NULL;
    int Count = 0;

    temp = this->first;

    if(first == NULL)
    {
        return 0;
    }

    do
    {
        if ((temp->data) < iNo)
        {
            Count++;
        }

        temp = temp->next;

    }while(temp != first);

    return Count;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      IsEmpty
//  Input:              NA
//  Output:             Boolean
//  Description:        Checks whether linked list is empty
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool SinglyCL<T>::IsEmpty()  const
{
    if(first == NULL)
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
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::ReplaceNegative() 
{
    SinglyCLnode<T> *temp = NULL;

    temp = this->first;

    if(first == NULL)
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

    }while(temp != first);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      IncrementAll
//  Input:              NA
//  Output:             NA
//  Description:        Displays all elements after incrementing by 1
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::IncrementAll()
{
    SinglyCLnode<T> *temp = NULL;

    temp = this->first;

    if(first == NULL)
    {
        return;
    }

    do
    {
        cout << "| " << temp->data + 1 << " |->";

        temp = temp->next;

    }while(temp != first);

    cout << "(Back to First)\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayReverse
//  Input:              Node pointer
//  Output:             Displays list in reverse order
//  Description:        Displays elements of linked list in reverse using recursion
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::DisplayReverse(SinglyCLLnode<T> *temp)  const
{
    if (temp == NULL)
    {
        return;
    }

    static SinglyCLnode<T> *start = temp;

    if (temp->next != start)
    {
        DisplayReverse(temp->next);
    }

    cout << "| " << temp->data << " |->";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CountDigit
//  Input:              NA
//  Output:             Displays digits of each element
//  Description:        Displays number of digits in each node
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::CountDigit()  const
{
    SinglyCLnode<T> *temp = NULL;

    temp = this->first;

    int Count = 0;
    int iNo = 0;

    if(first == NULL)
    {
        return;
    }

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

        cout << "\n" << temp->data << "-" << Count;

        temp = temp->next;

    }while(temp != first);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      IsPrime
//  Input:              Number
//  Output:             Boolean
//  Description:        Checks whether given number is Prime or not
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool SinglyCL<T>::IsPrime(T iNo)  const
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
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::CountPrime()  const
{
    SinglyCLnode<T> *temp = NULL;

    temp = this->first;
    int Count = 0;

    if(first == NULL)
    {
        return 0;
    }

    do
    {
        if (IsPrime(temp->data) == true)
        {
            Count++;
        }

        temp = temp->next;

    }while(temp != first);

    return Count;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      ReplaceEven
//  Input:              NA
//  Output:             NA
//  Description:        Replaces all even elements by zero
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::ReplaceEven()
{
    SinglyCLnode<T> *temp = NULL;

    temp = this->first;

    if(first == NULL)
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

    }while(temp != first);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Count
//  Input:              NA
//  Output:             Integer
//  Description:        Returns number of nodes in Singly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::Count()  const
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertAtPos
//  Input:              Data of node, Position
//  Output:             NA
//  Description:        Inserts node at given position in Singly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *newn = NULL;

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
        newn = new SinglyCLLnode<T>(no);

        temp = this->first;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DeleteAtPos
//  Input:              Position
//  Output:             NA
//  Description:        Deletes node at given position from Singly Circular Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::DeleteAtPos(int pos)
{
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *target = NULL;

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
        delete (target);
        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      ReplaceOdd
//  Input:              NA
//  Output:             NA
//  Description:        Replaces all odd elements by 1
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::ReplaceOdd()
{
    SinglyCLnode<T> *temp = NULL;

    temp = this->first;

    if(first == NULL)
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

    }while(temp != first);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      MultiplyBtTwo
//  Input:              NA
//  Output:             NA
//  Description:        Displays all elements after multiplying by 2
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::MultiplyBtTwo()
{
    SinglyCLnode<T> *temp = NULL;

    temp = this->first;

    if(first == NULL)
    {
        return;
    }

    do
    {
        cout << "| " << (temp->data) * 2 << " |->";

        temp = temp->next;

    }while(temp != first);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayEvenPosition
//  Input:              NA
//  Output:             Displays elements at even positions
//  Description:        Displays all elements present at even positions
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::DisplayEvenPosition()  const
{
    SinglyCLnode<T> *temp = NULL;

    temp = this->first;
    int Count = 0;

    if(first == NULL)
    {
        return;
    }

    do
    {
        if (Count % 2 == 0)
        {
            cout << "| " << temp->data << " |->";
        }

        Count++;
        temp = temp->next;

    }while(temp != first);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayOddPosition
//  Input:              NA
//  Output:             Displays elements at odd positions
//  Description:        Displays all elements present at odd positions
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::DisplayOddPosition()  const
{
    SinglyCLnode<T> *temp = NULL;

    temp = this->first;
    int Count = 0;

    if(first == NULL)
    {
        return;
    }

    do
    {
        if (Count % 2 == 1)
        {
            cout << "| " << temp->data << " |->";
        }

        Count++;
        temp = temp->next;

    }while(temp != first);

    cout << "(Back to First)\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Difference
//  Input:              NA
//  Output:             Integer
//  Description:        Returns difference between maximum and minimum elements
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::Difference()  const
{
    SinglyCLnode<T> *temp = NULL;

    temp = this->first;

    if(first == NULL)
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

    }while(temp != first);

    return (iMax - iMin);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CheckAllPositive
//  Input:              NA
//  Output:             Boolean
//  Description:        Checks whether all elements are positive
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool SinglyCL<T>::CheckAllPositive()  const
{
    SinglyCLnode<T> *temp = NULL;

    temp = this->first;

    if(first == NULL)
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

    }while(temp != first);

    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayDivByThree
//  Input:              NA
//  Output:             Displays elements
//  Description:        Displays elements divisible by 3
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::DisplayDivByThree()  const
{
    SinglyCLnode<T> *temp = NULL;

    temp = this->first;

    if(first == NULL)
    {
        return;
    }

    do
    {
        if (((temp->data) % 3) == 0)
        {
            cout << "| " << temp->data << " |->";
        }

        temp = temp->next;

    }while(temp != first);

    cout << "(Back to First)\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayDivByFive
//  Input:              NA
//  Output:             Displays elements
//  Description:        Displays elements divisible by 5
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::DisplayDivByFive()  const
{
    SinglyCLnode<T> *temp = NULL;

    temp = this->first;

    if(first == NULL)
    {
        return;
    }

    do
    {
        if (((temp->data) % 5) == 0)
        {
            cout << "| " << temp->data << " |->";
        }

        temp = temp->next;

    }while(temp != first);

    cout << "(Back to First)\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CountTwoDigit
//  Input:              NA
//  Output:             Integer
//  Description:        Returns count of two-digit elements
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::CountTwoDigit()  const
{
    SinglyCLnode<T> *temp = NULL;

    temp = this->first;

    int iNo = 0;
    int Count = 0;
    int iTwoCnt = 0;
    int iDigit = 0;

    if(first == NULL)
    {
        return 0;
    }

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

    }while(temp != first);

    return iTwoCnt;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      MakeAbsolute
//  Input:              NA
//  Output:             NA
//  Description:        Converts all elements to absolute values
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::MakeAbsolute()
{
    SinglyCLnode<T> *temp = NULL;

    temp = this->first;

    if(first == NULL)
    {
        return;
    }

    do
    {
        if ((temp->data) < 0)
        {
            temp->data = -(temp->data);
        }

        temp = temp->next;

    }while(temp != first);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayGreaterThanAvg
//  Input:              NA
//  Output:             Displays elements
//  Description:        Displays elements greater than average
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::DisplayGreaterThanAvg()  const
{
    SinglyCLnode<T> *temp = NULL;

    temp = this->first;
    int Count = 0;
    float fAvg = 0.0f;
    int iSum = 0;

    if(first == NULL)
    {
        return;
    }

    do
    {
        iSum = iSum + temp->data;
        Count++;

        temp = temp->next;

    }while(temp != first);

    fAvg = (float)(iSum) / Count;

    temp = this->first;

    do
    {
        if ((temp->data) > fAvg)
        {
            cout << "| " << temp->data << " |->";
        }

        temp = temp->next;

    }while(temp != first);

    cout << "(Back to First)\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CheckSorted
//  Input:              NA
//  Output:             Boolean
//  Description:        Checks whether linked list is sorted
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool SinglyCL<T>::CheckSorted()  const
{
    if (this->first == NULL || this->first->next == this->first)
    {
        return true;
    }

    SinglyCLnode<T> *temp = NULL;
    temp = this->first;

    do
    {
        if ((temp->next != this->first) && (temp->data > temp->next->data))
        {
            return false;
        }

        temp = temp->next;

    }while(temp != this->first);

    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayAlternate
//  Input:              NA
//  Output:             Displays elements
//  Description:        Displays alternate elements
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCL<T>::DisplayAlternate() const
{
    SinglyCLnode<T> *temp = NULL;

    temp = this->first;
    int Count = 1;

    if(first == NULL)
    {
        return;
    }

    do
    {
        if (Count % 2 == 1)
        {
            cout << "| " << temp->data << " |->";
        }

        Count++;
        temp = temp->next;

    }while(temp != this->first);

    cout << "(Back to First)\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DisplayCount
//  Input:              Position
//  Output:             Integer
//  Description:        Returns count of nodes at given positional interval
//  Author:             Kishor Suryabhan Handge
//  Date:               17-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCL<T>::DisplayCount(int pos) const
{
    SinglyCLnode<T> *temp = NULL;

    temp = this->first;

    int Count = 0;
    int iPos = 1;

    if(first == NULL)
    {
        return 0;
    }

    do
    {
        if ((iPos % pos) == 0)
        {
            Count++;
        }

        iPos++;
        temp = temp->next;

    }while(temp != this->first);

    return Count;
}


}
