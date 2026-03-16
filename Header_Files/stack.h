#pragma once

#include <iostream>

namespace dslib
{

    ////////////////////////////////////////////////////////////////
    //
    //        Stack Using Generic Approach
    //
    /////////////////////////////////////////////////////////////////

    template <class T>
    class Stacknode
    {
    public:
        T data;
        Stacknode<T> *next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
    };

    template <class T>
    class Stack
    {
    private:
        Stacknode<T> *first;
        int iCount;

    public:
        // Constructor
        Stack();

        // Basic Stack Operations
        void Push(T);
        T Pop();
        T Peep() const;
        void Display() const;
        int Count() const;

        // Utility Functions
        bool isEmpty() const;
        void Clear();

        // Search Functions
        bool Search(T) const;
        int Frequency(T) const;

        // Mathematical Functions
        T Maximum() const;
        T Minimum() const;
        T SecondMaximum() const;
        T SecondMinimum() const;

        T Sum() const;

        // Even / Odd Functions
        int CountEven() const;
        int CountOdd() const;

        // Prime Functions
        bool CheckPrime() const;
        int CountPrime() const;

        // Perfect Functions
        bool CheckPerfect() const;
        int CountPerfect() const;

        // Duplicate Functions
        bool CheckDuplicate() const;
        void RemoveDuplicates();

        // Special Functions
        T FindMiddle() const;
        int CountRange(T, T) const;

