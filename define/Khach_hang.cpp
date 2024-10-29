#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "../declare/Khach_hang.h"
#include "../declare/SanPham.h"

using namespace std;

KhachHang::KhachHang(const string& ten, const string& matKhau, const int& diemTichLuy, const string& hoTen, const Date& ngaySinh, const string& sdt) 
    : User(ten, matKhau), diemTichLuy(diemTichLuy), hoTen(hoTen), ngaySinh(ngaySinh), sdt(sdt) {}

void KhachHang::themVaoGioHang(SanPham* sanPham, int soLuong) {
    bool sanPhamTonTai = false;

    for (auto& sp : gioHang) {
        if (sp->getTenSanPham() == sanPham->getTenSanPham()) {
            sp->themSanPhamVaoDoHang(soLuong);
            sanPhamTonTai = true;
            break;
        }
    }

    if (!sanPhamTonTai) {
        SanPham* spMoi = sanPham->taoSanPham(); // Gọi hàm taoSanPham từ lớp con
        spMoi->setSoLuong(soLuong);
        gioHang.push_back(spMoi);
    }

    cout << "Đã thêm " << soLuong << " sản phẩm vào giỏ hàng." << endl;
}

void KhachHang::xoaSanPhamRaKhoiFile(const string& tenSanPham) {
    ifstream inputFile("SanPham.txt");
    vector<string> lines;
    string line;

    while (getline(inputFile, line)) {
        if (line.find(tenSanPham) == string::npos) {
            lines.push_back(line);
        }
    }
    inputFile.close();

    ofstream outputFile("SanPham.txt");
    for (const string& line : lines) {
        outputFile << line << endl;
    }
    outputFile.close();

    cout << "San pham '" << tenSanPham << "' da duoc xoa khoi file." << endl;
}


void KhachHang::thanhToan() {
    double tongTien = 0.0;
    cout << "================= Hoa Don Thanh Toan =================" << endl;
    cout << setw(25) << left << "San Pham" << setw(15) << "So Luong" << setw(15) << "Gia Tien" << endl;
    cout << "------------------------------------------------------" << endl;

    for (auto& sp : gioHang) {
        sp->inThongTin();
        tongTien += sp->giaTien;
    }

    cout << "------------------------------------------------------" << endl;
    cout << "Tong tien truoc khi ap dung giam gia: " << tongTien << " VND" << endl;
    suDungDiem();
    cout << "Tong tien can thanh toan: " << tongTien << " VND" << endl;

    int diemThem = tongTien / 100000;
    diemTichLuy += diemThem;
    cout << "Ban da tich them: " << diemThem << " diem" << endl;
    cout << "------------------------------------------------------" << endl;

    for (auto& sp : gioHang) {
        if (sp->getSoLuong() > 0) {
            sp->setSoLuong(sp->getSoLuong() - 1);
            if (sp->getSoLuong() == 0) {
                xoaSanPhamRaKhoiFile(sp->getTenSanPham());
            } else {
                capNhatSanPhamTrongFile(sp->getTenSanPham(), sp->getSoLuong());
            }
        }
    }

    xuatHoaDon();
    gioHang.clear();
    cout << "Da thanh toan thanh cong. Cam on ban da mua sam!" << endl;
    cout << "=====================================================" << endl;
}

void KhachHang::capNhatSanPhamTrongFile(const string& tenSanPham, int soLuongMoi) {
    ifstream inputFile("SanPham.txt");
    vector<string> lines;
    string line;

    while (getline(inputFile, line)) {
        if (line.find(tenSanPham) != string::npos) {
            istringstream ss(line);
            string ten, loai;
            double gia;
            ss >> ten >> loai >> gia;
            ostringstream updatedLine;
            updatedLine << ten << " " << loai << " " << gia << " " << soLuongMoi;
            lines.push_back(updatedLine.str());
        } else {
            lines.push_back(line);
        }
    }
    inputFile.close();

    ofstream outputFile("SanPham.txt");
    for (const string& line : lines) {
        outputFile << line << endl;
    }
    outputFile.close();

    cout << "San pham '" << tenSanPham << "' da duoc cap nhat trong file." << endl;
}


