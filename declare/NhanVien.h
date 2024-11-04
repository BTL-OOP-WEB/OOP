#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "SanPham.h"
#include "Khach_hang.h"
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

    void nhapSanPham(vector<SanPham*>& dsSanPham);
    void xoaSanPham(vector<SanPham*>& dsSanPham);
    void dangKyCaLam(string Tens); 
    void hienThiThongTin() const override; 
    void capNhatSanPhamTrongFile(const string& tenSanPham, int soLuongMoi);
    void xoaSanPhamRaKhoiFile(const string& tenSanPham);

    string getHoTen() const;
    Date getNgaySinh() const; 
    string getSdt() const; 
    string getCaLam() const;

    static void docDanhSachNhanVien(vector<NhanVien*>& dsNhanVien);
};

#endif