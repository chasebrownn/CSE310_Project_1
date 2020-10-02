#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <sstream>

/*
* Chase Brown
* 1212869071
*/

using namespace std;

//string* shiftRight(string, string* original_array);
//string* insertionSort(int, string* original_array, string* sorted_array);
//void quickSort(string* sorted_array, int, int);
//int partition(string* sorted_array, int, int);

void getAnswer(string, int, int*);
string getLast(string);
void getNext(int*, string, string);
string insertionSort(string);
void quickSort(char*, int, int);
int partition(char*, int, int);


int main(int argc, char** args)
{
    string answer;
    string sorted;
    string index;
    string last;
    string first;
    string sorting_method;
    string input;
    int input_size;
    int low;
    int high;
    int given;
    char* first_array;
    //int* next;

    for (int i = 0; i < argc; i++)
    {
        //printf("%d: %s\n", i, args[i]);
    }
    if (strcmp(args[1], "insertion") == 0)
    {
        sorting_method = "i";
    }
    else if (strcmp(args[1], "quick") == 0)
    {
        sorting_method = "q";
    }
    else
    {
        cout << "Not a valid sorting method" << endl;
        return 1;
    }

    //cout << sorting << endl;

    while (getline(cin, index))
    {
        getline(cin, input);
        //cout << "Index: " << index << endl;
        //cout << "Input String: " << input << endl;

        input_size = input.length();
        //cout << input_size << endl;

        last = getLast(input);
        //cout << last << endl;
        
        if (sorting_method == "i")
        {
            first = insertionSort(last);
            //cout << first << endl;
        }

        else if (sorting_method == "q")
        {

            //char_array = new char[input_size];
            first += last;
            first_array = &first[0];
            //strcpy(last, char_array.c_str());
            
            int low = 0;
            int high = (last.length() - 1);
            quickSort(first_array, low, high);
            //cout << first << endl;
            
        }

        int* next = new int[last.size()];
        getNext(next, first, last);

        stringstream geek(index);
        given = 0;
        geek >> given;

        getAnswer(last, given, next);

        delete[] next;
        delete first_array;
        //delete[] first_array;
    }

}

void getAnswer(string last_column, int index, int* next)
{
    string output;
    int i;
    int pos;

    pos = next[index];
    for (i = 0; i < last_column.size(); i++)
    {
        putchar(last_column[pos]);
        pos = next[pos];
    }

    cout << endl;
}

string getLast(string input)
{
    int k;
    int i = 0;
    int count;
    string last;
    int size = input.size();
    int index;

    while (i < size)
    {
        k = i;

        while (input[i] != ' ' && i < (size - 1))
        {
            i++;
        }

        count = stoi(input.substr(k, i));

        //cout << count << endl;

        if (i < (size))
        {
            for (int j = 0; j < count; j++)
            {
                last += input[i + 1];
            }
        }

        //cout << last << endl;
        i += 3;
    }
    return last;
}

void getNext(int* next_array, string first_string, string last_string)
{
    int j;
    int i;
    int k;
    int length = first_string.length();
    bool used = false;

    for (i = 0; i < length; i++)
    {
        //cout << endl;
        for (j = 0; j < length; j++)
        {
            //cout << "-> " << (int)last_string[j] << endl;
            if (first_string[i] == last_string[j])
            {
                for (k = 0; k < i; k++)
                {
                    if (next_array[k] == j)
                    {
                        used = true;
                        break;
                    }

                }
                
                if (used == false)
                {
                    next_array[i] = j;
                    break;
                }
                used = false;
            }

        }

    }

}

/*
* string test = "12 c 1 b";
* int index;
* 
* int i = stoi(test, &index);
* 
* Output: i = 12 . index = 2
*   c is at index 3
*   index + 1 will always be the start of the next fragment
*/

string insertionSort(string last)
{
    int size = last.length();
    int index;
    char key;

    for (int i = 0; i < size; i++)
    {
        key = last[i];
        index = i;
        while (index > 0 && last[index - 1] > key)
        {
            last[index] = last[index - 1];
            index = index - 1;
        }
        last[index] = key;
    }
    return last;
}

void quickSort(char* first, int low, int high)
{
    int pi;

    if (low < high)
    {
        pi = partition(first, low, high);

        quickSort(first, low, pi - 1);
        quickSort(first, pi + 1, high);
    }
    
}

int partition(char* sortThis, int low, int high)
{
    char pivot;
    pivot = sortThis[high];

    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (sortThis[j] < pivot)
        {
            i++;
            swap(sortThis[i], sortThis[j]);
        }
    }
    swap(sortThis[i + 1], sortThis[high]);

    return (i + 1);
}