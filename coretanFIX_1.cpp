#include <bits/stdc++.h> //
#include <cstring> //Header ini berfungsi untuk operasi string dan array of characters.
#include <ctime> //Header ini berfungsi untuk bekerja dengan waktu dan tanggal,
#include <fstream> //Header ini menyediakan kelas-kelas untuk operasi berkas (file), seperti ofstream dan ifstream.
#include <iostream> //Header ini berisi definisi dari objek input-output seperti (cin dan cout).
#include <sstream> // Header ini berfungsi untuk mengkonversi antara string dengan tipe data lainnya
// #include <string>

using namespace std; // agar tidak perlu menuliskan std:: setiap cout

// Struct adalah struktur data yang menggabungkan beberapa tipe data yang berbeda dalam satu unit.

// Struct ini digunakan untuk menyimpan data lapangan oleh admin

// kita memiliki 4 struct yaitu struct lapangan, user, LoginInfo, Pesanan

struct lapangan
{
  int no_lapangan;
  string jenis_lapangan;
  int harga;
  string fasilitas_lapangan;
  string hari[7] = {"Senin", "Selasa", "Rabu", "Kamis",
                    "Jumat", "Sabtu", "Minggu"};
  lapangan *next = nullptr;
  lapangan *prev = nullptr;
};

// Struct ini digunakan untuk menyimpan username, password, dan nomor hp
struct user
{
  string username;
  string password;
  string nomor_hp;
  user *next = nullptr;
  user *prev = nullptr;
};

// Struct ini digunakan untuk melihat history login
struct LoginInfo
{
  string username;
  string timestamp;
  LoginInfo *next;
  LoginInfo *prev;
};

//Struct ini digunakan untuk membuat pesanan.
struct pesanan
{
  string username;
  string nomor_hp;
  int no_lapangan;
  string hari;
  pesanan *next = nullptr;
  pesanan *prev = nullptr;
};

// Fungsi untuk mengecek apakah linked list kosong
template <typename P>
bool isempty(P *head, P *tail)
{
  return (head == nullptr && tail == nullptr);
}

// eror paksa agar inputan harus integer
bool ver_int(string input)
{
  for (char c : input)
  {
    if (!isdigit(c))
    {
      return true; // Mengandung karakter bukan integer
    }
  }
  return false; // Semua karakter adalah integer
}



// error handling untuk menginput no lapangan agar  khusus integer 
int noLap() {
  string reinput;
  cout << "Masukkan No Lapangan : ";
  getline(cin, reinput);
  while (true)
  {
    bool par = ver_int(reinput); // verifikasi inputan agar 
    if (par)
    {
      cout << "Masukkan No Lapangan Input Integer : ";
      getline(cin, reinput);
    }
    else
    {
      
      int number;
      stringstream ss(reinput); //untuk koversi ke tipe data lain
      if (ss >> number) //variabel ss menjadi int
      {
        return number;
      }
      else
      {
        
        cout << "Tidak Boleh Kosong ! : ";
        fflush(stdin);  //membersihkan buffer input
        getline(cin, reinput);
      }
    }
  }
}


// error handling untuk menginput harga agar khusus integer 
int hargaint() {
  string reinput;
  cout << "Masukkan Harga: ";
  getline(cin, reinput);
  while (true)
  {
    bool par = ver_int(reinput);
    if (par)
    {
      
      cout << "Hanya bisa Masukkan Bilangan Bulat : ";
      getline(cin, reinput);
    }
    else
    {
      
      int number;
      stringstream ss(reinput);
      if (ss >> number)
      {
        return number;
      }
      else
      {
        
        cout << "Tidak Boleh Kosong ! : ";
        fflush(stdin);
        getline(cin, reinput);
      }
    }
  }
}
//error handling untuk inputan string ke integer  khusus integer 
int paksaint()
{
  string reinput;
  cout << "Pilih Menu : ";
  getline(cin, reinput);
  while (true)
  {
    bool par = ver_int(reinput);
    if (par)
    {
      
      cout << "Hanya bisa Masukkan angka : ";
      getline(cin, reinput);
    }
    else
    {
      
      int number;
      stringstream ss(reinput);
      if (ss >> number)
      {
        return number;
      }
      else
      {
        
        cout << "Tidak Boleh Kosong ! : ";
        fflush(stdin);
        getline(cin, reinput);
      }
    }
  }
}

//error handling untuk inputan string ke integer  khusus integer 
int cosint(string perintah)
{
  string reinput;
  cout << perintah ;
  getline(cin, reinput);
  while (true)
  {
    bool par = ver_int(reinput);
    if (par)
    {
      
      cout << "Hanya bisa Masukkan angka : ";
      getline(cin, reinput);
    }
    else
    {
      
      int number;
      stringstream ss(reinput);
      if (ss >> number)
      {
        return number;
      }
      else
      {
        
        cout << "Tidak Boleh Kosong ! : ";
        fflush(stdin);
        getline(cin, reinput);
      }
    }
  }
}

bool ver_space(string str)// verifikasi karakter jika haya spasi
{
  for (char c : str)
  {
    if (!isspace(c))
    {
      return false; // Jika ada karakter selain spasi, maka bukan hanya spasi
    }
  }
  return true; // Jika semua karakter adalah spasi
}


// eror paksa input harus string dan tidak boleh kosong
string str_nokosong(string perintah)
{
  string user_input;
  do
  {
    cout << perintah;
    getline(cin, user_input);
    if (user_input.empty() || ver_space(user_input))
    {
      cout << "Input tidak boleh kosong atau hanya spasi. Silakan coba lagi." << endl;
    }
    else
    {
      return user_input;
    }
  } while (user_input.empty() || ver_space(user_input));
}


// Fungsi untuk mencari apakah username sudah digunakan
user *cariUser(string username, user *head_user)
{
  user *current = head_user;
  while (current != nullptr)
  {
    if (current->username == username)
    {
      return current;
    }
    current = current->next;
  }
  return nullptr;
}

// Fungsi untuk menmabah data riwayat login ke dalam csv file
void tambahLoginToCSV(const string &username, const string &timestamp)
{
  ofstream csvFile("login_history.csv", ios::app);
  if (csvFile.is_open())
  {
    csvFile << username << "," << timestamp << endl;
    csvFile.close();
  }
  else
  {
    cout << "Gagal membuka file CSV." << endl;
  }
}

