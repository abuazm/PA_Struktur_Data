// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <bits/stdc++.h>
// using namespace std;


// struct lapangan{
//     string id_lapangan;
//     string fasilitas;
//     string jenis_lapangan;
//     int harga;
//     //bisa di tambah array jadwal sewa
//     lapangan *next;
//     lapangan *prev;
// };
// struct user{
//     string username;
//     string password;
//     string nomor_hp;
//     user *next;
//     user *prev;
// };
// struct penyewaan{
//     //nanti aja
// };

// // #operation
// // ->check linked list
// template <typename P>
// bool isempty(P *head, P *tail){
//     if(head == nullptr && tail == nullptr){
//         return true;
//     }
//     return false;
// }
// // ->check username is used
// bool finduser(string username, user *head_user){
//     user* current = head_user;
//     while (current != nullptr) {
//         if (current->username == username) {
//             return true;
//         }
//         current = current->next;
//     }
//     return false;
// }


// // #add
// user *Newuser(user head_user){
//     user *newuser = new user;
//     string username;
//     cout << "Masukkan username: "; getline(cin,username);
//     if (finduser(username,head_user) == true)
//     {
//         /* code */
//         newuser->username;
//         cout << "Masukkan pass: "; getline(cin,newuser->password);
//         cout << "Masukkan no hp: "; getline(cin,newuser->nomor_hp);
//         newuser->next = nullptr;
//         newuser->prev = nullptr;
//         return newuser;
//     } else
//     {
//         /* code */
//         cout << "username sudah di pakai" << endl;
//     }
// }

// void adduser(user *head_user, user *tail_user){
//     user *newuser = Newuser(head_user);
//     if(isempty(head_user,tail_user)){
//         head_user = newuser;
//         tail_user = newuser;
//     }else{
//         tail_user->next = newuser;
//         newuser->prev = tail_user;
//         tail_user = newuser;
//     }
// }


// // #view
// void view_alluser(user *head_user){
//     user *temp = head_user;
//     while(temp!= nullptr){
//         cout << temp->username << endl;
//         cout << temp->password << endl;
//         cout << temp->nomor_hp << endl;
//         cout << "================" << endl;
//         temp = temp->next;
//     }
// }


// int main(){
//     // used variabel
//     user *head_user = nullptr;
//     user *tail_user = nullptr;
//     cout << "1. add user" << endl;
//     cout << "2. view all user" << endl;
//     cout << "0. exit" << endl;
//     cout << "Masukkan pilihan: ";
//     int pilihan;
//     if (pilihan == 1)
//     {
//         /* code */
//         adduser(head_user,tail_user);
//     } else if (pilihan == 2)
//     {
//         /* code */
//         view_alluser(head_user);
//     } else if (pilihan == 0)
//     {
//         /* code */
//         cout << "keluar" << endl;
//     }
//     return 0;
// }



#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <bits/stdc++.h>

using namespace std;

struct lapangan {
    int no_lapangan;
    string jenis_lapangan;
    int harga;
    string fasilitas_lapangan;
    string status_lapangan;
    string hari [7] ;
    lapangan *next = nullptr;
    lapangan *prev = nullptr;
};

struct user {
    string username;
    string password;
    string nomor_hp;
    user* next = nullptr;
    user* prev = nullptr;
};

// Fungsi untuk mengecek apakah linked list kosong
template <typename P>
bool isempty(P* head, P* tail) {
    return (head == nullptr && tail == nullptr);
}

//eror paksa input harus int
bool ver_int(string input) {
    for (char c : input) {
        if (!isdigit(c)) {
            return true; // Mengandung karakter bukan integer
        }
    }
    return false; // Semua karakter adalah integer
}

