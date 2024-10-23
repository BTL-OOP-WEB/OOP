#include "../declare/SanPham.h"

using namespace std;

// Constructor lớp SanPham
SanPham::SanPham(int soLuong, const string& ngaySanXuat, const string& hanSuDung, double giaTien) 
    : soLuong(soLuong), ngaySanXuat(ngaySanXuat), hanSuDung(hanSuDung), giaTien(giaTien) {}

// Phương thức in thông tin lớp SanPham
void SanPham::inThongTin() const {
    cout << "So luong: " << soLuong << "\n"
         << "Ngay san xuat: " << ngaySanXuat << "\n"
         << "Han su dung: " << hanSuDung << "\n"
         << "Gia tien: " << giaTien << "\n"; // Hiển thị giá tiền
}

// Thêm sản phẩm
void SanPham::themSanPham(int soLuong) {
    this->soLuong += soLuong;
}

// Bán sản phẩm
bool SanPham::banSanPham(int soLuong) {
    if (this->soLuong >= soLuong) {
        this->soLuong -= soLuong;
        return true;
    } else {
        cout << "Khong du san pham de ban!\n";
        return false;
    }
}

// Constructor lớp Thit
Thit::Thit(int soLuong, const string& ngaySanXuat, const string& hanSuDung, const string& loaiThit, double giaTien) 
    : SanPham(soLuong, ngaySanXuat, hanSuDung, giaTien), loaiThit(loaiThit) {}

// In thông tin lớp Thit
void Thit::inThongTin() const {
    SanPham::inThongTin();
    cout << "Loai thit: " << loaiThit << "\n";
}

// Constructor lớp Ca
Ca::Ca(int soLuong, const string& ngaySanXuat, const string& hanSuDung, const string& loaiCa, double giaTien) 
    : SanPham(soLuong, ngaySanXuat, hanSuDung, giaTien), loaiCa(loaiCa) {}

// In thông tin lớp Ca
void Ca::inThongTin() const {
    SanPham::inThongTin();
    cout << "Loai ca: " << loaiCa << "\n";
}

// Constructor lớp Keo
Keo::Keo(int soLuong, const string& ngaySanXuat, const string& hanSuDung, const string& loaiKeo, double giaTien) 
    : SanPham(soLuong, ngaySanXuat, hanSuDung, giaTien), loaiKeo(loaiKeo) {}

// In thông tin lớp Keo
void Keo::inThongTin() const {
    SanPham::inThongTin();
    cout << "Loai keo: " << loaiKeo << "\n";
}

// Constructor lớp Nuoc
Nuoc::Nuoc(int soLuong, const string& ngaySanXuat, const string& hanSuDung, const string& loaiNuoc, double giaTien) 
    : SanPham(soLuong, ngaySanXuat, hanSuDung, giaTien), loaiNuoc(loaiNuoc) {}

// In thông tin lớp Nuoc
void Nuoc::inThongTin() const {
    SanPham::inThongTin();
    cout << "Loai nuoc: " << loaiNuoc << "\n";
}

// Constructor lớp RauCu
RauCu::RauCu(int soLuong, const string& ngaySanXuat, const string& hanSuDung, const string& loaiRauCu, double giaTien) 
    : SanPham(soLuong, ngaySanXuat, hanSuDung, giaTien), loaiRauCu(loaiRauCu) {}

// In thông tin lớp RauCu
void RauCu::inThongTin() const {
    SanPham::inThongTin();
    cout << "Loai rau cu: " << loaiRauCu << "\n";
}

// Constructor lớp GiaVi
GiaVi::GiaVi(int soLuong, const string& ngaySanXuat, const string& hanSuDung, const string& loaiGiaVi, double giaTien) 
    : SanPham(soLuong, ngaySanXuat, hanSuDung, giaTien), loaiGiaVi(loaiGiaVi) {}

// In thông tin lớp GiaVi
void GiaVi::inThongTin() const {
    SanPham::inThongTin();
    cout << "Loai gia vi: " << loaiGiaVi << "\n";
}

// Constructor lớp Banh
Banh::Banh(int soLuong, const string& ngaySanXuat, const string& hanSuDung, const string& loaiBanh, double giaTien) 
    : SanPham(soLuong, ngaySanXuat, hanSuDung, giaTien), loaiBanh(loaiBanh) {}

// In thông tin lớp Banh
void Banh::inThongTin() const {
    SanPham::inThongTin();
    cout << "Loai banh: " << loaiBanh << "\n";
}

// Constructor lớp Giay
Giay::Giay(int soLuong, const string& ngaySanXuat, const string& hanSuDung, const string& loaiGiay, double giaTien) 
    : SanPham(soLuong, ngaySanXuat, hanSuDung, giaTien), loaiGiay(loaiGiay) {}

// In thông tin lớp Giay
void Giay::inThongTin() const {
    SanPham::inThongTin();
    cout << "Loai giay: " << loaiGiay << "\n";
}