// Fungsi untuk membaca data riwayat login dari csv file
void bacaLoginHistoryFromCSV(LoginInfo *&head, LoginInfo *&tail)
{
  ifstream csvFile("login_history.csv");
  if (csvFile.is_open())
  {
    string line;
    while (getline(csvFile, line))
    {
      size_t commaPos = line.find(",");
      if (commaPos != string::npos)
      {
        string username = line.substr(0, commaPos);
        string timestamp = line.substr(commaPos + 1);
        LoginInfo *newLogin = new LoginInfo;
        newLogin->username = username;
        newLogin->timestamp = timestamp;
        newLogin->next = nullptr;

        if (head == nullptr)
        {
          head = newLogin;
          tail = newLogin;
          newLogin->prev = nullptr;
        }
        else
        {
          tail->next = newLogin;
          newLogin->prev = tail;
          tail = newLogin;
        }
      }
    }
    csvFile.close();
  }
  else
  {
    cout << "Gagal membuka file CSV." << endl;
  }
}

// Fungsi untuk memeriksa apakah pengguna (user) valid (disini verif loginnya)
user *isUserValid(user *head_user, string username, string password,
                  const string &now)
{
  user *user = cariUser(username, head_user);
  if (user != nullptr && user->password == password)
  {
    tambahLoginToCSV(username, now);// ini untuk mencatat riwayaat login history agar masuk csv
    return user;
  }
  return nullptr;
}

// fungsi2 crud
//  Fungsi untuk membuat user baru
user *Newuser(user *head_user)
{
  user *newuser = new user;
  cout << "Masukkan username: ";
  newuser->username = str_nokosong("Masukkan username : ");
  fflush(stdin);
  if (!cariUser(newuser->username, head_user))
  {
    cout << "Masukkan password: ";
    newuser->password = str_nokosong("Masukkan password : ");
    fflush(stdin);
    cout << "Masukkan nomor hp: ";
    getline(cin, newuser->nomor_hp);
    newuser->next = nullptr;
    newuser->prev = nullptr;
    return newuser;
  }
  else
  {
    cout << "Username sudah digunakan" << endl;
    delete newuser; // Hapus pointer jika username sudah digunakan
    return nullptr;
  }
}

// Fungsi Untuk Registrasi(User)
void tambahUser(user *&head_user, user *&tail_user)
{
  user *newuser = Newuser(head_user);
  if (newuser)
  { // Periksa jika pointer user tidak nullptr
    if (isempty(head_user, tail_user))
    {
      head_user = newuser;
      tail_user = newuser;
    }
    else
    {
      tail_user->next = newuser;
      newuser->prev = tail_user;
      tail_user = newuser;
      cout << "Registrasi Berhasil" <<endl;
      cout << "Silahkan Login Untuk Memesan" <<endl;
    }
  }
}


// Fungsi untuk memeriksa apakah nomor lapangan sudah ada atau belum
bool isNomorLapangan(lapangan *head, lapangan *tail, int no_lapangan)
{
  lapangan *current = head;
  while (current != nullptr)
  {
    if (current->no_lapangan == no_lapangan)
    {
      return true; // Nomor lapangan sudah ada
    }
    current = current->next;
  }
  return false; // Nomor lapangan belum ada
}

// Fungsi Nambah Data Lapangan (Admin)
lapangan *newlapangan(lapangan *head, lapangan *tail)
{
  lapangan *lapanganBaru = new lapangan;
  bool ver_nomorLapangan = true;

  do
  {
    lapanganBaru->no_lapangan = noLap();
    ver_nomorLapangan = isNomorLapangan(head, tail, lapanganBaru->no_lapangan);

    if (ver_nomorLapangan)
    {
      cout << "Nomor lapangan sudah ada. Masukkan nomor lapangan yang berbeda." << endl;
    }

  } while (ver_nomorLapangan);
  lapanganBaru->jenis_lapangan = str_nokosong("Masukkan jenis_lapangan :");
  fflush(stdin);

  lapanganBaru->fasilitas_lapangan = str_nokosong("Masukkan Fasilitas lapangan : ");
  fflush(stdin);
  lapanganBaru->harga = hargaint();
  fflush(stdin);
  return lapanganBaru;
}

// Add First
void tambahDiawal(lapangan **head, lapangan **tail)
{
  lapangan *lapanganBaru = newlapangan(*head, *tail);

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
    cout << "Tambah Data Berhasil" << endl;
  }
}

// Add Last
void tambahDiakhir(lapangan **head, lapangan **tail)
{
  if (isempty(*head, *tail))
  {
    tambahDiawal(head, tail);
  }
  else
  {
    lapangan *lapanganBaru = newlapangan(*head, *tail);

    (*tail)->next = lapanganBaru;
    lapanganBaru->prev = *tail;
    *tail = lapanganBaru;
    cout << "Tambah Data Berhasil" << endl;
  }
}

// Add Between
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
      lapangan *lapanganBaru = newlapangan(*head, *tail);

      lapanganBaru->prev = temp->prev;
      lapanganBaru->next = temp;
      temp->prev->next = lapanganBaru;
      temp->prev = lapanganBaru;
      cout << "Tambah Data Berhasil" << endl;
    }
  }
}


// Fungsi Edit Data Lapangan (Admin)
void update(lapangan *head, int posisi)
{
  if (!head)
  {
    cout << "Linked List kosong." << endl;
    return;
  }

  lapangan *current = head;
  int count = 1;// update berdasarkan pengurutan data
  while (current && count < posisi)
  {
    current = current->next;
    count++;
  }

  if (current)
  {
    cout << "Data Lama" << endl;
    cout << "No Lapangan       : " << current->no_lapangan << endl;
    cout << "Jenis Lapangan    : " << current->jenis_lapangan << endl;
    cout << "Fasilitas Lapangan: " << current->fasilitas_lapangan << endl;
    cout << "Harga Perhari     : " << current->harga << endl;
    cout << "==========================================" << endl;
    cout << "Masukkan Data Baru" << endl;
    cin >> current->no_lapangan;
    current->no_lapangan = noLap();
    fflush(stdin);
    // cout << "Masukkan Jenis Lapangan    : ";
    // cin.ignore();
    // getline(cin, current->jenis_lapangan);
    current->jenis_lapangan = str_nokosong("Masukkan Jenis Lapangan  : ");
    //cout << "Masukkan Fasilitas Lapangan: ";
    current->fasilitas_lapangan = str_nokosong("Masukkan Fasilitas Lapangan : ");
    fflush(stdin);
    //getline(cin, current->fasilitas_lapangan);
    current->harga = hargaint();
    fflush(stdin);
    cout << "Data Berhasil Di Update" << endl;
  }
  else
  {
    cout << "Posisi tidak valid." << endl;
  }
}

// Fungsi Hapus Data Lapangan (Admin)

// Delete First
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
    cout << "Data Berhasil Di Hapus" << endl;
  }
}

// Delete Last
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
    cout << "Data Berhasil Di Hapus" << endl;
  }
}

