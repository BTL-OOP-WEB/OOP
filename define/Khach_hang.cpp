#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "../declare/Khach_hang.h"
#include "../declare/SanPham.h"
#include "../declare/Date.h"

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
        SanPham* spMoi = sanPham->taoSanPham(); 
        spMoi->setSoLuong(soLuong);
        gioHang.push_back(spMoi);
    }
}

void KhachHang::xoaSanPhamRaKhoiFile(const string& tenSanPham) {
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

bool KhachHang::neuGioHangRong() const {
    return gioHang.empty(); 
}

void KhachHang::thanhToan(const vector<SanPham*>& dsSanPham) {
    double tongTien = 0.0;
    cout << "================= Danh sach san pham =================" << endl;
    for (auto& sp : gioHang) {
        sp->inThongTin();
        tongTien += sp->giaTien;
        cout << endl;
    }

    cout << "------------------------------------------------------" << endl;
    cout << "Tong tien truoc khi ap dung giam gia: " << tongTien << " VND" << endl;
    suDungDiem(tongTien, this->ten);
    cout << "Tong tien can thanh toan: " << tongTien << " VND" << endl;

    int diemThem = static_cast<int>(tongTien / 100000);
    diemTichLuy += diemThem;

    ifstream inputFile("../resources/KhachHang.txt");
    vector<string> lines;
    string line;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string ten, matKhau, hoTen, sdt;
        int diem, ngay, thang, nam;
        ss >> ten >> matKhau >> diem >> ngay >> thang >> nam >> sdt;
        getline(ss, hoTen); 
        if (ten == this->ten) {
            string linehight = ten + " " + matKhau + " " + to_string(diemTichLuy) + " " +
                to_string(ngay) + " " + to_string(thang) + " " + to_string(nam) + " " + sdt + hoTen; 
            lines.push_back(linehight);
        }
        else 
            lines.push_back(line);
    }
    inputFile.close();

    ofstream outputFile("../resources/KhachHang.txt");
    for (const auto& updatedLine : lines) {
        outputFile << updatedLine << endl; 
    }
    outputFile.close();

    clearScreen();
    cout << "----------------------------------------\n";
    cout << "              BREAD3T SHOP            \n";
    cout << "----------------------------------------\n";
    cout << "   Tri Tram Tinh\n";
    cout << "   From CNTT K64 with luv \n";
    cout << "----------------------------------------\n";

    for (SanPham* sanPham : gioHang) {
        cout << sanPham->getSoLuong() << "x " << sanPham->getTenSanPham()
             << setw(26 - sanPham->getTenSanPham().length()) << right << "$ "
             << sanPham->getGia() * sanPham->getSoLuong() << "\n";
    }

    cout << "----------------------------------------\n";
    cout << "Tong tien" << setw(20) << "$ " << tongTien << "\n";
    cout << "----------------------------------------\n";

    for (auto& sp : gioHang) {
        for (auto& sanPham : dsSanPham) {
            if (sp->getTenSanPham() == sanPham->getTenSanPham()) {
                int soLuongConLai = sanPham->getSoLuong() - sp->getSoLuong();
                
                if (sp->getSoLuong() < sanPham->getSoLuong()) {
                    capNhatSanPhamTrongFile(sanPham->getTenSanPham(), soLuongConLai);
                } else if (sp->getSoLuong() == sanPham->getSoLuong()) {
                    xoaSanPhamRaKhoiFile(sanPham->getTenSanPham());
                }
                break;
            }
        }
    }
    gioHang.clear();
    return ;
}

void KhachHang::suDungDiem(double &tongTien, string tenUser) {
    if (diemTichLuy > 0) {
        cout << "Ban co " << diemTichLuy << " diem. Ban co muon su dung diem de giam gia khong? (1: Co, 0: Khong): ";
        int luaChon;
        cin >> luaChon;

        if (luaChon == 1) {
            double giamGia = std::min<double>(diemTichLuy * 100, static_cast<double>(tongTien));
            tongTien -= giamGia;
            diemTichLuy -= static_cast<int>(giamGia / 100);  
        }
    } else {
        cout << "Ban khong co diem tich luy de su dung." << endl;
        return;
    }

    ifstream inputFile("../resources/KhachHang.txt");
    vector<string> lines;
    string line;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string matKhau, hoTen, sdt;
        int diem, ngay, thang, nam;

        ss >> ten >> matKhau >> diem >> ngay >> thang >> nam >> sdt;
        getline(ss, hoTen); 

        if (ten == tenUser) {
            line = ten + " " + matKhau + " " + to_string(diemTichLuy)  + " " +
                   to_string(ngay) + " " + to_string(thang) + " " + to_string(nam) + " " + sdt + hoTen; 
        }
        lines.push_back(line); 
    }
    inputFile.close();

    ofstream outputFile("../resources/KhachHang.txt");
    for (const auto& updatedLine : lines) {
        outputFile << updatedLine << endl; 
    }
    outputFile.close();
}