int paksaint(){
    string reinput;
    cout << "Masukkan angka atau teks: ";
    getline(cin, reinput);
    while (true)
    {
        bool par = ver_int(reinput);
        if (par)
        {
            /* code */
            cout << "Hanya bisa Masukkan angka : ";
            getline(cin, reinput);
        } else
        {
            /* code */
            int number;
            stringstream ss(reinput);
            if (ss >> number) {
                cout << "Anda memasukkan angka: " << number << endl;
                return number;
            } else
            {
                /* code */
                cout << "Jangan kosong la : ";
                getline(cin, reinput);
            }
        }
    }
}
bool ver_space(string str) {
    for (char c : str) {
        if (!isspace(c)) {
            return false; // Jika ada karakter selain spasi, maka bukan hanya spasi
        }
    }
    return true; // Jika semua karakter adalah spasi
}

//eror paksa input harus string dan no kosong
string str_nokosong(){
    string user_input;
    do {
        cout << "Masukkan input: ";
        getline(cin, user_input);
        if (user_input.empty() || ver_space(user_input)) {
            cout << "Input tidak boleh kosong atau hanya spasi. Silakan coba lagi." << endl;
        }
        else {
            return user_input;
        }
    } while (user_input.empty() || ver_space(user_input));
}

// Fungsi untuk mencari apakah username sudah digunakan
user* finduser(string username, user* head_user) {
    user* current = head_user;
    while (current != nullptr) {
        if (current->username == username) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Fungsi untuk memeriksa apakah pengguna (user) valid (disini verif loginnya)
user* isUserValid (user *head_user, string username, string password) {
    user* user = finduser(username, head_user);
    if (user != nullptr && user->password == password) {
        return user;
    }
    return nullptr;
}


//fungsi2 crud
// Fungsi untuk membuat user baru
user* Newuser(user* head_user) {
    user* newuser = new user;
    cout << "Masukkan username: "; cin.ignore(); getline(cin, newuser->username);
    if (!finduser(newuser->username, head_user)) {
        cout << "Masukkan password: "; getline(cin, newuser->password);
        cout << "Masukkan nomor hp: "; getline(cin, newuser->nomor_hp);
        newuser->next = nullptr;
        newuser->prev = nullptr;
        return newuser;
    } else {
        cout << "Username sudah digunakan" << endl;
        delete newuser; // Hapus pointer jika username sudah digunakan
        return nullptr;
    }
}
lapangan *newlapangan()
{
    lapangan *lapanganBaru = new lapangan;
    cout << "Masukkan NO lapangan : ";
    cin >> lapanganBaru->no_lapangan;
    cout << "Masukkan jenis_lapangan : ";
    cin.ignore();
    getline(cin, lapanganBaru->jenis_lapangan);
    cout << "Masukkan Fasilitas lapangan : ";
    getline(cin, lapanganBaru->fasilitas_lapangan);
    cout << "Masukkan Status lapangan : ";
    getline(cin, lapanganBaru->status_lapangan);
    cout << "Masukkan harga : ";
    cin >> lapanganBaru->harga;
    return lapanganBaru;
}

// ========================================= untuk crud lapangan =================================================
void tambahDiawal(lapangan **head, lapangan **tail)
{
    lapangan *lapanganBaru = newlapangan();
    if (isempty(*head, *tail))
    {
        *head = lapanganBaru;
        *tail = lapanganBaru;
    }
    else
    {
        lapanganBaru->next = *head;
        (*head)->prev = lapanganBaru;
        *head = lapanganBaru;
    }
}
void tambahDiakhir(lapangan **head, lapangan **tail)
{
    if (isempty(*head, *tail))
    {
        tambahDiawal(head, tail);
    }
    else
    {
        lapangan *lapanganBaru = newlapangan();
        (*tail)->next = lapanganBaru;
        lapanganBaru->prev = *tail;
        *tail = lapanganBaru;
    }
}
void tambahDiantara(lapangan **head, lapangan **tail, int idx)
{
    if (isempty(*head, *tail))
    {
        tambahDiawal(head, tail);
    }
    else
    {
        lapangan *temp = *head;
        for (int i = 0; i < idx; i++)
        {
            temp = temp->next;
            if (temp == nullptr)
            {
                cout << "Indeks tidak valid" << endl;
                return;
            }
        }
        if (temp == *head)
        {
            tambahDiawal(head, tail);
        }
        else if (temp == nullptr)
        {
            tambahDiakhir(head, tail);
        }
        else
        {
            lapangan *lapanganBaru = newlapangan();
            lapanganBaru->prev = temp->prev;
            lapanganBaru->next = temp;
            temp->prev->next = lapanganBaru;
            temp->prev = lapanganBaru;
        }
    }
}
void update(lapangan *head, int posisi)
{
    if (!head)
    {
        cout << "Linked List kosong." << endl;
        return;
    }

    lapangan *current = head;
    int count = 1;
    while (current && count < posisi)
    {
        current = current->next;
        count++;
    }

    if (current)
    {
        cout << "Data Lama:" << endl;
        cout << "no_lapangan: " << current->no_lapangan << endl;
        cout << "jenis_lapangan_lapangan: " << current->jenis_lapangan << endl;
        cout << "fasilitas_lapangan: " << current->fasilitas_lapangan << endl;
        cout << "status_lapangan/Berat: " << current->status_lapangan << endl;
        cout << "harga: " << current->harga << endl;

        cout << "Masukkan Data Baru:" << endl;
        cout << "Masukkan no_lapangan: ";
        cin >> current->no_lapangan;
        cout << "Masukkan jenis_lapangan_lapangan: ";
        cin.ignore();
        getline(cin, current->jenis_lapangan);
        cout << "Masukkan fasilitas_lapangan: ";
        getline(cin, current->fasilitas_lapangan);
        cout << "Masukkan status_lapangan/Berat: ";
        getline(cin, current->status_lapangan);
        cout << "Masukkan harga: ";
        cin >> current->harga;
    }
    else
    {
        cout << "Posisi tidak valid." << endl;
    }
}
void hapusDiawal(lapangan **head, lapangan **tail)
{
    if (isempty(*head, *tail))
    {
        cout << "Linked List kosong." << endl;
        return;
    }
    if (*head == *tail)
    {
        delete *head;
        *head = nullptr;
        *tail = nullptr;
    }
    else
    {
        lapangan *temp = *head;
        *head = (*head)->next;
        (*head)->prev = nullptr;
        delete temp;
    }
}
void hapusDiakhir(lapangan **head, lapangan **tail)
{
    if (isempty(*head, *tail))
    {
        cout << "Linked List kosong." << endl;
        return;
    }
    if (*head == *tail)
    {
        delete *tail;
        *head = nullptr;
        *tail = nullptr;
    }
    else
    {
        lapangan *temp = *tail;
        *tail = (*tail)->prev;
        (*tail)->next = nullptr;
        delete temp;
    }
}
void hapusDiantara(lapangan **head, lapangan **tail, int idx)
{
    if (isempty(*head, *tail))
    {
        cout << "Linked List kosong." << endl;
        return;
    }
    lapangan *temp = *head;
    for (int i = 0; i < idx; i++)
    {
        temp = temp->next;
        if (temp == nullptr)
        {
            cout << "Indeks tidak valid." << endl;
            return;
        }
    }
    if (temp == *head)
    {
        hapusDiawal(head, tail);
    }
    else if (temp == *tail)
    {
        hapusDiakhir(head, tail);
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}
void displayHead(lapangan *head, lapangan *tail)
{
    if (isempty(head, tail))
    {
        cout << "lapangan masih kosong !!" << endl;
    }
    else
    {
        lapangan *temp = head;
        while (temp != nullptr)
        {
            cout << "====================================================" << endl;
            cout << "|| no_lapangan: " << temp->no_lapangan << endl;
            cout << "|| jenis_lapangan : " << temp->jenis_lapangan << endl;
            cout << "|| fasilitas_lapangan : " << temp->fasilitas_lapangan << endl;
            cout << "|| status_lapangan/Berat : " << temp->status_lapangan << endl;
            cout << "|| Harga : " << temp->harga << endl;
            cout << "====================================================" << endl;
            temp = temp->next;
        }
    }
}
void displayTail(lapangan *head, lapangan *tail)
{
    if (isempty(head, tail))
    {
        cout << "lapangan masih kosong !!" << endl;
    }
    else
    {
        lapangan *temp = tail;
        while (temp != nullptr)
        {
            cout << "====================================================" << endl;
            cout << "|| no_lapangan: " << temp->no_lapangan << endl;
            cout << "|| jenis_lapangan : " << temp->jenis_lapangan << endl;
            cout << "|| fasilitas_lapangan : " << temp->fasilitas_lapangan << endl;
            cout << "|| status_lapangan/Berat : " << temp->status_lapangan << endl;
            cout << "|| Harga : " << temp->harga << endl;
            cout << "====================================================" << endl;
            temp = temp->prev;
        }
    }
}



// ========================================= untuk crud user =================================================
// Fungsi untuk menambahkan user
void adduser(user* &head_user, user* &tail_user) {
    user* newuser = Newuser(head_user);
    if (newuser) { // Periksa jika pointer user tidak nullptr
        if (isempty(head_user, tail_user)) {
            head_user = newuser;
            tail_user = newuser;
        } else {
            tail_user->next = newuser;
            newuser->prev = tail_user;
            tail_user = newuser;
        }
    }
}

// Fungsi untuk melihat semua user
void view_alluser(user* head_user) {
    user* temp = head_user;
    while (temp != nullptr) {
        cout << "Username: " << temp->username << endl;
        cout << "Password: " << temp->password << endl;
        cout << "Nomor HP: " << temp->nomor_hp << endl;
        cout << "================" << endl;
        temp = temp->next;
    }
}


// ========================================= menulis dan baca csv =================================================
// penulisan dan pembacaan ke csv
// Fungsi untuk menulis data pengguna ke dalam file CSV
void writeUserToCSV(user* newUser) {
    ofstream file("users.csv"); // Membuka berkas untuk penulisan (ios::app untuk menambahkan data ke berkas yang ada)
    user *curr = newUser;
    if (file.is_open()) {
        while (curr!= nullptr) {
            file << curr->username << "," << curr->password << "," << curr->nomor_hp << endl;
            curr = curr->next;
        }
    } else {
        cout << "Gagal membuka berkas CSV" << endl;
    }
}

// Fungsi untuk membaca data pengguna dari file CSV
void readUsersFromCSV(user* &head_user, user* &tail_user) {
    ifstream file("users.csv");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string username, password, nomor_hp;
            if (getline(ss, username, ',') && getline(ss, password, ',') && getline(ss, nomor_hp, ',')) {
                user* newUser = new user;
                newUser->username = username;
                newUser->password = password;
                newUser->nomor_hp = nomor_hp;
                newUser->next = nullptr;
                newUser->prev = nullptr;

                if (isempty(head_user, tail_user)) {
                    head_user = newUser;
                    tail_user = newUser;
                } else {
                    tail_user->next = newUser;
                    newUser->prev = tail_user;
                    tail_user = newUser;
                }
            }
        }
        file.close();
    } else {
        cout << "Gagal membuka berkas CSV" << endl;
    }
}



// untuk lapangan
void simpanKeCSV(lapangan *head)
{
    ofstream file("data_lapangan.csv");
    if (!file.is_open())
    {
        cout << "Gagal membuka file data_lapangan.csv" << endl;
        return;
    }
    lapangan *current = head;
    while (current)
    {
        file << current->no_lapangan << ",";
        file << current->jenis_lapangan << ",";
        file << current->fasilitas_lapangan << ",";
        file << current->status_lapangan << ",";
        file << current->harga << "\n";
        current = current->next;
    }
    file.close();
    cout << "Data telah disimpan ke dalam file data_lapangan.csv" << endl;
}

void bacaDariCSV(lapangan *&head, lapangan *&tail)
{
    ifstream file("data_lapangan.csv");
    if (!file.is_open())
    {
        cout << "File data_lapangan.csv tidak ditemukan." << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string no_lapanganStr, jenis_lapangan, fasilitas_lapangan, status_lapangan, hargaStr;
        if (!getline(ss, no_lapanganStr, ',') || !getline(ss, jenis_lapangan, ',') ||
            !getline(ss, fasilitas_lapangan, ',') || !getline(ss, status_lapangan, ',') ||
            !getline(ss, hargaStr, ','))
        {
            cerr << "Error reading line from CSV." << endl;
            break;
        }

        int harga = stoi(hargaStr);
        int no_lapangan = stoi(no_lapanganStr);
        lapangan *brng = new lapangan;
        brng->no_lapangan = no_lapangan;
        brng->jenis_lapangan = jenis_lapangan;
        brng->fasilitas_lapangan = fasilitas_lapangan;
        brng->status_lapangan = status_lapangan;
        brng->harga = harga;
        brng->next = nullptr;
        brng->prev = tail;

        if (head == nullptr)
        {
            head = brng;
            brng->prev = nullptr;
            tail = brng;
        }
        else
        {
            tail->next = brng;
            tail = brng;
        }
    }

    file.close();
    cout << "Data telah dibaca dari file data_lapangan.csv" << endl;
}



int main() {
    // Variabel yang digunakan
    user* head_user = nullptr;
    user* tail_user = nullptr;
    lapangan* head_lapangan = nullptr;
    lapangan* tail_lapangan = nullptr;
    readUsersFromCSV(head_user, tail_user);
    bacaDariCSV(head_lapangan, tail_lapangan);
    bool isAdminLoggedIn = false; // Menandai apakah admin telah login
    user* loginuser = nullptr; // Menyimpan username pengguna yang sedang login (kalau ga di kasih nullptr keren :))

    while (true) {
        int pilihan; // Inisialisasi pilihan
        int idx;
        if (loginuser == nullptr) {
            cout << "====================================" << endl;
            cout << "||       Menu Toko Badminton      ||" << endl;
            cout << "===================================" << endl;
            cout << "|| 1. Registrasi                  ||" << endl;
            cout << "|| 2. Login                       ||" << endl;
            cout << "|| 0. Exit                        ||" << endl;
            cout << "====================================" << endl;
        } else {
            if (isAdminLoggedIn) {
                cout << "====================================" << endl;
                cout << "||       Logged in as: " << loginuser->username << endl;
                cout << "===================================" << endl;
                cout << "====================================" << endl;
                cout << "||       Menu Toko Badminton      ||" << endl;
                cout << "===================================" << endl;
                cout << "|| 1. Tambah Data lapangan        ||" << endl;
                cout << "|| 2. Lihat Data lapangan         ||" << endl;
                cout << "|| 3. Update Data lapangan        ||" << endl;
                cout << "|| 4. Hapus Data lapangan         ||" << endl;
                cout << "|| 9. Lihat Daftar Pengguna       ||" << endl;
                cout << "|| 0. Logout                      ||" << endl;
                cout << "====================================" << endl;
            } else
            {
                cout << "====================================" << endl;
                cout << "||       Logged in as: " << loginuser->username << endl;
                cout << "===================================" << endl;
                cout << "====================================" << endl;
                cout << "||       Menu Toko Badminton      ||" << endl;
                cout << "===================================" << endl;
                cout << "|| 1. (ini user biasa)            ||" << endl;
                cout << "|| 0. Logout                      ||" << endl;
                cout << "====================================" << endl;
            }
        }
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        if (pilihan == 1 && loginuser == nullptr) {
            adduser(head_user, tail_user);
        } else if (pilihan == 9 && isAdminLoggedIn) {
            view_alluser(head_user);
        } else if (pilihan == 1 && isAdminLoggedIn)
        {
            /* tambah lapangan */
            int pilih1;
            while (true) {
                cout << "====================================" << endl;
                cout << "||       Menu Tambah Data         ||" << endl;
                cout << "===================================" << endl;
                cout << "|| 1. Tambah Data di Awal         ||" << endl;
                cout << "|| 2. Tambah Data di Akhir        ||" << endl;
                cout << "|| 3. Tambah Data di Antara       ||" << endl;
                cout << "====================================" << endl;
                cout << "Pilih : ";
                cin >> pilih1;
                if (pilih1 == 1) {
                    tambahDiawal(&head_lapangan, &tail_lapangan);
                    break;
                }
                else if (pilih1 == 2) {
                    tambahDiakhir(&head_lapangan, &tail_lapangan);
                    break;
                }
                else if (pilih1 == 3) {
                    displayHead(head_lapangan, tail_lapangan);
                    cout << "Mau tambah di nama no brp : ";
                    cin >> idx;
                    tambahDiantara(&head_lapangan, &tail_lapangan, idx - 1);
                    break;
                }
                else {
                    cout << "Pilihan tidak valid." << endl;
                }
            }
        } else if (pilihan == 2 && isAdminLoggedIn)
        {
            /* lihat semua lapangan */
            int pilihdisplay;
            cout << "=================================" << endl;
            cout << "||       Menu Display          ||" << endl;
            cout << "=================================" << endl;
            cout << "||     1. Display Head         ||" << endl;
            cout << "||     2. Display Tail         ||" << endl;
            cout << "=================================" << endl;
            cout << "Pilih : ";
            cin >> pilihdisplay;
            if (pilihdisplay == 1) {
                displayHead(head_lapangan, tail_lapangan);
            }
            else if (pilihdisplay == 2) {
                displayTail(head_lapangan, tail_lapangan);
            }
        } else if (pilihan == 3 && isAdminLoggedIn)
        {
            /* update lapangan */
            displayHead(head_lapangan, tail_lapangan);
            cout << "Update Data lapangan Ke: ";
            cin >> idx;
            update(head_lapangan, idx);
        } else if (pilihan == 4 && isAdminLoggedIn)
        {
            /* code */
            int pilih2;
            displayHead(head_lapangan, tail_lapangan);
            while (true) {
                cout << "====================================" << endl;
                cout << "||       Menu Tambah Data         ||" << endl;
                cout << "===================================" << endl;
                cout << "|| 1. Hapus Data di Awal          ||" << endl;
                cout << "|| 2. Hapus Data di Akhir         ||" << endl;
                cout << "|| 3. Hapus Data di Antara        ||" << endl;
                cout << "====================================" << endl;
                cout << "Pilih : ";
                cin >> pilih2;
                if (pilih2 == 1) {
                    hapusDiawal(&head_lapangan, &tail_lapangan);
                    break;
                }
                else if (pilih2 == 2) {
                    hapusDiakhir(&head_lapangan, &tail_lapangan);
                    break;
                }
                else if (pilih2 == 3) {
                    displayHead(head_lapangan, tail_lapangan);
                    cout << "Mau hapus di nama no brp : ";
                    cin >> idx;
                    hapusDiantara(&head_lapangan, &tail_lapangan, idx - 1);
                    break;
                }
                else {
                    cout << "Pilihan tidak valid." << endl;
                }
            }
        } else if (pilihan == 2 && loginuser == nullptr) {
            // Login
            string username, password;
            cout << "Masukkan username: ";
            cin >> username;
            cout << "Masukkan password: ";
            cin >> password;
            loginuser = isUserValid(head_user, username, password);
            if (loginuser != nullptr) {
                cout << "Selamat datang, " << loginuser->username << "!" << endl;
                username.clear();
                password.clear();
                if (loginuser->username == "admin") {
                    cout << "Anda login sebagai admin." << endl;
                    isAdminLoggedIn = true;
                } else {
                    cout << "Anda login sebagai pengguna biasa." << endl;
                }
            } else {
                cout << "Username atau password tidak valid." << endl;
            }
        } else if (pilihan == 0 && loginuser != nullptr){
            cout << "Log Out" << endl;
            loginuser = nullptr;
            isAdminLoggedIn = false;
        } else if (pilihan == 0 && loginuser == nullptr) {
            cout << "Keluar" << endl;
            writeUserToCSV(head_user);
            simpanKeCSV(head_lapangan);
            break;
        } else {
            cout << "Pilihan tidak valid" << endl;
        }
    }
    return 0;
}


// int main() {
//     lapangan* head = NULL;
//     lapangan* tail = NULL;
  
//     bacaDariCSV(head, tail);
//     int idx;
//     int pilih, pilihdisplay;
//     while (true) {
//         cout << "====================================" << endl;
//         cout << "||       Menu Toko Badminton      ||" << endl;
//         cout << "===================================" << endl;
//         cout << "|| 1. Tambah Data lapangan        ||" << endl;
//         cout << "|| 2. Lihat Data lapangan         ||" << endl;
//         cout << "|| 3. Update Data lapangan        ||" << endl;
//         cout << "|| 4. Hapus Data lapangan         ||" << endl;
//         cout << "|| 5. Exit                        ||" << endl;
//         cout << "====================================" << endl;
//         cout << "Pilih : ";
//         cin >> pilih;
//         cin.ignore();

//         if (pilih == 1) {
//             int pilih1;
//             while (true) {
//                 cout << "====================================" << endl;
//                 cout << "||       Menu Tambah Data         ||" << endl;
//                 cout << "===================================" << endl;
//                 cout << "|| 1. Tambah Data di Awal         ||" << endl;
//                 cout << "|| 2. Tambah Data di Akhir        ||" << endl;
//                 cout << "|| 3. Tambah Data di Antara       ||" << endl;
//                 cout << "====================================" << endl;
//                 cout << "Pilih : ";
//                 cin >> pilih1;
//                 if (pilih1 == 1) {
//                     tambahDiawal(&head, &tail);
//                     break;
//                 }
//                 else if (pilih1 == 2) {
//                     tambahDiakhir(&head, &tail);
//                     break;
//                 }
//                 else if (pilih1 == 3) {
//                     displayHead(head, tail);
//                     cout << "Mau tambah di nama no brp : ";
//                     cin >> idx;
//                     tambahDiantara(&head, &tail, idx - 1);
//                     break;
//                 }
//                 else {
//                     cout << "Pilihan tidak valid." << endl;
//                 }
//             }
//         }
//         else if (pilih == 2) {
//             cout << "=================================" << endl;
//             cout << "||       Menu Display          ||" << endl;
//             cout << "=================================" << endl;
//             cout << "||     1. Display Head         ||" << endl;
//             cout << "||     2. Display Tail         ||" << endl;
//             cout << "=================================" << endl;
//             cout << "Pilih : ";
//             cin >> pilihdisplay;
//             if (pilihdisplay == 1) {
//                 displayHead(head, tail);
//             }
//             else if (pilihdisplay == 2) {
//                 displayTail(head, tail);
//             }
//         }
//         else if (pilih == 3) {
//             displayHead(head, tail);
//             cout << "Update Data lapangan Ke: ";
//             cin >> idx;
//             update(head, idx);
//         }
//         else if (pilih == 4) {
//             int pilih2;
//             displayHead(head, tail);
//             while (true) {
//                 cout << "====================================" << endl;
//                 cout << "||       Menu Tambah Data         ||" << endl;
//                 cout << "===================================" << endl;
//                 cout << "|| 1. Hapus Data di Awal          ||" << endl;
//                 cout << "|| 2. Hapus Data di Akhir         ||" << endl;
//                 cout << "|| 3. Hapus Data di Antara        ||" << endl;
//                 cout << "====================================" << endl;
//                 cout << "Pilih : ";
//                 cin >> pilih2;
//                 if (pilih2 == 1) {
//                     hapusDiawal(&head, &tail);
//                     break;
//                 }
//                 else if (pilih2 == 2) {
//                     hapusDiakhir(&head, &tail);
//                     break;
//                 }
//                 else if (pilih2 == 3) {
//                     displayHead(head, tail);
//                     cout << "Mau hapus di nama no brp : ";
//                     cin >> idx;
//                     hapusDiantara(&head, &tail, idx - 1);
//                     break;
//                 }
//                 else {
//                     cout << "Pilihan tidak valid." << endl;
//                 }
//             }
//         }
//         else if (pilih == 5) {
//             simpanKeCSV(head); // Simpan data ke CSV
//             exit(0);
//         }
//         else {
//             cout << "Menu tidak valid." << endl;
//         }
//     }

//     return 0;
// }