// Delete Between
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
    cout << "Data Berhasil Di Hapus" << endl;
  }
}

// Fungsi Lihat Data Lapangan (Admin) BUKANNN YANG TERSEDIA ATO TIDAK TERSEDIA !!

// Display Head
void displayHead(lapangan *head, lapangan *tail)
{
  if (isempty(head, tail))
  {
    cout << "Lapangan Masih Kosong !!" << endl;
  }
  else
  {
    lapangan *temp = head;
    while (temp != nullptr)
    {
      cout << "=====================================================================================" << endl;
      cout << "|| No Lapangan        : " << temp->no_lapangan << endl;
      cout << "|| Jenis Lapangan     : " << temp->jenis_lapangan << endl;
      cout << "|| Fasilitas_Lapangan : " << temp->fasilitas_lapangan << endl;
      cout << "|| Harga Perhari      : " << temp->harga << endl;
      cout << "=====================================================================================" << endl;
      temp = temp->next;
    }
  }
}

// Display Tail
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
      cout << "=====================================================================================" << endl;
      cout << "|| No Lapangan        : " << temp->no_lapangan << endl;
      cout << "|| Jenis Lapangan     : " << temp->jenis_lapangan << endl;
      cout << "|| Fasilitas_Lapangan : " << temp->fasilitas_lapangan << endl;
      cout << "|| Harga Perhari      : " << temp->harga << endl;
      cout << "=====================================================================================" << endl;
      temp = temp->prev;
    }
  }
}







void viewLoginHistory(LoginInfo *head)
{
  LoginInfo *current = head;
  int count = 1;

  if (current == nullptr)
  {
    cout << "Tidak ada riwayat login." << endl;
    return;
  }

  // Buat deque (double-ended queue) untuk menyimpan riwayat login terbaru
  deque<LoginInfo> recentLogins;

  while (current != nullptr)
  {
    if (current->username != "admin")
    {
      // Tambahkan riwayat login ke deque
      recentLogins.push_back(*current);

      // Hanya tampilkan 10 riwayat login terbaru
      if (recentLogins.size() > 10)
      {
        recentLogins.pop_front();
      }
    }

    current = current->next;
  }

  // Tampilkan riwayat login terbaru dalam urutan terbalik
  cout << "Riwayat Login Pengunjung (10 terbaru):" << endl;

  for (auto it = recentLogins.rbegin(); it != recentLogins.rend(); ++it)
  {
    cout << "Pengunjung " << count << endl;
    cout << "Username : " << it->username << endl;
    cout << "Waktu Login : " << it->timestamp << endl;
    cout << "______________________" << endl;
    count++;
  }
}

// ===============================sorting================================================
int length(lapangan *head_lapangan)
{
  int panjang = 0;
  lapangan *temp = head_lapangan;
  while (temp != NULL)
  {
    temp = temp->next;
    panjang++;
  }
  return panjang;
}

void swaplapangans(lapangan **head_lapangan, lapangan *a, lapangan *b)
{
  if (a == b)
    return;

  // Cari lapangan sebelum a dan b
  lapangan *prevA = NULL, *prevB = NULL, *curr = *head_lapangan;
  while (curr)
  {
    if (curr->next == a)
      prevA = curr;
    if (curr->next == b)
      prevB = curr;
    curr = curr->next;
  }

  // Jika a adalah head_lapangan, update head_lapangan
  if (a == *head_lapangan)
    *head_lapangan = b;
  else if (b == *head_lapangan)
    *head_lapangan = a; // Jika b adalah head_lapangan, update head_lapangan

  // Update next untuk prevA dan prevB
  if (prevA)
    prevA->next = b;
  if (prevB)
    prevB->next = a;

  // Tukar next untuk a dan b
  lapangan *temp = a->next;
  a->next = b->next;
  b->next = temp;
}

lapangan *cariLapangan(lapangan *head_lapangan, int idx)
{
  lapangan *temp = head_lapangan;

  for (int i = 0; i < idx; i++)
  {
    temp = temp->next;
  }

  return temp;
}

// Sorting Nomor Lapamgan Secara Ascending
void shellSort(lapangan **head_lapangan, int n)
{
  for (int gap = n / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < n; i++)
    {
      lapangan *temp = cariLapangan(*head_lapangan, i);
      int j;
      for (j = i;
           j >= gap && cariLapangan(*head_lapangan, j - gap)->no_lapangan > temp->no_lapangan;
           j -= gap)
      {
        swaplapangans(head_lapangan, cariLapangan(*head_lapangan, j),
                      cariLapangan(*head_lapangan, j - gap));
      }
    }
  }
}

// Sorting Nomor Lapangan Secara Descending
void shellSort2(lapangan **head_lapangan, int n)
{
  for (int gap = n / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < n; i++)
    {
      lapangan *temp = cariLapangan(*head_lapangan, i);
      int j;
      for (j = i;
           j >= gap && cariLapangan(*head_lapangan, j - gap)->no_lapangan <
                           temp->no_lapangan;
           j -= gap)
      {
        swaplapangans(head_lapangan, cariLapangan(*head_lapangan, j),
                      cariLapangan(*head_lapangan, j - gap));
      }
    }
  }
}

// Sorting Harga Secara Ascending
void shellSort3(lapangan **head_lapangan, int n)
{
  for (int gap = n / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < n; i++)
    {
      lapangan *temp = cariLapangan(*head_lapangan, i);
      int j;
      for (j = i; j >= gap &&
                  cariLapangan(*head_lapangan, j - gap)->harga > temp->harga;
           j -= gap)
      {
        swaplapangans(head_lapangan, cariLapangan(*head_lapangan, j),
                      cariLapangan(*head_lapangan, j - gap));
      }
    }
  }
}

// Sorting Harga Secara Descending
void shellSort4(lapangan **head_lapangan, int n)
{
  for (int gap = n / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < n; i++)
    {
      lapangan *temp = cariLapangan(*head_lapangan, i);
      int j;
      for (j = i; j >= gap &&
                  cariLapangan(*head_lapangan, j - gap)->harga < temp->harga;
           j -= gap)
      {
        swaplapangans(head_lapangan, cariLapangan(*head_lapangan, j),
                      cariLapangan(*head_lapangan, j - gap));
      }
    }
  }
}

//============================ SEARCHING BOOYER =======================================================

const int NO_OF_CHARS = 256;
void badCharHeuristic(string str, int size, int badChar[NO_OF_CHARS])
{
  // Inisialisasi semua nilai di badChar sebagai -1
  for (int i = 0; i < NO_OF_CHARS; i++)
  {
    badChar[i] = -1;
  }
  for (int i = 0; i < size; i++)
  {
    badChar[(int)str[i]] = i;
  }
}

