#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "../declare/GiamDoc.h"
#include "../declare/SanPham.h"
#include "../declare/Khach_hang.h"
#include "../declare/User.h"    
#include "../declare/NhanVien.h"
#include "../declare/DangNhap.h"
#include "../declare/Date.h"
#include "../declare/LinkedList.h"

using namespace std;

void dangNhap(const string& vaiTro);
void dangKy(const string& vaiTro);
void menuKhachHang(KhachHang& khachHang);
void menuNhanVien(NhanVien& nhanVien);
void menuGiamDoc(GiamDoc& giamDoc);

int main() {
    clearScreen();
    int luaChon;
    cout << "-------\033[38;5;49m[WELCOME BREAD3T SHOP]\033[0m-------" << endl;
    cout << "|         Chon vai tro:            |"<< endl;
    cout << "|        \033[38;5;214m~\033[0m 1. Khach hang           |"<< endl;
    cout << "|        \033[38;5;214m~\033[0m 2. Nhan vien            |" << endl;
    cout << "|        \033[38;5;214m~\033[0m 3. Giam doc             |" << endl;
    cout << "------------------------------------" << endl;
    cout.flush();
    setCursorPosition(24, 1); 
    cin >> luaChon;
    clearScreen();

    switch (luaChon) {
        case 1:
            cout << "---------\033[38;5;49m[CHON PHUONG THUC]\033[0m---------" << endl;
            cout << "|         Ban muon:                |"<< endl;
            cout << "|        \033[38;5;214m~\033[0m 1. Dang nhap            |"<< endl;
            cout << "|        \033[38;5;214m~\033[0m 2. Dang ky              |" << endl;
            cout << "------------------------------------" << endl;
            cout.flush();
            setCursorPosition(20, 1); 
            cin >> luaChon;
            clearScreen();
            if (luaChon == 1)
                dangNhap("KhachHang");
            else if (luaChon == 2)
                dangKy("KhachHang");
            break;
        case 2:
            cout << "---------\033[38;5;49m[CHON PHUONG THUC]\033[0m---------" << endl;
            cout << "|         Ban muon:                |"<< endl;
            cout << "|        \033[38;5;214m~\033[0m 1. Dang nhap            |"<< endl;
            cout << "|        \033[38;5;214m~\033[0m 2. Dang ky              |" << endl;
            cout << "------------------------------------" << endl;
            cout.flush();
            setCursorPosition(20, 1); 
            cin >> luaChon;
            clearScreen();
            if (luaChon == 1)
                dangNhap("NhanVien");
            else
                dangKy("NhanVien");
            break;
        case 3:
            cout << "---------\033[38;5;49m[CHON PHUONG THUC]\033[0m---------" << endl;
            cout << "|         Ban muon:                |"<< endl;
            cout << "|        \033[38;5;214m~\033[0m 1. Dang nhap            |"<< endl;
            cout << "|        \033[38;5;214m~\033[0m 2. Dang ky              |" << endl;
            cout << "------------------------------------" << endl;
            cout.flush();
            setCursorPosition(20, 1); 
            cin >> luaChon;
            clearScreen();
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

