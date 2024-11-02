#ifndef SANPHAM_H
#define SANPHAM_H

#include "GiamDoc.h"
#include "User.h"
#include "NhanVien.h"  
#include "Date.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class SanPham {
protected:
    int soLuong;

public:
    double giaTien;
    SanPham(int soLuong, double giaTien);
    
    virtual void inThongTin() const;
    virtual string getTenSanPham() const = 0;
    virtual SanPham* taoSanPham() const = 0;

    void themSanPhamVaoDoHang(int soLuong);
    int getSoLuong() const;
    void setSoLuong(int soLuongMoi);
    bool banSanPham(int soLuong);
    string getTen() const;
    string getLoaiSanPham() const;
    int getGia() const;
    
};

class Thit : public SanPham {
private:
    string loaiThit;

public:
    Thit(int soLuong, const string& loaiThit, double giaTien);
    void inThongTin() const override;
    string getTenSanPham() const override;
    SanPham* taoSanPham() const override;
};

class Ca : public SanPham {
private:
    string loaiCa;

public:
    Ca(int soLuong, const string& loaiCa, double giaTien);
    void inThongTin() const override;
    string getTenSanPham() const override;
    SanPham* taoSanPham() const override;
};

class Keo : public SanPham {
private:
    string loaiKeo;

public:
    Keo(int soLuong, const string& loaiKeo, double giaTien);
    void inThongTin() const override;
    string getTenSanPham() const override;
    SanPham* taoSanPham() const override;
};

class Nuoc : public SanPham {
private:
    string loaiNuoc;

public:
    Nuoc(int soLuong, const string& loaiNuoc, double giaTien);
    void inThongTin() const override;
    string getTenSanPham() const override;
    SanPham* taoSanPham() const override;
};

class RauCu : public SanPham {
private:
    string loaiRauCu;

public:
    RauCu(int soLuong, const string& loaiRauCu, double giaTien);
    void inThongTin() const override;
    string getTenSanPham() const override;
    SanPham* taoSanPham() const override;
};

class GiaVi : public SanPham {
private:
    string loaiGiaVi;

public:
    GiaVi(int soLuong, const string& loaiGiaVi, double giaTien);
    void inThongTin() const override;
    string getTenSanPham() const override;
    SanPham* taoSanPham() const override;
};

class Banh : public SanPham {
private:
    string loaiBanh;

public:
    Banh(int soLuong, const string& loaiBanh, double giaTien);
    void inThongTin() const override;
    string getTenSanPham() const override;
    SanPham* taoSanPham() const override;
};

class Giay : public SanPham {
private:
    string loaiGiay;

public:
    Giay(int soLuong, const string& loaiGiay, double giaTien);
    void inThongTin() const override;
    string getTenSanPham() const override;
    SanPham* taoSanPham() const override;
};

class ChenBat : public SanPham {
private:
    string loaiChenBat;

public:
    ChenBat(int soLuong, const string& loaiChenBat, double giaTien);
    void inThongTin() const override;
    string getTenSanPham() const override;
    SanPham* taoSanPham() const override;
};

class DoDongHop : public SanPham {
private:
    string loaiDoDongHop;

public:
    DoDongHop(int soLuong, const string& loaiDoDongHop, double giaTien);
    void inThongTin() const override;
    string getTenSanPham() const override;
    SanPham* taoSanPham() const override;
};

void hienThiThongTin(const vector<SanPham*>& dsSanPham);
void docDuLieuTuFile(const string& tenFile, vector<SanPham*>& dsSanPham);
void giaiPhongBoNho(vector<SanPham*>& dsSanPham);
void themSanPham(vector<SanPham*>& dsSanPham, const string& loaiSanPham, int soLuong, const string& loai, double giaTien);
void ghiDuLieuVaoFile(const string& tenFile, const vector<SanPham*>& dsSanPham);

#endif // SANPHAM_H
