#ifndef HAMTAOLAO_H
#define HAMTAOLAO_H

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

using namespace std;

void dangNhap(const string& vaiTro);
void dangKy(const string& vaiTro);
void menuKhachHang(KhachHang& khachHang);
void menuNhanVien(NhanVien& nhanVien);
void menuGiamDoc(GiamDoc& giamDoc);

#endif // HAMTAOLAO_H