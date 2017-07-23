#include <iostream>

using namespace std;

const int ARRAY_SIZE = 50;

void initializeArray(double array[ARRAY_SIZE]);
void printArray(const double array[ARRAY_SIZE]);
void copyArray(const double fromArray[ARRAY_SIZE], double toArray[ARRAY_SIZE]);

int main()
{
    double alpha[ARRAY_SIZE];
    double beta[ARRAY_SIZE];
    
    initializeArray(alpha);
    cout << "The output of the alpha array:\n";
    printArray(alpha);
    cout << "\n\n";
    
    copyArray(alpha, beta);
    cout << "The output of the beta array:\n";
    printArray(beta);
    
    return 0;
}

void initializeArray(double array[ARRAY_SIZE])
{
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        // First 25 elements is the square of the index
        if(i < 25)
        {
            array[i] = i * i;
        }
        // Last 25 are three times the index
        else
        {
            array[i] = i * 3;
        }
    }
}

void printArray(const double array[ARRAY_SIZE])
{
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << array[i] << "\t";
        // 10 numbers per line
        if(((i + 1) % 10) == 0)
        {
            cout << "\n";
        }
    }
}

void copyArray(const double fromArray[ARRAY_SIZE], double toArray[ARRAY_SIZE])
{
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        toArray[i] = fromArray[i];
    }
}