        // Sorting Function
        void SortStack();
    };

    
////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Stack (Constructor)
//  Input:              NA
//  Output:             NA
//  Description:        Initializes empty Stack
//  Author:             Kishor Suryabhan Handge
//  Date:               07-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
Stack<T>::Stack()
{
    cout << "Stacks gets created successfully....:\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Push
//  Input:              Data
//  Output:             NA
//  Description:        Inserts element into Stack (LIFO)
//  Author:             Kishor Suryabhan Handge
//  Date:               07-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void Stack<T>::Push(T no)
{
    Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>(no);
    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Pop
//  Input:              NA
//  Output:             Data
//  Description:        Removes and returns top element from Stack
//  Author:             Kishor Suryabhan Handge
//  Date:               07-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T Stack<T>::Pop()
{
    T Value = 0;
    Stacknode<T> *temp = this->first;

    if (this->first == NULL)
    {
        cout << "Stack Is Empty:\n";
        return -1;
    }

    Value = this->first->data;
    this->first = this->first->next;
    delete temp;

    this->iCount--;
    return Value;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Peep
//  Input:              NA
//  Output:             Data
//  Description:        Returns top element without removing it
//  Author:             Kishor Suryabhan Handge
//  Date:               07-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T Stack<T>::Peep()const
{
    T Value = 0;

    if (this->first == NULL)
    {
        cout << "Stack Is Empty:\n";
        return -1;
    }

    Value = this->first->data;
    return Value;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Display
//  Input:              NA
//  Output:             Displays Stack elements
//  Description:        Displays all elements of Stack
//  Author:             Kishor Suryabhan Handge
//  Date:               07-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void Stack<T>::Display()const
{
    Stacknode<T> *temp = this->first;

    if (this->first == NULL)
    {
        cout << "Stack Is Empty:\n";
        return;
    }

    while (temp != NULL)
    {
        cout << "|\t" << temp->data << "\t|\n";
        temp = temp->next;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      isEmpty
//  Input:              NA
//  Output:             Boolean
//  Description:        Checks whether Stack is empty or not
//  Author:             Kishor Suryabhan Handge
//  Date:               21-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool Stack<T>::isEmpty()const
{
    if(this->first == NULL)
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
//  Function Name:      Clear
//  Input:              NA
//  Output:             NA
//  Description:        Deletes all elements from Stack
//  Author:             Kishor Suryabhan Handge
//  Date:               21-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void Stack<T>::Clear()
{
    Stacknode<T> *temp = NULL;

    while(this->first != NULL)
    {
        temp = this->first;
        this->first = this->first->next;
        delete temp;
    }

    this->iCount = 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Search
//  Input:              Data
//  Output:             Boolean
//  Description:        Checks whether given element is present in Stack or not
//  Author:             Kishor Suryabhan Handge
//  Date:               21-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool Stack<T>::Search(T no)const
{
    Stacknode<T> *temp = this->first;

    while(temp != NULL)
    {
        if(temp->data == no)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Frequency
//  Input:              Data
//  Output:             Integer
//  Description:        Counts frequency of given element in Stack
//  Author:             Kishor Suryabhan Handge
//  Date:               21-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int Stack<T>::Frequency(T no)const
{
    int iFreq = 0;
    Stacknode<T> *temp = this->first;

    while(temp != NULL)
    {
        if(temp->data == no)
        {
            iFreq++;
        }

        temp = temp->next;
    }

    return iFreq;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Maximum
//  Input:              NA
//  Output:             Data
//  Description:        Returns largest element from Stack
//  Author:             Kishor Suryabhan Handge
//  Date:               21-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T Stack<T>::Maximum()const
{
    Stacknode<T> *temp = this->first;
    T Max;

    if(this->first == NULL)
    {
        cout<<"Stack Is Empty:\n";
        return 0;
    }

    Max = temp->data;

    while(temp != NULL)
    {
        if(temp->data > Max)
        {
            Max = temp->data;
        }

        temp = temp->next;
    }

    return Max;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Minimum
//  Input:              NA
//  Output:             Data
//  Description:        Returns smallest element from Stack
//  Author:             Kishor Suryabhan Handge
//  Date:               21-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T Stack<T>::Minimum()const
{
    Stacknode<T> *temp = this->first;
    T Min;

    if(this->first == NULL)
    {
        cout<<"Stack Is Empty:\n";
        return 0;
    }

    Min = temp->data;

    while(temp != NULL)
    {
        if(temp->data < Min)
        {
            Min = temp->data;
        }

        temp = temp->next;
    }

    return Min;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Sum
//  Input:              NA
//  Output:             Data
//  Description:        Returns summation of all elements from Stack
//  Author:             Kishor Suryabhan Handge
//  Date:               21-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T Stack<T>::Sum()const
{
    T iSum = 0;
    Stacknode<T> *temp = this->first;

    while(temp != NULL)
    {
        iSum = iSum + temp->data;
        temp = temp->next;
    }

    return iSum;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CheckPrime
//  Input:              NA
//  Output:             Boolean
//  Description:        Checks whether Stack contains any prime number
//  Author:             Kishor Suryabhan Handge
//  Date:               21-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool Stack<T>::CheckPrime()const
{
    Stacknode<T> *temp = this->first;
    int iCnt = 0;

    while(temp != NULL)
    {
        int iNo = temp->data;
        int iFlag = 1;

        if(iNo <= 1)
        {
            iFlag = 0;
        }

        for(iCnt = 2; iCnt <= iNo/2; iCnt++)
        {
            if(iNo % iCnt == 0)
            {
                iFlag = 0;
                break;
            }
        }

        if(iFlag == 1)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CheckPerfect
//  Input:              NA
//  Output:             Boolean
//  Description:        Checks whether Stack contains any perfect number
//  Author:             Kishor Suryabhan Handge
//  Date:               21-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool Stack<T>::CheckPerfect()const
{
    Stacknode<T> *temp = this->first;
    int iCnt = 0;

    while(temp != NULL)
    {
        int iNo = temp->data;
        int iSum = 0;

        for(iCnt = 1; iCnt <= iNo/2; iCnt++)
        {
            if(iNo % iCnt == 0)
            {
                iSum = iSum + iCnt;
            }
        }

        if(iSum == iNo)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CheckDuplicate
//  Input:              NA
//  Output:             Boolean
//  Description:        Checks whether Stack contains duplicate elements
//  Author:             Kishor Suryabhan Handge
//  Date:               21-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool Stack<T>::CheckDuplicate()const
{
    Stacknode<T> *temp1 = this->first;
    Stacknode<T> *temp2 = NULL;

    while(temp1 != NULL)
    {
        temp2 = temp1->next;

        while(temp2 != NULL)
        {
            if(temp1->data == temp2->data)
            {
                return true;
            }

            temp2 = temp2->next;
        }

        temp1 = temp1->next;
    }

    return false;
} 

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CountEven
//  Input:              NA
//  Output:             Integer
//  Description:        Counts number of even elements in Stack
//  Author:             Kishor Suryabhan Handge
//  Date:               21-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int Stack<T>::CountEven()const
{
    int iEvenCount = 0;
    Stacknode<T> *temp = this->first;

    while(temp != NULL)
    {
        if((temp->data % 2) == 0)
        {
            iEvenCount++;
        }
        temp = temp->next;
    }
    return iEvenCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CountOdd
//  Input:              NA
//  Output:             Integer
//  Description:        Counts number of odd elements in Stack
//  Author:             Kishor Suryabhan Handge
//  Date:               21-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int Stack<T>::CountOdd()const
{
    int iOddCount = 0;
    Stacknode<T> *temp = this->first;

    while(temp != NULL)
    {
        if((temp->data % 2) != 0)
        {
            iOddCount++;
        }
        temp = temp->next;
    }
    return iOddCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CountPrime
//  Input:              NA
//  Output:             Integer
//  Description:        Counts number of prime elements in Stack
//  Author:             Kishor Suryabhan Handge
//  Date:               21-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int Stack<T>::CountPrime()const
{
    int iPrimeCount = 0, iCnt = 0;
    Stacknode<T> *temp = this->first;

    while(temp != NULL)
    {
        int iNo = temp->data;
        int iFlag = 1;

        if(iNo <= 1)
        {
            iFlag = 0;
        }

        for(iCnt = 2; iCnt <= iNo/2; iCnt++)
        {
            if((iNo % iCnt) == 0)
            {
                iFlag = 0;
                break;
            }
        }

        if(iFlag == 1)
        {
            iPrimeCount++;
        }
        temp = temp->next;
    }
    return iPrimeCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CountPerfect
//  Input:              NA
//  Output:             Integer
//  Description:        Counts number of perfect elements in Stack
//  Author:             Kishor Suryabhan Handge
//  Date:               21-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int Stack<T>::CountPerfect()const
{
    int iPerfectCount = 0, iCnt = 0;
    Stacknode<T> *temp = this->first;

    while(temp != NULL)
    {
        int iNo = temp->data;
        int iSum = 0;

        for(iCnt = 1; iCnt <= iNo/2; iCnt++)
        {
            if((iNo % iCnt) == 0)
            {
                iSum = iSum + iCnt;
            }
        }

        if(iSum == iNo)
        {
            iPerfectCount++;
        }
        temp = temp->next;
    }
    return iPerfectCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      SecondMaximum
//  Input:              NA
//  Output:             Data
//  Description:        Returns second largest element from Stack
//  Author:             Kishor Suryabhan Handge
//  Date:               21-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T Stack<T>::SecondMaximum()const
{
    Stacknode<T> *temp = this->first;
    T Max = temp->data;
    T SecondMax = temp->data;

    while(temp != NULL)
    {
        if(temp->data > Max)
        {
            SecondMax = Max;
            Max = temp->data;
        }
        else if(temp->data > SecondMax && temp->data != Max)
        {
            SecondMax = temp->data;
        }
        temp = temp->next;
    }
    return SecondMax;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      SecondMinimum
//  Input:              NA
//  Output:             Data
//  Description:        Returns second smallest element from Stack
//  Author:             Kishor Suryabhan Handge
//  Date:               21-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T Stack<T>::SecondMinimum()const
{
    Stacknode<T> *temp = this->first;
    T Min = temp->data;
    T SecondMin = temp->data;

    while(temp != NULL)
    {
        if(temp->data < Min)
        {
            SecondMin = Min;
            Min = temp->data;
        }
        else if(temp->data < SecondMin && temp->data != Min)
        {
            SecondMin = temp->data;
        }
        temp = temp->next;
    }
    return SecondMin;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      RemoveDuplicates
//  Input:              NA
//  Output:             NA
//  Description:        Removes duplicate elements from Stack
//  Author:             Kishor Suryabhan Handge
//  Date:               21-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void Stack<T>::RemoveDuplicates()
{
    Stacknode<T> *temp1 = this->first;
    Stacknode<T> *temp2 = NULL;
    Stacknode<T> *prev = NULL;

    while(temp1 != NULL)
    {
        prev = temp1;
        temp2 = temp1->next;

        while(temp2 != NULL)
        {
            if(temp1->data == temp2->data)
            {
                prev->next = temp2->next;
                delete temp2;
                temp2 = prev->next;
                this->iCount--;
            }
            else
            {
                prev = temp2;
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      FindMiddle
//  Input:              NA
//  Output:             Data
//  Description:        Returns middle element from Stack
//  Author:             Kishor Suryabhan Handge
//  Date:               21-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T Stack<T>::FindMiddle()const
{
    int iMid = this->iCount / 2;
    int iCnt = 0;
    Stacknode<T> *temp = this->first;

    while(iCnt < iMid)
    {
        temp = temp->next;
        iCnt++;
    }
    return temp->data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      CountRange
//  Input:              Data, Data
//  Output:             Integer
//  Description:        Counts number of elements within given range
//  Author:             Kishor Suryabhan Handge
//  Date:               21-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int Stack<T>::CountRange(T iStart, T iEnd)const
{
    int iRangeCount = 0;
    Stacknode<T> *temp = this->first;

    while(temp != NULL)
    {
        if(temp->data >= iStart && temp->data <= iEnd)
        {
            iRangeCount++;
        }
        temp = temp->next;
    }
    return iRangeCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      SortStack
//  Input:              NA
//  Output:             NA
//  Description:        Sorts elements of Stack in ascending order
//  Author:             Kishor Suryabhan Handge
//  Date:               21-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void Stack<T>::SortStack()
{
    Stacknode<T> *temp1 = this->first;
    Stacknode<T> *temp2 = NULL;
    T tempData;

    while(temp1 != NULL)
    {
        temp2 = temp1->next;

        while(temp2 != NULL)
        {
            if(temp1->data > temp2->data)
            {
                tempData = temp1->data;
                temp1->data = temp2->data;
                temp2->data = tempData;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      Count
//  Input:              NA
//  Output:             Integer
//  Description:        Returns number of elements in Stack
//  Author:             Kishor Suryabhan Handge
//  Date:               07-01-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int Stack<T>::Count()const
{
    return this->iCount;
}

}