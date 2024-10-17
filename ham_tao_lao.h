#ifndef HAMTAOLAO_H
#define HAMTAOLAO_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Khach_hang.h"
#include "GiamDoc.h"
#include "NhanVien.h"
#include "SanPham.h"
#include "User.h"

using namespace std;

void dangNhap(const string& vaiTro);
void dangKy(const string& vaiTro);
void menuKhachHang(KhachHang& khachHang);
void menuNhanVien(NhanVien& nhanVien);
void menuGiamDoc(GiamDoc& giamDoc);

#endif // HAMTAOLAO_H