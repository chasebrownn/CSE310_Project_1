//#include "encode.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <string>

/*
* Chase Brown
* 1212869071
*/

//  Scope:
//  1. Take a string
//  2. Place that string into an array
//  3. Shift string
//  4. Sort every row of the array via ASCII
//  5. Index
//  6. Last
//  7. Clusterlast

//Notes: Make sure to delete[] an array after using it.

using namespace std;

string* shift(string, string* original_array);
string* insertionSort(int, string* original_array, string* sorted_array);
void quickSort(string* sorted_array, int, int);
int partition(string* sorted_array,int, int);


int main(int argc, char** args)
{
    string sorting;
    
    for (int i = 0; i < argc; i++)
    {
        //printf("%d: %s\n", i, args[i]);
    }
    if (strcmp(args[1], "insertion") == 0 )
    {
        sorting = "i";
    }
    else if (strcmp(args[1], "quick") == 0)
    {
        sorting = "q";
    }
    else
    {
        cout << "Not a valid sorting method" << endl;
        return 1;
    }

    string str;

    while (getline(cin,str))
    {
        /*if (cin.eof())
        {
            break;
        }*/

        //getline(cin, str);
        int input_size = str.size();

        string* original = new string[input_size];
        string* sortedArray = new string[input_size];
        
        shift(str, original);

        // Shifted Array done. Now sort ======================================================================================================

        if (sorting == "i")
        {
            for (int i = 0; i < input_size; i++)
            {
                sortedArray[i] += original[i];
            }

            insertionSort(input_size, (string*)original, (string*)sortedArray); // Execute Insertion-Sort

            //Print sortedArray
            /*
            for (int i = 0; i < input_size; i++)
            {
                cout << sortedArray[i];
                cout << endl;
            }
            cout << endl; // indent
            */

        }

        else if (sorting == "q")
        {
            for (int i = 0; i < input_size; i++)
            {
                sortedArray[i] += original[i];
            }

            int lowInt = 0;
            int highInt = input_size - 1;

            quickSort((string*)sortedArray, lowInt, highInt); // Execute Quick-Sort

            //Print sortedArray
            /*
            for (int i = 0; i < input_size; i++)
            {
                cout << sortedArray[i];
                cout << endl;
            }*/
            
            
        }


        // return of sorted array ================================================================================================================

        // Storing the original (shifted) array into a string
        // array to compare with sorted array for similar lines

        for (int i = 0; i < input_size; i++)
        {
            if (original[i] == sortedArray[i])
            {
                cout << i << endl;
            }
        }

        char* last = new char[input_size];

        for (int i = 0; i < input_size; i++)
        {
            last[i] = sortedArray[i][input_size - 1];
        }
        for (int i = 0; i < input_size; i++)
        {
            //cout << last[i];
        }

        //cout << endl;

        string cluster;
        int counter = 1;

        for (int i = 0; i < input_size; i++)
        {
            while (i+1 < input_size && last[i] == last[i + 1])
            {
                counter++;
                i++;
            }
            cluster += to_string(counter);
            cluster += " ";
            cluster += last[i];
            cluster += " ";
            counter = 1;

        }

        cout << cluster << endl;

        cout << endl;

        delete[] original;
        delete[] sortedArray;
        delete[] last;
        //delete ptr;
    }

}

string* shift(string input, string* original_array)
{
    int size = input.length();

    for (int i = 0; i < size; i++)
    {
        //cout << input << endl;
        original_array[i] = input;
        input += input[0];
        input = input.substr(1);
    }

    return original_array;
}

string* insertionSort(int inputSize, string* original_array, string* sorted_array) //========================================================================================
{
    string key;
    int index;
    for (int i = 0; i < inputSize; i++)
    {
        key = sorted_array[i];
        index = i;
            while (index > 0 && sorted_array[index-1] > key)
            {
                sorted_array[index] = sorted_array[index-1];
                index = index - 1;
            }
            sorted_array[index] = key;
    }

    return sorted_array;
}

void quickSort(string* sorted_array, int low, int high) //========================================================================================================
{
    int pi;

    if (low < high)
    {
        pi = partition((string*)sorted_array, low, high);
        //cout << pi << endl;
        quickSort((string*)sorted_array, low, pi - 1);
        quickSort((string*)sorted_array, pi + 1, high);
    }   
}

int partition(string* sorted_array, int low, int high)
{
    string key;
    string keyTwo;
    string pivot;
    pivot = sorted_array[high];
    //cout << pivot << endl;
    int i = (low-1);
    for (int j = low; j <= high - 1; j++)
    {
        // if current value is smaller than pivot
        if (sorted_array[j] < pivot)
        {
            i++;
            swap(sorted_array[i], sorted_array[j]);
        }
    }

    swap(sorted_array[i + 1], sorted_array[high]);

    return (i + 1);
}