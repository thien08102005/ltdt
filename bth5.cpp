#include<stdio.h>
#include<iostream>
#define vocung 10000

int s, n, a[10][10], L[10], d[10], truoc[10],f;
using namespace std;

void docfile() {  
    FILE *f;
    f = fopen("TH5.txt", "r");
    if (f == NULL)
        printf("Khong co tap tin!\n");
    else {
        fscanf(f, "%d", &n); 
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                fscanf(f, "%d", &a[i][j]);  
    }
    fclose(f);
}

void infile() {
    printf("Ma tran ke:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", a[i][j]);  
        }
        printf("\n");
    }
}

void khoitao(int s) {
    for (int i = 1; i <= n; i++) {
        L[i] = vocung;  
        d[i] = 0;       
        truoc[i] = 0;    
    }
    L[s] = 0;  
}

int timvitrimin() {
    int min = vocung;
    int vt = -1;
    for (int i = 1; i <= n; i++) {
        if (L[i] < min && d[i] == 0) {  
            min = L[i];
            vt = i;
        }
    }
    return vt;
}

void capnhatke(int vt) {
    for (int i = 1; i <= n; i++) {
        if (a[vt][i] != 0 && d[i] == 0) {  
            if (L[i] > L[vt] + a[vt][i]) {
                L[i] = L[vt] + a[vt][i];  
                truoc[i] = vt; 
            }
        }
    }
}

void timduong(int f) {
    printf("Do dai duong di ngan nhat tu dinh %d den dinh %d la: %d\n", s, f, L[f]);
    printf("%d <- ", f);
    while (truoc[f] != 0) {
        printf("%d <- ", truoc[f]);
        f = truoc[f];
    }
    printf("%d\n", s); 
}

int main() {
    docfile();
    infile();

    printf("Nhap dinh bat dau: ");
    scanf("%d", &s);  
    khoitao(s);  

    int lap = 1;
    while (lap < n) {  
        int vt = timvitrimin(); 
        capnhatke(vt);  
        d[vt] = 1;  
        lap++;
    }

    
    printf("Nhap dinh ket thuc: ");
    scanf("%d", &f); 
    timduong(f); 

    return 0;
}

