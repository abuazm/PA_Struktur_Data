#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

struct lapangan{
    string id_lapangan;
    string fasilitas;
    string jenis_lapangan;
    string id_penyewa;
    int harga;
};
struct user{
    string id_user;
    string username;
    string password;
    string nomor_hp;
    string alamat;
};




// struct barang
// {
//     string nama;
//     string jenis;
//     string warna;
//     string ukuran;
//     int harga;
//     barang *next = NULL;
//     barang *prev = NULL;
// };

// barang *newbarang()
// {
//     barang *barangBaru = new barang;
//     cout << "Masukkan Nama: ";
//     fflush(stdin);
//     getline(cin, barangBaru->nama);
//     cout << "Masukkan Jenis: ";
//     fflush(stdin);
//     getline(cin, barangBaru->jenis);
//     cout << "Masukkan Warna: ";
//     fflush(stdin);
//     getline(cin, barangBaru->warna);
//     cout << "Masukkan Ukuran/Berat: ";
//     fflush(stdin);
//     getline(cin, barangBaru->ukuran);
//     cout << "Masukkan Harga: ";
//     cin >> barangBaru->harga;
//     return barangBaru;
// }
// bool isEmpty(barang *head, barang *tail)
// {
//     if (head == NULL && tail == NULL)
//     {
//         return true;
//     }
//     return false;
// }

// void tambahDiAwal(barang **head, barang **tail)
// {
//     barang *barangBaru = newbarang();
//     if (isEmpty(*head, *tail))
//     {
//         *head = barangBaru;
//         *tail = barangBaru;
//     }
//     else
//     {
//         barangBaru->next = *head;
//         (*head)->prev = barangBaru;
//         *head = barangBaru;
//     }
// }

// void tambahDiAkhir(barang **head, barang **tail)
// {
//     if (isEmpty(*head, *tail))
//     {
//         tambahDiAwal(head, tail);
//     }
//     else
//     {
//         barang *barangBaru = newbarang();
//         (*tail)->next = barangBaru;
//         barangBaru->prev = *tail;
//         *tail = barangBaru;
//     }
// }

// // Fungsi untuk menambah data di akhir linked list

// void tambahDiAntara(barang **head, barang **tail, int idx)
// {
//     if (isEmpty(*head, *tail))
//     {
//         tambahDiAwal(head, tail);
//     }
//     else
//     {
//         barang *temp = *head;
//         for (int i = 0; i < idx; i++)
//         {
//             temp = temp->next;
//         }
//         if (temp == *head)
//         {
//             tambahDiAwal(head, tail);
//         }
//         else if (temp == NULL)
//         {
//             tambahDiAkhir(head, tail);
//         }
//         else
//         {
//             barang *barangBaru = newbarang();
//             barangBaru->prev = temp->prev;
//             barangBaru->next = temp;
//             temp->prev->next = barangBaru;
//             temp->prev = barangBaru;
//         }
//     }
// }

// // Fungsi untuk menghapus data di awal linked list

// void hapusDiAwal(barang **head, barang **tail)
// {
//     delete *head;
//     if ((*head)->next == NULL)
//     {
//         *head == NULL;
//         *tail == NULL;
//     }
//     else
//     {
//         *head = (*head)->next;
//         (*head)->prev = NULL;
//         cout << "Linked List kosong." << endl;
//     }
// }

// // Fungsi untuk menghapus data di akhir linked list
// void hapusDiAkhir(barang **head, barang **tail)
// {
//     delete *tail;
//     if ((*head)->next == NULL)
//     {
//         hapusDiAwal(head, tail);
//     }
//     else
//     {
//         *tail = (*tail)->prev;
//         (*tail)->next = NULL;
//     }
// }

// // Fungsi untuk menghapus data di antara node-node linked list
// void hapusDiAntara(barang **head, barang **tail, int idx)
// {
//     barang *temp = *head;
//     for (int i = 0; i < idx; i++)
//     {
//         temp = temp->next;
//     }
//     if (temp == *head)
//     {
//         hapusDiAwal(head, tail);
//     }
//     else if (temp == *tail)
//     {
//         hapusDiAkhir(head, tail);
//     }
//     else
//     {
//         temp->prev->next = temp->next;
//         temp->next->prev = temp->prev;
//         delete temp;
//     }
// }

