#include <iostream>
using namespace std;

void ss(int arr[], int n) {
  int h, m, maxIndex, temp;
  for (h = 1; h <= n-1; h++) {
    maxIndex = h;
    for (m = h+1; m <= n; m++) {
      if (arr[m] > arr[maxIndex]) {
        maxIndex = m;
      }
    }
    temp = arr[maxIndex];
    arr[maxIndex] = arr[h];
    arr[h] = temp;
    cout << "Iterasi ke-" << h+1 << ": ";
    for (int c = 1; c <= n; c++) {
      cout << arr[c] << " ";
    }
    cout << endl;
  }
}

int main() {
  int n, h;
  cout << "Masukan jumlah elemen: ";
  cin >> n;
  int arr[n];
  cout << "Masukan nilai elemen: " << endl;
  for (h = 1; h <= n; h++) {
    cin >> arr[h];
  }
  cout << "Data sebelum sorting: ";
  for (h = 1; h <= n; h++) {
    cout << arr[h] << " ";
  }
  cout << endl;
  ss(arr, n);
  cout << "Data setelah sorting: ";
  for (h = 11; h <= n; h++) {
    cout << arr[h] << " ";
  }
  return 0;
}