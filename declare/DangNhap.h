#ifndef DANGNHAP_H
#define DANGNHAP_H

#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Khach_hang.h"
#include "GiamDoc.h"
#include "SanPham.h"
#include "NhanVien.h"
#include "User.h"
#include "Date.h"

using namespace std;

void dangNhap(const string& vaiTro);
void dangKy(const string& vaiTro);
void menuKhachHang(KhachHang& khachHang);
void menuNhanVien(NhanVien& nhanVien);
void menuGiamDoc(GiamDoc& giamDoc);

#endif // DANGNHAP_H