void KhachHang::capNhatSanPhamTrongFile(const string& tenSanPham, int soLuongMoi) {
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

void KhachHang::hienThiGioHang() {
    cout << "===============================" << endl;
    cout << "       Gio hang cua ban     " << endl;
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
                    
                    cout << "Nhap so luong san pham can bo: ";
                    int soLuongCanBo;
                    cin >> soLuongCanBo;

                    while (soLuongCanBo < 0 || soLuongCanBo > soLuongHienTai) {
                        if (soLuongCanBo > soLuongHienTai) {
                            cout << "Khong the bo so luong lon hon so luong hien co. Nhap lai: ";
                        } else if (soLuongCanBo < 0) {
                            cout << "So luong phai >= 0. Nhap lai: ";
                        }
                        cin >> soLuongCanBo;
                    }

                    if (soLuongCanBo == 0) {
                        gioHang.erase(gioHang.begin() + spIndex - 1);
                    } else {
                        int soLuongSauKhiBo = soLuongHienTai - soLuongCanBo;
                        if (soLuongSauKhiBo == 0) {
                            gioHang.erase(gioHang.begin() + spIndex - 1);
                        } else {
                            sp->setSoLuong(soLuongSauKhiBo);
                        }
                    }
                    
                } else {
                    cout << "So thu tu khong hop le." << endl;
                }
            }
            case 2:
                tiepTuc = false;
                clearScreen();
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
        clearScreen();
        cout << " __________________________________________________ " << endl;
        cout << "| \033[38;5;214m~\033[0m 1. Quay Thit                  |                 |" << endl;
        cout << "| \033[38;5;214m~\033[0m 2. Quay Ca                    |                 |" << endl;
        cout << "| \033[38;5;214m~\033[0m 3. Quay Keo                   |                 |" << endl;
        cout << "| \033[38;5;214m~\033[0m 4. Quay Nuoc                  |                 |" << endl;
        cout << "| \033[38;5;214m~\033[0m 5. Quay Rau Cu                |                 |" << endl;
        cout << "| \033[38;5;214m~\033[0m 6. Quay Gia Vi                |                 |" << endl;
        cout << "| \033[38;5;214m~\033[0m 7. Quay Banh                  |                 |" << endl;
        cout << "| \033[38;5;214m~\033[0m 8. Quay Giay                  |                 |" << endl;
        cout << "| \033[38;5;214m~\033[0m 9. Quay Chen Bat              |                 |" << endl;
        cout << "| \033[38;5;214m~\033[0m 10. Quay Do Dong Hop          |                 |" << endl;
        cout << "| \033[38;5;214m~\033[0m 0. Quay lai                   |                 |" << endl;
        cout << "| \033[38;5;214m~\033[0m Chon quay muon mua (0-10):    |                 |" << endl;
        cout << "|________________________________|   |W|E|L|C|O|M|E| " << endl;

        cout.flush();
        setCursorPosition(31, 12); 
        cin >> luaChonQuay;
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

        switch (luaChonQuay) {
            case 1: 
                cout << "Ban da chon Quay Thit. Cac san pham co san:" << endl;      
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "Thit") {
                        cout << "_______________________" << endl;
                        cout << "| \033[38;5;214m~\033[0m " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_______________________" << endl;
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
                } else if (luaChonSanPham != 0) {
                    cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                }
                break;


            case 2:              
                cout << "Ban da chon Quay Ca. Cac san pham co san:" << endl;
                for (const auto& sp : danhSachSanPham) {
                    if (sp->getLoaiSanPham() == "Ca") {
                        cout << "_________________________" << endl;
                        cout << "| \033[38;5;214m~\033[0m " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_________________________" << endl;
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
                        cout << "_________________________" << endl;
                        cout << "| \033[38;5;214m~\033[0m " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_________________________" << endl;
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
                        cout << "_________________________" << endl;
                        cout << "| \033[38;5;214m~\033[0m " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_________________________" << endl;
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
                        cout << "_________________________" << endl;
                        cout << "| \033[38;5;214m~\033[0m " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_________________________" << endl;
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
                        cout << "_________________________" << endl;
                        cout << "| \033[38;5;214m~\033[0m " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_________________________" << endl;
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
                        cout << "_________________________" << endl;
                        cout << "| \033[38;5;214m~\033[0m " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_________________________" << endl;
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
                        cout << "_________________________" << endl;
                        cout << "| \033[38;5;214m~\033[0m " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_________________________" << endl;
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
                        cout << "_________________________" << endl;
                        cout << "| \033[38;5;214m~\033[0m " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_________________________" << endl;
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
                        cout << "_________________________" << endl;
                        cout << "| \033[38;5;214m~\033[0m " << index << ". " << sp->getTenSanPham() << " - " << sp->getGia() << " VND |" << endl;
                        cout << "_________________________" << endl;
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
            case 0: continue;
            default:
                cout << "Lua chon khong hop le! Vui long chon lai." << endl;
                continue;
    
}
}while (luaChonQuay != 0);
}
