#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>  
#include "../declare/NhanVien.h"
#include "../declare/SanPham.h"
#include "../declare/Khach_hang.h"
#include "../declare/Date.h"

using namespace std;

NhanVien::NhanVien(const string& ten, const string& matKhau, const string& hoTen, const Date& ngaySinh, const string& sdt, const string& lichLamViec)
    : User(ten, matKhau), hoTen(hoTen), ngaySinh(ngaySinh), sdt(sdt), lichLamViec(lichLamViec) {}

string NhanVien::getTenNguoiDung() const {
    return ten;
}

void NhanVien::docDanhSachNhanVien(std::vector<NhanVien*>& dsNhanVien) {
    std::ifstream file("../resources/NhanVien.txt");
    if (!file) {
        std::cerr << "Khong the mo file NhanVien.txt" << std::endl;
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        
        std::string ten, matKhau, lichLamViec, hoTen, sdt;
        int ngay, thang, nam;

        ss >> ten >> matKhau >> lichLamViec >> ngay >> thang >> nam >> sdt;
        getline(ss, hoTen);  

        Date date(ngay, thang, nam);
        NhanVien* nhanVien = new NhanVien(ten, matKhau, hoTen, date, sdt, lichLamViec);
        dsNhanVien.push_back(nhanVien);

        std::cout << "Nhan vien " << nhanVien->getTen() << " da duoc them vao danh sach." << std::endl;
    }

    file.close();
}


int NhanVien::getSoCaDaLam() const {
    int soCaDaLam = 0;
    for (char c : lichLamViec) {
        if (c != '0') {
            soCaDaLam++;
        }
    }
    return soCaDaLam;
}

string NhanVien::getHoTen() const {
    return hoTen;
}

Date NhanVien::getNgaySinh() const {
    return ngaySinh;
}

string NhanVien::getSdt() const {
    return sdt;
}

string NhanVien::getCaLam() const {
    return lichLamViec;
}

void NhanVien::xoaSanPhamRaKhoiFile(const string& tenSanPham) {
    ifstream inputFile("../resources/input.txt");
    vector<string> lines;
    string line;

    while (getline(inputFile, line)) {
        if (line.find(tenSanPham) == string::npos) {
            lines.push_back(line);
        }
    }
    inputFile.close();

    ofstream outputFile("../resources/input.txt");
    for (const string& line : lines) {
        outputFile << line << endl;
    }
    outputFile.close();

}

string NhanVien::getLichLamViec() const {
    return lichLamViec;
}

void NhanVien::capNhatSanPhamTrongFile(const string& tenSanPham, int soLuongMoi) {
    ifstream inputFile("../resources/input.txt");
    vector<string> lines;
    string line;

    while (getline(inputFile, line)) {
        istringstream ss(line);
        string loai, ten;
        int soLuong;
        double gia;

        ss >> loai >> soLuong >> ten >> gia;

        if (ten == tenSanPham) {
            ostringstream updatedLine;
            updatedLine << loai << " " << soLuongMoi << " " << ten << " " << gia;
            lines.push_back(updatedLine.str());
        } else {
            lines.push_back(line);
        }
    }
    inputFile.close();

    ofstream outputFile("../resources/input.txt");
    for (const string& line : lines) {
        outputFile << line << endl;
    }
    outputFile.close();
}