// void update(barang *&head, int posisi)
// {
//     if (!head)
//     {
//         cout << "Linked List kosong." << endl;
//         return;
//     }

//     barang *current = head;
//     int count = 1;
//     while (current && count < posisi)
//     {
//         current = current->next;
//         count++;
//     }

//     if (current)
//     {
//         cout << "Data Lama:" << endl;
//         cout << "Nama: " << current->nama << endl;
//         cout << "Jenis: " << current->jenis << endl;
//         cout << "Warna: " << current->warna << endl;
//         cout << "Ukuran/Berat: " << current->ukuran << endl;
//         cout << "Harga: " << current->harga << endl;

//         cout << "Masukkan Data Baru:" << endl;
//         cout << "Masukkan Nama: ";
//         fflush(stdin);
//         getline(cin, current->nama);
//         cout << "Masukkan Jenis: ";
//         fflush(stdin);
//         getline(cin, current->jenis);
//         cout << "Masukkan Warna: ";
//         fflush(stdin);
//         getline(cin, current->warna);
//         cout << "Masukkan Ukuran/Berat: ";
//         fflush(stdin);
//         getline(cin, current->ukuran);
//         cout << "Masukkan Harga: ";
//         cin >> current->harga;
//     }
//     else
//     {
//         cout << "Posisi tidak valid." << endl;
//     }
// }

// // Fungsi untuk menampilkan data dari linked list

// void displayHead(barang *head, barang *tail)
// {
//     if (isEmpty(head, tail))
//     {
//         cout << "Barang masih kosong !!" << endl;
//     }
//     else
//     {
//         barang *temp = head;
//         while (temp != NULL)
//         {
//             cout << "====================================================" << endl;
//             cout << "|| Nama : " << temp->nama << endl;
//             cout << "|| Jenis : " << temp->jenis << endl;
//             cout << "|| Warna : " << temp->warna << endl;
//             cout << "|| Ukuran/Berat : " << temp->ukuran << endl;
//             cout << "|| Harga : " << temp->harga << endl;
//             cout << "====================================================" << endl;
//             temp = temp->next;
//         }
//     }
// }

// void displayTail(barang *head, barang *tail)
// {
//     if (isEmpty(head, tail))
//     {
//         cout << "Barang masih kosong !!" << endl;
//     }
//     else
//     {
//         barang *temp = tail;
//         while (temp != NULL)
//         {
//             cout << "====================================================" << endl;
//             cout << "|| Nama : " << temp->nama << endl;
//             cout << "|| Jenis : " << temp->jenis << endl;
//             cout << "|| Warna : " << temp->warna << endl;
//             cout << "|| Ukuran/Berat : " << temp->ukuran << endl;
//             cout << "|| Harga : " << temp->harga << endl;
//             cout << "====================================================" << endl;
//             temp = temp->prev;
//         }
//     }
// }

// // Fungsi untuk menyimpan data ke dalam file CSV
// void simpanKeCSV(barang *head)
// {
//     ofstream file("data_barang.csv");

//     if (!file.is_open())
//     {
//         cout << "Gagal membuka file data_barang.csv" << endl;
//         return;
//     }

//     barang *current = head;
//     while (current)
//     {
//         file << current->nama << ",";
//         file << current->jenis << ",";
//         file << current->warna << ",";
//         file << current->ukuran << ",";
//         file << current->harga << "\n";
//         current = current->next;
//     }

//     file.close();
//     cout << "Data telah disimpan ke dalam file data_barang.csv" << endl;
// }

// // Fungsi untuk membaca data dari file CSV
// void bacaDariCSV(barang *&head, barang *&tail)
// {
//     ifstream file("data_barang.csv");

//     if (!file.is_open())
//     {
//         cout << "File data_barang.csv tidak ditemukan." << endl;
//         return;
//     }

