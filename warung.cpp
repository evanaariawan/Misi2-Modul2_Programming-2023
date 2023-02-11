#include <iostream>
using namespace std;

int askCustomer(string name)
{
    int order;

    cout << "1. Menu" << endl;
    cout << "2. Pesan Makan/Minum" << endl;
    cout << "3. Keluar" << endl;
    cout << name << ", ingin pilih apa (pilihan sesuai angka)? ";
    cin >> order;

    return order;
}

void showMenu(string menu[], int harga[])
{
    cout << "\nMakanan :\n";
    for (int i = 0; i < 7; i++)
    {
        cout << "id: " << i + 1 << ", " << menu[i] << ", Rp" << harga[i] << endl;
    }
    cout << "\nMinuman:\n";
    for (int i = 7; i < 10; i++)
    {
        cout << "id: " << i + 1 << ", " << menu[i] << ", Rp" << harga[i] << endl;
    }
    cout << endl;
}

int* orderSomething()
{
    static int orderList[2];
    int id, quantity;

    cout << "\nID Menu Pesanan: ";
    cin >> id;
    cout << "Jumlah pesanan: ";
    cin >> quantity;
    cout << "\n";
    orderList[0] = id;
    orderList[1] = quantity;

    return orderList;
}

void showHistory(string nameHistory[][2], int quantityHistory[][2], int idx)
{
    cout << "Data Penjualan Warung Kang Roger\n\n";

    if (idx == 0){
        cout << "Tidak ada Penjualan";
    }
    for (int row = 0; row < idx; row++)
    {
        cout << "Nama: " << nameHistory[row][0] << endl;
        cout << "Pesanan: " << nameHistory[row][1] << endl;
        cout << "Jumlah: " << quantityHistory[row][0] << endl;
        cout << "Total Harga: " << "Rp." << quantityHistory[row][1] << "\n" << endl;
    }
}
    int main()
    {
        string menu[10] = {"Nasi Goreng", "Indomie Goreng Telur", "Indomie Goreng Rebus", "Magelangan",
                           "Nasi Ayam Geprek", "Soto Ayam", "Nasi Pecel", "Es Teh", "Es Jeruk", "Air Mineral"};
        int harga[10] = {15000, 10000, 10000, 12000, 14000, 11000, 13000, 3000, 5000, 4000};

        string salesNameHistory[100][2];
        int salesQuantityHistory[100][2];
        
        string status, customerName;
        int perintah, idx;

        idx = 0;

        cout << "Pemilik ingin buka/tutup: ";
        cin >> status;

        while (status != "tutup")
        {
            cout << "Nama : ";
            cin >> customerName;
            cout << "Selamat datang di warung Kang Roger pelanggan " << customerName << ".\n\n";

            perintah = askCustomer(customerName);
            while (perintah != 3)
            {

                if (perintah == 1)
                {
                    showMenu(menu, harga);
                }
                else if (perintah == 2)
                {
                    int* orderList;
                    orderList = orderSomething();

                    salesNameHistory[idx][0] = customerName;
                    salesNameHistory[idx][1] = menu[orderList[0] - 1];
                    salesQuantityHistory[idx][0] = orderList[1];
                    salesQuantityHistory[idx][1] = orderList[1] * harga[*orderList - 1];

                    idx++;
                }
                else if (perintah == 3)
                {
                    cout << "Terimakasih sudah datang di warung Kang Roger " << customerName << ".\n";
                }

                perintah = askCustomer(customerName);
            }

            cout << "Pemilik ingin buka/tutup: ";
            cin >> status;
        }

        showHistory(salesNameHistory, salesQuantityHistory, idx);

        return 0;
    }