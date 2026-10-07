// Sinh viên hãy lập trình giải bài toán quản lý nhân viên, trong chương trình thực hiện các công việc sau:
// Câu 1. Định nghĩa một cấu trúc nhân viên bao gồm các thông tin: Mã nhân viên, họ tên, ngày sinh (kiểu ngày/tháng/năm, ví dụ 10/10/2000), lương  (đơn vị triệu đồng).
// Câu 2. Viết hàm nhập vào một mảng gồm n nhân viên
// Câu 3. Viết hàm xuất ra mảng n nhân viên vừa nhập.
// Câu 4. Sử dụng phương pháp sắp xếp nổi bọt (Bubble sort), viết hàm sắp xếp các nhân viên theo chiều tăng dần của lương
// Câu 5. Áp dụng chiến lược chia để trị (bằng thuật toán tìm kiếm nhị phân). Viết hàm tìm kiếm các nhân viên có lương bằng X.
// Câu 6. Viết hàm chính thực hiện:
// - Nhập vào n nhân viên và hiển thị các nhân viên vừa nhập
// - Sắp xếp n nhân viên theo chiều tăng dần của lương.
// - Sử dụng hàm tìm kiếm hiển thị các nhân viên có lương bằng X (X do người dùng nhập vào)

#include <iostream>
#include <string>

using namespace std;

struct ngay{
    int ngay;
    int thang;
    int nam;
};

struct nhanvien{
    int manv;
    string hoten;
    ngay ngaysinh;
    double luong;
};

bool lanamnhuan(int nam){
    return (nam%4==0 && nam%100!=0)||(nam%400==0);
}


bool ngayhople(ngay d){
    if (d.thang<1 || d.thang>12 || d.ngay<1 || d.ngay>31) return false;
    int songay[] = {31,28,31,20,31,20,31,31,30,31,30,31};
    if (lanamnhuan(d.nam)) songay[1]=29;
    return d.ngay<=songay[d.thang-1];
}

void nhapds(nhanvien nv[], int n){
    for(int i = 0; i<n; i++){
        cout<<"\nnhan vien thu "<<i+1<<":\n";
        cout<<"ma nhan vien: ";
        cin>>nv[i].manv;
        cin.ignore();
        cout<<"ho ten nhan vien: ";
        getline(cin, nv[i].hoten);
        char c1,c2;
        do{
            cout<<"ngay sinh (dd/mm/yyyy):";
            cin>>nv[i].ngaysinh.ngay>>c1
                >>nv[i].ngaysinh.thang>>c2
                >>nv[i].ngaysinh.nam;
            if(cin.fail()||c1!='/'||c2!='/'||!ngayhople(nv[i].ngaysinh)){
                cout<<"ngay sinh khong hop le, vui long nhap lai\n";
                cin.clear();
                cin.ignore(10000,'\n');
                nv[i].ngaysinh={0,0,0};
            }   
        }while(!ngayhople(nv[i].ngaysinh));

        do{
            cout<<"luong (trieu dong): ";
            cin>>nv[i].luong;
            if(cin.fail()||nv[i].luong<0){
                cout<<"luong khong hop le, vui long nhap lai\n";
                cin.clear();
                cin.ignore(1000,'\n');
                nv[i].luong=-1;
            }
        }while(nv[i].luong<0);
    }
}

void xuat1nv(const nhanvien &nv){
    cout<<nv.manv<<"\t"<<nv.hoten<<"\t\t";
    if(nv.ngaysinh.ngay<10) cout<<"0";
    cout<<nv.ngaysinh.ngay<<"/";
    if(nv.ngaysinh.thang<10) cout<<"0";
    cout<<nv.ngaysinh.thang<<"/"<<nv.ngaysinh.nam<<"\t"<<nv.luong<<"\n";
}

void xuatds(nhanvien nv[],int n){
    if(n<=0){
        cout<<"khong co nhan vien nao\n";
        return;
    }
    cout<<"\nma nv\tho ten\t\tngay sinh\tluong\n";
    for(int i = 0; i < n; i++){
        xuat1nv(nv[i]);
    }
}

void bubblesort(nhanvien nv[], int n){
    for(int i = 0; i<n-1;i++){
        bool kt = false;
        for(int j=0;j<n-1-i;j++){
            if (nv[j].luong>nv[j+1].luong){
                swap(nv[j],nv[j+1]);
                kt = true;
            }
        }
        if(!kt) break;
    }
}

int timkiem(nhanvien nv[], int n, double x){
    int l=0, r=n-1, vt=-1;
    while(l<=r){
        int m = (l+r)/2;
        if(nv[m].luong == x){
            vt = m;
            r=m-1;
        }else if(nv[m].luong < x){
            l = m+1;
        }else{
            r = m-1;
        }
    }   
    if(vt == -1) return 0;

    int dem=0;
    cout<<"\nma nv\tho ten\t\tngay sinh\tluong\n";
    for(int i=vt; i<n && nv[i].luong==x; i++){
        xuat1nv(nv[i]);
        dem++;
    }
    return dem;
}

int main(){
    int n;
    do{
        cout<<"Nhap so luong nhan vien: ";
        cin>>n;
        if(cin.fail()||n<=0){
            cout<<"so luong khong hop le, vui long nhap lai\n";
            cin.clear();
            cin.ignore(10000,'\n');
            n=-1;
        }
    }while(n<=0);

    nhanvien* nv = new nhanvien[n];
    nhapds(nv,n);
    cout<<"\nDanh sach nhan vien vua nhap:\n";
    xuatds(nv,n);

    bubblesort(nv,n);
    cout<<"\nDanh sach nhan vien sau khi sap xep theo luong tang dan:\n";
    xuatds(nv,n);

    double x;
    cout<<"\nNhap luong can tim kiem: ";
    cin>>x;
    int dem = timkiem(nv,n,x);
    if(dem==0){
        cout<<"khong co nhan vien nao co luong bang "<<x<<"\n";
    }else{
        cout<<"co "<<dem<<" nhan vien co luong bang "<<x<<"\n";
    }
    delete[] nv;
}
