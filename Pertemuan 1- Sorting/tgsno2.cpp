#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
  char str[5][20], t[20];
  int h, m;
  cout << "\n Masukan Judul Buku : \n\n";
  for (h = 0; h < 5; h++) {
    cout << " ";
    cin >> str[h];
  }
  for (h = 1; h < 5; h++) {
    for (m = 1; m < 5; m++) {
      if (strcmp(str[m - 1], str[m]) > 0) {
        strcpy(t, str[m - 1]);
        strcpy(str[m - 1], str[m]);
        strcpy(str[m], t);
      }
    }
  }
  cout << "\n Judul buku setelah diurutkan dalam alfabet : \n\n";
  for (h = 0; h < 5; h++) {
    cout << " ";
    cout << str[h] << "\n";
  }
  return 0;
}