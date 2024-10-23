#include <iostream>
#include <vector>
#include <string>
#include "../declare/Khach_hang.h"
#include "../declare/SanPham.h"

using namespace std;

KhachHang::KhachHang(const string& ten, const string& matKhau, const int& diemTichLuy, const string& hoTen, const Date& ngaySinh, const string& sdt) 
    : User(ten, matKhau), diemTichLuy(diemTichLuy), hoTen(hoTen), ngaySinh(ngaySinh), sdt(sdt) {}

void KhachHang::themVaoGioHang(SanPham* sanPham, int soLuong) {
    sanPham->themSanPhamVaoDoHang(soLuong);
    gioHang.push_back(sanPham);
    cout << "Da them " << soLuong << " san pham vao gio hang." << endl;
}

void KhachHang::boSanPham(SanPham* sanPham, int soLuong) {
    for (auto it = gioHang.begin(); it != gioHang.end(); ++it) {
        if (*it == sanPham) {
            sanPham->banSanPham(soLuong);
            gioHang.erase(it);
            cout << "Da xoa san pham khoi gio hang." << endl;
            return;
        }
    }
    cout << "Khong tim thay san pham trong gio hang." << endl;
}

void KhachHang::thanhToan() {
    double tongTien = 0.0;
    for (auto& sp : gioHang) {
        tongTien += sp->giaTien;
    }

    cout << "Tong tien truoc khi ap dung giam gia: " << tongTien << " VND" << endl;

    suDungDiem();
    
    cout << "Tong tien can thanh toan: " << tongTien << " VND" << endl;
    
    diemTichLuy += tongTien / 100000;
    cout << "Ban da tich them: " << tongTien / 100000 << " diem" << endl;

    xuatHoaDon();

    gioHang.clear();
}

void KhachHang::suDungDiem() {
    if (diemTichLuy > 0) {
        cout << "Ban co " << diemTichLuy << " diem. Ban co muon su dung diem de giam gia khong? (1: Co, 0: Khong): ";
        int luaChon;
        cin >> luaChon;

        if (luaChon == 1) {
            double giamGia = diemTichLuy * 1000;
            cout << "Ban da giam: " << giamGia << " VND tu diem tich luy." << endl;
            diemTichLuy = 0;
        }
    } else {
        cout << "Ban khong co diem tich luy de su dung." << endl;
    }
}

void KhachHang::hienThiGioHang() const {
    cout << "Gio hang cua ban:" << endl;
    for (auto& sp : gioHang) {
        sp->inThongTin();
    }
}

void KhachHang::hienThiThongTin() const {
    cout << "Ten khach hang: " << getTen() << endl;
    cout << "Diem tich luy: " << diemTichLuy << endl;
}

void KhachHang::xuatHoaDon() const {
    cout << "Hoa don cua ban:" << endl;
    for (auto& sp : gioHang) {
        sp->inThongTin();
    }
    cout << "Cam on ban da mua sam tai cua hang!" << endl;
}

SanPham* KhachHang::timSanPhamTrongGioHang(const string& tenSanPham) {
    for (SanPham* sanPham : gioHang) {
        if (sanPham->getTenSanPham() == tenSanPham) {
            return sanPham;
        }
    }
    return nullptr;
}

string KhachHang::getTenSanPham() const {
    return "Ten khach hang: " + getTen();
}

SanPham* KhachHang::timSanPham(const std::string& tenSanPham, const std::vector<SanPham*>& danhSachSanPham) const {
    for (auto& sanPham : danhSachSanPham) {
        if (sanPham->getTenSanPham() == tenSanPham) {
            return sanPham;
        }
    }
    return nullptr;
}