void KhachHang::suDungDiem() {
    if (diemTichLuy > 0) {
        cout << "Ban co " << diemTichLuy << " diem. Ban co muon su dung diem de giam gia khong? (1: Co, 0: Khong): ";
        int luaChon;
        cin >> luaChon;

        if (luaChon == 1) {
            double giamGia = diemTichLuy * 1000;
            cout << "Ban da giam: " << giamGia << " VND tu diem tich luy." << endl;
            diemTichLuy = 0;
        }
    } else {
        cout << "Ban khong co diem tich luy de su dung." << endl;
    }
}

void KhachHang::hienThiGioHang() {
    cout << "===============================" << endl;
    cout << "          Gio hang cua ban     " << endl;
    cout << "===============================" << endl;
    
    int index = 1;
    for (auto& sp : gioHang) {
        cout << "San pham " << index++ << ":" << endl;
        sp->inThongTin();
        cout << "-------------------------------" << endl;
    }

    bool tiepTuc = true;
    while (tiepTuc) {
        cout << "\nLua chon cua ban:" << endl;
        cout << "1. Bo san pham khoi gio hang" << endl;
        cout << "2. Quay lai de tiep tuc" << endl;
        cout << "Nhap lua chon (1-2): ";
        
        int luaChon;
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                cout << "Nhap so thu tu san pham can bo: ";
                int spIndex;
                cin >> spIndex;
                
                if (spIndex > 0 && spIndex <= gioHang.size()) {
                    SanPham* sp = gioHang[spIndex - 1];
                    int soLuongHienTai = sp->getSoLuong();
                    
                    if (soLuongHienTai > 1) {
                        sp->setSoLuong(soLuongHienTai - 1);
                        cout << "So luong san pham da giam xuong " << soLuongHienTai - 1 << "." << endl;
                    } else {
                        gioHang.erase(gioHang.begin() + spIndex - 1);
                        cout << "San pham da duoc xoa khoi gio hang do so luong = 0." << endl;
                    }
                    
                    cout << "===============================" << endl;
                    cout << "          Gio hang cua ban     " << endl;
                    cout << "===============================" << endl;
                    
                    int idx = 1;
                    for (auto& sp : gioHang) {
                        cout << "San pham " << idx++ << ":" << endl;
                        sp->inThongTin();
                        cout << "-------------------------------" << endl;
                    }
                } else {
                    cout << "So thu tu khong hop le." << endl;
                }
                break;
            }
            case 2:
                tiepTuc = false;
                break;
            default:
                cout << "Lua chon khong hop le." << endl;
        }
    }
}

void KhachHang::hienThiThongTin() const {
    cout << "Ten khach hang: " << getTen() << endl;
    cout << "Diem tich luy: " << diemTichLuy << endl;
}

void KhachHang::xuatHoaDon() const {
    cout << "Hoa don cua ban:" << endl;
    for (auto& sp : gioHang) {
        sp->inThongTin();
    }
    cout << "Cam on ban da mua sam tai cua hang!" << endl;
}

SanPham* KhachHang::timSanPhamTrongGioHang(const string& tenSanPham) {
    for (SanPham* sanPham : gioHang) {
        if (sanPham->getTenSanPham() == tenSanPham) {
            return sanPham;
        }
    }
    return nullptr;
}

string KhachHang::getTenSanPham() const {
    return "Ten khach hang: " + getTen();
}

SanPham* KhachHang::timSanPham(const string& tenSanPham, const vector<SanPham*>& danhSachSanPham) const {
    for (auto& sanPham : danhSachSanPham) {
        if (sanPham->getTenSanPham() == tenSanPham) {
            return sanPham;
        }
    }
    return nullptr;
}


