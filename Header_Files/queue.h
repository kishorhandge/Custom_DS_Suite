#pragma once

#include <iostream>

namespace dslib
{
    template <class T>
    class Queuenode
    {
    public:
        T data;
        Queuenode<T> *next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
    };

    template <class T>
    class Queue
    {
    private:
        Queuenode<T> *first;
        Queuenode<T> *last;
        int iCount;

    public:
        // Constructor
        Queue();

        // Basic Queue Operations
        void enqueue(T);
        T dequeue();
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
        void SortQueue();
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      Queue (Constructor)
    //  Input:              NA
    //  Output:             NA
    //  Description:        Initializes empty Queue
    //  Author:             Kishor Suryabhan Handge
    //  Date:               07-01-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    Queue<T>::Queue()
    {
        cout << "Queues gets created successfully....:\n";
        this->first = NULL;
        this->last = NULL;
        this->iCount = 0;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      enqueue
    //  Input:              Data
    //  Output:             NA
    //  Description:        Inserts element into Queue (FIFO)
    //  Author:             Kishor Suryabhan Handge
    //  Date:               07-01-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    void Queue<T>::enqueue(T no)
    {
        Queuenode<T> *newn = NULL;

        newn = new Queuenode<T>(no);

        if (this->first == NULL && this->last == NULL)
        {
            this->first = newn;
            this->last = newn;
        }
        else
        {
            this->last->next = newn;
            this->last = this->last->next;
        }

        this->iCount++;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      dequeue
    //  Input:              NA
    //  Output:             Data
    //  Description:        Removes and returns front element from Queue
    //  Author:             Kishor Suryabhan Handge
    //  Date:               07-01-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    T Queue<T>::dequeue()
    {
        T Value = 0;
        Queuenode<T> *temp = this->first;

        if (this->first == NULL && this->last == NULL)
        {
            cout << "Queue Is Empty:\n";
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
    //  Function Name:      Display
    //  Input:              NA
    //  Output:             Displays Queue elements
    //  Description:        Displays all elements of Queue
    //  Author:             Kishor Suryabhan Handge
    //  Date:               07-01-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    void Queue<T>::Display() const
    {
        Queuenode<T> *temp = this->first;

        if (this->first == NULL && this->last == NULL)
        {
            cout << "Queue Is Empty:\n";
            return;
        }

        while (temp != NULL)
        {
            cout << "| " << temp->data << " | -";
            temp = temp->next;
        }
        cout << "\n";
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      isEmpty
    //  Input:              NA
    //  Output:             Boolean
    //  Description:        Checks whether Queue is empty or not
    //  Author:             Kishor Suryabhan Handge
    //  Date:               23-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    bool Queue<T>::isEmpty()const
    {
        if (this->first == NULL)
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
    //  Description:        Deletes all elements from Queue
    //  Author:             Kishor Suryabhan Handge
    //  Date:               23-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    void Queue<T>::Clear()
    {
        Queuenode<T> *temp = NULL;

        while (this->first != NULL)
        {
            temp = this->first;
            this->first = this->first->next;
            delete temp;
        }

        this->last = NULL;
        this->iCount = 0;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      Search
    //  Input:              Data
    //  Output:             Boolean
    //  Description:        Checks whether given element is present in Queue or not
    //  Author:             Kishor Suryabhan Handge
    //  Date:               23-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    bool Queue<T>::Search(T no)const
    {
        Queuenode<T> *temp = this->first;

        while (temp != NULL)
        {
            if (temp->data == no)
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
    //  Description:        Counts frequency of given element in Queue
    //  Author:             Kishor Suryabhan Handge
    //  Date:               23-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    int Queue<T>::Frequency(T no)const
    {
        int iFreq = 0;
        Queuenode<T> *temp = this->first;

        while (temp != NULL)
        {
            if (temp->data == no)
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
    //  Description:        Returns largest element from Queue
    //  Author:             Kishor Suryabhan Handge
    //  Date:               23-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    T Queue<T>::Maximum()const
    {
        Queuenode<T> *temp = this->first;
        T Max;

        if (this->first == NULL)
        {
            cout << "Queue Is Empty:\n";
            return 0;
        }

        Max = temp->data;

        while (temp != NULL)
        {
            if (temp->data > Max)
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
    //  Description:        Returns smallest element from Queue
    //  Author:             Kishor Suryabhan Handge
    //  Date:               23-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    T Queue<T>::Minimum()const
    {
        Queuenode<T> *temp = this->first;
        T Min;

        if (this->first == NULL)
        {
            cout << "Queue Is Empty:\n";
            return 0;
        }

        Min = temp->data;

        while (temp != NULL)
        {
            if (temp->data < Min)
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
    //  Description:        Returns summation of all elements from Queue
    //  Author:             Kishor Suryabhan Handge
    //  Date:               23-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    T Queue<T>::Sum()const
    {
        T iSum = 0;
        Queuenode<T> *temp = this->first;

        while (temp != NULL)
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
    //  Description:        Checks whether Queue contains any prime number
    //  Author:             Kishor Suryabhan Handge
    //  Date:               23-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    bool Queue<T>::CheckPrime()const
    {
        Queuenode<T> *temp = this->first;
        int iCnt = 0;

        while (temp != NULL)
        {
            int iNo = temp->data;
            int iFlag = 1;

            if (iNo <= 1)
            {
                iFlag = 0;
            }

            for (iCnt = 2; iCnt <= iNo / 2; iCnt++)
            {
                if (iNo % iCnt == 0)
                {
                    iFlag = 0;
                    break;
                }
            }

            if (iFlag == 1)
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
    //  Description:        Checks whether Queue contains any perfect number
    //  Author:             Kishor Suryabhan Handge
    //  Date:               23-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    bool Queue<T>::CheckPerfect()const
    {
        Queuenode<T> *temp = this->first;
        int iCnt = 0;

        while (temp != NULL)
        {
            int iNo = temp->data;
            int iSum = 0;

            for (iCnt = 1; iCnt <= iNo / 2; iCnt++)
            {
                if (iNo % iCnt == 0)
                {
                    iSum = iSum + iCnt;
                }
            }

            if (iSum == iNo)
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
    //  Description:        Checks whether Queue contains duplicate elements
    //  Author:             Kishor Suryabhan Handge
    //  Date:               23-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    bool Queue<T>::CheckDuplicate()const
    {
        Queuenode<T> *temp1 = this->first;
        Queuenode<T> *temp2 = NULL;

        while (temp1 != NULL)
        {
            temp2 = temp1->next;

            while (temp2 != NULL)
            {
                if (temp1->data == temp2->data)
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
    //  Description:        Counts number of even elements in Queue
    //  Author:             Kishor Suryabhan Handge
    //  Date:               23-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    int Queue<T>::CountEven()const
    {
        int iEvenCount = 0;
        Queuenode<T> *temp = this->first;

        while (temp != NULL)
        {
            if ((temp->data % 2) == 0)
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
    //  Description:        Counts number of odd elements in Queue
    //  Author:             Kishor Suryabhan Handge
    //  Date:               23-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    int Queue<T>::CountOdd()const
    {
        int iOddCount = 0;
        Queuenode<T> *temp = this->first;

        while (temp != NULL)
        {
            if ((temp->data % 2) != 0)
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
    //  Description:        Counts number of prime elements in Queue
    //  Author:             Kishor Suryabhan Handge
    //  Date:               23-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    int Queue<T>::CountPrime()const
    {
        int iPrimeCount = 0, iCnt = 0;
        Queuenode<T> *temp = this->first;

        while (temp != NULL)
        {
            int iNo = temp->data;
            int iFlag = 1;

            if (iNo <= 1)
            {
                iFlag = 0;
            }

            for (iCnt = 2; iCnt <= iNo / 2; iCnt++)
            {
                if ((iNo % iCnt) == 0)
                {
                    iFlag = 0;
                    break;
                }
            }

            if (iFlag == 1)
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
    //  Description:        Counts number of perfect elements in Queue
    //  Author:             Kishor Suryabhan Handge
    //  Date:               23-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    int Queue<T>::CountPerfect()const
    {
        int iPerfectCount = 0, iCnt = 0;
        Queuenode<T> *temp = this->first;

        while (temp != NULL)
        {
            int iNo = temp->data;
            int iSum = 0;

            for (iCnt = 1; iCnt <= iNo / 2; iCnt++)
            {
                if ((iNo % iCnt) == 0)
                {
                    iSum = iSum + iCnt;
                }
            }

            if (iSum == iNo)
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
    //  Description:        Returns second largest element from Queue
    //  Author:             Kishor Suryabhan Handge
    //  Date:               23-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    T Queue<T>::SecondMaximum()const
    {
        Queuenode<T> *temp = this->first;
        T Max = temp->data;
        T SecondMax = temp->data;

        while (temp != NULL)
        {
            if (temp->data > Max)
            {
                SecondMax = Max;
                Max = temp->data;
            }
            else if (temp->data > SecondMax && temp->data != Max)
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
    //  Description:        Returns second smallest element from Queue
    //  Author:             Kishor Suryabhan Handge
    //  Date:               23-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    T Queue<T>::SecondMinimum()const
    {
        Queuenode<T> *temp = this->first;
        T Min = temp->data;
        T SecondMin = temp->data;

        while (temp != NULL)
        {
            if (temp->data < Min)
            {
                SecondMin = Min;
                Min = temp->data;
            }
            else if (temp->data < SecondMin && temp->data != Min)
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
    //  Description:        Removes duplicate elements from Queue
    //  Author:             Kishor Suryabhan Handge
    //  Date:               23-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    void Queue<T>::RemoveDuplicates()
    {
        Queuenode<T> *temp1 = this->first;
        Queuenode<T> *temp2 = NULL;
        Queuenode<T> *prev = NULL;

        while (temp1 != NULL)
        {
            prev = temp1;
            temp2 = temp1->next;

            while (temp2 != NULL)
            {
                if (temp1->data == temp2->data)
                {
                    prev->next = temp2->next;

                    if (temp2 == this->last)
                    {
                        this->last = prev;
                    }

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
    //  Description:        Returns middle element from Queue
    //  Author:             Kishor Suryabhan Handge
    //  Date:               23-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    T Queue<T>::FindMiddle()const
    {
        int iMid = this->iCount / 2;
        int iCnt = 0;
        Queuenode<T> *temp = this->first;

        while (iCnt < iMid)
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
    //  Description:        Counts number of elements within given range in Queue
    //  Author:             Kishor Suryabhan Handge
    //  Date:               23-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    int Queue<T>::CountRange(T iStart, T iEnd)const
    {
        int iRangeCount = 0;
        Queuenode<T> *temp = this->first;

        while (temp != NULL)
        {
            if (temp->data >= iStart && temp->data <= iEnd)
            {
                iRangeCount++;
            }
            temp = temp->next;
        }
        return iRangeCount;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      SortQueue
    //  Input:              NA
    //  Output:             NA
    //  Description:        Sorts elements of Queue in ascending order
    //  Author:             Kishor Suryabhan Handge
    //  Date:               23-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    void Queue<T>::SortQueue()
    {
        Queuenode<T> *temp1 = this->first;
        Queuenode<T> *temp2 = NULL;
        T tempData;

        while (temp1 != NULL)
        {
            temp2 = temp1->next;

            while (temp2 != NULL)
            {
                if (temp1->data > temp2->data)
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
    //  Description:        Returns number of elements in Queue
    //  Author:             Kishor Suryabhan Handge
    //  Date:               07-01-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    int Queue<T>::Count()const
    {
        return this->iCount;
    }
}