void NhanVien::nhapSanPham(vector<SanPham*>& dsSanPham) {
    int soLuong;
    string loaiSanPham;
    string tenSanPham;
    double giaTien;
    int luaChon;
    cout << " ____________________________________________________________ " << endl;
    cout << "| \033[38;5;214m~\033[0m 1. Kho Thit                            |                 |" << endl;
    cout << "| \033[38;5;214m~\033[0m 2. Kho Ca                              |                 |" << endl;
    cout << "| \033[38;5;214m~\033[0m 3. Kho Keo                             |                 |" << endl;
    cout << "| \033[38;5;214m~\033[0m 4. Kho Nuoc                            |                 |" << endl;
    cout << "| \033[38;5;214m~\033[0m 5. Kho Rau Cu                          |                 |" << endl;
    cout << "| \033[38;5;214m~\033[0m 6. Kho Gia Vi                          |                 |" << endl;
    cout << "| \033[38;5;214m~\033[0m 7. Kho Banh                            |                 |" << endl;
    cout << "| \033[38;5;214m~\033[0m 8. Kho Giay                            |                 |" << endl;
    cout << "| \033[38;5;214m~\033[0m 9. Kho Chen Bat                        |                 |" << endl;
    cout << "| \033[38;5;214m~\033[0m 10. Kho Do Dong Hop                    |                 |" << endl;
    cout << "| \033[38;5;214m~\033[0m 0. Kho lai                             |                 |" << endl;
    cout << "| \033[38;5;214m~\033[0m Chon Kho muon them san pham (1-10):    |                 |" << endl;
    cout << "|__________________________________________|   |W|E|L|C|O|M|E| " << endl;
    cout.flush();
    setCursorPosition(31, 11); 
    cin >> luaChon;
    clearScreen();

    switch (luaChon)
    {
    case 1:
        loaiSanPham="Thit";
        break;
    case 2:
        loaiSanPham="Ca";
        break;
    case 3:
        loaiSanPham="Keo";
        break;
    case 4:
        loaiSanPham="Nuoc";
        break;
    case 5:
        loaiSanPham="RauCu";
        break;
    case 6:
        loaiSanPham="GiaVi";
        break;
    case 7:
        loaiSanPham="Banh";
        break;
    case 8:
        loaiSanPham="Giay";
        break;
    case 9:
        loaiSanPham="ChenBat";
        break;
    case 10:
        loaiSanPham="DoDongHop";
        break;
    default:
        break;
    }
    cout << "Nhap so luong: ";
    cin >> soLuong;
    cout << "Nhap gia tien: ";
    cin >> giaTien;

    SanPham* sanPham = nullptr;
    if (loaiSanPham == "Thit") {
        cout << "Nhap loai thit: ";
        cin >> tenSanPham;
        sanPham = new Thit(soLuong, tenSanPham, giaTien);
    } else if (loaiSanPham == "Ca") {
        cout << "Nhap loai ca: ";
        cin >> tenSanPham;
        sanPham = new Ca(soLuong, tenSanPham, giaTien);
    } else if (loaiSanPham == "Keo") {
        cout << "Nhap loai keo: ";
        cin >> tenSanPham;
        sanPham = new Keo(soLuong, tenSanPham, giaTien);
    } else if (loaiSanPham == "Nuoc") {
        cout << "Nhap loai nuoc: ";
        cin >> tenSanPham;
        sanPham = new Nuoc(soLuong, tenSanPham, giaTien);
    } else if (loaiSanPham == "RauCu") {
        cout << "Nhap loai rau cu: ";
        cin >> tenSanPham;
        sanPham = new RauCu(soLuong, tenSanPham, giaTien);
    } else if (loaiSanPham == "GiaVi") {
        cout << "Nhap loai gia vị: ";
        cin >> tenSanPham;
        sanPham = new GiaVi(soLuong, tenSanPham, giaTien);
    } else if (loaiSanPham == "Banh") {
        cout << "Nhap loai banh: ";
        cin >> tenSanPham;
        sanPham = new Banh(soLuong, tenSanPham, giaTien);
    } else if (loaiSanPham == "Giay") {
        cout << "Nhap loai giay: ";
        cin >> tenSanPham;
        sanPham = new Giay(soLuong, tenSanPham, giaTien);
    } else if (loaiSanPham == "ChenBat") {
        cout << "Nhap loai chen bat: ";
        cin >> tenSanPham;
        sanPham = new ChenBat(soLuong, tenSanPham, giaTien);
    } else if (loaiSanPham == "DoDongHop") {
        cout << "Nhap loai do dong hop: ";
        cin >> tenSanPham;
        sanPham = new DoDongHop(soLuong, tenSanPham, giaTien);
    }

    dsSanPham.push_back(sanPham);
    cout << "San pham da duoc them thanh cong!" << endl;

    ofstream outFile("../resources/input.txt", ios::app);
    if (outFile.is_open()) {
        outFile << loaiSanPham << " " << soLuong << " " << tenSanPham << " " << giaTien << endl;
        outFile.close();
    } else {
        cout << "Khong the mo file de ghi!" << endl;
    }
}