void KhachHang::muaHang(const vector<SanPham*>& danhSachSanPham) {
    int luaChonQuay;

    do {
        cout << " _________________________________________ " << endl;
        cout << "| 1. Quay Thit          |                 |" << endl;
        cout << "| 2. Quay Ca            |                 |" << endl;
        cout << "| 3. Quay Keo           |                 |" << endl;
        cout << "| 4. Quay Nuoc          |                 |" << endl;
        cout << "| 5. Quay Rau Cu        |                 |" << endl;
        cout << "| 6. Quay Gia Vi        |                 |" << endl;
        cout << "| 7. Quay Banh          |                 |" << endl;
        cout << "| 8. Quay Giay          |                 |" << endl;
        cout << "| 9. Quay Chen Bat      |                 |" << endl;
        cout << "| 10. Quay Do Dong Hop  |                 |" << endl;
        cout << "| 0. Quay lai          |                 |" << endl;
        cout << "|_______________________|   |W|E|L|C|O|M|E| " << endl;

        cout << "Chon quay muon mua (1-10): ";
        cin >> luaChonQuay;

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

        switch (luaChonQuay) {
            case 1: 
                cout << "Ban da chon Quay Thit. Cac san pham co san:" << endl;      
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "Thit") {
                        cout << "_____________________" << endl;
                        cout << "| " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_____________________" << endl;
                        sanPhamThit.push_back(sp);
                        index++;
                    }
                }

                cout << "Nhap so thu tu san pham muon mua (0 de quay lai): ";
                cin >> luaChonSanPham;

                if (luaChonSanPham > 0 && luaChonSanPham <= sanPhamThit.size()) {
                    cout << "Nhap so luong muon mua: ";
                    cin >> soLuong;
                    themVaoGioHang(sanPhamThit[luaChonSanPham - 1], soLuong);
                    cout << "San pham da duoc them vao gio hang!" << endl;
                } else if (luaChonSanPham != 0) {
                    cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                }
                break;


            case 2:              
                cout << "Ban da chon Quay Ca. Cac san pham co san:" << endl;
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "Ca") {
                        cout << "_____________________" << endl;
                        cout << "| " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_____________________" << endl;
                        sanPhamCa.push_back(sp);
                        index++;
                    }
                }

                cout << "Nhap so thu tu san pham muon mua (0 de quay lai): ";
                cin >> luaChonSanPham;

                if (luaChonSanPham > 0 && luaChonSanPham <= sanPhamCa.size()) {
                    cout << "Nhap so luong muon mua: ";
                    cin >> soLuong;
                    themVaoGioHang(sanPhamCa[luaChonSanPham - 1], soLuong);
                    cout << "San pham da duoc them vao gio hang!" << endl;
                } else if (luaChonSanPham != 0) {
                    cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                }
                break;
        
            case 3: 
                cout << "Ban da chon Quay Keo. Cac san pham co san:" << endl;
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "Keo") {
                        cout << "_____________________" << endl;
                        cout << "| " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_____________________" << endl;
                        sanPhamKeo.push_back(sp);
                        index++;
                    }
                }

                cout << "Nhap so thu tu san pham muon mua (0 de quay lai): ";
                cin >> luaChonSanPham;

                if (luaChonSanPham > 0 && luaChonSanPham <= sanPhamKeo.size()) {
                    cout << "Nhap so luong muon mua: ";
                    cin >> soLuong;
                    themVaoGioHang(sanPhamKeo[luaChonSanPham - 1], soLuong);
                    cout << "San pham da duoc them vao gio hang!" << endl;
                } else if (luaChonSanPham != 0) {
                    cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                }
                break;
            case 4: 
                cout << "Ban da chon Quay Nuoc. Cac san pham co san:" << endl;
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "Nuoc") {
                        cout << "_____________________" << endl;
                        cout << "| " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_____________________" << endl;
                        sanPhamNuoc.push_back(sp);
                        index++;
                    }
                }

                cout << "Nhap so thu tu san pham muon mua (0 de quay lai): ";
                cin >> luaChonSanPham;

                if (luaChonSanPham > 0 && luaChonSanPham <= sanPhamNuoc.size()) {
                    cout << "Nhap so luong muon mua: ";
                    cin >> soLuong;
                    themVaoGioHang(sanPhamNuoc[luaChonSanPham - 1], soLuong);
                    cout << "San pham da duoc them vao gio hang!" << endl;
                } else if (luaChonSanPham != 0) {
                    cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                }
                break;

            case 5: 
                cout << "Ban da chon Quay Rau Cu. Cac san pham co san:" << endl;
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "RauCu") {
                        cout << "_____________________" << endl;
                        cout << "| " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_____________________" << endl;
                        sanPhamRauCu.push_back(sp);
                        index++;
                    }
                }

                cout << "Nhap so thu tu san pham muon mua (0 de quay lai): ";
                cin >> luaChonSanPham;

                if (luaChonSanPham > 0 && luaChonSanPham <= sanPhamRauCu.size()) {
                    cout << "Nhap so luong muon mua: ";
                    cin >> soLuong;
                    themVaoGioHang(sanPhamRauCu[luaChonSanPham - 1], soLuong);
                    cout << "San pham da duoc them vao gio hang!" << endl;
                } else if (luaChonSanPham != 0) {
                    cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                }
                break;
            case 6: 
                cout << "Ban da chon Quay Gia Vi. Cac san pham co san:" << endl;
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "GiaVi") {
                        cout << "_____________________" << endl;
                        cout << "| " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_____________________" << endl;
                        sanPhamGiaVi.push_back(sp);
                        index++;
                    }
                }

                cout << "Nhap so thu tu san pham muon mua (0 de quay lai): ";
                cin >> luaChonSanPham;

                if (luaChonSanPham > 0 && luaChonSanPham <= sanPhamGiaVi.size()) {
                    cout << "Nhap so luong muon mua: ";
                    cin >> soLuong;
                    themVaoGioHang(sanPhamGiaVi[luaChonSanPham - 1], soLuong);
                    cout << "San pham da duoc them vao gio hang!" << endl;
                } else if (luaChonSanPham != 0) {
                    cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                }
                break;
            case 7: 
                cout << "Ban da chon Quay Banh. Cac san pham co san:" << endl;
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "Banh") {
                        cout << "_____________________" << endl;
                        cout << "| " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_____________________" << endl;
                        sanPhamBanh.push_back(sp);
                        index++;
                    }
                }

                cout << "Nhap so thu tu san pham muon mua (0 de quay lai): ";
                cin >> luaChonSanPham;

                if (luaChonSanPham > 0 && luaChonSanPham <= sanPhamBanh.size()) {
                    cout << "Nhap so luong muon mua: ";
                    cin >> soLuong;
                    themVaoGioHang(sanPhamBanh[luaChonSanPham - 1], soLuong);
                    cout << "San pham da duoc them vao gio hang!" << endl;
                } else if (luaChonSanPham != 0) {
                    cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                }
                break;
            case 8: 
                cout << "Ban da chon Quay Giay. Cac san pham co san:" << endl;
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "Giay") {
                        cout << "_____________________" << endl;
                        cout << "| " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_____________________" << endl;
                        sanPhamGiay.push_back(sp);
                        index++;
                    }
                }

                cout << "Nhap so thu tu san pham muon mua (0 de quay lai): ";
                cin >> luaChonSanPham;

                if (luaChonSanPham > 0 && luaChonSanPham <= sanPhamGiay.size()) {
                    cout << "Nhap so luong muon mua: ";
                    cin >> soLuong;
                    themVaoGioHang(sanPhamGiay[luaChonSanPham - 1], soLuong);
                    cout << "San pham da duoc them vao gio hang!" << endl;
                } else if (luaChonSanPham != 0) {
                    cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                }
                break;
            case 9: 
                cout << "Ban da chon Quay Chen Bat. Cac san pham co san:" << endl;
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "ChenBat") {
                        cout << "_____________________" << endl;
                        cout << "| " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_____________________" << endl;
                        sanPhamChenBat.push_back(sp);
                        index++;
                    }
                }

                cout << "Nhap so thu tu san pham muon mua (0 de quay lai): ";
                cin >> luaChonSanPham;

                if (luaChonSanPham > 0 && luaChonSanPham <= sanPhamChenBat.size()) {
                    cout << "Nhap so luong muon mua: ";
                    cin >> soLuong;
                    themVaoGioHang(sanPhamChenBat[luaChonSanPham - 1], soLuong);
                    cout << "San pham da duoc them vao gio hang!" << endl;
                } else if (luaChonSanPham != 0) {
                    cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                }
                break;
            case 10: 
                cout << "Ban da chon Quay Do Dong Hop. Cac san pham co san:" << endl;
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "DoDongHop") {
                        cout << "_____________________" << endl;
                        cout << "| " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_____________________" << endl;
                        sanPhamDoDongHop.push_back(sp);
                        index++;
                    }
                }

                cout << "Nhap so thu tu san pham muon mua (0 de quay lai): ";
                cin >> luaChonSanPham;

                if (luaChonSanPham > 0 && luaChonSanPham <= sanPhamDoDongHop.size()) {
                    cout << "Nhap so luong muon mua: ";
                    cin >> soLuong;
                    themVaoGioHang(sanPhamDoDongHop[luaChonSanPham - 1], soLuong);
                    cout << "San pham da duoc them vao gio hang!" << endl;
                } else if (luaChonSanPham != 0) {
                    cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                }
                break;
            default:
                cout << "Lua chon khong hop le! Vui long chon lai." << endl;
                continue;
    
}
}while (luaChonQuay != 0);
}
