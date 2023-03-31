#include <iostream>
using namespace std;


// array of integers to hold values
int arr[20];
int cmp_count = 0;  // number of comparision
int mov_count = 0; // number of movement
int n;

void input() {
    while (true) {
        cout << "Masukkan panjang element array: ";
        cin >> n;

        if (n <= 20)
            break;
        else
            cout << "\n Maksimum panjang array adalah 20" << endl;
    }

    cout << "\n =======================" << endl;
    cout << "\n  Enter Array Element" << endl;
    cout << "\n =======================" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "<" << (i + 1) << ">";
        cin >> arr[i];
    }
}
//swap element at index x with the element at index y
void swap(int x, int y)
{
    int temp;
    temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void q_sort(int low, int high)
{
    int pivot, i, j;
    if (low > high) // langkah 1
        return;
    // partition the list into two part
    // one containing element less that or equal to pivot
    // outher containing element greather than pivot

    i = low + 1; // langkah 3
    j = high; // langkah 4
    pivot = arr[low]; // langkah 2

    while (i <= j) // langkah 10
    {
        // search for element greather than pivot
        while ((arr[i] <= pivot) && (i <= high)) // langkah 5
        {
            i++; // langkah 6
            cmp_count++;
        }
        cmp_count++;
        // search for an element less than or equal to pivot
        while ((arr[j] > pivot) && (j >= low)) 
        { 
            j--; //langkah 8
            cmp_count++;
        }
    }
    cmp_count++;
    if (i < j) // langkah 9
        // if greater element is on left of the element 
    {
        // swap the element at index  i with the element at index j
        swap(i, j); // langkah 11
        mov_count++;
    }
    // j now containt the index of the last element in the sort list
    if (low < j) // langkah 11
        // move  to the pivot to its correct  position in the list
    {
        swap(low, j);
        mov_count++;
    }

    // sort the list on the left of pivot using quick sort
    q_sort(low, j - 1); // langkah 12
    // sort the list on the right of pivot using quick sort
    q_sort(j + 1, high); // langkah 13
}

void display() {
    cout << "\n===========================" << endl;
    cout << "\n Sorted Array"<< endl;
    cout << "\n===========================" << endl;

    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << "\n\n Number of comparision: " << cmp_count << endl;
    cout << " Number of data movement: " << mov_count << endl;
}


int main()
{
    input();
    q_sort(0, n - 1);  // sort the array using quick sort
    display();
    system("pause");

         return 0;
}
