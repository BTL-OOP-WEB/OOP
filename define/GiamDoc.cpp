#include "../declare/GiamDoc.h"
#include "../declare/SanPham.h"
#include "../declare/Khach_hang.h"
#include "../declare/NhanVien.h"
#include "../declare/Date.h"
#include <iostream>
#include <iomanip>
#include <fstream>

GiamDoc::GiamDoc(const string& ten, const string& matKhau) : User(ten, matKhau) {};

void GiamDoc::hienThiThongTin() const {
    cout << "Thông tin Giám đốc: ..." << endl;
}

void GiamDoc::xuatThongTinNhanVien() {
    vector<NhanVien*> dsNhanVien;
    ifstream inFile("../resources/NhanVien.txt");

    if (inFile.is_open()) {
        string line;

        while (getline(inFile, line)) {
            stringstream ss(line);
            string ten, matKhau, lichLamViec, hoTen, temp, sdt;
            int d, m, y;

            ss >> ten >> matKhau >> lichLamViec;

            hoTen.clear();
            while (ss >> temp) {
                if (isdigit(temp[0])) {
                    ss.putback(temp[0]);
                    break;
                }
                if (!hoTen.empty()) hoTen += " ";
                hoTen += temp;
            }

            ss >> d >> m >> y >> sdt;
            Date ngaySinh(d, m, y);
            dsNhanVien.push_back(new NhanVien(ten, matKhau, hoTen, ngaySinh, sdt, lichLamViec));
        }
        inFile.close();
    } else {
        cout << "Không thể mở file NhanVien.txt!" << endl;
    }

    cout << left << setw(20) << "Ho Ten"
         << setw(10) << "Ngay"
         << setw(10) << "Thang"
         << setw(10) << "Nam"
         << setw(15) << "So Dien Thoai" << endl;

    cout << setfill('-') << setw(65) << "-" << setfill(' ') << endl;

    for (const auto& nv : dsNhanVien) {
        cout << left << setw(20) << nv->getHoTen()
             << setw(10) << nv->getNgaySinh().getNgay()
             << setw(10) << nv->getNgaySinh().getThang()
             << setw(10) << nv->getNgaySinh().getNam()
             << setw(15) << nv->getSdt() << endl;
    }
    
    for (auto nv : dsNhanVien) {
        delete nv;
    }
    dsNhanVien.clear();
}



void GiamDoc::xuatThongTinSanPham() {
    vector<SanPham*> dsSanPham; 

    ifstream file("../resources/input.txt");
    if (!file) {
        cout << "Khong the mo file input.txt!" << endl;
        return; 
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string loaiSanPham, tenSanPham;
        int soLuong;
        double gia;

        ss >> loaiSanPham >> soLuong >> tenSanPham >> gia;

        SanPham* sanPham = nullptr; 
        if (loaiSanPham == "Thit") {
            sanPham = new Thit(soLuong, tenSanPham, gia);
        } else if (loaiSanPham == "Ca") {
            sanPham = new Ca(soLuong, tenSanPham, gia);
        } else if (loaiSanPham == "Keo") {
            sanPham = new Keo(soLuong, tenSanPham, gia);
        } else if (loaiSanPham == "Nuoc") {
            sanPham = new Nuoc(soLuong, tenSanPham, gia);
        } else if (loaiSanPham == "RauCu") {
            sanPham = new RauCu(soLuong, tenSanPham, gia);
        } else if (loaiSanPham == "GiaVi") {
            sanPham = new GiaVi(soLuong, tenSanPham, gia);
        } else if (loaiSanPham == "Banh") {
            sanPham = new Banh(soLuong, tenSanPham, gia);
        } else if (loaiSanPham == "Giay") {
            sanPham = new Giay(soLuong, tenSanPham, gia);
        } else if (loaiSanPham == "ChenBat") {
            sanPham = new ChenBat(soLuong, tenSanPham, gia);
        } else if (loaiSanPham == "DoDongHop") {
            sanPham = new DoDongHop(soLuong, tenSanPham, gia);
        } else {
            cout << "Loai san pham khong hop le: " << loaiSanPham << endl;
            continue; 
        }

        dsSanPham.push_back(sanPham); 
    }

    file.close();

    cout << left << setw(15) << "Loai San Pham" 
         << setw(10) << "So Luong" 
         << setw(20) << "Ten San Pham" 
         << setw(15) << "Gia" << endl;

    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

    for (const auto& sp : dsSanPham) {
        cout << left << setw(15) << sp->getLoaiSanPham() 
             << setw(10) << sp->getSoLuong() 
             << setw(20) << sp->getTenSanPham() 
             << setw(15) << sp->giaTien << endl; 
    }
    cout << endl;

    for (auto sp : dsSanPham) {
        delete sp; 
    }
}



void GiamDoc::xuatThongTinKhachHang() {
    vector<KhachHang> dsKhachHang; 

    ifstream file("../resources/KhachHang.txt");
    if (!file) {
        cout << "Khong the mo file KhachHang.txt!" << endl;
        return; 
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string tenDangNhap, matKhau, hoTen, temp, sdt;
        int diemTichLuy, ngay, thang, nam;

        ss >> tenDangNhap >> matKhau >> diemTichLuy;

        hoTen.clear();
        while (ss >> temp) {
            if (isdigit(temp[0])) {
                ss.putback(temp[0]);
                break;
            }
            if (!hoTen.empty()) hoTen += " ";
            hoTen += temp;
        }

        ss >> ngay >> thang >> nam >> sdt;
        Date ngaySinh(ngay, thang, nam);

        KhachHang kh(tenDangNhap, matKhau, diemTichLuy, hoTen, ngaySinh, sdt);
        dsKhachHang.push_back(kh);
    }

    file.close();
    
    cout << left << setw(20) << "Ho Ten"
         << setw(10) << "Diem TL"
         << setw(10) << "Ngay Sinh"
         << setw(15) << "So Dien Thoai" << endl;

    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

    for (const auto& kh : dsKhachHang) {
        cout << left << setw(20) << kh.getHoTen()
             << setw(10) << kh.getDiemTichLuy()
             << setw(2) << kh.getNgaySinh().getNgay() << "/"
             << setw(2) << kh.getNgaySinh().getThang() << "/"
             << setw(6) << kh.getNgaySinh().getNam()
             << setw(15) << kh.getSdt() << endl;
    }
    cout << endl;
}
