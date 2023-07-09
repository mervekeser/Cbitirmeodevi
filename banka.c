#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    char isim[20];
    char soyisim[20];          /*Veri Yapıları*/
    char hesapno[11];
    int islem, toplam, paraEkle, paraCek,bakiye;
}Record;
void menu();              
int hesapac();
int hesapsil();
int hesapgoruntule();        /*Fonksiyonlar*/
int parayatir();
int paracek();
int bakiye();

int main(){
    int islem=0;
    menu();
    
    do{
        printf("\n\n");
        printf("Lutfen bir islem seciniz:");
        scanf("%d", &islem);
        switch(islem){
            case 1: if(hesapac() == 0){
                
                printf("Hesabiniz Acildi\n");
            }
            else{
                printf("Hesap Acilirken Hata Olustu\n");
            }
            break;
            case 2: if(hesapsil() ==0){
               printf("Hesap Silinirken Hata Olustu\n"); 
            }
            else{
                printf("Hesabiniz Silindi\n");
            }
            break;
            case 3: if(hesapgoruntule() == 0){
                printf("\nHesap Goruntuleme\n");
            }
            else{
                printf("\nHesap Goruntulenemedi\n");
            }
            break;
            case 4:if(paracek()==0){
                printf("Para Cekildi\n");
            }
            else{
                printf("Bakiye Yetersiz\n");
            }
            break;
            case 5:if(parayatir()==0){

                printf("Paraniz Yatirildi\n");
            }
            else{
                printf("Paraniz Yatirilamadi\n");
            }
            break;
            case 6:if(bakiye() == 0){
                printf("\n\n");
            }
            else{
                printf("\nBakiye Goruntulenemedi\n");
            }
            break;
            case 7:printf("\nGuvenli Cikis Yaptiniz-Iyi Gunler\n");
            return 0;
            break;
            default:printf("\nLutfen 1-7 arasinda secim yapin\n");
        }
    }
    while(islem!=7);
    return 0;
}

void menu(){
    printf("==============================\n");
    printf("|                            |\n");
    printf("|    BANKA İSLEMLERİ         |\n");
    printf("|   1-Hesap Ac               |\n");
    printf("|   2-Hesap Sil              |\n");
    printf("|   3-Hesap Goruntule        |\n");
    printf("|   4-Para Cek               |\n");
    printf("|   5-Para Yatir             |\n");
    printf("|   6-Bakiye Goruntule       |\n");
    printf("|   7-Cikis                  |\n");
    printf("|                            |\n");
    printf("==============================\n");

}
int hesapac(){
    Record yeniHesap;
    FILE *dosya;
    dosya=fopen("metin.txt","a");
    if (dosya==NULL){
        return -1;
    }
    printf("\n\n");
    printf("Isim Girin (max 20 karakter):");
    scanf("%s", yeniHesap.isim);
    printf("Soyisim Girin (max 20 karakter):");
    scanf("%s", yeniHesap.soyisim);
    printf("Kimlik No Girin (max 11 karakter):");
    scanf("%s", yeniHesap.hesapno);
    fprintf(dosya,"\n%s %s %s", yeniHesap.isim, yeniHesap.soyisim, yeniHesap.hesapno);
    fclose(dosya);
    return 0;
}
int hesapsil(){
    Record mevcutHesap;
    FILE *dosya;
    dosya=remove("metin.txt");
    dosya=remove("belge.txt");
    if (dosya==NULL){
        return -1;
    }
    
    return 0;
}
int hesapgoruntule(){
    Record mevcutHesap;
    FILE *dosya;
    dosya=fopen("metin.txt","r");
    if (dosya==NULL){
        return -1;
    }
    printf("\n\nIsim\t\t\tSoyisim\t\t\tHesapNo\n");
    printf("====\t\t\t=======\t\t\t=======\n\n");
    while(!feof(dosya)){
        fscanf(dosya,"%s%s%s", mevcutHesap.isim, mevcutHesap.soyisim, mevcutHesap.hesapno);
        printf("%s\t\t\t", mevcutHesap.isim);
        printf("%s\t\t\t", mevcutHesap.soyisim);
        printf("%s\n", mevcutHesap.hesapno);
    }
    fclose(dosya);
    return 0;
}
int paracek(){
    int bakiye=500;
    Record paraCekme;
    FILE *dosya;
    dosya=fopen("belge.txt","a");
    if (dosya==NULL){
        return -1;
    }
    printf("Cekebileceginiz Max Tutar= 500TL");
    printf("\nCekmek Istediginiz Tutari Girin(Ornek-->50):");
    scanf("%d", &paraCekme.paraCek);
    paraCekme.bakiye=500;
    paraCekme.bakiye=paraCekme.bakiye - paraCekme.paraCek;
    fprintf(dosya,"%d\n", paraCekme.bakiye);
    fclose(dosya);
    return 0;
}
int parayatir(){
    int toplam=0;
    Record paraYatir;
    FILE *dosya;
    dosya=fopen("belge.txt","a");
    if (dosya==NULL){
        return -1;
    }
    printf("Yatirmak Istediginiz Tutari Girin(Ornek-->50):");
    scanf("%d", &paraYatir.paraEkle);
    paraYatir.toplam=0;
    paraYatir.toplam=paraYatir.toplam + paraYatir.paraEkle;
    fprintf(dosya,"\n%d\n", paraYatir.toplam);
    fclose(dosya);
    return 0;
}
int bakiye(){
    Record bakiyeHesap;
    FILE *dosya;
    dosya=fopen("belge.txt","r");
    if (dosya==NULL){
        return -1;
    }
    
         printf("\n====Bakiye====\n");
        while(!feof(dosya)){
            fscanf(dosya,"%d", &bakiyeHesap.bakiye);
            printf("%dTL\n", bakiyeHesap.bakiye);
        }
    
   
    fclose(dosya);
    return 0;
}