// Searching  Jenis Lapangan
void search_booyer(lapangan *head, string pat)
{
  int m = pat.size();
  int count;
  lapangan *temp = head;
  while (temp != NULL)
  {
    int n = temp->jenis_lapangan.size();
    int badChar[NO_OF_CHARS];
    badCharHeuristic(pat, m, badChar);
    int s = 0;
    while (s <= (n - m))
    {
      int j = m - 1;
      while (j >= 0 && pat[j] == temp->jenis_lapangan[s + j])
      {
        j--;
      }
      if (j < 0)
      {
        cout << "====================================================" << endl;
        cout << "|| No Lapangan        : " << temp->no_lapangan << endl;
        cout << "|| Jenis Lapangan     : " << temp->jenis_lapangan << endl;
        cout << "|| Fasilitas_Lapangan : " << temp->fasilitas_lapangan << endl;
        cout << "|| Harga Perhari      : " << temp->harga << endl;
        cout << "====================================================" << endl;
        count++;
        break;
      }
      else
      {
        s += max(1, j - badChar[temp->jenis_lapangan[s + j]]);
      }
    }
    temp = temp->next;
  }
  if (count == 0)
  {
    cout << "Data tidak ditemukan" << endl;
  }
}

// Searching Fasilitas Lapangan
void search_booyer1(lapangan *head, string pat)
{
  int m = pat.size();
  int count;
  lapangan *temp = head;
  while (temp != NULL)
  {
    int n = temp->fasilitas_lapangan.size();
    int badChar[NO_OF_CHARS];
    badCharHeuristic(pat, m, badChar);
    int s = 0;
    while (s <= (n - m))
    {
      int j = m - 1;
      while (j >= 0 && pat[j] == temp->fasilitas_lapangan[s + j])
      {
        j--;
      }
      if (j < 0)
      {
        cout << "====================================================" << endl;
        cout << "|| No Lapangan        : " << temp->no_lapangan << endl;
        cout << "|| Jenis Lapangan     : " << temp->jenis_lapangan << endl;
        cout << "|| Fasilitas_Lapangan : " << temp->fasilitas_lapangan << endl;
        cout << "|| Harga Perhari      : " << temp->harga << endl;
        cout << "====================================================" << endl;
        count++;
        break;
      }
      else
      {
        s += max(1, j - badChar[temp->fasilitas_lapangan[s + j]]);
      }
    }
    temp = temp->next;
  }
  if (count == 0)
  {
    cout << "Data tidak ditemukan" << endl;
  }
}

// ========================================= menulis dan baca csv
// ================================================= penulisan dan pembacaan ke
// csv Fungsi untuk menulis data pengguna ke dalam file CSV
void writeUserToCSV(user *newUser)
{
  ofstream file("users.csv"); // Membuka berkas untuk penulisan (ios::app untuk
                             // menambahkan data ke berkas yang ada)
  user *curr = newUser;
  if (file.is_open())
  {
    while (curr != nullptr)
    {
      file << curr->username << "," << curr->password << "," << curr->nomor_hp << endl;
      curr = curr->next;
    }
  }
  else
  {
    cout << "Gagal membuka berkas CSV" << endl;
  }
}

// Fungsi untuk membaca data pengguna dari file CSV
void readUsersFromCSV(user *&head_user, user *&tail_user)
{
  ifstream file("users.csv");// ini sebelumnya user.csv
  if (file.is_open())
  {
    string line;
    while (getline(file, line))
    {
      stringstream ss(line);
      string username, password, nomor_hp;
      if (getline(ss, username, ',') && getline(ss, password, ',') &&
          getline(ss, nomor_hp, ','))
      {
        user *newUser = new user;
        newUser->username = username;
        newUser->password = password;
        newUser->nomor_hp = nomor_hp;
        newUser->next = nullptr;
        newUser->prev = nullptr;

        if (isempty(head_user, tail_user))
        {
          head_user = newUser;
          tail_user = newUser;
        }
        else
        {
          tail_user->next = newUser;
          newUser->prev = tail_user;
          tail_user = newUser;
        }
      }
    }
    file.close();
  }
  else
  {
    cout << "Gagal membuka berkas CSV" << endl;
  }
}

// Fungsi Untuk Menyimpan Struct Lapanngan ke dalam CSV file
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
    file << current->harga << "\n";
    current = current->next;
  }
  file.close();
  cout << "Data telah disimpan ke dalam file data_lapangan.csv" << endl;
}

// Fungsi Untuk Membaca CSV File Untuk Data Lapangan
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
    string no_lapanganStr, jenis_lapangan, fasilitas_lapangan, hargaStr;
    if (!getline(ss, no_lapanganStr, ',') ||
        !getline(ss, jenis_lapangan, ',') ||
        !getline(ss, fasilitas_lapangan, ',') || !getline(ss, hargaStr, ','))
    {
      cerr << "Error reading line from CSV." << endl;
      break;
    }

    int harga = stoi(hargaStr);
    int no_lapangan = stoi(no_lapanganStr);
    lapangan *lpng = new lapangan;
    lpng->no_lapangan = no_lapangan;
    lpng->jenis_lapangan = jenis_lapangan;
    lpng->fasilitas_lapangan = fasilitas_lapangan;
    lpng->harga = harga;
    lpng->next = nullptr;
    lpng->prev = tail;

    if (head == nullptr)
    {
      head = lpng;
      lpng->prev = nullptr;
      tail = lpng;
    }
    else
    {
      tail->next = lpng;
      tail = lpng;
    }
  }

  file.close();
  cout << "Data telah dibaca dari file data_lapangan.csv" << endl;
}


// Fungsi Agar Memperbaiki data setelah disorting agar saat masuk ke menu display maka terururt sesuai yang diinginkn
void fixPrevious(lapangan **head, lapangan **tail)
{
  lapangan *temp = *head;
  lapangan *prev = NULL;
  while (temp != NULL)
  {
    temp->prev = prev;
    prev = temp;
    temp = temp->next;
  }
  *tail = prev;
}


//1. hari, 2. muncul list lapangan(yg tersedia), 3. pilih nomor lapangannya(baru di rubah harinya)
//lalu masuk ke pesanan

