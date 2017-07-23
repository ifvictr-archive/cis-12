#include <cmath>
#include <iostream>

using namespace std;

void setZero(int array[], int arraySize);
void inputArray(int array[], int arraySize);
void doubleArray(const int fromArray[], int toArray[], int arraySize);
void copyGamma(const int fromArray[], int toArray[][4]);
void copyAlphaBeta(const int fromArray1[20], const int fromArray2[20], int toArray[][4]);
void printArray(const int array[], int arraySize);
void setInStock(const int fromArray[], int toArray[][4]);

int main()
{
    int alpha[20];
    int beta[20];
    int gamma[4] = {11, 13, 15, 17};
    int delta[10] = {3, 5, 2, 6, 10, 9, 7, 11, 1, 8};
    int inStock[10][4];
    
    setZero(alpha, 20);
    cout << "Alpha after initialization\n";
    printArray(alpha, 20);
    cout << "\n\n";
    
    inputArray(alpha, 20);
    cout << "\n";
    cout << "Alpha after reading 20 numbers\n";
    printArray(alpha, 20);
    cout << "\n\n";
    
    doubleArray(alpha, beta, 20);
    cout << "Beta after a call to doubleArray\n";
    printArray(beta, 20);
    cout << "\n\n";
    
    cout << "inStock after a call to copyGamma\n";
    copyGamma(gamma, inStock);
    cout << "\n";
    
    cout << "inStock after a call to copyAlphaBeta\n";
    copyAlphaBeta(alpha, beta, inStock);
    cout << "\n";
    
    setInStock(delta, inStock);
    
    return 0;
}

void setZero(int array[], int arraySize)
{
    for(int i = 0; i < arraySize; i++)
    {
        array[i] = 0;
    }
}

void inputArray(int array[], int arraySize)
{
    cout << "Enter " << arraySize << " integers\n";
    for(int i = 0; i < arraySize; i++)
    {
        cin >> array[i];
    }
}

void doubleArray(const int fromArray[], int toArray[], int arraySize)
{
    for(int i = 0; i < arraySize; i++)
    {
        toArray[i] = fromArray[i] * 2;
    }
}

void copyGamma(const int fromArray[], int toArray[10][4])
{
    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 4; y++)
        {
            toArray[x][y] = fromArray[y] * pow(3, x);
            cout << toArray[x][y] << "\t";
        }
        cout << "\n";
    }
}

void copyAlphaBeta(const int fromArray1[20], const int fromArray2[20], int toArray[10][4])
{
    int counter = 0;
    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 4; y++)
        {
            // First array goes in first five rows
            if(x < 5)
            {
                toArray[x][y] = fromArray1[counter];
            }
            // Second array goes in last five rows
            else
            {
                toArray[x][y] = fromArray2[counter];
            }
            cout << toArray[x][y] << "\t";
            counter++;
        }
        // Reset counter when at end of of a fromArray
        if(counter > 19)
        {
            counter = 0;
        }
        cout << "\n";
    }
}

void printArray(const int array[], int arraySize)
{
    for(int i = 0; i < arraySize; i++)
    {
        cout << array[i] << "\t";
    }
}

void setInStock(const int fromArray[], int toArray[][4])
{
    cout << "Enter 10 integers\n";
    for(int i = 0; i < 10; i++)
    {
        cin >> toArray[i][0];
    }
    cout << "\n";
    cout << "inStock after a call to setInStock\n";
    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 4; y++)
        {
            // Only edit columns that aren't the first column
            if(y != 0){
                toArray[x][y] = (toArray[x][y - 1] * 2) - fromArray[x];
            }
            cout << toArray[x][y] << "\t";
        }
        cout << "\n";
    }
}