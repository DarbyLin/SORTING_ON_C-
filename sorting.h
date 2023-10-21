#ifndef __CLASS_SORTING_H__
#define __CLASS_SORTING_H__

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

template <typename T>
class SORTING
{
    private:
        bool is_random_mode = true;
        void show_result(const vector<T> &input);
        vector<T> output_vector;
        vector<T> *p_input_vector;
        void SWAP(T &x, T &y);
        void merge_sort_conquer(int front, int mid, int end);
        void merge_sort_divide(int front, int end);
        void quicksort(int front, int end);
        int  quick_sort_divide(int front, int end);
        void max_heapify(int start, int end);

    public:
        SORTING();
        void input(T *input, int size);
        void input(vector<T> &input);
        void input(int size, int max_value);
        void input();
        ~SORTING();
        void bubble_sort();
        void selection_sort();
        void insertion_sort();
        void shell_sort();
        void shell_sort(int gap, int step);
        void merge_sort();
        void quick_sort();
        void radix_sort();
        void heap_sort();
        vector<T> output();
        void output(T * input);
        vector<T> *get_random_mode_vector();
};


#endif