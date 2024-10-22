#ifndef DANGNHAP_H
#define DANGNHAP_H

#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "declare/Khach_hang.h"
#include "declare/GiamDoc.h"
#include "declare/SanPham.h"
#include "declare/NhanVien.h"
#include "declare/User.h"

using namespace std;

void dangNhap(const string& vaiTro);
void dangKy(const string& vaiTro);
void menuKhachHang(KhachHang& khachHang);
void menuNhanVien(NhanVien& nhanVien);
void menuGiamDoc(GiamDoc& giamDoc);

#endif // DANGNHAP_H