#include "sorting.h"
#include <iostream>
#include <vector>
#include <limits>
#include <random>

using std::string;
using std::cout;
using std::cin;
using std::ios_base;
using std::endl;
using std::istream;
using std::ostream;
using std::vector;
using std::vector;

template <typename T>
SORTING<T>::SORTING()
{
    //contruct
}

template <typename T>
void SORTING<T>::input(T *input, int size)
{
    cout << input[1];
    
    is_random_mode = false;
    // show original result
    cout << "input value" << endl;
    
    vector<T> value(input, input + size);
    output_vector.assign(value.begin(), value.end());
    show_result(output_vector);
}

template <typename T>
void SORTING<T>::input(vector<T> &input)
{

    is_random_mode = false;
    // show original result
    cout << "input value" << endl;
    show_result(input);
    // store 
    output_vector.assign(input.begin(), input.end());
}

template <typename T>
void SORTING<T>::input()
{
    is_random_mode = true;
    int size = 20; 
    int max_value = 100;
    p_input_vector = new vector<T>(size);

    for (int i = 0; i < size; i++)
    {
        (*p_input_vector)[i] = std::rand() % 100;
    }
    cout << "Random vector result" << endl;
    show_result(*p_input_vector);
    // store 
    output_vector.assign((*p_input_vector).begin(), (*p_input_vector).end());
}

template <typename T>
void SORTING<T>::input(int size, int max_value)
{

    is_random_mode = true;

    p_input_vector = new vector<T>(size);

    for (int i = 0; i < size; i++)
    {
        (*p_input_vector)[i] = std::rand() % 100;
    }
    cout << "Random vector result" << endl;
    show_result(*p_input_vector);
    // store 
    output_vector.assign((*p_input_vector).begin(), (*p_input_vector).end());
}

template<typename T>
vector<T> * SORTING<T>::get_random_mode_vector()
{
    return p_input_vector;
}

template <typename T>
SORTING<T>::~SORTING()
{
    //de-construct
    if (is_random_mode == true)
    {
        delete p_input_vector;
    }
}

template <typename T>
void SORTING<T>::SWAP(T &x, T &y)
{
    T temp = y;
    y = x;
    x = temp;
}

template <typename T>
void SORTING<T>::bubble_sort()
{
    bool flag;
    for( int i = 0; i < output_vector.size() - 1; i++)
    {
        flag = false;
        for( int j = 0; j < output_vector.size() - 1 - i; j++)
        {
            if( output_vector[j] > output_vector[j+1])
            {
                SWAP(output_vector[j], output_vector[j+1]);
                flag = true;
            }
        }
        if( !flag)
        {
            break;
        }
    }
    
    cout << "BUBBLE SORTING RESULT: " << endl;
    show_result(output_vector);
}

template <typename T>
void SORTING<T>::selection_sort()
{
    int min_idx = 0;
    for( int i = 0; i < output_vector.size() - 1; i++)
    {
       min_idx = i;
       for( int j = i + 1; j < output_vector.size(); j++)
       {
            if(output_vector[min_idx] > output_vector[j])
            {
                min_idx = j;
            }
       }
       if(min_idx != i)
       {
            SWAP(output_vector[min_idx], output_vector[i]);
       }
    }
    
    cout << "SELECTION SORTING RESULT: " << endl;
    show_result(output_vector);
}

template <typename T>
void SORTING<T>::insertion_sort()
{
    T insert = 0;
    int count = 0;
    for(int i = 0; i < output_vector.size(); i ++)
    {
        insert = output_vector[i];
        count = i - 1;

        while( count >= 0 && insert < output_vector[count])
        {
            output_vector[count+1] = output_vector[count];
            count -= 1;
        }
        output_vector[count+1] = insert;
    }
    
    cout << "INSERTION SORTING RESULT: " << endl;
    show_result(output_vector);
}

template <typename T>
void SORTING<T>::shell_sort()
{
    T insert = 0;
    int count = 0;

    int gap = 5, step = 3;
    
    for(int k = 0; k < step; k++)
    {
        for(int i = gap; i < output_vector.size(); i ++)
        {
            insert = output_vector[i];
            count = i;

            while( count - gap >= 0  &&  insert < output_vector[count - gap])
            {
                output_vector[count] = output_vector[count - gap];
                count -= gap;
            }
            output_vector[count] = insert;
        }

        gap = gap - step * k > 0 ? gap - step : 1;
    }
    
    cout << "SHELL SORTING RESULT: " << endl;
    show_result(output_vector);
}

template <typename T>
void SORTING<T>::shell_sort( int gap, int step)
{
    T insert = 0;
    int count = 0;
    
    for(int k = 0; ; k++)
    {
        for(int i = gap; i < output_vector.size(); i ++)
        {
            insert = output_vector[i];
            count = i;

            while( count - gap >= 0  &&  insert < output_vector[count - gap])
            {
                output_vector[count] = output_vector[count - gap];
                count -= gap;
            }
            output_vector[count] = insert;
        }

        if( gap == 1)
        {
            break;
        }
        gap = gap - step * k > 0 ? gap - step : 1;
        
    }
    
    cout << "SHELL SORTING RESULT: " << endl;
    show_result(output_vector);
}