bool display_daylap(lapangan *head, lapangan *tail, int no){
  if (isempty(head, tail))
  {
    cout << "Lapangan Masih Kosong !!" << endl;
  }
  else
  {
    bool ver = true;
    lapangan *temp = head;
    while (temp != nullptr)
    {
        if (temp->hari[no] != " ")
        {
            
            cout << "====================================================" << endl;
            cout << "|| No Lapangan        : " << temp->no_lapangan << endl;
            cout << "|| Jenis Lapangan     : " << temp->jenis_lapangan << endl;
            cout << "|| Fasilitas_Lapangan : " << temp->fasilitas_lapangan << endl;
            cout << "|| Harga Perhari      : " << temp->harga << endl;
            cout << "====================================================" << endl;
            ver = false;
        }
        temp = temp->next;
    }
    if (ver)
    {
      
      cout <<"Lapangan sudah Tidak tersedia"<< endl;
      return false;
    }
    return true;
  }
}

bool pesan(lapangan *head, int no, int hari){
    if (!head)
    {
        cout << "Linked List kosong." << endl;
        return false;
    }
    lapangan *current = head;
    while (current->no_lapangan != no)
    {
      if (current->next == nullptr)
      {
        
        break;
      } else
      {
        
        current = current->next;
      }
    }
    if (current->no_lapangan == no && current->hari[hari] != " ")
    {
        
      return true;
    } else
    {
        cout << "gada lapangannya---" << endl;
        return false;
    }
}

pesanan *newpesanan(user *user, lapangan *head, int no_lap, int hari){
  pesanan *pesanabaru = new pesanan;
  lapangan *head_lapangan = head;
  while (true)
  {
    
    if (head_lapangan->no_lapangan == no_lap)
    {
      
      //head_lapangan = head_lapangan->next;
      pesanabaru->username = user->username;
      pesanabaru->nomor_hp = user->nomor_hp;
      pesanabaru->no_lapangan = no_lap;
      pesanabaru->hari = head_lapangan->hari[hari];
      head_lapangan->hari[hari] = " ";
      cout << "Lapangan berhasil di Pesan" << endl;
      return pesanabaru;
      break;
    }
    head_lapangan = head_lapangan->next;
  }
  
}

void addpesanan(pesanan *&head, pesanan *&tail, user *user, lapangan *head_lapangan, int no_lap, int hari)
{
  pesanan *pesananBaru = newpesanan(user, head_lapangan, no_lap, hari);
  if (isempty(head, tail))
  {
    head = pesananBaru;
    tail = pesananBaru;
  }
  else
  {
    pesananBaru->next = head;
    (head)->prev = pesananBaru;
    head = pesananBaru;
  }
}

//lihat semua pesanan
void display_pesanan(pesanan *head, pesanan *tail){
  {
  if (isempty(head, tail))
  {
    cout << "Pesanan Masih Kosong !!" << endl;
  }
  else
  {
    pesanan *temp = head;
    while (temp != nullptr)
    {
      cout << "====================================================" << endl;
      cout << "|| No Lapangan      : " << temp->no_lapangan << endl;
      cout << "|| Hari             : " << temp->hari << endl;
      cout << "|| Nama Penyewa     : " << temp->username << endl;
      cout << "|| Nomor HP Penyewa : " << temp->nomor_hp << endl;
      cout << "====================================================" << endl;
      temp = temp->next;
    }
  }
}
}

//baca csv pesanan
void bacaPesananDariCSV(pesanan *&head, pesanan *&tail, lapangan *head_lapangan)
{
  ifstream file("data_pesanan.csv");
  if (!file.is_open())
  {
    cout << "File data_pesanan.csv tidak ditemukan." << endl;
    return;
  }

  string line;
  while (getline(file, line))
  {
    stringstream ss(line);
    string username, nomor_hp, no_lapangan, hari;

    if (!getline(ss, username, ',') ||
        !getline(ss, nomor_hp, ',') ||
        !getline(ss, no_lapangan, ',')||
        !getline(ss, hari, ','))
    {
      cerr << "Error reading line from CSV." << endl;
      break;
    }
    int no_lap = stoi(no_lapangan);
    lapangan* temp_lapangan = head_lapangan;
    while (temp_lapangan != nullptr) {
        if (temp_lapangan->no_lapangan == no_lap) {
            break;
        }
        temp_lapangan = temp_lapangan->next;
    }
    
    pesanan *pesan = new pesanan;
    pesan->username = username;
    pesan->nomor_hp = nomor_hp;
    pesan->no_lapangan = no_lap;
    pesan->hari = hari;
    for (int i = 0; i < 7; i++)
    {
      
      //cout << "hall"<< i << endl;
      if (hari == temp_lapangan->hari[i])
      {
        
        temp_lapangan->hari[i] = " ";
      }
    }
    
    pesan->next = nullptr;
    pesan->prev = tail;

    if (head == nullptr)
    {
      head = pesan;
      pesan->prev = nullptr;
      tail = pesan;
    }
    else
    {
      tail->next = pesan;
      tail = pesan;
    }
  }

  file.close();
  cout << "Data pesanan telah dibaca dari file data_pesanan.csv" << endl;
}


void simpanPesananKeCSV(pesanan *head, pesanan *tail)
{
  ofstream file("data_pesanan.csv");
  if (!file.is_open())
  {
    cerr << "Gagal membuka file data_pesanan.csv" << endl;
    return;
  }

  pesanan *current = head;
  while (current)
  {
    file << current->username << ",";
    file << current->nomor_hp << ",";
    file << current->no_lapangan << ",";
    file << current->hari << "\n";
    current = current->next;
  }

  file.close();
  cout << "Data pesanan telah disimpan ke dalam file data_pesanan.csv" << endl;
}


// =============== hapus pesanan ============= // admin
// 1. pesanan -> display & ->hapus 2. pashapus pakai index
// Fungsi untuk menampilkan daftar pesanan
// void dishappe(pesanan* head, pesanan* tail) {
//     if (isempty(head, tail)) {
//         cout << "Lapangan Masih Kosong !!" << endl;
//     } else {
//         pesanan* temp = head;
//         int idx = 1;
//         while (temp != nullptr) {
//             cout << "====================================================" << endl;
//             cout << "|| No Pesanan       : " << idx << endl;
//             cout << "|| No Lapangan      : " << temp->no_lapangan << endl;
//             cout << "|| Hari             : " << temp->hari << endl;
//             cout << "|| Nama Penyewa     : " << temp->username << endl;
//             cout << "|| Nomor HP Penyewa : " << temp->nomor_hp << endl;
//             cout << "====================================================" << endl;
//             idx += 1;
//             temp = temp->next;
//         }
//     }
// }

// // Fungsi untuk menghapus pesanan
// void deletePesanan(pesanan*& head_pesanan, pesanan*& tail_pesanan, lapangan*&head_lapangan) {
//     // Menampilkan daftar pesanan
//     dishappe(head_pesanan, tail_pesanan);

//     int no_pesanan;
//     cout << "Masukkan nomor pesanan yang ingin dihapus: ";
//     no_pesanan = paksaint();
//     fflush(stdin);

