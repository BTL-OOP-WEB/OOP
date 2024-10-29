#include "../declare/NhanVien.h"
#include "../declare/SanPham.h"
#include "../declare/GiamDoc.h"
#include "../declare/User.h"
#include "../declare/Date.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

SanPham::SanPham(int soLuong, double giaTien) 
    : soLuong(soLuong), giaTien(giaTien) {}

void SanPham::inThongTin() const {
    cout << "So luong: " << soLuong << "\n"
         << "Gia tien: " << giaTien << "\n";
}

void SanPham::themSanPhamVaoDoHang(int soLuong) {
    this->soLuong += soLuong;
}

bool SanPham::banSanPham(int soLuong) {
    if (this->soLuong >= soLuong) {
        this->soLuong -= soLuong;
        return true;
    } else {
        cout << "Khong du san pham de ban!\n";
        return false;
    }
}

string SanPham::getLoaiSanPham() const {
    if (dynamic_cast<const Thit*>(this)) {
        return "Thit";
    } else if (dynamic_cast<const Ca*>(this)) {
        return "Ca";
    } else if (dynamic_cast<const Keo*>(this)) {
        return "Keo";
    } else if (dynamic_cast<const Nuoc*>(this)) {
        return "Nuoc";
    } else if (dynamic_cast<const RauCu*>(this)) {
        return "RauCu";
    } else if (dynamic_cast<const GiaVi*>(this)) {
        return "GiaVi";
    } else if (dynamic_cast<const Banh*>(this)) {
        return "Banh";
    } else if (dynamic_cast<const Giay*>(this)) {
        return "Giay";
    } else if (dynamic_cast<const ChenBat*>(this)) {
        return "ChenBat";
    } else if (dynamic_cast<const DoDongHop*>(this)) {
        return "DoDongHop";
    } else {
        return "Khong Xac Dinh"; 
    }
}

int SanPham::getGia() const {
    return giaTien;
}

string SanPham::getTenSanPham() const {
    return "San pham chung";
}

Thit::Thit(int soLuong, const string& loaiThit, double giaTien) 
    : SanPham(soLuong, giaTien), loaiThit(loaiThit) {}

void Thit::inThongTin() const {
    SanPham::inThongTin();
    cout << "Loai thit: " << loaiThit << "\n";
}

string Thit::getTenSanPham() const {
    return loaiThit;
}

Ca::Ca(int soLuong, const string& loaiCa, double giaTien) 
    : SanPham(soLuong, giaTien), loaiCa(loaiCa) {}

void Ca::inThongTin() const {
    SanPham::inThongTin();
    cout << "Loai ca: " << loaiCa << "\n";
}

string Ca::getTenSanPham() const {
    return loaiCa;
}

Keo::Keo(int soLuong, const string& loaiKeo, double giaTien) 
    : SanPham(soLuong, giaTien), loaiKeo(loaiKeo) {}

void Keo::inThongTin() const {
    SanPham::inThongTin();
    cout << "Loai keo: " << loaiKeo << "\n";
}

string Keo::getTenSanPham() const {
    return loaiKeo;
}

Nuoc::Nuoc(int soLuong, const string& loaiNuoc, double giaTien) 
    : SanPham(soLuong, giaTien), loaiNuoc(loaiNuoc) {}

void Nuoc::inThongTin() const {
    SanPham::inThongTin();
    cout << "Loai nuoc: " << loaiNuoc << "\n";
}

string Nuoc::getTenSanPham() const {
    return loaiNuoc;
}

RauCu::RauCu(int soLuong, const string& loaiRauCu, double giaTien) 
    : SanPham(soLuong, giaTien), loaiRauCu(loaiRauCu) {}

void RauCu::inThongTin() const {
    SanPham::inThongTin();
    cout << "Loai rau cu: " << loaiRauCu << "\n";
}

string RauCu::getTenSanPham() const {
    return loaiRauCu;
}

GiaVi::GiaVi(int soLuong, const string& loaiGiaVi, double giaTien) 
    : SanPham(soLuong, giaTien), loaiGiaVi(loaiGiaVi) {}

void GiaVi::inThongTin() const {
    SanPham::inThongTin();
    cout << "Loai gia vi: " << loaiGiaVi << "\n";
}

string GiaVi::getTenSanPham() const {
    return loaiGiaVi;
}

Banh::Banh(int soLuong, const string& loaiBanh, double giaTien) 
    : SanPham(soLuong, giaTien), loaiBanh(loaiBanh) {}

