#ifndef GIAMDOC_H
#define GIAMDOC_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "User.h"
#include "SanPham.h" 
#include "NhanVien.h"
#include "Khach_hang.h"
#include "Date.h"
#include "LinkedList.h"
#include <list>
class NhanVien;
class KhachHang;
class SanPham;

class GiamDoc : public User {
public:
    GiamDoc(const string& ten, const string& matKhau);

    void hienThiThongTin() const override;

    void xuatLichLamViec(const vector<NhanVien*>& dsNhanVien) const;
    void xuatThongTinNhanVien();
    void xuatThongTinSanPham();
    void xuatThongTinKhachHang();
};


#endif // GIAMDOC_H
