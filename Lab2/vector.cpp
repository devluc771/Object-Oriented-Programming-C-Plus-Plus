//vector.cpp
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief prints the elements in the vector and their memory locations
 * 
 * @param v - vector of integers
 */
void printMemVec(const vector<int> vector, int size) 
{
    printf("Vector - Each int is worth %lu bytes\n", sizeof(vector[0]));
    for(int i = 0; i < size; i++)
    {
        printf("Value: %i at Memory Location: %p\n", vector[i], &vector + i);
    }
}

/**
 * @brief increments all of the elements in v by 10
 * 
 * @param v - address to a vector of integers
 */
void incVecBy10(vector<int> vector, int size) 
{
    for(int i = 0; i < size; i++)
    {
        vector[i] += 10;
    }
}

int main()
{
    //create a constant integer called SIZE that is of value 5 
    const int SIZE = 5;
    //create a vector of integers called vec that can hold up to 5 elements
    vector<int> vec(5);
    //use a for loop to populate vec with the values 100 to 104
    for(int i = 0; i < SIZE; i++)
    {
        vec[i] = 100 + i;
    }

    printf("Before Increment---------------\n");
    //call printMemVec(...) on vec
    printMemVec(vec, SIZE);
    //call incBy10(...) on vec
    incVecBy10(vec, SIZE);

    printf("After Increment----------------\n");
    //call printMemVec(...) on vec again to view changes
    printMemVec(vec, SIZE);

    //remove last element of vec
    vec.pop_back();

    printf("After Pop--------------------\n");
    //call printMemVec(...) on vec again to view changes
    printMemVec(vec, vec.size());
    //append 101 and 102 at the end of the vec
    vec.push_back(101);
    vec.push_back(102);

    printf("After Push-------------------\n");
    //call printMemVec(...) on vec again to view changes
    printMemVec(vec, vec.size());
    return 0;
}
