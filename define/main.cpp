#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../declare/GiamDoc.h"
#include "../declare/SanPham.h"
#include "../declare/User.h"    
#include "../declare/NhanVien.h"
#include "../declare/DangNhap.h"

using namespace std;

void dangNhap(const string& vaiTro);
void dangKy(const string& vaiTro);
void menuKhachHang(KhachHang& khachHang);
void menuNhanVien(NhanVien& nhanVien);
void menuGiamDoc(GiamDoc& giamDoc);

int main() {
    int luaChon;
    cout << "Chon vai tro: " << endl;
    cout << "1. Khach hang" << endl;
    cout << "2. Nhan vien" << endl;
    cout << "3. Giam doc" << endl;
    cin >> luaChon;

    switch (luaChon) {
        case 1:
            cout << "Ban muon: " << endl;
            cout << "1. Dang nhap" << endl;
            cout << "2. Dang ky" << endl;
            cin >> luaChon;
            if (luaChon == 1)
                dangNhap("KhachHang");
            else
                dangKy("KhachHang");
            break;
        case 2:

            cout << "Ban muon: " << endl;
            cout << "1. Dang nhap" << endl;
            cout << "2. Dang ky" << endl;
            cin >> luaChon;
            if (luaChon == 1)
                dangNhap("NhanVien");
            else
                dangKy("NhanVien");
            break;
        case 3:
            cout << "Ban muon: " << endl;
            cout << "1. Dang nhap" << endl;
            cout << "2. Dang ky" << endl;
            cin >> luaChon;
            if (luaChon == 1)
                dangNhap("GiamDoc");
            else 
                dangKy("GiamDoc");
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
    }

    return 0;
}



// thiet ke giao dien
// phan dang ky, sao cho giong that
// ngay