//     string line;
//     barang *current = nullptr; // Pointer tambahan
//     while (getline(file, line))
//     {
//         stringstream ss(line);
//         string nama, jenis, warna, ukuran, hargaStr;
//         getline(ss, nama, ',');
//         getline(ss, jenis, ',');
//         getline(ss, warna, ',');
//         getline(ss, ukuran, ',');
//         getline(ss, hargaStr, ',');

//         int harga = stoi(hargaStr); // Mengonversi harga dari string ke integer

//         barang *brng = new barang;
//         brng->nama = nama;
//         brng->jenis = jenis;
//         brng->warna = warna;
//         brng->ukuran = ukuran;
//         brng->harga = harga;
//         brng->next = nullptr;
//         brng->prev = current; // Mengatur node sebelumnya

//         if (head == nullptr)
//         {
//             // Jika *head masih NULL, maka elemen baru menjadi head
//             head = brng;
//             brng->prev = nullptr; // Set prev dari elemen baru ke nullptr
//             tail = brng;          // elemen baru juga menjadi tail karena ini elemen pertama
//         }
//         else
//         {
//             // Jika *head sudah ada, hubungkan elemen baru dengan yang ada
//             tail->next = brng;
//             brng->prev = tail;
//             tail = brng; // Set tail ke elemen baru
//         }

//         current = brng; // Update node sebelumnya ke elemen baru
//     }

//     file.close();
//     cout << "Data telah dibaca dari file data_barang.csv" << endl;
// }

// int length(barang *head)
// {
//     int panjang = 0;
//     barang *temp = head;
//     while (temp != NULL)
//     {
//         temp = temp->next;
//         panjang++;
//     }
//     return panjang;
// }

// void swapbarangs(barang **head, barang *a, barang *b)
// {
//     if (a == b)
//         return;

//     // Cari barang sebelum a dan b
//     barang *prevA = NULL, *prevB = NULL, *curr = *head;
//     while (curr)
//     {
//         if (curr->next == a)
//             prevA = curr;
//         if (curr->next == b)
//             prevB = curr;
//         curr = curr->next;
//     }

//     // Jika a adalah head, update head
//     if (a == *head)
//         *head = b;
//     else if (b == *head)
//         *head = a; // Jika b adalah head, update head

//     // Update next untuk prevA dan prevB
//     if (prevA)
//         prevA->next = b;
//     if (prevB)
//         prevB->next = a;

//     // Tukar next untuk a dan b
//     barang *temp = a->next;
//     a->next = b->next;
//     b->next = temp;
// }

// barang *findbarang(barang *head, int idx)
// {
//     barang *temp = head;

//     for (int i = 0; i < idx; i++)
//     {
//         temp = temp->next;
//     }

//     return temp;
// }

// void shellSort(barang **head, int n)
// {
//     for (int gap = n / 2; gap > 0; gap /= 2)
//     {
//         for (int i = gap; i < n; i++)
//         {
//             barang *temp = findbarang(*head, i);
//             int j;
//             for (j = i; j >= gap && findbarang(*head, j - gap)->nama > temp->nama; j -= gap)
//             {
//                 swapbarangs(head, findbarang(*head, j), findbarang(*head, j - gap));
//             }
//         }
//     }
// }

// void shellSort2(barang **head, int n)
// {
//     for (int gap = n / 2; gap > 0; gap /= 2)
//     {
//         for (int i = gap; i < n; i++)
//         {
//             barang *temp = findbarang(*head, i);
//             int j;
//             for (j = i; j >= gap && findbarang(*head, j - gap)->nama < temp->nama; j -= gap)
//             {
//                 swapbarangs(head, findbarang(*head, j), findbarang(*head, j - gap));
//             }
//         }
//     }
// }
// void shellSort3(barang **head, int n)
// {
//     for (int gap = n / 2; gap > 0; gap /= 2)
//     {
//         for (int i = gap; i < n; i++)
//         {
//             barang *temp = findbarang(*head, i);
//             int j;
//             for (j = i; j >= gap && findbarang(*head, j - gap)->harga > temp->harga; j -= gap)
//             {
//                 swapbarangs(head, findbarang(*head, j), findbarang(*head, j - gap));
//             }
//         }
//     }
// }
// void shellSort4(barang **head, int n)
// {
//     for (int gap = n / 2; gap > 0; gap /= 2)
//     {
//         for (int i = gap; i < n; i++)
//         {
//             barang *temp = findbarang(*head, i);
//             int j;
//             for (j = i; j >= gap && findbarang(*head, j - gap)->harga < temp->harga; j -= gap)
//             {
//                 swapbarangs(head, findbarang(*head, j), findbarang(*head, j - gap));
//             }
//         }
//     }
// }

