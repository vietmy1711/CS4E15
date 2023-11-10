#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Vemaybay
{
public:
    string tenchuyen;
    string ngaybay;
    int giave;

    Vemaybay() : giave(0) {}

    ~Vemaybay() {}

    void Nhap()
    {
        cout << "Nhap ten chuyen: ";
        cin.ignore();
        getline(cin, tenchuyen);
        cout << "Nhap ngay bay: ";
        cin >> ngaybay;
        cout << "Nhap gia ve: ";
        cin >> giave;
    }

    void Xuat()
    {
        cout << "Ten chuyen: " << tenchuyen << endl;
        cout << "Ngay bay: " << ngaybay << endl;
        cout << "Gia ve: " << giave << endl;
    }

    int getgiave()
    {
        return giave;
    }
};

class Nguoi
{
public:
    string hoten;
    string gioitinh;
    int tuoi;

    Nguoi() : tuoi(0) {}

    void Nhap()
    {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoten);
        cout << "Nhap gioi tinh: ";
        cin >> gioitinh;
        cout << "Nhap tuoi: ";
        cin >> tuoi;
    }

    void Xuat()
    {
        cout << "Ho ten: " << hoten << endl;
        cout << "Gioi tinh: " << gioitinh << endl;
        cout << "Tuoi: " << tuoi << endl;
    }
};

class HanhKhach : public Nguoi
{
public:
    Vemaybay ve;
    int soluong;

    HanhKhach() : soluong(0) {}

    void Nhap()
    {
        Nguoi::Nhap();
        cout << "Nhap so luong ve: ";
        cin >> soluong;
        ve.Nhap();
    }

    void Xuat()
    {
        Nguoi::Xuat();
        cout << "So luong ve: " << soluong << endl;
        ve.Xuat();
    }

    int tongtien()
    {
        return soluong * ve.getgiave();
    }
};

int main()
{
    int n;
    cout << "Nhap so luong hanh khach: ";
    cin >> n;

    vector<HanhKhach> dsHanhKhach;

    for (int i = 0; i < n; ++i)
    {
        cout << "\nNhap thong tin cho hanh khach thu " << i + 1 << endl;
        HanhKhach hanhKhach;
        hanhKhach.Nhap();
        dsHanhKhach.push_back(hanhKhach);
    }

    cout << "\nDanh sach hanh khach va so tien phai tra tuong ung:" << endl;
    for (auto &hanhKhach : dsHanhKhach)
    {
        hanhKhach.Xuat();
        cout << "Tong tien phai tra: " << hanhKhach.tongtien() << endl;
    }

    cout << "Sap xep danh sach theo chieu giam dan cua Tong tien:" << endl;
    sort(dsHanhKhach.begin(), dsHanhKhach.end(), [](HanhKhach &a, HanhKhach &b)
         { return a.tongtien() > b.tongtien(); });

    for (auto &hanhKhach : dsHanhKhach)
    {
        hanhKhach.Xuat();
        cout << "Tong tien phai tra: " << hanhKhach.tongtien()
             << endl;
    }

    return 0;
}
