#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <vector>
#include <string>
#include "User.h"
#include "SanPham.h"
#include "NhanVien.h"

using namespace std;

class KhachHang : public User {
private:
    vector<SanPham*> gioHang;  
    int diemTichLuy;           
    string hoTen;              
    Date ngaySinh;             
    string sdt;                

public:
    KhachHang(const string& ten, const string& matKhau, const int& diemTichLuy, const string& hoTen, const Date& ngaySinh, const string& sdt);

    void themVaoGioHang(SanPham* sanPham, int soLuong);
    void boSanPham(SanPham* sanPham, int soLuong);
    
    void thanhToan();          
    void hienThiGioHang() const;
    void hienThiThongTin() const override; 
    
    void suDungDiem();         
    void xuatHoaDon() const;   
    void muaHang(const vector<SanPham*>& danhSachSanPham);

    SanPham* timSanPhamTrongGioHang(const string& tenSanPham);
    SanPham* timSanPham(const std::string& tenSanPham, const std::vector<SanPham*>& danhSachSanPham) const;
    virtual string getTenSanPham() const;


private:
    void xoaSanPhamRaKhoiFile(const string& tenSanPham);
};

#endif // KHACHHANG_H
