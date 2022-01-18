#include <iostream>
#include <string>
using namespace std;

class myArray
{
public:
    int totalSize, usedSize;
    int *ptr = new int[totalSize];

    myArray(int tSize, int uSize)
    {
        totalSize = tSize;
        usedSize = uSize;
    }

    void setValue(void);
    void display(void);
    void insertion(int, int);
    void deletetion(int);
};

void myArray ::setValue()
{
    int value;

    for (int i = 0; i < usedSize; i++)
    {
        cout << "Enter Value at position " << i + 1 << ": ";
        cin >> value;

        *(ptr + i) = value;
    }
}

// Insertion
void myArray ::insertion(int ind, int element)
{
    if (usedSize < totalSize)
    {
        for (int i = usedSize-1; i >= ind; i--)
        {
            *(ptr + i+1) = *(ptr + i);
        }

        *(ptr + ind) = element;
        usedSize += 1;
        display();
    }
}

// Deletion
void myArray :: deletetion(int possition) {
    for (int i = possition-1; i < usedSize-1; i++)
    {
        *(ptr + i) = *(ptr + i+1);
    }

    usedSize --;
    display();
}

// Traversal
void myArray ::display()
{
    for (int i = 0; i < usedSize; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;
}

int main()
{
    myArray arr1(10, 5);
    arr1.setValue();
    arr1.display();

    arr1.insertion(3, 70);
    arr1.deletetion(2);

    return 0;
}