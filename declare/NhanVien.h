#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "SanPham.h"
#include "Date.h"

class SanPham;

class NhanVien : public User {
private:
    string hoTen;        
    Date ngaySinh;      
    string sdt;         
    string lichLamViec;  
    vector<SanPham*> khoHang; 

public:
    NhanVien(const string& ten, const string& matKhau, const string& hoTen, const Date& ngaySinh, const string& sdt, const string& lichLamViec);

    int getSoCaDaLam() const;
    string getTenNguoiDung() const; 

    void nhapSanPham(vector<SanPham*>& khoHang, const string& loaiSanPham, int soLuong);
    void xoaSanPham(SanPham* sanPham, int soLuong);
    void dangKyCaLam(); 
    void hienThiThongTin() const override; 

    string getHoTen() const;
    Date getNgaySinh() const; 
    string getSdt() const; 
    string getCaLam() const;

    static void docDanhSachNhanVien(vector<NhanVien*>& dsNhanVien);
};

#endif