#pragma once

#include <iostream>

#define INC_ORDER 1
#define DEC_ORDER 2

namespace dslib
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Class Name:         ArrayX
    //  Description:        Generic Array Data Structure Library
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    class ArrayX
    {
    private:
        T *Arr;
        int Size;

    public:
        // Constructor / Destructor
        ArrayX(int);
        ~ArrayX();

        // Input / Output
        void Accept();
        void Display() const;

        // Basic operations
        T Sum() const;
        T Product() const;
        T Difference() const;

        // Searching
        bool Check(T) const;
        bool Contains(T) const;
        int Search(T) const;

        // Searching Algorithms
        bool LinearSearch(T) const;
        bool BidirectionalSearch(T) const;
        bool BinarySearch(T) const;

        // Frequency / Count
        int Frequency(T) const;
        int CountGreater(T) const;
        int CountSmaller(T) const;
        int CountNotEqual(T) const;

        // Position
        int FirstOcc(T) const;
        int LastOcc(T) const;
        int LargestIndex() const;
        int SmallestIndex() const;

        // Extreme values
        T Maximum() const;
        T Minimum() const;
        T SecondMaximum() const;
        T SecondMinimum() const;

        // Manipulation
        void ReverseArray(T, int);
        void Replace(T, T);
        void Initialize(T);

        // Validation
        bool CheckSorted() const;

        // Comparison
        bool CompareArray(T[], int) const;
        bool CheckReverseEqual(T[], int) const;

        // Utility
        void CopyArray(T[], int) const;

        // Sorting
        void BubbleSort();
        void BubbleSortEfficient();
        void BubbleSortEfficientX(int iOption = INC_ORDER);
        void SelectionSort();
        void InsertionSort();
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      Check
    //  Input:              Generic Array, Integer size, Generic element
    //  Output:             Boolean
    //  Description:        Checks whether given element is present in array or not
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    bool Check(const T Arr[], int iLength, T iNo)
    {
        int iCnt = 0;

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            if (Arr[iCnt] == iNo)
            {
                return true;
            }
        }
        return false;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      Frequency
    //  Input:              Generic Array, Integer size, Generic element
    //  Output:             Integer
    //  Description:        Returns frequency of given element in array
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    int Frequency(const T Arr[], int iLength, T iNo)
    {
        int iCnt = 0;
        int iCount = 0;

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            if (Arr[iCnt] == iNo)
            {
                iCount++;
            }
        }

        return iCount;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      FirstOcc
    //  Input:              Generic Array, Integer size, Generic element
    //  Output:             Integer
    //  Description:        Returns first occurrence index of given element
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    int FirstOcc(const T Arr[], int iLength, T iNo)
    {
        int iCnt = 0;

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            if (Arr[iCnt] == iNo)
            {
                return iCnt;
            }
        }

        return -1;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      LastOcc
    //  Input:              Generic Array, Integer size, Generic element
    //  Output:             Integer
    //  Description:        Returns last occurrence index of given element
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    int LastOcc(const T Arr[], int iLength, T iNo)
    {
        int iCnt = 0;

        for (iCnt = iLength - 1; iCnt >= 0; iCnt--)
        {
            if (Arr[iCnt] == iNo)
            {
                return iCnt;
            }
        }

        return -1;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      Range
    //  Input:              Generic Array, Integer size, Generic start, Generic end
    //  Output:             Void
    //  Description:        Displays elements between given range
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    void Range(const T Arr[], int iLength, T iStart, T iEnd)
    {
        int iCnt = 0;

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            if (Arr[iCnt] >= iStart && Arr[iCnt] <= iEnd)
            {
                std ::cout << Arr[iCnt] << "\n";
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      Product
    //  Input:              Generic Array, Integer size
    //  Output:             Generic element
    //  Description:        Returns product of all elements in array
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    T Product(const T Arr[], int iLength)
    {
        int iCnt = 0;
        T iProduct = 1;

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            iProduct = iProduct * Arr[iCnt];
        }

        return iProduct;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      Maximum
    //  Input:              Generic Array, Integer size
    //  Output:             Generic element
    //  Description:        Returns maximum element from array
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    T Maximum(const T Arr[], int iLength)
    {
        int iCnt = 0;
        T iMax = Arr[0];

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            if (Arr[iCnt] > iMax)
            {
                iMax = Arr[iCnt];
            }
        }

        return iMax;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      Minimum
    //  Input:              Generic Array, Integer size
    //  Output:             Generic element
    //  Description:        Returns minimum element from array
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    T Minimum(const T Arr[], int iLength)
    {
        int iCnt = 0;
        T iMin = Arr[0];

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            if (Arr[iCnt] < iMin)
            {
                iMin = Arr[iCnt];
            }
        }

        return iMin;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      Sum
    //  Input:              Generic Array, Integer size
    //  Output:             Generic element
    //  Description:        Returns sum of all elements in array
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    T Sum(const T Arr[], int iLength)
    {
        int iCnt = 0;
        T iSum = 0;

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            iSum = iSum + Arr[iCnt];
        }

        return iSum;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      CountGreater
    //  Input:              Generic Array, Integer size, Generic element
    //  Output:             Integer
    //  Description:        Returns count of elements greater than given element
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    int CountGreater(const T Arr[], int iLength, T iNo)
    {
        int iCnt = 0, iCount = 0;

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            if (Arr[iCnt] > iNo)
            {
                iCount++;
            }
        }

        return iCount;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      Difference
    //  Input:              None
    //  Output:             Generic
    //  Description:        Returns difference between maximum and minimum element
    //  Author:             Kishor Suryabhan Handge
    //  Date:               20-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>

    T ArrayX<T>::Difference() const
    {
        if (Size == 0)
        {
            return T(); // return default value
        }

        T iMax = Arr[0];
        T iMin = Arr[0];

        for (int i = 1; i < Size; i++)
        {
            if (Arr[i] > iMax)
            {
                iMax = Arr[i];
            }

            if (Arr[i] < iMin)
            {
                iMin = Arr[i];
            }
        }

        return iMax - iMin;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      CountSmaller
    //  Input:              Generic Array, Integer size, Generic element
    //  Output:             Integer
    //  Description:        Returns count of elements smaller than given element
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    int CountSmaller(const T Arr[], int iLength, T iNo)
    {
        int iCnt = 0, iCount = 0;

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            if (Arr[iCnt] < iNo)
            {
                iCount++;
            }
        }

        return iCount;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      CheckSorted
    //  Input:              Generic Array, Integer size
    //  Output:             Boolean
    //  Description:        Checks whether array is sorted or not
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    bool CheckSorted(const T Arr[], int iLength)
    {
        int iCnt = 0;

        for (iCnt = 0; iCnt < iLength - 1; iCnt++)
        {
            if (Arr[iCnt] > Arr[iCnt + 1])
            {
                return false;
            }
        }

        return true;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      CopyArray
    //  Input:              Source Array, Destination Array, Integer size
    //  Output:             Void
    //  Description:        Copies elements from source array to destination array
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    void CopyArray(T Src[], T Dest[], int iLength)
    {
        int iCnt = 0;

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            Dest[iCnt] = Src[iCnt];
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      ReverseArray
    //  Input:              Generic Array, Integer size
    //  Output:             Void
    //  Description:        Reverses the array elements
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    void ReverseArray(T Arr[], int iLength)
    {
        int iStart = 0;
        int iEnd = iLength - 1;
        T temp;

        while (iStart < iEnd)
        {
            temp = Arr[iStart];
            Arr[iStart] = Arr[iEnd];
            Arr[iEnd] = temp;

            iStart++;
            iEnd--;
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      Search
    //  Input:              Generic Array, Integer size, Generic element
    //  Output:             Integer
    //  Description:        Searches element and returns index
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    int Search(const T Arr[], int iLength, T iNo)
    {
        int iCnt = 0;

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            if (Arr[iCnt] == iNo)
            {
                return iCnt;
            }
        }

        return -1;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      Swap
    //  Input:              Two generic variables
    //  Output:             Void
    //  Description:        Swaps two values
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    void Swap(T &A, T &B)
    {
        T temp;

        temp = A;
        A = B;
        B = temp;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      Display
    //  Input:              Generic Array, Integer size
    //  Output:             Void
    //  Description:        Displays all elements of array
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    void Display(const T Arr[], int iLength)
    {
        int iCnt = 0;

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            std ::cout << Arr[iCnt] << "\n";
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      CompareArray
    //  Input:              Two generic arrays, Integer size
    //  Output:             Boolean
    //  Description:        Compares two arrays and checks if equal
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    bool CompareArray(T Arr1[], T Arr2[], int iLength)
    {
        int iCnt = 0;

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            if (Arr1[iCnt] != Arr2[iCnt])
            {
                return false;
            }
        }

        return true;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      SecondMaximum
    //  Input:              Generic Array, Integer size
    //  Output:             Generic element
    //  Description:        Returns second maximum element from array
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    T SecondMaximum(const T Arr[], int iLength)
    {
        T Max = Arr[0];
        T SecondMax = Arr[0];
        int iCnt = 0;

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            if (Arr[iCnt] > Max)
            {
                SecondMax = Max;
                Max = Arr[iCnt];
            }
            else if ((Arr[iCnt] > SecondMax) && (Arr[iCnt] != Max))
            {
                SecondMax = Arr[iCnt];
            }
        }

        return SecondMax;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      SecondMinimum
    //  Input:              Generic Array, Integer size
    //  Output:             Generic element
    //  Description:        Returns second minimum element from array
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    T SecondMinimum(const T Arr[], int iLength)
    {
        T Min = Arr[0];
        T SecondMin = Arr[0];
        int iCnt = 0;

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            if (Arr[iCnt] < Min)
            {
                SecondMin = Min;
                Min = Arr[iCnt];
            }
            else if ((Arr[iCnt] < SecondMin) && (Arr[iCnt] != Min))
            {
                SecondMin = Arr[iCnt];
            }
        }

        return SecondMin;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      Contains
    //  Input:              Generic Array, Integer size, Generic element
    //  Output:             Boolean
    //  Description:        Checks whether element exists in array
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    bool Contains(const T Arr[], int iLength, T Value)
    {
        int iCnt = 0;

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            if (Arr[iCnt] == Value)
            {
                return true;
            }
        }

        return false;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      Replace
    //  Input:              Generic Array, Integer size, Old value, New value
    //  Output:             Void
    //  Description:        Replaces old value with new value in array
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    void Replace(const T Arr[], int iLength, T OldValue, T NewValue)
    {
        int iCnt = 0;

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            if (Arr[iCnt] == OldValue)
            {
                Arr[iCnt] = NewValue;
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      CountEqual
    //  Input:              Two Generic Arrays, Integer size
    //  Output:             Integer
    //  Description:        Returns count of equal elements at same position
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    int CountEqual(T Arr1[], T Arr2[], int iLength)
    {
        int iCnt = 0;
        int iCount = 0;

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            if (Arr1[iCnt] == Arr2[iCnt])
            {
                iCount++;
            }
        }

        return iCount;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      LargestIndex
    //  Input:              Generic Array, Integer size
    //  Output:             Integer
    //  Description:        Returns index of largest element
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    int LargestIndex(const T Arr[], int iLength)
    {
        int iCnt = 0;
        int iMaxIndex = 0;

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            if (Arr[iCnt] > Arr[iMaxIndex])
            {
                iMaxIndex = iCnt;
            }
        }

        return iMaxIndex;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      SmallestIndex
    //  Input:              Generic Array, Integer size
    //  Output:             Integer
    //  Description:        Returns index of smallest element
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    int SmallestIndex(const T Arr[], int iLength)
    {
        int iCnt = 0;
        int iMinIndex = 0;

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            if (Arr[iCnt] < Arr[iMinIndex])
            {
                iMinIndex = iCnt;
            }
        }

        return iMinIndex;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      CountNotEqual
    //  Input:              Generic Array, Integer size, Generic element
    //  Output:             Integer
    //  Description:        Returns count of elements not equal to given value
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    int CountNotEqual(const T Arr[], int iLength, T Value)
    {
        int iCnt = 0;
        int iCount = 0;

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            if (Arr[iCnt] != Value)
            {
                iCount++;
            }
        }

        return iCount;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      Initialize
    //  Input:              Generic Array, Integer size, Generic value
    //  Output:             Void
    //  Description:        Initializes all elements of array with given value
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    void Initialize(const T Arr[], int iLength, T Value)
    {
        int iCnt = 0;

        for (iCnt = 0; iCnt < iLength; iCnt++)
        {
            Arr[iCnt] = Value;
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name:      CheckReverseEqual
    //  Input:              Two Generic Arrays, Integer size
    //  Output:             Boolean
    //  Description:        Checks whether arrays are reverse equal
    //  Author:             Kishor Suryabhan Handge
    //  Date:               17-02-2026
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    template <class T>
    bool CheckReverseEqual(T Arr1[], T Arr2[], int iLength)
    {
        int i = 0;
        int j = iLength - 1;

        while (i < iLength)
        {
            if (Arr1[i] != Arr2[j])
            {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }


////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      LinearSearch
//  Input:              Generic Array, Integer size, Generic element
//  Output:             Boolean
//  Description:        Performs linear search to check whether given element is present or not
//  Author:             Kishor Suryabhan Handge
//  Date:               20-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool LinearSearch(const T Arr[], int iSize, T iNo)
{
    int iCnt = 0;
    bool bFlag = false;

    for (iCnt = 0; iCnt < iSize; iCnt++)
    {
        if (Arr[iCnt] == iNo)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      BidirectionalSearch
//  Input:              Generic Array, Integer size, Generic element
//  Output:             Boolean
//  Description:        Performs bidirectional search to check whether given element is present or not
//  Author:             Kishor Suryabhan Handge
//  Date:               20-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool BidirectionalSearch(const T Arr[], int iSize, T iNo)
{
    int iStart = 0;
    int iEnd = 0;
    bool bFlag = false;

    for (iStart = 0, iEnd = iSize - 1; iStart <= iEnd; iStart++, iEnd--)
    {
        if (Arr[iStart] == iNo || Arr[iEnd] == iNo)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      BinarySearch
//  Input:              Generic Array, Integer size, Generic element
//  Output:             Boolean
//  Description:        Performs binary search if array is sorted, otherwise performs bidirectional search
//  Author:             Kishor Suryabhan Handge
//  Date:               20-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool BinarySearch(const T Arr[], int iSize, T iNo, bool Sorted)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    if (Sorted == false)
    {
        return BidirectionalSearch(Arr, iSize, iNo);
    }

    iStart = 0;
    iEnd = iSize - 1;

    while (iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if (Arr[iMid] == iNo)
        {
            bFlag = true;
            break;
        }
        else if (iNo < Arr[iMid])
        {
            iEnd = iMid - 1;
        }
        else if (iNo > Arr[iMid])
        {
            iStart = iMid + 1;
        }
    }

    return bFlag;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      BubbleSort
//  Input:              Generic Array, Integer size
//  Output:             Void
//  Description:        Sorts the array using basic Bubble Sort algorithm (Increasing order)
//  Author:             Kishor Suryabhan Handge
//  Date:               20-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void BubbleSort(T Arr[], int iSize)
{
    int i = 0, j = 0;
    T temp;
    int pass = 0;
    int Time = 0;

    Time = 1;

    for (i = 0, pass = 1; i < iSize - 1; i++, pass++)
    {
        for (j = 0; j < iSize - 1 - i; j++, Time++)
        {
            if (Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      BubbleSortEfficient
//  Input:              Generic Array, Integer size
//  Output:             Void
//  Description:        Sorts the array using optimized Bubble Sort with early stopping
//  Author:             Kishor Suryabhan Handge
//  Date:               20-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void BubbleSortEfficient(T Arr[], int iSize)
{
    int i = 0, j = 0;
    T temp;

    bool bFlag = true;

    for (i = 0; (i < iSize - 1) && (bFlag == true); i++)
    {
        bFlag = false;

        for (j = 0; j < iSize - 1 - i; j++)
        {
            if (Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;

                bFlag = true;
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      BubbleSortEfficientX
//  Input:              Generic Array, Integer size, Integer option
//  Output:             Void
//  Description:        Sorts the array in increasing or decreasing order using optimized Bubble Sort
//  Author:             Kishor Suryabhan Handge
//  Date:               20-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
void BubbleSortEfficientX(T Arr[], int iSize, int iOption)
{
    int i = 0, j = 0;
    T temp;

    bool bFlag = true;

    if (iOption == INC_ORDER)
    {
        for (i = 0; (i < iSize - 1) && (bFlag == true); i++)
        {
            bFlag = false;

            for (j = 0; j < iSize - 1 - i; j++)
            {
                if (Arr[j] > Arr[j + 1])
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;

                    bFlag = true;
                }
            }
        }
    }
    else if (iOption == DEC_ORDER)
    {
        for (i = 0; (i < iSize - 1) && (bFlag == true); i++)
        {
            bFlag = false;

            for (j = 0; j < iSize - 1 - i; j++)
            {
                if (Arr[j] < Arr[j + 1])
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j + 1] = temp;

                    bFlag = true;
                }
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      SelectionSort
//  Input:              Generic Array, Integer size
//  Output:             Void
//  Description:        Sorts the array using Selection Sort algorithm
//  Author:             Kishor Suryabhan Handge
//  Date:               20-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SelectionSort(T Arr[], int iSize)
{
    int i = 0, j = 0;
    int min_index = 0;
    T temp;

    for (i = 0; i < iSize - 1; i++)
    {
        min_index = i;

        for (j = i + 1; j < iSize; j++)
        {
            if (Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }

        if (i != min_index)
        {
            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:      InsertionSort
//  Input:              Generic Array, Integer size
//  Output:             Void
//  Description:        Sorts the array using Insertion Sort algorithm
//  Author:             Kishor Suryabhan Handge
//  Date:               20-02-2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void InsertionSort(T Arr[], int iSize)
{
    int i = 0, j = 0;
    T selected;

    for (i = 1; i < iSize; i++)
    {
        for (j = i - 1, selected = Arr[i]; (j >= 0) && (Arr[j] > selected); j--)
        {
            Arr[j + 1] = Arr[j];
        }

        Arr[j + 1] = selected;
    }
}
}