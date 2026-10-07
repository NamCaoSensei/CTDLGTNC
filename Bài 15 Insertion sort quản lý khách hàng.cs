// Sinh viên hãy lập trình giải bài toán quản lý khách hàng, trong chương trình thực hiện các công việc sau:
// Câu 1. (2 -) Định nghĩa một cấu trúc Khách hàng, bao gồm các trường thông tin như sau: Mã khách hàng (kiểu số nguyên), tên khách hàng (kiểu chuỗi ký tự), số điện thoại (kiểu chuỗi ký tự), tổng tiền thanh toán (kiểu số).
// Câu 2. (2 -) Viết hàm nhập vào một mảng gồm n khách hàng
// Câu 3. (1 -) Viết hàm xuất ra mảng n khách hàng vừa nhập.
// Câu 4. (2 -) Sử dụng phương pháp sắp xếp chèn trực tiếp(inserttion sort), viết hàm sắp xếp các khách hàng theo chiều tăng dần của tổng tiền thanh toán
// Câu 5. (1.5 -). Áp dụng chiến lược chia để trị (bằng thuật toán tìm kiếm nhị phân). Viết hàm tìm kiếm các khách hàng có tổng tiền thanh toán bằng X.
// Câu 6. (1.5 -). Viết hàm chính thực hiện:
// -(0.5 -) Nhập vào n khách hàng và hiển thị các khách hàng vừa nhập
// -(0.5 -) Sắp xếp n khách hàng theo chiều tăng dần của tổng tiền thanh toán.
// -(0.5 -) Sử dụng hàm tìm kiếm hiển thị các khách hàng có tổng tiền thanh toán bằng X (X do người dùng nhập vào)

#include <iostream>
#include <string>

using namespace std;
struct KhachHang {
    int makh;
    string tenkh;
    string sdt;
    double tongtien;
};

void nhapds(KhachHang kh[], int n){
    for(int i = 0; i<n; i++){
        cout<<"\nkhach hang thu "<<i+1<<":\n";
        cout<<"Nhap ma khach hang: ";
        cin>>kh[i].makh;
        cin.ignore();
        cout<<"nhap ten khach hang: ";
        getline(cin, kh[i].tenkh);
        cout<<"nhap so dien thoai: ";
        getline(cin, kh[i].sdt);
        cout<<"nhap tong tien thanh toan: ";
        cin>>kh[i].tongtien;
        cin.ignore();
    }
}

void xuatds(KhachHang kh[],int n){
    if(n==0){
        cout<<"khong co khach hang nao";
    }else{
        cout<<"\n"<<"makh\tten kh\tsdt\ttong tien\n";
        for(int i = 0; i < n; i++){
            cout<<kh[i].makh<<"\t"<<kh[i].tenkh<<"\t"<<kh[i].sdt<<"\t"<<kh[i].tongtien<<"\n";
        }
    }
}

void sxtangdan(KhachHang a[],int n){
    for(int i=1; i<n;i++){
        KhachHang tmp = a[i];
        int j = i-1;
        while(j>=0 && a[j].tongtien > tmp.tongtien){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = tmp;
    }
}

int timkiem(KhachHang a[], int n, double x){
    int l=0, r=n-1, vt=-1;
    while(l<=r){
        int m = (l+r)/2;
        if(a[m].tongtien == x){
            vt = m;
            r=m-1;
        }else if(a[m].tongtien < x){
            l = m+1;
        }else{
            r = m-1;
        }
    }   
    if(vt == -1) return 0;

    int dem=0;
    cout<<"\n"<<'makh\tten kh\tsdt\ttong tien\n';
    for(int i=vt; i<n && a[i].tongtien==x; i++){
        cout<<a[i].makh<<"\t"<<a[i].tenkh<<"\t"<<a[i].sdt<<"\t"<<a[i].tongtien<<"\n";
        dem++;
    }
    return dem;
}

int main(){
    int n;
    do{
        cout<<"Nhap so luong khach hang: ";
        cin>>n;
    }while(n<=0);

    KhachHang kh[n];
    nhapds(kh,n);

    cout<<"\nDanh sach khach hang vua nhap:\n";
    xuatds(kh,n);   

    sxtangdan(kh,n);
    cout<<"\nDanh sach khach hang sau khi sap xep tang dan theo tong tien:\n";
    xuatds(kh,n);
    
    double x;
    cout<<"\nNhap tong tien can tim: ";
    cin>>x;
    int dem = timkiem(kh,n,x);
    if(dem==0){
        cout<<"\nKhong co khach hang nao co tong tien thanh toan bang "<<x;
    }else{
        cout<<"\nCo "<<dem<<" khach hang co tong tien thanh toan bang "<<x;
    }
}


