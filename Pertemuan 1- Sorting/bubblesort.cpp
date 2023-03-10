#include <iostream>
using namespace std;

void bs(int arr[], int n){
  int h, m, tmp;
  for (h=1; h<=n; h++){
    for (m=1; m<n; m++){
      if(arr[m]<arr[m+1]){
        tmp = arr[m];
        arr[m] = arr[m+1];
        arr[m+1] = tmp;
      }
    }
  }
}
  int main() {
    int array[100], n, h, m;
    cout << "Masukan banyak elemen: ";
    cin >> n;
    cout << "Masukan nilai : \n";
    for (h=1; h<=n; h++){
      cin >> array[h];
    }
    bs(array, n);
    cout << "Hasil pengurutan dengan algoritma bubble sort : \n";
    for (h=1; h<=n; h++){
      cout << array[h] << " ";
    }
    cout << "\n";
 }