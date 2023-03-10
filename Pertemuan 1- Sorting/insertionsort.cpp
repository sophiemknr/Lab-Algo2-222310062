#include <iostream>
using namespace std;

int main() {
  int h;
  cout << "Masukan banyak array : ";
  cin >> h;
  int x[h];
  for (int m=0; m<h; m++){
    cout << "Masukan angka ke " << m << " :";
    cin >> x[m];
    cout << endl;
  }
  for (int m=1; m<h; m++){
    int key = x[m];
    int c = m-1;
    while(c>=0 && x[c] < key){
      x[c+1] = x[c];
      c--;
    }
    x[c+1] = key;
    cout << "Proses sorting" << endl;
    for (int p=0; p<h; p++){
      cout << x[p] << " ";
    }
    cout << endl;
  }
  cout << "Hasil akhir" << endl;
  for (int p=0; p<h; p++){
    cout << x[p] << " ";
  }
}