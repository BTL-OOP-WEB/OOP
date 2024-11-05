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

void GiamDoc::xuatLichLamViec(const vector<NhanVien*>& dsNhanVien) const {
    cout << left << setw(20) << "Ho Ten"
         << setw(15) << "So Dien Thoai"
         << setw(10) << "Lich Lam Viec" << endl;

    cout << setfill('-') << setw(45) << "-" << setfill(' ') << endl;
    cout << setw(20) << " " << setw(15) << " " << "CN T2 T3 T4 T5 T6 T7" << endl;

    for (const auto& nv : dsNhanVien) {
        cout << left << setw(20) << nv->getHoTen()
             << setw(15) << nv->getSdt();

        string lichLamViec = nv->getLichLamViec();
        for (char c : lichLamViec) {
            if (c == '1')
                cout << " S ";
            else if (c == '2')
                cout << " C ";
            else
                cout << " - ";
        }
        cout << endl;
    }
}

void GiamDoc::xuatThongTinNhanVien() {
    vector<NhanVien*> dsNhanVien;
    ifstream inFile("../resources/NhanVien.txt");
    vector<string> lines;

    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string ten, matKhau, lichLamViec, hoTen, temp, sdt;
            int d, m, y;

            ss >> ten >> matKhau >> lichLamViec >> d >> m >> y >> sdt;
            getline(ss, hoTen);
            Date ngaySinh(d, m, y);

            dsNhanVien.push_back(new NhanVien(ten, matKhau, hoTen, ngaySinh, sdt, lichLamViec));
            lines.push_back(line);
        }
        inFile.close();
    } else {
        cout << "Khong the mo file NhanVien.txt!" << endl;
        return;
    }

    cout << left << setw(5) << "STT"
         << setw(20) << "Ho Ten"
         << setw(10) << "Ngay"
         << setw(10) << "Thang"
         << setw(10) << "Nam"
         << setw(15) << "So Dien Thoai" << endl;

    cout << setfill('-') << setw(65) << "-" << setfill(' ') << endl;

    for (size_t i = 0; i < dsNhanVien.size(); ++i) {
        const auto& nv = dsNhanVien[i];
        cout << left << setw(5) << (i + 1)
             << setw(20) << nv->getHoTen()
             << setw(10) << nv->getNgaySinh().getNgay()
             << setw(10) << nv->getNgaySinh().getThang()
             << setw(10) << nv->getNgaySinh().getNam()
             << setw(15) << nv->getSdt() << endl;
    }

    xuatLichLamViec(dsNhanVien);
    
    int option;
    do {
        cout << "\nChon hanh dong:\n\033[38;5;214m~\033[0m 1. Xoa nhan vien\n\033[38;5;214m~\033[0m 2. Quay lai\nNhap lua chon cua ban: ";
        cin >> option;

        switch (option) {
            case 1: {
                int indexToDelete;
                cout << "Nhap so thu tu cua nhan vien can xoa: ";
                cin >> indexToDelete;

                if (indexToDelete > 0 && indexToDelete <= lines.size()) {
                    lines.erase(lines.begin() + indexToDelete - 1);
                    ofstream outFile("../resources/NhanVien.txt", ios::trunc);
                    for (const auto& line : lines) {
                        outFile << line << endl;
                    }
                    outFile.close();
                    cout << "Da xoa nhan vien thanh cong." << endl;
                } else {
                    cout << "So thu tu khong hop le." << endl;
                }
                break;
            }
            case 2:
                cout << "Quay lai menu chinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
                break;
        }
    } while (option != 1 && option != 2);

    for (auto nv : dsNhanVien) {
        delete nv;
    }
    dsNhanVien.clear();
    clearScreen();
}