void Banh::inThongTin() const {
    SanPham::inThongTin();
    cout << "Loai banh: " << loaiBanh << "\n";
}

string Banh::getTenSanPham() const {
    return loaiBanh;
}

Giay::Giay(int soLuong, const string& loaiGiay, double giaTien) 
    : SanPham(soLuong, giaTien), loaiGiay(loaiGiay) {}

void Giay::inThongTin() const {
    SanPham::inThongTin();
    cout << "Loai giay: " << loaiGiay << "\n";
}

string Giay::getTenSanPham() const {
    return loaiGiay;
}

ChenBat::ChenBat(int soLuong, const string& loaiChenBat, double giaTien) 
    : SanPham(soLuong, giaTien), loaiChenBat(loaiChenBat) {}

void ChenBat::inThongTin() const {
    SanPham::inThongTin();
    cout << "Loai chen bat: " << loaiChenBat << "\n";
}

string ChenBat::getTenSanPham() const {
    return loaiChenBat;
}

DoDongHop::DoDongHop(int soLuong, const string& loaiDoDongHop, double giaTien) 
    : SanPham(soLuong, giaTien), loaiDoDongHop(loaiDoDongHop) {}

void DoDongHop::inThongTin() const {
    SanPham::inThongTin();
    cout << "Loai do dong hop: " << loaiDoDongHop << "\n";
}

string DoDongHop::getTenSanPham() const {
    return loaiDoDongHop;
}


void hienThiThongTin(const vector<SanPham*>& dsSanPham) {
    for (const auto& sp : dsSanPham) {
        sp->inThongTin();
        cout << "---------------------\n";
    }
}

void docDuLieuTuFile(const string& tenFile, vector<SanPham*>& dsSanPham) {
    ifstream file(tenFile);
    if (!file) {
        cout << "Khong mo duoc file.\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string loai, loaiChiTiet;
        int soLuong;
        double giaTien;

        ss >> loai >> soLuong;
        ss >> loaiChiTiet >> giaTien;

        if (loai == "Thit") {
            dsSanPham.push_back(new Thit(soLuong, loaiChiTiet, giaTien));
        } else if (loai == "Ca") {
            dsSanPham.push_back(new Ca(soLuong, loaiChiTiet, giaTien));
        } else if (loai == "Keo") {
            dsSanPham.push_back(new Keo(soLuong, loaiChiTiet, giaTien));
        } else if (loai == "Nuoc") {
            dsSanPham.push_back(new Nuoc(soLuong, loaiChiTiet, giaTien));
        } else if (loai == "RauCu") {
            dsSanPham.push_back(new RauCu(soLuong, loaiChiTiet, giaTien));
        } else if (loai == "GiaVi") {
            dsSanPham.push_back(new GiaVi(soLuong, loaiChiTiet, giaTien));
        } else if (loai == "Banh") {
            dsSanPham.push_back(new Banh(soLuong, loaiChiTiet, giaTien));
        } else if (loai == "Giay") {
            dsSanPham.push_back(new Giay(soLuong, loaiChiTiet, giaTien));
        } else if (loai == "ChenBat") {
            dsSanPham.push_back(new ChenBat(soLuong, loaiChiTiet, giaTien));
        } else if (loai == "DoDongHop") {
            dsSanPham.push_back(new DoDongHop(soLuong, loaiChiTiet, giaTien));
        } else {
            cout << "Loai san pham khong hop le: " << loai << endl;
        }
    }

    file.close();
}

void giaiPhongBoNho(vector<SanPham*>& dsSanPham) {
    for (auto& sp : dsSanPham) {
        delete sp;
    }
    dsSanPham.clear();
}

int SanPham::getSoLuong() const {
    return soLuong;
}

void SanPham::setSoLuong(int soLuongMoi) {
    soLuong = soLuongMoi;
}