// barang *findNode(barang *head, int idx)
// {
//     barang *temp = head;

//     for (int i = 0; i < idx; i++)
//     {
//         temp = temp->next;
//     }

//     return temp;
// }

// int jumpSearch(barang *head, string x, int n)
// {
//     int step = sqrt(n);
//     int prev = 0;
//     int idx = min(step, n) - 1;
//     while (findNode(head, idx)->nama < x)
//     {
//         prev = step;
//         step += sqrt(n);
//         idx = min(step, n) - 1;
//         if (prev >= n)
//         {
//             return -1;
//         }
//     }
//     while (findNode(head, prev)->nama < x)
//     {
//         prev++;
//     }
//     cout << endl;
//     if (findNode(head, prev)->nama == x)
//     {
//         return prev;
//     }
//     return -1;
// }



// const int NO_OF_CHARS = 256;
// void badCharHeuristic(string str, int size, int badChar[NO_OF_CHARS])
// {
//     // Inisialisasi semua nilai di badChar sebagai -1
//     for (int i = 0; i < NO_OF_CHARS; i++)
//     {
//         badChar[i] = -1;
//     }
//     for (int i = 0; i < size; i++)
//     {
//         badChar[(int)str[i]] = i;
//     }
// }

// // Booyer Moore Nama
// void search_booyer(barang *head, string pat)
// {
//     int m = pat.size();
//     int count;
//     barang *temp = head;
//     while (temp != NULL)
//     {
//         int n = temp->nama.size();
//         int badChar[NO_OF_CHARS];
//         badCharHeuristic(pat, m, badChar);
//         int s = 0;
//         while (s <= (n - m))
//         {
//             int j = m - 1;
//             while (j >= 0 && pat[j] == temp->nama[s + j])
//             {
//                 j--;
//             }
//             if (j < 0)
//             {
//                 cout << "Nama : " << temp->nama << endl;
//                 cout << "Jenis : " << temp->jenis << endl;
//                 cout << "Warna : " << temp->warna << endl;
//                 cout << "Ukuran/Harga : " << temp->ukuran << endl;
//                 cout << "Harga : " << temp->harga << endl;
//                 cout << "====================================" << endl;
//                 count++;
//                 break;
//             }
//             else
//             {
//                 s += max(1, j - badChar[temp->nama[s + j]]);
//             }
//         }
//         temp = temp->next;
//     }
//     if (count == 0)
//     {
//         cout << "Data tidak ditemukan" << endl;
//     }
// }
// // searching jenis
// void search_booyer1(barang *head, string pat)
// {
//     int m = pat.size();
//     int count;
//     barang *temp = head;
//     while (temp != NULL)
//     {
//         int n = temp->nama.size();
//         int badChar[NO_OF_CHARS];
//         badCharHeuristic(pat, m, badChar);
//         int s = 0;
//         while (s <= (n - m))
//         {
//             int j = m - 1;
//             while (j >= 0 && pat[j] == temp->jenis[s + j])
//             {
//                 j--;
//             }
//             if (j < 0)
//             {
//                 cout << "Nama : " << temp->nama << endl;
//                 cout << "Jenis : " << temp->jenis << endl;
//                 cout << "Warna : " << temp->warna << endl;
//                 cout << "Ukuran/Harga : " << temp->ukuran << endl;
//                 cout << "Harga : " << temp->harga << endl;
//                 cout << "====================================" << endl;

//                 count++;
//                 break;
//             }
//             else
//             {
//                 s += max(1, j - badChar[temp->nama[s + j]]);
//             }
//         }
//         temp = temp->next;
//     }
//     if (count == 0)
//     {
//         cout << "Data tidak ditemukan" << endl;
//     }
// }