void GiamDoc::xuatThongTinSanPham() {
    vector<SanPham*> dsSanPham;
    vector<string> lines;
    ifstream file("../resources/input.txt");
    
    if (!file) {
        cout << "Khong the mo file input.txt!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        lines.push_back(line);
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

    cout << left << setw(5) << "STT" 
         << setw(15) << "Loai San Pham" 
         << setw(10) << "So Luong" 
         << setw(20) << "Ten San Pham" 
         << setw(15) << "Gia" << endl;
    cout << setfill('-') << setw(65) << "-" << setfill(' ') << endl;

    int stt = 1;
    for (const auto& sp : dsSanPham) {
        cout << left << setw(5) << stt++  
             << setw(15) << sp->getLoaiSanPham() 
             << setw(10) << sp->getSoLuong() 
             << setw(20) << sp->getTenSanPham() 
             << setw(15) << sp->giaTien << endl;
    }
    cout << endl;

    int option;
    do {
        cout << "\nChon hanh dong:\n\033[38;5;214m~\033[0m 1. Xoa san pham\n\033[38;5;214m~\033[0m 2. Quay lai\nNhap lua chon cua ban: ";
        cin >> option;

        switch (option) {
            case 1: {
                int indexToDelete;
                cout << "Nhap so thu tu cua san pham can xoa: ";
                cin >> indexToDelete;

                if (indexToDelete > 0 && indexToDelete <= lines.size()) {
                    lines.erase(lines.begin() + indexToDelete - 1);
                    ofstream outFile("../resources/input.txt", ios::trunc);
                    for (const auto& line : lines) {
                        outFile << line << endl;
                    }
                    outFile.close();
                    cout << "Da xoa san pham thanh cong." << endl;
                } else {
                    cout << "So thu tu khong hop le." << endl;
                }
                break;
            }
            case 2:
                cout << "Quay lai menu chinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
                break;
        }
    } while (option != 1 && option != 2);

    for (auto sp : dsSanPham) {
        delete sp;
    }
    clearScreen();
}

void GiamDoc::xuatThongTinKhachHang() {
    vector<KhachHang> dsKhachHang; 
    vector<string> lines;

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

        ss >> tenDangNhap >> matKhau >> diemTichLuy >> ngay >> thang >> nam >> sdt;
        getline(ss, hoTen);
        Date ngaySinh(ngay, thang, nam);

        KhachHang kh(tenDangNhap, matKhau, diemTichLuy, hoTen, ngaySinh, sdt);
        dsKhachHang.push_back(kh);
        lines.push_back(line);
    }

    file.close();
    
    cout << left << setw(5) << "STT"
        << setw(20) << "Ho Ten"
        << setw(10) << "Diem TL"
        << setw(10) << "Ngay Sinh"
        << setw(15) << "So Dien Thoai" << endl;

    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

    size_t stt = 1;
    for (const auto& kh : dsKhachHang) {
        cout << left << setw(5) << stt++
            << setw(20) << kh.getHoTen()
            << setw(10) << kh.getDiemTichLuy()
            << setw(2) << kh.getNgaySinh().getNgay() << "/"
            << setw(2) << kh.getNgaySinh().getThang() << "/"
            << setw(6) << kh.getNgaySinh().getNam()
            << setw(15) << kh.getSdt() << endl;
    }
    cout << endl;
    int option;
    do {
        cout << "\nChon hanh dong:\n\033[38;5;214m~\033[0m 1. Xoa khach hang\n\033[38;5;214m~\033[0m 2. Quay lai\nNhap lua chon cua ban: ";
        cin >> option;

        switch (option) {
            case 1: {
                int indexToDelete;
                cout << "Nhap so thu tu cua khach hang can xoa: ";
                cin >> indexToDelete;

                if (indexToDelete > 0 && indexToDelete <= lines.size()) {
                    lines.erase(lines.begin() + indexToDelete - 1);
                    ofstream outFile("../resources/KhachHang.txt", ios::trunc);
                    for (const auto& line : lines) {
                        outFile << line << endl;
                    }
                    outFile.close();
                    cout << "Da xoa khach hang thanh cong." << endl;
                } else {
                    cout << "So thu tu khong hop le." << endl;
                }
                break;
            }
            case 2:
                cout << "Quay lai menu chinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
                break;
        }
    } while (option != 1 && option != 2);
    clearScreen();

}
