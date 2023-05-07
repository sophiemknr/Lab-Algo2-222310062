#include <iostream>
#include <string>

using namespace std;

class Buku {
private:
  string judul;
  string pengarang;
  bool dipinjam;

public:
  Buku(string j, string p) {
    judul = j;
    pengarang = p;
    dipinjam = false;
  }
  void setDipinjam(bool status) { dipinjam = status; }
  bool getDipinjam() { return dipinjam; }
  string getJudul() { return judul; }
  string getPengarang() { return pengarang; }
};

class Pelajar {
private:
  string nama;
  int umur;
  Buku *bukuPinjaman;

public:
  Pelajar(string n, int u) {
    nama = n;
    umur = u;
    bukuPinjaman = nullptr;
  }
  void pinjamBuku(Buku *buku) {
    if (buku->getDipinjam()) {
      cout << "Buku sedang dipinjam" << endl;
    } else {
      buku->setDipinjam(true);
      bukuPinjaman = buku;
      cout << "Buku " << buku->getJudul() << " berhasil dipinjam oleh " << nama
           << endl;
    }
  }
  void kembalikanBuku() {
    if (bukuPinjaman == nullptr) {
      cout << "Anda tidak memiliki buku yang dipinjam" << endl;
    } else {
      bukuPinjaman->setDipinjam(false);
      cout << "Buku " << bukuPinjaman->getJudul()
           << " berhasil dikembalikan oleh " << nama << endl;
      bukuPinjaman = nullptr;
    }
  }
};

int main() {
  Buku buku1("Laut Bercerita", "Leila S. Chudori");
  Buku buku2("The Subtle Art of Not Giving a F*ck", "Mark Manson");
  Pelajar pelajar1("Yujin", 25);
  Pelajar pelajar2("Hyunjae", 38);

  pelajar1.pinjamBuku(&buku1);
  pelajar2.pinjamBuku(&buku1);
  pelajar2.pinjamBuku(&buku2);

  pelajar1.kembalikanBuku();
  pelajar2.kembalikanBuku();
  pelajar1.kembalikanBuku();

  return 0;
}