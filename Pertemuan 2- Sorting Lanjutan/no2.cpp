#include <iostream>
using namespace std;
int const SIZE = 5;                               

void swap(int &c, int &s)
{
    int temp;
    temp = c;
    c = s;
    s = temp;
}


void PrintArray(int* array, int n)
{
    int i;

    for( i = 0; i < n; i++) cout<<array[i]<<',';
}

int SplitArray(int* array, int pivot, int startIndex, int endIndex){
    int leftBoundary = startIndex;
    int rightBoundary = endIndex;
    while(leftBoundary < rightBoundary)            {
        while( pivot < array[rightBoundary]&& rightBoundary > leftBoundary){
            rightBoundary--;                      
        }
        swap(array[leftBoundary], array[rightBoundary]);
        while( pivot >= array[leftBoundary]&& leftBoundary < rightBoundary){
            leftBoundary++;                        
        }
        swap(array[rightBoundary], array[leftBoundary]);
    }
    return leftBoundary;                              
}

void QuickSort(int* array, int startIndex, int endIndex){
    int pivot = array[startIndex];                  
    int splitPoint;
    if(endIndex > startIndex){
        splitPoint = SplitArray(array, pivot, startIndex, endIndex);
        array[splitPoint] = pivot;
        QuickSort(array, startIndex, splitPoint-1);  
        QuickSort(array, splitPoint+1, endIndex);    
    }
}
int main(){
    int array[SIZE];
    cout << "Program ini mendemonstrasikan quicksort menggunakan algoritma rekursif" << endl;
    for(int i = 0; i < SIZE; i++){
        cout<<"Masukkan nilai integer : ";
        cin>>array[i];
    }
    cout<<endl<<"Daftar yang Anda masukkan adalah : "<<endl;
    PrintArray(array, SIZE);
    QuickSort(array,0,SIZE - 1);
    cout<<endl<<"Daftarnya sudah diurutkan, daftar sekarang adalah : "<<endl;
    PrintArray(array,SIZE);
    cin.sync();
    cin.get();
}