template <typename T>
void SORTING<T>::merge_sort_conquer(int front, int mid, int end)
{
    int idxLeft = 0, idxRight = 0;
    vector<T> LeftSub(output_vector.begin()+front, output_vector.begin()+mid+1);
    vector<T> RighttSub(output_vector.begin()+mid+1, output_vector.begin()+end+1);
    LeftSub.insert(LeftSub.end(), std::numeric_limits<T>::max());
    RighttSub.insert(RighttSub.end(), std::numeric_limits<T>::max());

    for( int i = front; i <= end; i++)
    {
        if( LeftSub[idxLeft] < RighttSub[idxRight])
        {   
            output_vector[i] = LeftSub[idxLeft];
            idxLeft++;
        }
        else
        {
            output_vector[i] = RighttSub[idxRight];
            idxRight++;
        }
    }
}

template <typename T>
void SORTING<T>::merge_sort_divide(int front, int end)
{
    int mid = (front + end) / 2;
    if( front < end)
    {
        merge_sort_divide(front, mid);
        merge_sort_divide(mid + 1, end);
        merge_sort_conquer(front, mid, end);
    }
}

template <typename T>
void SORTING<T>::merge_sort()
{
    int left = 0;
    int right = output_vector.size() - 1;

    merge_sort_divide(left, right);
    
    cout << "MERGE SORTING RESULT: " << endl;
    show_result(output_vector);
}

template <typename T>
int SORTING<T>::quick_sort_divide(int front,int end)
{
    int i = front;
    int j = end;
    int pivot = output_vector[end];

    while( i < j)
    {
        while(i < end && output_vector[i] < pivot)
        {
            i++;
        }
        while(j > front && output_vector[j] > pivot)
        {
            j--;
        }
        if(i < j)
        {
            SWAP(output_vector[i], output_vector[j]);
        }
    }
    if(output_vector[i] > pivot)
    {
        SWAP(output_vector[i], output_vector[end]);
    }
    return i;
}

template <typename T>
void SORTING<T>::quicksort(int front, int end)
{
    if( front < end)
    {
        int partition = quick_sort_divide(front, end);
        quicksort(front, partition - 1);
        quicksort(partition + 1, end);
    }
}

template <typename T>
void SORTING<T>::quick_sort()
{
    int left = 0;
    int right = output_vector.size() - 1;

    quicksort(left, right);
    
    cout << "QUICK SORTING RESULT: " << endl;
    show_result(output_vector);
}

template <typename T>
void SORTING<T>::radix_sort()
{
    vector<T> temp(output_vector.size());
    int significantDigit = 1;
    // find max value
    int max_value = output_vector[0];
    for(int i = 1; i < output_vector.size(); i++)
    {
        if(max_value < output_vector[i])
        {
            max_value = output_vector[i];
        }
    }

    while( max_value/significantDigit > 0)
    {
        vector<T> bucket(10);

        for(int i = 0; i < output_vector.size(); i++)
        {
            bucket[(output_vector[i]/significantDigit) % 10]++;
        }
        for(int i = 1; i < 10; i++)
        {
            bucket[i] += bucket[i-1];
        }
        for(int i = output_vector.size()-1; i >= 0; i --)
        {
            int digitNum = (output_vector[i]/significantDigit) % 10;
            temp[--bucket[digitNum]] = output_vector[i];
            
        }
        output_vector.assign(temp.begin(), temp.end());
        significantDigit *= 10; // go to nest Digit
    }
    cout << "RADIX SORTING RESULT: " << endl;
    show_result(output_vector);
}

template <typename T>
void SORTING<T>::max_heapify(int start, int end)
{
    
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end)
    {
        if ( (son + 1) <= end && output_vector[son] < output_vector[son+1])
        {
            son += 1;
        }
        if (output_vector[dad] >= output_vector[son])
        {
            return;
        }
        else
        {
            SWAP(output_vector[dad], output_vector[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

template <typename T>
void SORTING<T>::heap_sort()
{
    for (int i = output_vector.size()/2 - 1; i >= 0; i--)
    {
        max_heapify(i, output_vector.size()-1);
    }

    for (int i = output_vector.size() - 1; i > 0; i--)
    {
        SWAP(output_vector[0], output_vector[i]);
        max_heapify(0, i - 1);
    }
    
    cout << "HEAP SORTING RESULT: " << endl;
    show_result(output_vector);
}

template <typename T>
vector<T> SORTING<T>::output()
{
    return output_vector;
}

template <typename T>
void SORTING<T>::output(T * input)
{
   std::copy(output_vector.begin(), output_vector.end(), input);
}

template <typename T>
void SORTING<T>::show_result(const vector<T> &input)
{
    cout << "|";
    for( int i = 0; i < input.size(); i++)
    {
        if( i % 5 == 0 && i != 0)
        {
            cout << "|";
            cout << endl;
            cout << "|";
        }
        cout.width(4);
        cout << input[i] << " ";
    }
    cout << "|" << endl << endl;

}

