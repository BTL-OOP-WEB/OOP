
#ifndef DATE_H
#define DATE_H

#include <string>
#include <conio.h> 
#include <windows.h>

class Date {
private:
    int ngay;
    int thang;
    int nam;

public:
    Date() : ngay(1), thang(1), nam(2000) {}
    Date(int d, int m, int y) : ngay(d), thang(m), nam(y) {}
    
    int getNgay() const { return ngay; }
    int getThang() const { return thang; }
    int getNam() const { return nam; }

    void setNgay(int d) { ngay = d; }
    void setThang(int m) { thang = m; }
    void setNam(int y) { nam = y; }
};


void setCursorPosition(int x, int y);

#endif 
