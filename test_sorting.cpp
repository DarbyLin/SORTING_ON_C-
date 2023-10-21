#include <iostream>
#include <string>
#include <cctype>
#include "class_sorting.cpp"
#include <cstdlib>
#include <new>
#include <memory>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

const long Size = 390000L;

using std::cin;
using std::cout;
using std::endl;
using std::vector;


int main(int argc, char **argv)
{
    cout << "test_1" << endl;
    vector <int> data_1 = {7,1,10,22,88,0,63,4,15,17};
    SORTING<int> sort_test1;
    sort_test1.input(data_1);
    sort_test1.bubble_sort();
    sort_test1.input(data_1);
    sort_test1.selection_sort();
    sort_test1.input(data_1);
    sort_test1.insertion_sort();
    sort_test1.input(data_1);
    sort_test1.shell_sort();
    sort_test1.input(data_1);
    sort_test1.shell_sort(5,2);
    sort_test1.input(data_1);
    sort_test1.merge_sort();
    sort_test1.input(data_1);
    sort_test1.quick_sort();
    sort_test1.input(data_1);
    sort_test1.radix_sort();
    sort_test1.input(data_1);
    sort_test1.heap_sort();
    vector <int> data_2;
    data_2 = sort_test1.output();


    SORTING<int> sort_test2;
    sort_test2.input();
    sort_test2.merge_sort();
    vector<int> *p_random_vector = sort_test2.get_random_mode_vector();


    SORTING<int> sort_test3;
    sort_test3.input(*p_random_vector);
    sort_test3.heap_sort();
    /*
    cout << "test_2" << endl;
    float arr[10] = {7,1,10,22,88,0,63,4,15,17};
    SORTING<float> sort_test2;
    sort_test2.input(arr, 10);
    sort_test2.bubble_sort();
    sort_test2.selection_sort();
    sort_test2.insertion_sort();
    sort_test2.output(arr);
    */
    

    cin.get();
    return 0;
}