//     // Menemukan pesanan berdasarkan nomor pesanan yang dimasukkan
//     lapangan* lap = head_lapangan;
//     pesanan* current = head_pesanan;
//     for (int i = 1; i < no_pesanan && current != nullptr; i++) {
//         current = current->next;
//     }
//     while (lap->no_lapangan != current->no_lapangan)
//     {
//       
//       lap = lap->next;
//     }
//     for (int i = 0; i < 7; i++)
//     {
//       
//       if (lap->hari[i] == " ")
//       {
//         
//         lap->hari[i] = current->hari;
//       }
//     }

bool dishappe(pesanan* head, pesanan* tail) {
    if (isempty(head, tail)) {
        cout << "Lapangan Masih Kosong !!" << endl;
        return false;
    } else {
        pesanan* temp = head;
        int idx = 1;
        while (temp != nullptr) {
            cout << "====================================================" << endl;
            cout << "|| No Pesanan       : " << idx << endl;
            cout << "|| No Lapangan      : " << temp->no_lapangan << endl;
            cout << "|| Hari             : " << temp->hari << endl;
            cout << "|| Nama Penyewa     : " << temp->username << endl;
            cout << "|| Nomor HP Penyewa : " << temp->nomor_hp << endl;
            cout << "====================================================" << endl;
            idx += 1;
            temp = temp->next;
        }
        return true;
    }
}

// Fungsi untuk menghapus pesanan
void deletePesanan(pesanan*& head_pesanan, pesanan*& tail_pesanan, lapangan*& head_lapangan) {
    // Menampilkan daftar pesanan
    bool var;
    var = dishappe(head_pesanan, tail_pesanan);
    pesanan* current = head_pesanan;
    if(var){
      int no_pesanan;
      cout << "Masukkan nomor pesanan yang ingin dihapus: ";
      cin >> no_pesanan ;
      fflush(stdin);

      // Menemukan pesanan berdasarkan nomor pesanan yang dimasukkan
      for (int i = 1; i < no_pesanan && current != nullptr; i++) {
          current = current->next;
      }

    } 
      // Jika pesanan ditemukan, lakukan penghapusan
      if (current != nullptr) {
          lapangan* lap = head_lapangan;
          while (lap->no_lapangan != current->no_lapangan)
          {
            lap = lap->next;
          }
          for (int i = 0; i < 7; i++)
          {
            if (lap->hari[i] == " ")
            {
              lap->hari[i] = current->hari;
            }
          }

          if (current->prev != nullptr) {
              current->prev->next = current->next;
          }
          if (current->next != nullptr) {
              current->next->prev = current->prev;
          }
          if (current == head_pesanan) {
              head_pesanan = current->next;
          }
          if (current == tail_pesanan) {
              tail_pesanan = current->prev;
          }

          delete current;
          cout << "Pesanan berhasil dihapus." << endl;

    }
    else {
        cout << "Nomor pesanan tidak ditemukan atau tidak valid." <<endl;
  }
}



//display khusus user
void dispesus(pesanan *head, pesanan *tail, user *user){
  bool ver = true;
  if (isempty(head, tail))
  {
    cout << "Pesanan Masih Kosong !!" << endl;
  }
  else
  {
    pesanan *temp = head;
    while (temp != nullptr)
    {
      if (user->username == temp->username)
      {
        
        cout << "====================================================" << endl;
        cout << "|| No Lapangan      : " << temp->no_lapangan << endl;
        cout << "|| Hari             : " << temp->hari << endl;
        cout << "|| Nama Penyewa     : " << temp->username << endl;
        cout << "|| Nomor HP Penyewa : " << temp->nomor_hp << endl;
        cout << "====================================================" << endl;
        ver = false;
      }
      temp = temp->next;
    }
  }
  if (ver)
  {
    
    cout << "Pesanan Masih Kosong !!" << endl;
  }
}