void themSanPham(vector<SanPham*>& dsSanPham, const string& loaiSanPham, int soLuong, const string& loaiChiTiet, double giaTien) {
    for (SanPham* sp : dsSanPham) {
        if (sp->getTenSanPham() == loaiSanPham) {
            sp->setSoLuong(sp->getSoLuong() + soLuong);
            return;
        }
    }

    if (loaiSanPham == "Thit") {
        dsSanPham.push_back(new Thit(soLuong, loaiChiTiet, giaTien));
    } else if (loaiSanPham == "Ca") {
        dsSanPham.push_back(new Ca(soLuong, loaiChiTiet, giaTien));
    } else if (loaiSanPham == "Keo") {
        dsSanPham.push_back(new Keo(soLuong, loaiChiTiet, giaTien));
    } else if (loaiSanPham == "Nuoc") {
        dsSanPham.push_back(new Nuoc(soLuong, loaiChiTiet, giaTien));
    } else if (loaiSanPham == "RauCu") {
        dsSanPham.push_back(new RauCu(soLuong, loaiChiTiet, giaTien));
    } else if (loaiSanPham == "GiaVi") {
        dsSanPham.push_back(new GiaVi(soLuong, loaiChiTiet, giaTien));
    } else if (loaiSanPham == "Banh") {
        dsSanPham.push_back(new Banh(soLuong, loaiChiTiet, giaTien));
    } else if (loaiSanPham == "Giay") {
        dsSanPham.push_back(new Giay(soLuong, loaiChiTiet, giaTien));
    } else if (loaiSanPham == "ChenBat") {
        dsSanPham.push_back(new ChenBat(soLuong, loaiChiTiet, giaTien));
    } else if (loaiSanPham == "DoDongHop") {
        dsSanPham.push_back(new DoDongHop(soLuong, loaiChiTiet, giaTien));
    } else {
        cout << "Loai san pham khong hop le!" << endl;
    }
}

void ghiDuLieuVaoFile(const string& tenFile, const vector<SanPham*>& dsSanPham) {
    ofstream fileOut(tenFile);
    if (fileOut.is_open()) {
        for (const SanPham* sp : dsSanPham) {
            fileOut << sp->getTenSanPham() << " "
                    << sp->getSoLuong() << " ";

            // Xác định loại chi tiết của sản phẩm và ghi vào file
            if (const Thit* thit = dynamic_cast<const Thit*>(sp)) {
                fileOut << thit->getTenSanPham() << " " << thit->giaTien << endl;
            } else if (const Ca* ca = dynamic_cast<const Ca*>(sp)) {
                fileOut << ca->getTenSanPham() << " " << ca->giaTien << endl;
            } else if (const Keo* keo = dynamic_cast<const Keo*>(sp)) {
                fileOut << keo->getTenSanPham() << " " << keo->giaTien << endl;
            } else if (const Nuoc* nuoc = dynamic_cast<const Nuoc*>(sp)) {
                fileOut << nuoc->getTenSanPham() << " " << nuoc->giaTien << endl;
            } else if (const RauCu* rauCu = dynamic_cast<const RauCu*>(sp)) {
                fileOut << rauCu->getTenSanPham() << " " << rauCu->giaTien << endl;
            } else if (const GiaVi* giaVi = dynamic_cast<const GiaVi*>(sp)) {
                fileOut << giaVi->getTenSanPham() << " " << giaVi->giaTien << endl;
            } else if (const Banh* banh = dynamic_cast<const Banh*>(sp)) {
                fileOut << banh->getTenSanPham() << " " << banh->giaTien << endl;
            } else if (const Giay* giay = dynamic_cast<const Giay*>(sp)) {
                fileOut << giay->getTenSanPham() << " " << giay->giaTien << endl;
            } else if (const ChenBat* chenBat = dynamic_cast<const ChenBat*>(sp)) {
                fileOut << chenBat->getTenSanPham() << " " << chenBat->giaTien << endl;
            } else if (const DoDongHop* doDongHop = dynamic_cast<const DoDongHop*>(sp)) {
                fileOut << doDongHop->getTenSanPham() << " " << doDongHop->giaTien << endl;
            }
        }
        fileOut.close();
    } else {
        cout << "Khong the mo file de ghi!" << endl;
    }
}

SanPham* Thit::taoSanPham() const {
    return new Thit(*this);
}

SanPham* Ca::taoSanPham() const {
    return new Ca(*this);
}

SanPham* Keo::taoSanPham() const {
    return new Keo(*this);
}

SanPham* Nuoc::taoSanPham() const {
    return new Nuoc(*this);
}

SanPham* RauCu::taoSanPham() const {
    return new RauCu(*this);
}

SanPham* GiaVi::taoSanPham() const {
    return new GiaVi(*this);
}

SanPham* Banh::taoSanPham() const {
    return new Banh(*this);
}

SanPham* Giay::taoSanPham() const {
    return new Giay(*this);
}

SanPham* ChenBat::taoSanPham() const {
    return new ChenBat(*this);
}

SanPham* DoDongHop::taoSanPham() const {
    return new DoDongHop(*this);
}