void NhanVien::xoaSanPham(vector<SanPham*>& dsSanPham) {
    int luaChon1;
    cout << "Chon cach xoa san pham: (1) Xoa theo so luong, (2) Xoa luon san pham: ";
    cin >> luaChon1;
    string loaiSanPham;

    if (luaChon1 == 1) {
        int luaChonKho;

        do {
            cout << " ___________________________________________________________ " << endl;
            cout << "| \033[38;5;214m~\033[0m 1. Kho Thit                           |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m 2. Kho Ca                             |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m 3. Kho Keo                            |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m 4. Kho Nuoc                           |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m 5. Kho Rau Cu                         |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m 6. Kho Gia Vi                         |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m 7. Kho Banh                           |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m 8. Kho Giay                           |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m 9. Kho Chen Bat                       |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m 10. Kho Do Dong Hop                   |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m 0. Kho lai                            |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m Chon Kho muon xoa san pham (1-10):    |                 |" << endl;
            cout << "|_________________________________________|   |W|E|L|C|O|M|E| " << endl;

            cout.flush();
            setCursorPosition(31, 11); 
            cin >> luaChonKho;
            clearScreen();

            vector<SanPham*> sanPhamThit;
            vector<SanPham*> sanPhamCa;
            vector<SanPham*> sanPhamKeo;
            vector<SanPham*> sanPhamNuoc;
            vector<SanPham*> sanPhamRauCu;
            vector<SanPham*> sanPhamGiaVi;
            vector<SanPham*> sanPhamBanh;
            vector<SanPham*> sanPhamGiay;
            vector<SanPham*> sanPhamChenBat;
            vector<SanPham*> sanPhamDoDongHop;
            int index = 1;
            int luaChonSanPham; 
            int soLuong; 

            switch (luaChonKho) {
                case 1: 
                    cout << "Ban da chon Kho Thit. Cac san pham co san:" << endl;      
                    for (const auto& sp : dsSanPham) {
                        if (sp->getLoaiSanPham() == "Thit") {
                            cout << "_______________________" << endl;
                            cout << "| \033[38;5;214m~\033[0m " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                            cout << "_______________________" << endl;
                            sanPhamThit.push_back(sp);
                            index++;
                        }
                    }

                    cout << "Nhap so thu tu san pham muon xoa (0 de Kho lai): ";
                    cin >> luaChonSanPham;

                    if (luaChonSanPham > 0 && luaChonSanPham <= sanPhamThit.size()) {
                        cout << "Nhap so luong muon xoa: ";
                        cin >> soLuong;
                        capNhatSanPhamTrongFile(sanPhamThit[luaChonSanPham - 1]->getTenSanPham(), soLuong);
                    } else if (luaChonSanPham != 0) {
                        cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                    }
                    break;


                case 2:              
                    cout << "Ban da chon Kho Ca. Cac san pham co san:" << endl;
                    for (const auto& sp : dsSanPham) {
                        if (sp->getLoaiSanPham() == "Ca") {
                            cout << "_________________________" << endl;
                            cout << "| \033[38;5;214m~\033[0m " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                            cout << "_________________________" << endl;
                            sanPhamCa.push_back(sp);
                            index++;
                        }
                    }

                    cout << "Nhap so thu tu san pham muon xoa (0 de Kho lai): ";
                    cin >> luaChonSanPham;

                    if (luaChonSanPham > 0 && luaChonSanPham <= sanPhamCa.size()) {
                        cout << "Nhap so luong muon xoa: ";
                        cin >> soLuong;
                        capNhatSanPhamTrongFile(sanPhamCa[luaChonSanPham - 1]->getTenSanPham(), soLuong);
                        cout << "San pham da duoc them vao gio hang!" << endl;
                    } else if (luaChonSanPham != 0) {
                        cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                    }
                    break;
            
                case 3: 
                    cout << "Ban da chon Kho Keo. Cac san pham co san:" << endl;
                    for (const auto& sp : dsSanPham) {
                        if (sp->getLoaiSanPham() == "Keo") {
                            cout << "_________________________" << endl;
                            cout << "| \033[38;5;214m~\033[0m " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                            cout << "_________________________" << endl;
                            sanPhamKeo.push_back(sp);
                            index++;
                        }
                    }

                    cout << "Nhap so thu tu san pham muon xoa (0 de Kho lai): ";
                    cin >> luaChonSanPham;

                    if (luaChonSanPham > 0 && luaChonSanPham <= sanPhamKeo.size()) {
                        cout << "Nhap so luong muon xoa: ";
                        cin >> soLuong;
                        capNhatSanPhamTrongFile(sanPhamKeo[luaChonSanPham - 1]->getTenSanPham(), soLuong);
                        cout << "San pham da duoc them vao gio hang!" << endl;
                    } else if (luaChonSanPham != 0) {
                        cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                    }
                    break;
                case 4: 
                    cout << "Ban da chon Kho Nuoc. Cac san pham co san:" << endl;
                    for (const auto& sp : dsSanPham) {
                        if (sp->getLoaiSanPham() == "Nuoc") {
                            cout << "_________________________" << endl;
                            cout << "| \033[38;5;214m~\033[0m " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                            cout << "_________________________" << endl;
                            sanPhamNuoc.push_back(sp);
                            index++;
                        }
                    }

                    cout << "Nhap so thu tu san pham muon xoa (0 de Kho lai): ";
                    cin >> luaChonSanPham;

                    if (luaChonSanPham > 0 && luaChonSanPham <= sanPhamNuoc.size()) {
                        cout << "Nhap so luong muon xoa: ";
                        cin >> soLuong;
                        capNhatSanPhamTrongFile(sanPhamNuoc[luaChonSanPham - 1]->getTenSanPham(), soLuong);
                        cout << "San pham da duoc them vao gio hang!" << endl;
                    } else if (luaChonSanPham != 0) {
                        cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                    }
                    break;

                case 5: 
                    cout << "Ban da chon Kho Rau Cu. Cac san pham co san:" << endl;
                    for (const auto& sp : dsSanPham) {
                        if (sp->getLoaiSanPham() == "RauCu") {
                            cout << "_________________________" << endl;
                            cout << "| \033[38;5;214m~\033[0m " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                            cout << "_________________________" << endl;
                            sanPhamRauCu.push_back(sp);
                            index++;
                        }
                    }

                    cout << "Nhap so thu tu san pham muon xoa (0 de Kho lai): ";
                    cin >> luaChonSanPham;

                    if (luaChonSanPham > 0 && luaChonSanPham <= sanPhamRauCu.size()) {
                        cout << "Nhap so luong muon xoa: ";
                        cin >> soLuong;
                        capNhatSanPhamTrongFile(sanPhamRauCu[luaChonSanPham - 1]->getTenSanPham(), soLuong);
                        cout << "San pham da duoc them vao gio hang!" << endl;
                    } else if (luaChonSanPham != 0) {
                        cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                    }
                    break;
                case 6: 
                    cout << "Ban da chon Kho Gia Vi. Cac san pham co san:" << endl;
                    for (const auto& sp : dsSanPham) {
                        if (sp->getLoaiSanPham() == "GiaVi") {
                            cout << "_________________________" << endl;
                            cout << "| \033[38;5;214m~\033[0m " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                            cout << "_________________________" << endl;
                            sanPhamGiaVi.push_back(sp);
                            index++;
                        }
                    }

                    cout << "Nhap so thu tu san pham muon xoa (0 de Kho lai): ";
                    cin >> luaChonSanPham;

                    if (luaChonSanPham > 0 && luaChonSanPham <= sanPhamGiaVi.size()) {
                        cout << "Nhap so luong muon xoa: ";
                        cin >> soLuong;
                        capNhatSanPhamTrongFile(sanPhamGiaVi[luaChonSanPham - 1]->getTenSanPham(), soLuong);
                        cout << "San pham da duoc them vao gio hang!" << endl;
                    } else if (luaChonSanPham != 0) {
                        cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                    }
                    break;
                case 7: 
                    cout << "Ban da chon Kho Banh. Cac san pham co san:" << endl;
                    for (const auto& sp : dsSanPham) {
                        if (sp->getLoaiSanPham() == "Banh") {
                            cout << "_________________________" << endl;
                            cout << "| \033[38;5;214m~\033[0m " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                            cout << "_________________________" << endl;
                            sanPhamBanh.push_back(sp);
                            index++;
                        }
                    }

                    cout << "Nhap so thu tu san pham muon xoa (0 de Kho lai): ";
                    cin >> luaChonSanPham;

                    if (luaChonSanPham > 0 && luaChonSanPham <= sanPhamBanh.size()) {
                        cout << "Nhap so luong muon xoa: ";
                        cin >> soLuong;
                        capNhatSanPhamTrongFile(sanPhamBanh[luaChonSanPham - 1]->getTenSanPham(), soLuong);
                        cout << "San pham da duoc them vao gio hang!" << endl;
                    } else if (luaChonSanPham != 0) {
                        cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                    }
                    break;
                case 8: 
                    cout << "Ban da chon Kho Giay. Cac san pham co san:" << endl;
                    for (const auto& sp : dsSanPham) {
                        if (sp->getLoaiSanPham() == "Giay") {
                            cout << "_________________________" << endl;
                            cout << "| \033[38;5;214m~\033[0m " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                            cout << "_________________________" << endl;
                            sanPhamGiay.push_back(sp);
                            index++;
                        }
                    }

                    cout << "Nhap so thu tu san pham muon xoa (0 de Kho lai): ";
                    cin >> luaChonSanPham;

                    if (luaChonSanPham > 0 && luaChonSanPham <= sanPhamGiay.size()) {
                        cout << "Nhap so luong muon xoa: ";
                        cin >> soLuong;
                        capNhatSanPhamTrongFile(sanPhamGiay[luaChonSanPham - 1]->getTenSanPham(), soLuong);
                        cout << "San pham da duoc them vao gio hang!" << endl;
                    } else if (luaChonSanPham != 0) {
                        cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                    }
                    break;
                case 9: 
                    cout << "Ban da chon Kho Chen Bat. Cac san pham co san:" << endl;
                    for (const auto& sp : dsSanPham) {
                        if (sp->getLoaiSanPham() == "ChenBat") {
                            cout << "_________________________" << endl;
                            cout << "| \033[38;5;214m~\033[0m " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                            cout << "_________________________" << endl;
                            sanPhamChenBat.push_back(sp);
                            index++;
                        }
                    }

                    cout << "Nhap so thu tu san pham muon xoa (0 de Kho lai): ";
                    cin >> luaChonSanPham;

                    if (luaChonSanPham > 0 && luaChonSanPham <= sanPhamChenBat.size()) {
                        cout << "Nhap so luong muon xoa: ";
                        cin >> soLuong;
                        capNhatSanPhamTrongFile(sanPhamChenBat[luaChonSanPham - 1]->getTenSanPham(), soLuong);
                        cout << "San pham da duoc them vao gio hang!" << endl;
                    } else if (luaChonSanPham != 0) {
                        cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                    }
                    break;
                case 10: 
                    cout << "Ban da chon Kho Do Dong Hop. Cac san pham co san:" << endl;
                    for (const auto& sp : dsSanPham) {
                        if (sp->getLoaiSanPham() == "DoDongHop") {
                            cout << "_________________________" << endl;
                            cout << "| \033[38;5;214m~\033[0m " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                            cout << "_________________________" << endl;
                            sanPhamDoDongHop.push_back(sp);
                            index++;
                        }
                    }

                    cout << "Nhap so thu tu san pham muon xoa (0 de Kho lai): ";
                    cin >> luaChonSanPham;

                    if (luaChonSanPham > 0 && luaChonSanPham <= sanPhamDoDongHop.size()) {
                        cout << "Nhap so luong muon xoa: ";
                        cin >> soLuong;
                        capNhatSanPhamTrongFile(sanPhamDoDongHop[luaChonSanPham - 1]->getTenSanPham(), soLuong);
                        cout << "San pham da duoc them vao gio hang!" << endl;
                    } else if (luaChonSanPham != 0) {
                        cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                    }
                    break;
                case 0: continue;
                default:
                    cout << "Lua chon khong hop le! Vui long chon lai." << endl;
                    continue;
        
    }
    }while (luaChonKho != 0);
    }

     else if (luaChon1 == 2) {
            int luaChon;
            cout << " __________________________________________________ " << endl;
            cout << "| \033[38;5;214m~\033[0m 1. Kho Thit                  |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m 2. Kho Ca                    |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m 3. Kho Keo                   |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m 4. Kho Nuoc                  |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m 5. Kho Rau Cu                |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m 6. Kho Gia Vi                |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m 7. Kho Banh                  |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m 8. Kho Giay                  |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m 9. Kho Chen Bat              |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m 10. Kho Do Dong Hop          |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m 0. Kho lai                   |                 |" << endl;
            cout << "| \033[38;5;214m~\033[0m Chon Kho muon mua (1-10):    |                 |" << endl;
            cout << "|________________________________|   |W|E|L|C|O|M|E| " << endl;
            cout.flush();
            setCursorPosition(31, 11); 
            cin >> luaChon;

            switch (luaChon)
            {
            case 1:
                loaiSanPham="Thit";
                break;
            case 2:
                loaiSanPham="Ca";
                break;
            case 3:
                loaiSanPham="Keo";
                break;
            case 4:
                loaiSanPham="Nuoc";
                break;
            case 5:
                loaiSanPham="RauCu";
                break;
            case 6:
                loaiSanPham="GiaVi";
                break;
            case 7:
                loaiSanPham="Banh";
                break;
            case 8:
                loaiSanPham="Giay";
                break;
            case 9:
                loaiSanPham="ChenBat";
                break;
            case 10:
                loaiSanPham="DoDongHop";
                break;
            default:
                break;
            }

            bool found = false;
            for (size_t i = 0; i < dsSanPham.size(); ++i) {
                if (dsSanPham[i]->getTenSanPham() == loaiSanPham) {
                    found = true;
                    this->xoaSanPhamRaKhoiFile(loaiSanPham);
                    delete dsSanPham[i];
                    dsSanPham.erase(dsSanPham.begin() + i);
                    cout << "San pham da duoc xoa khoi kho va file." << endl;
                    break;
                }
            }

            if (!found) {
                cout << "San pham khong ton tai trong danh sach." << endl;
            }
            
}
}


