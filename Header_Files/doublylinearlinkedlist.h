
#pragma once

#include <iostream>

namespace dslib
{

///////////////////////////////////////////////////////////////
//
//          Doubly Linear Linked List Using Generic Approach
//
/////////////////////////////////////////////////////////////////

template <class T>
class DoublyLLLnode
{
public:
    T data;
    DoublyLLLnode<T> *next;
    DoublyLLLnode<T> *prev;

    DoublyLLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <class T>
class DoublyLLL
{
private:
    DoublyLLLnode<T> *first;
    int iCount;

public:
    DoublyLLL();

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

    void DisplayReverse(DoublyLLLnode<T> *) const;

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
//  Function Name:      DoublyLLL (Constructor)
//  Input:              NA
//  Output:             NA
//  Description:        Initializes empty Doubly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyLLL<T>::DoublyLLL()
{
    cout << "Object Of DoublyLLL gets created\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertFirst
//  Input:              Data of node
//  Output:             NA
//  Description:        Inserts node at first position in Doubly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if (this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertLast
//  Input:              Data of node
//  Output:             NA
//  Description:        Inserts node at last position in Doubly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if (this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DeleteFirst
//  Input:              NA
//  Output:             NA
//  Description:        Deletes first node from Doubly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteFirst()
{
    DoublyLLLnode<T> *temp = NULL;

    if (this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        this->first->prev = NULL;
        delete temp;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DeleteLast
//  Input:              NA
//  Output:             NA
//  Description:        Deletes last node from Doubly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if (this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        delete temp;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Display
//  Input:              NA
//  Output:             Displays linked list
//  Description:        Displays all nodes of Doubly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::Display()const
{
    DoublyLLLnode<T> *temp = this->first;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |<=>";
        temp = temp->next;
    }

    cout << "NULL\n";
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
int DoublyLLL<T>::CheckPerfect(T iNo)const
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
void DoublyLLL<T>::DisplayPerfect()const
{
    DoublyLLLnode<T> *temp = NULL;
    temp = this->first;

    cout << "Perfect Elements are:\n";

    while (temp != NULL)
    {
        if (CheckPerfect(temp->data))
        {
            cout << "| " << temp->data << " |->";
        }
        temp = temp->next;
    }
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
int DoublyLLL<T>::CheckPrime(T iNo)const
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
void DoublyLLL<T>::DisplayPrime()const
{
    DoublyLLLnode<T> *temp = NULL;
    temp = this->first;

    cout << "Prime Elements are:\n";

    while (temp != NULL)
    {
        if (CheckPrime(temp->data))
        {
            cout << "| " << temp->data << " |->";
        }
        temp = temp->next;
    }
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
int DoublyLLL<T>::EvenAdd()const
{
    int iAdd = 0;

    DoublyLLLnode<T> *temp = NULL;
    temp = this->first;

    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            iAdd = iAdd + temp->data;
        }
        temp = temp->next;
    }
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
int DoublyLLL<T>::SecMaximum()const
{
    int iMaxi = 0;
    int SecMaxi = iMaxi;

    DoublyLLLnode<T> *temp = NULL;
    temp = this->first;

    while (temp != NULL)
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
    }

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
int DoublyLLL<T>::CheckDigit(T iNo)const
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
int DoublyLLL<T>::SumDigit()const
{
    int iSum = 0;

    DoublyLLLnode<T> *temp = NULL;
    temp = this->first;

    while (temp != NULL)
    {
        iSum = iSum + CheckDigit(temp->data);
        temp = temp->next;
    }
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
bool DoublyLLL<T>::Search(T iNo)const
{
    DoublyLLLnode<T> *temp = NULL;
    temp = this->first;

    while (temp != NULL)
    {
        if (temp->data == iNo)
        {
            return true;
        }
        temp = temp->next;
    }
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
int DoublyLLL<T>::CountEven()const
{
    DoublyLLLnode<T> *temp = NULL;
    int Count = 0;

    temp = this->first;

    while (temp != NULL)
    {
        if ((temp->data) % 2 == 0)
        {
            Count++;
        }
        temp = temp->next;
    }
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
int DoublyLLL<T>::CountOdd()const
{
    DoublyLLLnode<T> *temp = NULL;
    int Count = 0;

    temp = this->first;

    while (temp != NULL)
    {
        if ((temp->data) % 2 == 1)
        {
            Count++;
        }
        temp = temp->next;
    }
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
int DoublyLLL<T>::Frequency(T iNo)const
{
    DoublyLLLnode<T> *temp = NULL;
    int Count = 0;

    temp = this->first;

    while (temp != NULL)
    {
        if ((temp->data) == iNo)
        {
            Count++;
        }
        temp = temp->next;
    }
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
void DoublyLLL<T>::DisplayEven()const
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;

    while (temp != NULL)
    {
        if ((temp->data) % 2 == 0)
        {
            cout << "| " << temp->data << " |->";
        }
        temp = temp->next;
    }
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
void DoublyLLL<T>::DisplayOdd()const
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;

    while (temp != NULL)
    {
        if ((temp->data) % 2 == 1)
        {
            cout << "| " << temp->data << " |->";
        }
        temp = temp->next;
    }
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
int DoublyLLL<T>::FirstOcc(T iNo)const
{
    DoublyLLLnode<T> *temp = NULL;
    int iPos = 1;

    temp = this->first;

    while (temp != NULL)
    {
        if ((temp->data) == iNo)
        {
            return iPos;
        }

        temp = temp->next;
        iPos++;
    }
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
int DoublyLLL<T>::LastOcc(T iNo)const
{
    DoublyLLLnode<T> *temp = NULL;
    int iPos = 1;
    int Lastpos = 0;

    temp = this->first;

    while (temp != NULL)
    {
        if ((temp->data) == iNo)
        {
            Lastpos = iPos;
        }

        temp = temp->next;
        iPos++;
    }
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
int DoublyLLL<T>::CountGreater(T iNo)const
{
    DoublyLLLnode<T> *temp = NULL;
    int Count = 0;

    temp = this->first;

    while (temp != NULL)
    {
        if ((temp->data) > iNo)
        {
            Count++;
        }

        temp = temp->next;
    }
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
int DoublyLLL<T>::CountSmaller(T iNo)const
{
    DoublyLLLnode<T> *temp = NULL;
    int Count = 0;

    temp = this->first;

    while (temp != NULL)
    {
        if ((temp->data) < iNo)
        {
            Count++;
        }

        temp = temp->next;
    }
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
bool DoublyLLL<T>::IsEmpty()const
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;

    if ((temp->data) == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }

    temp = temp->next;
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
void DoublyLLL<T>::ReplaceNegative()
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;
    while (temp != NULL)
    {
        if ((temp->data) < 0)
        {
            temp->data = 0;
        }

        temp = temp->next;
    }
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
void DoublyLLL<T>::IncrementAll()
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;
    while (temp != NULL)
    {
        cout << "| " << temp->data + 1 << " |->";
        temp = temp->next;
    }
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
void DoublyLLL<T>::DisplayReverse(DoublyLLLnode<T> *temp)const
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
void DoublyLLL<T>::CountDigit()const
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;

    int Count = 0;
    int iNo = 0;

    while (temp != NULL)
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
    }
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
bool DoublyLLL<T>::IsPrime(T iNo)const
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
int DoublyLLL<T>::CountPrime()const
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;
    int Count = 0;

    while (temp != NULL)
    {
        if (IsPrime(temp->data) == true)
        {
            Count++;
        }
        temp = temp->next;
    }

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
void DoublyLLL<T>::ReplaceEven()
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;

    while (temp != NULL)
    {
        if (((temp->data) % 2) == 0)
        {
            temp->data = 0;
        }
        temp = temp->next;
    }
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
void DoublyLLL<T>::ReplaceOdd()
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;
    int Count = 0;

    while (temp != NULL)
    {
        if (((temp->data) % 2) == 1)
        {
            temp->data = 1;
        }
        temp = temp->next;
    }
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
void DoublyLLL<T>::MultiplyBtTwo()
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;
    int Count = 0;

    while (temp != NULL)
    {
        cout << "| " << (temp->data) * 2 << " |->";
        temp = temp->next;
    }
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
void DoublyLLL<T>::DisplayEvenPosition()const
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;
    int Count = 0;

    while (temp != NULL)
    {
        if (Count % 2 == 0)
        {
            cout << "| " << (temp->data) << " |->";
        }
        Count++;
        temp = temp->next;
    }
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
void DoublyLLL<T>::DisplayOddPosition()const
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;
    int Count = 0;

    while (temp != NULL)
    {
        if (Count % 2 == 1)
        {
            cout << "| " << (temp->data) << " |->";
        }
        Count++;
        temp = temp->next;
    }
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
int DoublyLLL<T>::Difference()const
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;
    int iMax = temp->data;
    int iMin = temp->data;

    while (temp != NULL)
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
    }

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
bool DoublyLLL<T>::CheckAllPositive()const
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;

    while (temp != NULL)
    {
        if ((temp->data) < 0)
        {
            return false;
        }

        temp = temp->next;
    }

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
void DoublyLLL<T>::DisplayDivByThree()const
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;

    while (temp != NULL)
    {
        if (((temp->data) % 3) == 0)
        {
            cout << "| " << temp->data << " |->";
        }
        temp = temp->next;
    }
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
void DoublyLLL<T>::DisplayDivByFive()const
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;

    while (temp != NULL)
    {
        if (((temp->data) % 5) == 0)
        {
            cout << "| " << temp->data << " |->";
        }
        temp = temp->next;
    }
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
int DoublyLLL<T>::CountTwoDigit()const
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;

    int iNo = 0;
    int Count = 0;
    int iTwoCnt = 0;
    int iDigit = 0;

    while (temp != NULL)
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
    }

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
void DoublyLLL<T>::MakeAbsolute()
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;

    while (temp != NULL)
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
    }
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
void DoublyLLL<T>::DisplayGreaterThanAvg()const
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;
    int Count = 0;
    float fAvg = 0.0f;
    int iSum = 0;

    while (temp != NULL)
    {
        iSum = iSum + temp->data;
        Count++;
        temp = temp->next;
    }

    if (Count == 0)
    {
        return;
    }

    fAvg = (float)(iSum) / Count;

    temp = this->first;

    while (temp != NULL)
    {
        if ((temp->data) > fAvg)
        {
            cout << "| " << temp->data << " |->";
        }
        temp = temp->next;
    }

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
bool DoublyLLL<T>::CheckSorted()const
{
    if (this->first == NULL || this->first->next == NULL)
    {
        return true;
    }

    DoublyLLLnode<T> *temp = NULL;
    temp = this->first;

    while (temp->next != NULL)
    {
        if ((temp->data) > (temp->next->data))
        {
            return false;
        }
        temp = temp->next;
    }

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
void DoublyLLL<T>::DisplayAlternate()const
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;
    int Count = 1;

    while (temp != NULL)
    {
        if (Count % 2 == 1)
        {
            cout << "| " << temp->data << " |->";
        }
        Count++;
        temp = temp->next;
    }
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
int DoublyLLL<T>::DisplayCount(int pos)const
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;

    int Count = 0;
    int iPos = 1;

    while (temp != NULL)
    {
        if ((iPos % pos) == 0)
        {
            Count++;
        }
        iPos++;
        temp = temp->next;
    }
    return Count;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Count
//  Input:              NA
//  Output:             Integer
//  Description:        Returns number of nodes in Doubly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyLLL<T>::Count()const
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertAtPos
//  Input:              Data of node, Position
//  Output:             NA
//  Description:        Inserts node at given position in Doubly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertAtPos(T no, int pos)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

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
        newn = new DoublyLLLnode<T>(no);
        temp = this->first;

        for (int iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      DeleteAtPos
//  Input:              Position
//  Output:             NA
//  Description:        Deletes node at given position from Doubly Linear Linked List
//  Author:             Kishor Suryabhan Handge
//  Date:               06-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;

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

        for (int iCnt = 1; iCnt < pos; iCnt++)
        {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;

        this->iCount--;
    }
}

}
