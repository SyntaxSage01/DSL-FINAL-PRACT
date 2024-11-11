/*
Name : Kashvi Goyal 
Roll No : 15
PRN No : F23112017
Class : SE-II(P-Batch)
*/

//Problem Statement M5

/*
Write merge sort algorithm in cpp.
*/

#include <iostream>
using namespace std;

void merge(int a[], int beg, int mid, int end)
{
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int LeftArray[n1], RightArray[n2];
    for (int i = 0; i < n1; i++)
        LeftArray[i] = a[beg + i];
    for (int j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j];
    i = 0;
    j = 0; 
    k = beg; 
    while (i < n1 && j < n2) {
        if(LeftArray[i] <= RightArray[j]) {
            a[k] = LeftArray[i];
            i++;
        }
        else
        {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }
    while (i<n1)
    {
        a[k] = LeftArray[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        a[k] = RightArray[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int beg, int end)
{
    if (beg < end) {
        int mid = (beg + end) / 2;
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}

void printArray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
    cout<<a[i]<<" ";
}

int main()
{
    int n;
    cout<<"Enter number of elements in array :"<<endl;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Enter array element : "<<endl;
        cin>>a[i];
    }
    cout<<"Before sorting array elements are - \n";
    printArray(a, n);
    mergeSort(a, 0, n - 1);
    cout<<"\nAfter sorting array elements are - \n";
    printArray(a, n);
    return 0;
}
/*
OUTPUT:
Enter the number of students: 6
Enter the marks of students: 90
Enter the marks of students: 78
Enter the marks of students: 86
Enter the marks of students: 45
Enter the marks of students: 98
Enter the marks of students: 60 

Before sorting array elements are-
90 78 86 45 98 60 
After sorting array elements are-
45 60 78 86 90 98 
Top 5 marks are: 98 90 86 78 60
*/