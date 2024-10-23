#include "../declare/GiamDoc.h"
#include <iostream>

GiamDoc::GiamDoc(const string& ten, const string& matKhau) : User(ten, matKhau) {};

void GiamDoc::diemDanhNhanVien(const vector<NhanVien*>& dsNhanVien) {
    cout << "Danh sach nhan vien diem danh:\n";
    for (const auto& nhanVien : dsNhanVien) {
        cout << nhanVien->getTen() << endl; // Giả sử bạn có phương thức getTenNguoiDung() trong NhanVien
    }
}

void GiamDoc::xuatLuongNhanVien(NhanVien* nhanVien) {
    int soCa = nhanVien->getSoCaDaLam(); // Lấy số ca đã làm
    int luong = soCa * 100000; // 1 ca là 100k
    cout << "Luong cua nhan vien " << nhanVien->getTen() << " la: " << luong << " VND" << endl;
}

void GiamDoc::hienThiThongTin() const {
    cout << "Giam doc: " << getTen() << endl; // Sử dụng phương thức getTenNguoiDung()
}
