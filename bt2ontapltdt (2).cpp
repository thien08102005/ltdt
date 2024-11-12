#include <stdio.h>

void nhapMang(int a[][100], int n) {
    printf("Nhap ma tran vuong %dx%d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void xuatMang(int a[][100], int n) {
    printf("Ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int phanTuLonNhatTrenHang(int a[][100], int n, int x) {
    int max = a[x][0];
    for (int j = 1; j < n; j++) {
        if (a[x][j] > max) {
            max = a[x][j];
        }
    }
    return max;
}

int phanTuNhoNhatTrenCot(int a[][100], int n, int y) {
    int min = a[0][y];
    for (int i = 1; i < n; i++) {
        if (a[i][y] < min) {
            min = a[i][y];
        }
    }
    return min;
}

int tongHang(int a[][100], int n, int k) {
    int tong = 0;
    for (int j = 0; j < n; j++) {
        tong += a[k][j];
    }
    return tong;
}

int tongCot(int a[][100], int n, int m) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += a[i][m];
    }
    return tong;
}

int tongPhanTuChan(int a[][100], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0) {
                tong += a[i][j];
            }
        }
    }
    return tong;
}

int kiemTraDuongCheoBang0(int a[][100], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i][i] != 0) {
            return 0; 
        }
    }
    return 1; 
}

int kiemTraMaTranNhoHonHoacBang1(int a[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] > 1) {
                return 0; 
            }
        }
    }
    return 1; 
}

int kiemTraDoiXung(int a[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                return 0; 
            }
        }
    }
    return 1; 
}

int main() {
    int n, a[100][100]; 
    printf("Nhap cap ma tran vuong n: ");
    scanf("%d", &n);
    
    nhapMang(a, n);
    
    xuatMang(a, n);
    
    int x, y, k, m;
    
    printf("Nhap x (hang): ");
    scanf("%d", &x);
    printf("Phan tu lon nhat tren hang %d: %d\n", x, phanTuLonNhatTrenHang(a, n, x));
    
    printf("Nhap y (cot): ");
    scanf("%d", &y);
    printf("Phan tu nho nhat tren cot %d: %d\n", y, phanTuNhoNhatTrenCot(a, n, y));
    
    printf("Nhap k (hang): ");
    scanf("%d", &k);
    printf("Tong cac phan tu tren hang %d: %d\n", k, tongHang(a, n, k));
    
    printf("Nhap m (cot): ");
    scanf("%d", &m);
printf("Tong cac phan tu tren cot %d: %d\n", m, tongCot(a, n, m));
    
    printf("Tong cac phan tu co gia tri chan la: %d\n", tongPhanTuChan(a, n));
    
    if (kiemTraDuongCheoBang0(a, n)) {
        printf("Duong cheo bang 0\n");
    } else {
        printf("Duong cheo khac 0\n");
    }
    
    if (kiemTraMaTranNhoHonHoacBang1(a, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    if (kiemTraDoiXung(a, n)) {
        printf("DOI XUNG\n");
    } else {
        printf("KHONG DOI XUNG\n");
    }
    
    return 0;
}
