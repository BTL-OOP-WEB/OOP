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

SanPham* KhachHang::timSanPham(const string& tenSanPham, const vector<SanPham*>& danhSachSanPham) const {
    for (auto& sanPham : danhSachSanPham) {
        if (sanPham->getTenSanPham() == tenSanPham) {
            return sanPham;
        }
    }
    return nullptr;
}


void KhachHang::muaHang(const vector<SanPham*>& danhSachSanPham) {
    int luaChonQuay;

    do {
        cout << " _________________________________________ " << endl;
        cout << "| 1. Quay Thit          |                 |" << endl;
        cout << "| 2. Quay Ca            |                 |" << endl;
        cout << "| 3. Quay Keo           |                 |" << endl;
        cout << "| 4. Quay Nuoc          |                 |" << endl;
        cout << "| 5. Quay Rau Cu        |                 |" << endl;
        cout << "| 6. Quay Gia Vi        |                 |" << endl;
        cout << "| 7. Quay Banh          |                 |" << endl;
        cout << "| 8. Quay Giay          |                 |" << endl;
        cout << "| 9. Quay Chen Bat      |                 |" << endl;
        cout << "| 10. Quay Do Dong Hop  |                 |" << endl;
        cout << "|________________________|   |W|E|L|C|O|M|E| " << endl;

        cout << "Chon quay muon mua (1-10): ";
        cin >> luaChonQuay;

        switch (luaChonQuay) {
            case 1: 
                cout << "Ban da chon Quay Thit. Cac san pham co san:" << endl;
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "Thit") {
                        cout << "_____________________" << endl;
                        cout << "| " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_____________________" << endl;
                    }
                }
                break;
            case 2:
                cout << "Ban da chon Quay Ca. Cac san pham co san:" << endl;
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "Ca") {
                        cout << "_____________________" << endl;
                        cout << "| " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_____________________" << endl;
                    }
                }
                break;
            case 3:
                cout << "Ban da chon Quay Keo. Cac san pham co san:" << endl;
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "Keo") {
                        cout << "_____________________" << endl;
                        cout << "| " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_____________________" << endl;
                    }
                }
                break;
            case 4:
                cout << "Ban da chon Quay Nuoc. Cac san pham co san:" << endl;
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "Nuoc") {
                        cout << "_____________________" << endl;
                        cout << "| " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_____________________" << endl;
                    }
                }
                break;
            case 5:
                cout << "Ban da chon Quay Rau Cu. Cac san pham co san:" << endl;
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "Rau Cu") {
                        cout << "_____________________" << endl;
                        cout << "| " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_____________________" << endl;
                    }
                }
                break;
            case 6:
                cout << "Ban da chon Quay Gia Vi. Cac san pham co san:" << endl;
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "Gia Vi") {
                        cout << "_____________________" << endl;
                        cout << "| " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_____________________" << endl;
                    }
                }
                break;
            case 7:
                cout << "Ban da chon Quay Banh. Cac san pham co san:" << endl;
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "Banh") {
                        cout << "_____________________" << endl;
                        cout << "| " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_____________________" << endl;
                    }
                }
                break;
            case 8:
                cout << "Ban da chon Quay Giay. Cac san pham co san:" << endl;
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "Giay") {
                        cout << "_____________________" << endl;
                        cout << "| " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_____________________" << endl;
                    }
                }
                break;
            case 9:
                cout << "Ban da chon Quay Chen Bat. Cac san pham co san:" << endl;
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "Chen Bat") {
                        cout << "_____________________" << endl;
                        cout << "| " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_____________________" << endl;
                    }
                }
                break;
            case 10:
                cout << "Ban da chon Quay Do Dong Hop. Cac san pham co san:" << endl;
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "Do Dong Hop") {
                        cout << "_____________________" << endl;
                        cout << "| " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_____________________" << endl;
                    }
                }
                break;
            default:
                cout << "Lua chon khong hop le! Vui long chon lai." << endl;
                continue;
        }

        string tenSanPham;
        int soLuong;
        cout << "Nhap ten san pham ban muon mua: ";
        cin >> tenSanPham;
        cout << "Nhap so luong: ";
        cin >> soLuong;

        SanPham* spChon = timSanPham(tenSanPham, danhSachSanPham);
        if (spChon) {
            themVaoGioHang(spChon, soLuong);
            cout << "San pham da duoc them vao gio hang!" << endl;
        } else {
            cout << "San pham khong ton tai!" << endl;
        }
}
