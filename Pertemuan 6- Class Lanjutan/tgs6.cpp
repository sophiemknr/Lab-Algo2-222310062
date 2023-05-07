#include <iostream>
using namespace std;

class contoh { // nama kelas
private:       // membatasi akses
  int nilai;   // atribut

public:           // agar atribut dapat diubah diluar akses
  contoh(int n) { // object dan mengambil parameter n dan menugaskan ke atribut nilai = n
    nilai = n;
  }
  int getNum() { return nilai; }
};

int main() {
  // nama class nama obj(10)
  contoh obj(10);
  cout << "Nilai yang diinput: " << obj.getNum() << endl;
  return 0;
}