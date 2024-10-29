#include "../declare/GiamDoc.h"
#include <iostream>

GiamDoc::GiamDoc(const string& ten, const string& matKhau) : User(ten, matKhau) {};

void GiamDoc::diemDanhNhanVien(const std::vector<NhanVien*>& dsNhanVien) {
    std::vector<NhanVien*> temp; 
    NhanVien::docDanhSachNhanVien(temp);

    if (temp.empty()) {
        std::cout << "Danh sach nhan vien trong!" << std::endl;
    } else {
        std::cout << "Danh sach nhan vien khong trong!" << std::endl;
    }
    
    std::cout << "So luong nhan vien trong danh sach: " << temp.size() << std::endl;

    std::cout << "Danh sach nhan vien diem danh:\n";
    for (const auto& nhanVien : temp) {
        std::cout << "Ten nhan vien: " << nhanVien->getHoTen() << std::endl;

        std::string caLam = nhanVien->getCaLam();
        std::string ngayTrongTuan[] = {"Chu Nhat", "Thu Hai", "Thu Ba", "Thu Tu", "Thu Nam", "Thu Sau", "Thu Bay"};

        for (int i = 0; i < 7; ++i) {
            char ca = caLam[i];
            std::cout << ngayTrongTuan[i] << ": ";
            
            if (ca == '0') {
                std::cout << "Khong lam viec";
            } else if (ca == '1') {
                std::cout << "Lam ca sang";
            } else if (ca == '2') {
                std::cout << "Lam ca chieu";
            } else {
                std::cout << "Thong tin ca lam khong hop le";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
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
