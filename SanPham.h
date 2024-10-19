#ifndef SANPHAM_H
#define SANPHAM_H

#include "GiamDoc.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Lớp cơ sở cho tất cả các sản phẩm
class SanPham {
protected:
    int soLuong;
    string ngaySanXuat;
    string hanSuDung;

public:
    double giaTien;
    SanPham(int soLuong, const string& ngaySanXuat, const string& hanSuDung, double giaTien);
    
    virtual void inThongTin() const;
    virtual string getTenSanPham() const = 0;

    void themSanPham(int soLuong);
    int getSoLuong() const;
    void setSoLuong(int soLuongMoi);
    bool banSanPham(int soLuong);
    
};

// Lớp con cho thịt
class Thit : public SanPham {
private:
    string loaiThit;

public:
    Thit(int soLuong, const string& ngaySanXuat, const string& hanSuDung, const string& loaiThit, double giaTien);
    void inThongTin() const override;
    string getTenSanPham() const override;
};

// Lớp con cho cá
class Ca : public SanPham {
private:
    string loaiCa;

public:
    Ca(int soLuong, const string& ngaySanXuat, const string& hanSuDung, const string& loaiCa, double giaTien);
    void inThongTin() const override;
    string getTenSanPham() const override;
};

// Lớp con cho kẹo
class Keo : public SanPham {
private:
    string loaiKeo;

public:
    Keo(int soLuong, const string& ngaySanXuat, const string& hanSuDung, const string& loaiKeo, double giaTien);
    void inThongTin() const override;
    string getTenSanPham() const override;
};

// Lớp con cho nước
class Nuoc : public SanPham {
private:
    string loaiNuoc;

public:
    Nuoc(int soLuong, const string& ngaySanXuat, const string& hanSuDung, const string& loaiNuoc, double giaTien);
    void inThongTin() const override;
    string getTenSanPham() const override;
};

// Lớp con cho rau củ
class RauCu : public SanPham {
private:
    string loaiRauCu;

public:
    RauCu(int soLuong, const string& ngaySanXuat, const string& hanSuDung, const string& loaiRauCu, double giaTien);
    void inThongTin() const override;
    string getTenSanPham() const override;
};

// Lớp con cho gia vị
class GiaVi : public SanPham {
private:
    string loaiGiaVi;

public:
    GiaVi(int soLuong, const string& ngaySanXuat, const string& hanSuDung, const string& loaiGiaVi, double giaTien);
    void inThongTin() const override;
    string getTenSanPham() const override;
};

// Lớp con cho bánh
class Banh : public SanPham {
private:
    string loaiBanh;

public:
    Banh(int soLuong, const string& ngaySanXuat, const string& hanSuDung, const string& loaiBanh, double giaTien);
    void inThongTin() const override;
    string getTenSanPham() const override;
};

// Lớp con cho giấy
class Giay : public SanPham {
private:
    string loaiGiay;

public:
    Giay(int soLuong, const string& ngaySanXuat, const string& hanSuDung, const string& loaiGiay, double giaTien);
    void inThongTin() const override;
    string getTenSanPham() const override;
};

// Lớp con cho chén bát
class ChenBat : public SanPham {
private:
    string loaiChenBat;

public:
    ChenBat(int soLuong, const string& ngaySanXuat, const string& hanSuDung, const string& loaiChenBat, double giaTien);
    void inThongTin() const override;
    string getTenSanPham() const override;
};

// Lớp con cho đồ đóng hộp
class DoDongHop : public SanPham {
private:
    string loaiDoDongHop;

public:
    DoDongHop(int soLuong, const string& ngaySanXuat, const string& hanSuDung, const string& loaiDoDongHop, double giaTien);
    void inThongTin() const override;
    string getTenSanPham() const override;
};

// Các hàm khác
void hienThiThongTin(const vector<SanPham*>& dsSanPham);
void docDuLieuTuFile(const string& tenFile, vector<SanPham*>& dsSanPham);
void giaiPhongBoNho(vector<SanPham*>& dsSanPham);

#endif // SANPHAM_H