void NhanVien::dangKyCaLam(string Tens) {
    lichLamViec = "0000000"; 

    cout << "Dang ky lich lam viec cho tung ngay trong tuan:" << endl;
    const string ngayTrongTuan[7] = {"Chu Nhat", "Thu Hai", "Thu Ba", "Thu Tu", "Thu Nam", "Thu Sau", "Thu Bay"};

    int ngay = 0;

    while (ngay < 7) {
        bool validInput = false;

        while (!validInput) {
            cout << ngayTrongTuan[ngay] << ": " << endl;
            cout << "1. Ca sang" << endl;
            cout << "2. Ca chieu" << endl;
            cout << "3. Khong lam" << endl;
            cout << "4. Quay lai ngay truoc do" << endl;
            cout << "Lua chon cua ban (1-4): ";

            int luaChon;
            cin >> luaChon;

            switch (luaChon) {
                case 1:
                    lichLamViec[ngay] = '1'; 
                    cout << "Ban da chon lam ca sang." << endl;
                    validInput = true;
                    ngay++;
                    break;
                case 2:
                    lichLamViec[ngay] = '2'; 
                    cout << "Ban da chon lam ca chieu." << endl;
                    validInput = true;
                    ngay++;
                    break;
                case 3:
                    lichLamViec[ngay] = '0'; 
                    cout << "Ban da chon khong lam viec ngay nay." << endl;
                    validInput = true;
                    ngay++;
                    break;
                case 4:
                    if (ngay > 0) {
                        ngay--; 
                    } else {
                        cout << "Ban dang o ngay dau tien, khong the quay lai." << endl;
                    }
                    validInput = true;
                    break;
                default:
                    cout << "Lua chon khong hop le! Vui long nhap lai." << endl;
            }
        }
    }

    ifstream inputFile("../resources/NhanVien.txt");
    vector<string> lines;
    string line;

    while (getline(inputFile, line)) {
        istringstream ss(line);
        string ten, matKhau, lichcu, hoTen, sdt;
        int ngay, thang, nam;
        double gia;

        ss >> ten >> matKhau >> lichcu >> ngay >> thang >> nam >> sdt;
        getline(ss, hoTen);
        Date ngaySinh(ngay, thang, nam);

        if (ten == Tens) {
            ostringstream updatedLine;
            updatedLine << ten << " " << matKhau << " " << lichLamViec << " " << ngaySinh.getNgay() << " " << ngaySinh.getThang() << " " << ngaySinh.getNam() << " " << sdt << " " << hoTen;
            lines.push_back(updatedLine.str());
        } else {
            lines.push_back(line);
        }
    }
    inputFile.close();

    ofstream outputFile("../resources/NhanVien.txt");
    for (const string& line : lines) {
        outputFile << line << endl;
    }
    outputFile.close();

}

void NhanVien::hienThiThongTin() const {
    cout << "Ho ten: " << hoTen << endl;
    cout << "Ngay sinh: " << ngaySinh.getNgay() << "/" << ngaySinh.getThang() << "/" << ngaySinh.getNam() << endl;
    cout << "So dien thoai: " << sdt << endl;
    cout << "Lich lam viec: " << lichLamViec << endl;
}

