#include <iostream>
#define SIZE 10
using namespace std;

class HashTable {
private:
    int* keys;
    int* values;
    int* flags;

public:
    HashTable() {
        keys = new int[SIZE];
        values = new int[SIZE];
        flags = new int[SIZE];
        for (int i = 0; i < SIZE; i++) {
            keys[i] = -1;
            values[i] = -1;
            flags[i] = 0;
        }
    }

    int hashFunction1(int key) {
        return key % SIZE;
    }

    int hashFunction2(int key) {
        return 7 - (key % 7);
    }

    void insert(int key, int value) {
        int index = hashFunction1(key);
        int stepSize = hashFunction2(key);
        while (flags[index] == 1) {
            index += stepSize;
            index %= SIZE;
        }
        keys[index] = key;
        values[index] = value;
        flags[index] = 1;
    }

    int search(int key) {
        int index = hashFunction1(key);
        int stepSize = hashFunction2(key);
        while (flags[index] != 0) {
            if (flags[index] == 1 && keys[index] == key) {
                return values[index];
            }
            index += stepSize;
            index %= SIZE;
        }
        return -1; // Jika kunci tidak ditemukan
    }

    void remove(int key) {
        int index = hashFunction1(key);
        int stepSize = hashFunction2(key);
        while (flags[index] != 0) {
            if (flags[index] == 1 && keys[index] == key) {
                keys[index] = -1;
                values[index] = -1;
                flags[index] = -1;
                std::cout << "Elemen dengan kunci " << key << " telah dihapus." << std::endl;
                return;
            }
            index += stepSize;
            index %= SIZE;
        }
        cout << "Elemen dengan kunci " << key << " tidak ditemukan." << endl;
    }

    ~HashTable() {
        delete[] keys;
        delete[] values;
        delete[] flags;
    }
};

int main() {
    HashTable hashTable;
    
    hashTable.insert(5, 10);
    hashTable.insert(15, 20);
    hashTable.insert(25, 30);
    
    cout << "Hasil pencarian untuk kunci 5: " << hashTable.search(5) << endl;
    cout << "Hasil pencarian untuk kunci 15: " << hashTable.search(15) << endl;
    cout << "Hasil pencarian untuk kunci 25: " << hashTable.search(25) << endl;
    cout << "Hasil pencarian untuk kunci 35: " << hashTable.search(35) << endl;
    
    hashTable.remove(15);
    hashTable.remove(35);

    return 0;
}  