// Constructor lớp ChenBat
ChenBat::ChenBat(int soLuong, const string& ngaySanXuat, const string& hanSuDung, const string& loaiChenBat, double giaTien) 
    : SanPham(soLuong, ngaySanXuat, hanSuDung, giaTien), loaiChenBat(loaiChenBat) {}

// In thông tin lớp ChenBat
void ChenBat::inThongTin() const {
    SanPham::inThongTin();
    cout << "Loai chen bat: " << loaiChenBat << "\n";
}

// Constructor lớp DoDongHop
DoDongHop::DoDongHop(int soLuong, const string& ngaySanXuat, const string& hanSuDung, const string& loaiDoDongHop, double giaTien) 
    : SanPham(soLuong, ngaySanXuat, hanSuDung, giaTien), loaiDoDongHop(loaiDoDongHop) {}

// In thông tin lớp DoDongHop
void DoDongHop::inThongTin() const {
    SanPham::inThongTin();
    cout << "Loai do dong hop: " << loaiDoDongHop << "\n";
}

string Thit::getTenSanPham() const {
    return loaiThit; // Trả về loại thịt
}

string Ca::getTenSanPham() const {
    return loaiCa; // Trả về loại thịt
}

string Keo::getTenSanPham() const {
    return loaiKeo; // Trả về loại thịt
}

string Nuoc::getTenSanPham() const {
    return loaiNuoc; // Trả về loại thịt
}

string RauCu::getTenSanPham() const {
    return loaiRauCu; // Trả về loại thịt
}

string GiaVi::getTenSanPham() const {
    return loaiGiaVi; // Trả về loại thịt
}

string Banh::getTenSanPham() const {
    return loaiBanh; // Trả về loại thịt
}

string ChenBat::getTenSanPham() const {
    return loaiChenBat; // Trả về loại thịt
}

string Giay::getTenSanPham() const {
    return loaiGiay; // Trả về loại thịt
}

string DoDongHop::getTenSanPham() const {
    return loaiDoDongHop; // Trả về loại thịt
}

// Hàm hiển thị thông tin tất cả các sản phẩm
void hienThiThongTin(const vector<SanPham*>& dsSanPham) {
    for (const auto& sp : dsSanPham) {
        sp->inThongTin();
        cout << "---------------------\n";
    }
}

// Hàm đọc dữ liệu từ file
void docDuLieuTuFile(const string& tenFile, vector<SanPham*>& dsSanPham) {
    ifstream file(tenFile);
    if (!file) {
        cout << "Khong mo duoc file.\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string loai, loaiChiTiet, ngaySanXuat, hanSuDung;
        int soLuong;
        double giaTien; // Thêm biến cho giá tiền

        ss >> loai >> soLuong >> ngaySanXuat >> hanSuDung >> loaiChiTiet >> giaTien; // Đọc giá tiền

        if (loai == "Thit") {
            dsSanPham.push_back(new Thit(soLuong, ngaySanXuat, hanSuDung, loaiChiTiet, giaTien));
        } else if (loai == "Ca") {
            dsSanPham.push_back(new Ca(soLuong, ngaySanXuat, hanSuDung, loaiChiTiet, giaTien));
        } else if (loai == "Keo") {
            dsSanPham.push_back(new Keo(soLuong, ngaySanXuat, hanSuDung, loaiChiTiet, giaTien));
        } else if (loai == "Nuoc") {
            dsSanPham.push_back(new Nuoc(soLuong, ngaySanXuat, hanSuDung, loaiChiTiet, giaTien));
        } else if (loai == "RauCu") {
            dsSanPham.push_back(new RauCu(soLuong, ngaySanXuat, hanSuDung, loaiChiTiet, giaTien));
        } else if (loai == "GiaVi") {
            dsSanPham.push_back(new GiaVi(soLuong, ngaySanXuat, hanSuDung, loaiChiTiet, giaTien));
        } else if (loai == "Banh") {
            dsSanPham.push_back(new Banh(soLuong, ngaySanXuat, hanSuDung, loaiChiTiet, giaTien));
        } else if (loai == "Giay") {
            dsSanPham.push_back(new Giay(soLuong, ngaySanXuat, hanSuDung, loaiChiTiet, giaTien));
        } else if (loai == "ChenBat") {
            dsSanPham.push_back(new ChenBat(soLuong, ngaySanXuat, hanSuDung, loaiChiTiet, giaTien));
        } else if (loai == "DoDongHop") {
            dsSanPham.push_back(new DoDongHop(soLuong, ngaySanXuat, hanSuDung, loaiChiTiet, giaTien));
        }
    }

    file.close();
}

// Hàm giải phóng bộ nhớ
void giaiPhongBoNho(vector<SanPham*>& dsSanPham) {
    for (auto& sp : dsSanPham) {
        delete sp;
    }
    dsSanPham.clear();
}

// Phương thức lấy số lượng hiện tại
int SanPham::getSoLuong() const {
    return soLuong;
}

// Phương thức cập nhật số lượng mới
void SanPham::setSoLuong(int soLuongMoi) {
    soLuong = soLuongMoi; // Cập nhật số lượng mới
}