// void fixPrevious(barang **head, barang **tail)
// {
//    barang *temp = *head;
//     barang *prev = NULL;
//     while (temp!= NULL)
//     {
//         temp->prev = prev;
//         prev = temp;
//         temp = temp->next;
//     }
//     *tail = prev;
// }



// int main()
// {
//     barang *head = NULL;
//     barang *tail = NULL;
//     bacaDariCSV(head, tail);
//     int idx;
//     int pilih, pilihdisplay;
//     while (true)
//     {
//         cout << "====================================" << endl;
//         cout << "||       Menu Toko Badminton      ||" << endl;
//         cout << "===================================" << endl;
//         cout << "|| 1. Tambah Data Barang          ||" << endl;
//         cout << "|| 2. Lihat Data Barang           ||" << endl;
//         cout << "|| 3. Update Data Barang          ||" << endl;
//         cout << "|| 4. Hapus Data Barang           ||" << endl;
//         cout << "|| 5. Urutkan Data                ||" << endl;
//         cout << "|| 6. Searching Data              ||" << endl;
//         cout << "|| 7. Exit                        ||" << endl;
//         cout << "====================================" << endl;
//         cout << "Pilih : ";
//         cin >> pilih;
//         cin.ignore();

//         if (pilih == 1)
//         {
//             int pilih1;
//             while (true)
//             {
//                 cout << "====================================" << endl;
//                 cout << "||       Menu Tambah Data         ||" << endl;
//                 cout << "===================================" << endl;
//                 cout << "|| 1. Tambah Data di Awal         ||" << endl;
//                 cout << "|| 2. Tambah Data di Akhir        ||" << endl;
//                 cout << "|| 3. Tambah Data di Antara       ||" << endl;
//                 cout << "====================================" << endl;
//                 cout << "Pilih : ";
//                 cin >> pilih1;
//                 if (pilih1 == 1)
//                 {
//                     tambahDiAwal(&head, &tail);
//                 }
//                 else if (pilih1 == 2)
//                 {
//                     tambahDiAkhir(&head, &tail);
//                 }
//                 else if (pilih1 == 3)
//                 {
//                     displayHead(head, tail);
//                     cout << "Mau tambah di nama no brp : ";
//                     cin >> idx;
//                     tambahDiAntara(&head, &tail, idx - 1);
//                 }
//                 else
//                 {
//                     cout << "Pilihan tidak valid." << endl;
//                 }
//             }
//         }
//         else if (pilih == 2)
//         {
//             cout << "=================================" << endl;
//             cout << "||       Menu Display          ||" << endl;
//             cout << "=================================" << endl;
//             cout << "||     1. Display Head         ||" << endl;
//             cout << "||     2. Display Tail         ||" << endl;
//             cout << "=================================" << endl;
//             cout << "Pilih : ";
//             cin >> pilihdisplay;
//             if (pilihdisplay == 1)
//             {
//                 displayHead(head, tail);
//             }
//             else if (pilihdisplay == 2)
//             {
//                 displayTail(head, tail);
//             }
//         }
//         else if (pilih == 3)
//         {
//             displayHead(head, tail);
//             int idx;
//             cout << "Update Data Barang Ke: ";
//             cin >> idx;
//             update(head, idx);
//         }
//         else if (pilih == 4)
//         {
//             int pilih2;
//             displayHead(head, tail);
//             while (true)
//             {
//                 cout << "====================================" << endl;
//                 cout << "||       Menu Tambah Data         ||" << endl;
//                 cout << "===================================" << endl;
//                 cout << "|| 1. Hapus Data di Awal          ||" << endl;
//                 cout << "|| 2. Hapus Data di Akhir         ||" << endl;
//                 cout << "|| 3. Hapus Data di Antara        ||" << endl;
//                 cout << "====================================" << endl;
//                 cout << "Pilih : ";
//                 cin >> pilih2;
//                 if (pilih2 == 1)
//                 {
//                     hapusDiAwal(&head, &tail);
//                     break;
//                 }
//                 else if (pilih2 == 2)
//                 {
//                     hapusDiAkhir(&head, &tail);
//                     break;
//                 }
//                 else if (pilih2 == 3)
//                 {
//                     displayHead(head, tail);
//                     cout << "Mau hapus di nama no brp : ";
//                     cin >> idx;
//                     hapusDiAntara(&head, &tail, idx - 1);
//                 }
//                 else
//                 {
//                     cout << "Pilihan tidak valid." << endl;
//                 }
//             }
//         }
//         else if (pilih == 5)
// {
//     int pilih2;
//     while (true)
//     {
//         cout << "================================" << endl;
//         cout << "||        MENU SORT            ||" << endl;
//         cout << "================================" << endl;
//         cout << "|| 1.        ASC               ||" << endl;
//         cout << "|| 2.        DESC              ||" << endl;
//         cout << "================================" << endl;
//         cout << "Pilih : ";
//         cin >> pilih2;
//         if (pilih2 == 1)
//         {
//             int pilih1;
//             while (true)
//             {
//                 cout << "====================================" << endl;
//                 cout << "||          MENU SORT             ||" << endl;
//                 cout << "====================================" << endl;
//                 cout << "|| 1.     Sorting By Nama         ||" << endl;
//                 cout << "|| 2.     Sorting By Harga        ||" << endl;
//                 cout << "====================================" << endl;
//                 cout << "Pilih : ";
//                 cin >> pilih1;
//                 if (pilih1 == 1)
//                 {
//                     shellSort(&head, length(head));
//                     fixPrevious(&head, &tail);
//                     break;
//                 }
//                 else if (pilih1 == 2)
//                 {
//                     shellSort3(&head, length(head));
//                     fixPrevious(&head, &tail);
//                     break;
//                 }
//             }
//         }
//         else if (pilih2 == 2)
//         {
//             int pilih1;
//             while (true)
//             {
//                 cout << "====================================" << endl;
//                 cout << "||          MENU SORT             ||" << endl;
//                 cout << "====================================" << endl;
//                 cout << "|| 1.     Sorting By Nama         ||" << endl;
//                 cout << "|| 2.     Sorting By Harga        ||" << endl;
//                 cout << "====================================" << endl;
//                 cout << "Pilih : ";
//                 cin >> pilih1;
//                 if (pilih1 == 1)
//                 {
//                     shellSort2(&head, length(head));
//                     fixPrevious(&head, &tail);
//                     break;
//                 }
//                 else if (pilih1 == 2)
//                 {
//                     shellSort4(&head, length(head));
//                     fixPrevious(&head, &tail);
//                     break;
//                 }
//             }
//         }
//         break; // Perlu ada break di sini agar kembali ke menu utama
//     }
// }