int main()
{

  // Variabel yang digunakan
  time_t now;
  time(&now);
  user *head_user = nullptr;
  user *tail_user = nullptr; //
  lapangan *head_lapangan = nullptr;
  lapangan *tail_lapangan = nullptr;
  LoginInfo *head = nullptr;
  LoginInfo *tail = nullptr;
  pesanan* head_pesanan = nullptr;
  pesanan* tail_pesanan = nullptr;
  readUsersFromCSV(head_user, tail_user);
  bacaDariCSV(head_lapangan, tail_lapangan);
  bacaLoginHistoryFromCSV(head, tail);
  bacaPesananDariCSV(head_pesanan, tail_pesanan, head_lapangan);
  bool isAdminLoggedIn = false; // Menandai apakah admin telah login
  user *loginuser = nullptr;    // Menyimpan username pengguna yang sedang login
                                // (kalau ga di kasih nullptr keren :))

  while (true)
  {
    int pilihan; // Inisialisasi pilihan
    int idx;
    if (loginuser == nullptr)
    {
      // system("cls");
      cout << "====================================" << endl;
      cout << "||  Penyewaan Lapangan Badminton  ||" << endl;
      cout << "====================================" << endl;
      cout << "|| 1. Registrasi                  ||" << endl;
      cout << "|| 2. Login                       ||" << endl;
      cout << "|| 0. Exit                        ||" << endl;
      cout << "====================================" << endl;
    }
    else
    {
      if (isAdminLoggedIn)
      {
        cout << "====================================" << endl;
        cout << "||       Logged in as: " << loginuser->username << endl;
        cout << "====================================" << endl;
        cout << "====================================" << endl;
        cout << "||  Penyewaan Lapangan Badminton  ||" << endl;
        cout << "====================================" << endl;
        cout << "|| 1. Tambah Data lapangan        ||" << endl;
        cout << "|| 2. Lihat Data lapangan         ||" << endl;
        cout << "|| 3. Update Data lapangan        ||" << endl;
        cout << "|| 4. Hapus Data lapangan         ||" << endl;
        cout << "|| 5. Searching                   ||" << endl;
        cout << "|| 6. Sorting Data                ||" << endl;
        cout << "|| 7. Lihat Daftar Pengunjung     ||" << endl;
        cout << "|| 8. Pesanan                     ||" << endl;
        cout << "|| 0. Logout                      ||" << endl;
        cout << "====================================" << endl;
      }
      else
      {
        cout << "====================================" << endl;
        cout << "||       Logged in as: " << loginuser->username << endl;
        cout << "====================================" << endl;
        cout << "====================================" << endl;
        cout << "||  Penyewaan Lapangan Badminton  ||" << endl;
        cout << "====================================" << endl;
        cout << "|| 1. Booking Lapangan            ||" << endl;
        cout << "|| 2. Display Lapangan            ||" << endl;
        cout << "|| 3. Searching Data              ||" << endl;
        cout << "|| 4. Display Pesanan             ||" << endl;
        cout << "|| 0. Logout                      ||" << endl;
        cout << "====================================" << endl;
      }
    }
    // system("color 2");
    pilihan = paksaint();
    fflush(stdin);

    if (pilihan == 1 && loginuser == nullptr)
    {
      tambahUser(head_user, tail_user);
    }
    else if (pilihan == 1 && isAdminLoggedIn)
    {
      /* tambah lapangan */
      int pilih1;
      while (true)
      {
        cout << "====================================" << endl;
        cout << "||       Menu Tambah Data         ||" << endl;
        cout << "====================================" << endl;
        cout << "|| 1. Tambah Data di Awal         ||" << endl;
        cout << "|| 2. Tambah Data di Akhir        ||" << endl;
        cout << "|| 3. Tambah Data di Antara       ||" << endl;
        cout << "====================================" << endl;
        pilih1 = paksaint();
        fflush(stdin);
        if (pilih1 == 1)
        {
          tambahDiawal(&head_lapangan, &tail_lapangan);
          break;
        }
        else if (pilih1 == 2)
        {
          tambahDiakhir(&head_lapangan, &tail_lapangan);
          break;
        }
        else if (pilih1 == 3)
        {
          displayHead(head_lapangan, tail_lapangan);
          idx = cosint("Mau Tambah Di Index Berapa : ");
          fflush(stdin);
          tambahDiantara(&head_lapangan, &tail_lapangan, idx - 1);
          break;
        }
        else
        {
          cout << "Pilihan tidak valid." << endl;
        }
      }
    }
    else if (pilihan == 2 && isAdminLoggedIn)
    {
      /* lihat semua lapangan */
      int pilihdisplay;
      cout << "=================================" << endl;
      cout << "||       Menu Display          ||" << endl;
      cout << "=================================" << endl;
      cout << "||     1. Display Head         ||" << endl;
      cout << "||     2. Display Tail         ||" << endl;
      cout << "=================================" << endl;
      pilihdisplay = paksaint();
      if (pilihdisplay == 1)
      {
        displayHead(head_lapangan, tail_lapangan);
      }
      else if (pilihdisplay == 2)
      {
        displayTail(head_lapangan, tail_lapangan);
      }
      else
      {
        cout << "Pilihan tidak valid" << endl;
      }
    }
    else if (pilihan == 3 && isAdminLoggedIn)
    {
      /* update lapangan */
      displayHead(head_lapangan, tail_lapangan);
      cout << "Update Data lapangan Ke: ";
      cin >> idx;
      fflush(stdin);
      update(head_lapangan, idx);
    }
    else if (pilihan == 4 && isAdminLoggedIn)
    {
      /* hapus */
      int pilihapus;
      displayHead(head_lapangan, tail_lapangan);
      while (true)
      {
        cout << "====================================" << endl;
        cout << "||       Menu Tambah Data         ||" << endl;
        cout << "====================================" << endl;
        cout << "|| 1. Hapus Data Di Awal          ||" << endl;
        cout << "|| 2. Hapus Data Di Akhir         ||" << endl;
        cout << "|| 3. Hapus Data Di Antara        ||" << endl;
        cout << "====================================" << endl;
        pilihapus = paksaint();
        if (pilihapus == 1)
        {
          hapusDiawal(&head_lapangan, &tail_lapangan);
          break;
        }
        else if (pilihapus == 2)
        {
          hapusDiakhir(&head_lapangan, &tail_lapangan);
          break;
        }
        else if (pilihapus == 3)
        {
          displayHead(head_lapangan, tail_lapangan);
          cout << "Mau hapus di nama no brp : ";
          cin >> idx;
          fflush(stdin);
          hapusDiantara(&head_lapangan, &tail_lapangan, idx - 1);
          break;
        }
        else
        {
          cout << "Pilihan tidak valid." << endl;
        }
      }
    }
    else if (pilihan == 5 && isAdminLoggedIn)
    {
      /* For admin */
      int pilihseacrh;
      while (true)
      {

        cout << "===================================" << endl;
        cout << "||         Menu Searching        ||" << endl;
        cout << "===================================" << endl;
        cout << "|| 1. Search Jenis Lap.          ||" << endl;
        cout << "|| 2. Search Fasilitas Lap.      ||" << endl;
        cout << "===================================" << endl;
        pilihseacrh = paksaint();
        fflush(stdin);
        cout << "____________" << endl;
        if (pilihseacrh == 1)
        {
          string search;
          shellSort2(&head_lapangan, length(head_lapangan));
          cout << "Masukkan Jenis Lapangan :";
          cin >> search;
          fflush(stdin);
          cout << "____________" << endl;
          search_booyer(head_lapangan, search);
          break;
        }
        else if (pilihseacrh == 2)
        {
          string search;
          shellSort2(&head_lapangan, length(head_lapangan));
          cout << "Fasilitas Yang Dicari :";
          cin >> search; 
          fflush(stdin);
          cout << "____________" << endl;
          search_booyer(head_lapangan, search);
          break;
        }
        else
        {
          cout << "Pilihan tidak valid." << endl;
        }
      }
    }
    else if (pilihan == 6 && loginuser != nullptr)
    {
      int pilih2;
      while (true)
      {
        cout << "=================================" << endl;
        cout << "||        MENU SORT            ||" << endl;
        cout << "=================================" << endl;
        cout << "|| 1.        ASC               ||" << endl;
        cout << "|| 2.        DESC              ||" << endl;
        cout << "=================================" << endl;
        pilih2 = paksaint();
        if (pilih2 == 1)
        {
          int pilih1;
          while (true)
          {
            cout << "====================================" << endl;
            cout << "||          MENU SORT             ||" << endl;
            cout << "====================================" << endl;
            cout << "|| 1.     Sorting By No Lapangan  ||" << endl;
            cout << "|| 2.     Sorting By Harga        ||" << endl;
            cout << "====================================" << endl;
            pilih1 = paksaint();
            if (pilih1 == 1)
            {
              shellSort(&head_lapangan, length(head_lapangan));
              fixPrevious(&head_lapangan, &tail_lapangan);
              break;
            }
            else if (pilih1 == 2)
            {
              shellSort3(&head_lapangan, length(head_lapangan));
              fixPrevious(&head_lapangan, &tail_lapangan);
              break;
            }
            else
            {
              cout << "Pilihan tidak valid" << endl;
            }
          }
        }
        else if (pilih2 == 2)
        {
          int pilih1;
          while (true)
          {
            cout << "====================================" << endl;
            cout << "||          MENU SORT             ||" << endl;
            cout << "====================================" << endl;
            cout << "|| 1.     Sorting By No Lapangan  ||" << endl;
            cout << "|| 2.     Sorting By Harga        ||" << endl;
            cout << "====================================" << endl;
            pilih1 = paksaint();
            if (pilih1 == 1)
            {
              shellSort2(&head_lapangan, length(head_lapangan));
              fixPrevious(&head_lapangan, &tail_lapangan);
              break;
            }
            else if (pilih1 == 2)
            {
              shellSort4(&head_lapangan, length(head_lapangan));
              fixPrevious(&head_lapangan, &tail_lapangan);
              break;
            }
            else
            {
              cout << "Pilihan tidak valid" << endl;
            }
          }
        }
        break; // Perlu ada break di sini agar kembali ke menu utama
      }
    }
    else if (pilihan == 7 && isAdminLoggedIn)
    {
      viewLoginHistory(head);
    }
    else if (pilihan == 8 && isAdminLoggedIn)
    {
      cout << "====================================" << endl;
      cout << "||          MENU PESANAN          ||" << endl;
      cout << "====================================" << endl;
      cout << "|| 1.     Display Pesanan         ||" << endl;
      cout << "|| 2.     Hapus Pesanan           ||" << endl;
      cout << "====================================" << endl;
      pilihan = paksaint();
      if (pilihan == 1)
      {
        
        cout << "Lihat semua pesanan" << endl;
        display_pesanan(head_pesanan,tail_pesanan);
      } else if (pilihan == 2)
      {
        
        deletePesanan(head_pesanan,tail_pesanan,head_lapangan);
        simpanPesananKeCSV(head_pesanan,tail_pesanan);
      }
      
      

    }
else if (pilihan == 1 && loginuser != nullptr && isAdminLoggedIn == false)
{
        int hari;
        int nomor_lap;
        bool ver = false;
        cout << "====================================" << endl;
        cout << "||  Booking Lapangan              ||" << endl;
        cout << "===================================" << endl;
        cout << "|| 1. Senin                       ||" << endl;
        cout << "|| 2. Selasa                      ||" << endl;
        cout << "|| 3. Rabu                        ||" << endl;
        cout << "|| 4. Kamis                       ||" << endl;
        cout << "|| 5. Jumat                       ||" << endl;
        cout << "|| 6. Sabtu                       ||" << endl;
        cout << "|| 7. Minggu                      ||" << endl;
        cout << "====================================" << endl;
        hari = paksaint();
        fflush(stdin);
        hari -= 1;
        ver = display_daylap(head_lapangan,tail_lapangan,hari);
        if (ver == true)
        {
          
          nomor_lap = noLap();
          fflush(stdin);
          ver = pesan(head_lapangan,nomor_lap,hari);
          if (ver == true)
          {
            /* disini masukkan ke struck pesanan */
            addpesanan(head_pesanan,tail_pesanan,loginuser, head_lapangan,nomor_lap, hari);
            simpanPesananKeCSV(head_pesanan,tail_pesanan);
          }
        }
}

    else if (pilihan == 2 && loginuser != nullptr && isAdminLoggedIn == false)
    {
        
        int hari;
        bool var;
        cout << "====================================" << endl;
        cout << "||  Booking Lapangan              ||" << endl;
        cout << "====================================" << endl;
        cout << "|| 1. Senin                       ||" << endl;
        cout << "|| 2. Selasa                      ||" << endl;
        cout << "|| 3. Rabu                        ||" << endl;
        cout << "|| 4. Kamis                       ||" << endl;
        cout << "|| 5. Jumat                       ||" << endl;
        cout << "|| 6. Sabtu                       ||" << endl;
        cout << "|| 7. Minggu                      ||" << endl;
        cout << "====================================" << endl;
        hari = paksaint();
        hari -= 1;
        var = display_daylap(head_lapangan,tail_lapangan,hari);
    }
    else if (pilihan == 3 && loginuser != nullptr)
    {
      int pilihseacrh;
      while (true)
      {
        // for user
        cout << "====================================" << endl;
        cout << "||         Menu Searching        ||" << endl;
        cout << "===================================" << endl;
        cout << "|| 1. Search Jenis Lap.         ||" << endl;
        cout << "|| 2. Search Fasilitas Lap.      ||" << endl;
        cout << "====================================" << endl;
        pilihseacrh = paksaint();
        cout << "____________" << endl;
        if (pilihseacrh == 1)
        {
          string search;
          shellSort2(&head_lapangan, length(head_lapangan));
          cout << "Masukkan Jenis Lapangan :";
          cin >> search;
          cout << "____________" << endl;
          search_booyer(head_lapangan, search);
          break;
        }
        else if (pilihseacrh == 2)
        {
          string search;
          shellSort2(&head_lapangan, length(head_lapangan));
          cout << "Masukkan Fasilitas Lapangan :";
          cin >> search;
          cout << "____________" << endl;
          search_booyer1(head_lapangan, search);
          break;
        }
        else
        {
          cout << "Pilihan tidak valid." << endl;
        }
      }
    }
    else if(pilihan == 4 && loginuser != nullptr && isAdminLoggedIn == false){
        // display pesanan yang telah user itu sendiri
      dispesus(head_pesanan,tail_pesanan,loginuser);
    }
    else if (pilihan == 2 && loginuser == nullptr)
    {
      // Login
      time_t now;
      time(&now);
      char *now_string = ctime(&now);
      string username, password;
      cout << "Masukkan username: ";
      fflush(stdin);
      getline(cin, username);
      cout << "Masukkan password: ";
      fflush(stdin);
      getline(cin, password);
      loginuser = isUserValid(head_user, username, password, now_string);
      if (loginuser != nullptr)
      {
        cout << "Selamat datang, " << loginuser->username << "!" << endl;
        username.clear();
        password.clear();
        if (loginuser->username == "admin")
        {
          cout << "Anda login sebagai admin." << endl;
          isAdminLoggedIn = true;
        }
        else
        {
          cout << "Anda login sebagai pengguna biasa." << endl;
        }
      }
      else
      {
        cout << "Username atau password tidak valid." << endl;
      }
    }
    else if (pilihan == 0 && loginuser != nullptr)
    {
      cout << "Log Out" << endl;
      loginuser = nullptr;
      isAdminLoggedIn = false;
    }
    else if (pilihan == 0 && loginuser == nullptr)
    {
      cout << "Keluar" << endl;
      writeUserToCSV(head_user);
      simpanKeCSV(head_lapangan);
      break;
    }
    else
    {
      cout << "Pilihan tidak valid" << endl;
    }
  }
  return 0;
}