//         else if (pilih == 6)
//         {
//             int pilihseacrh;
//             while (true)
//             {
//                 cout << "====================================" << endl;
//                 cout << "||         Menu Searching        ||" << endl;
//                 cout << "===================================" << endl;
//                 cout << "|| 1. Search Nama Barang         ||" << endl;
//                 cout << "|| 2. Search Jenis Barang        ||" << endl;
//                 cout << "====================================" << endl;
//                 cout << "Pilih : ";
//                 cin >> pilihseacrh;
//                 cout << "____________________________________" << endl;
//                 if (pilihseacrh == 1)
//                 {
//                     string search;
//                     shellSort2(&head, length(head));
//                     cout << "Masukkan Nama Barang :";
//                     cin >> search;
//                     cout << "____________________________________" << endl;
//                     search_booyer(head, search);
//                     break;
//                 }
//                 else if (pilihseacrh == 2)
//                 {
//                     string search;
//                     shellSort2(&head, length(head));
//                     cout << "Masukkan Jenis Barang :";
//                     cin >> search;
//                     cout << "____________________________________" << endl;
//                     search_booyer1(head, search);
//                     break;
//                 }
//                 else
//                 {
//                     cout << "Pilihan tidak valid." << endl;
//                 }
//             }
//         }
//         else if (pilih == 7)
//         {
//             simpanKeCSV(head); // Simpan data ke CSV
//             exit(0);
//         }
//         else
//         {
//             cout << "Menu tidak valid." << endl;
//         }
//     }

//     return 0;
// }