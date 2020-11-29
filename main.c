#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct nasabah
{
    char nama[50];
    char alamat[30];
    long int no_rek;
    double saldo;
};
int main()
{
    int n=0;
    struct nasabah nas[50];
    int i, pil, x, pos;
    long int no;
    long int no_rek;
    double setor, tarik;
    bool ketemu=0;
    menu :
        printf("\n==================================");
        printf("\n|           BANK KLP 4           |");
        printf("\n==================================");
        printf("\n__________Menu Transaksi__________");
        printf("\n|  1. Pendaftaran Nasabah        |");
        printf("\n|  2. Menabung                   |");
        printf("\n|  3. Penarikan                  |");
        printf("\n|  4. Cetak Daftar Nasabah       |");
        printf("\n|  5. Cari Nasabah               |");
        printf("\n|  6. Keluar                     |");
        printf("\n|________________________________|");
        printf("\nPilihan anda : ");
        scanf("%d", &pil);

        if(pil==1)
            {
                lagi:
                    printf("\n================================");
                    printf("\nMasukkan Nomor Rekening : ");
                    scanf("%lf", &no);

                    for(i=0; i<n; i++){
                            if(no==nas[i].no_rek)
                            ketemu=true;
                            else
                            ketemu=false;
                    }
                    if(ketemu){
                        printf("\nNomor Rekening sudah ada, coba lagi!");
                    }
                    else {
                        printf("\n================================");
                        printf("\nMasukkan Nama Anda: ");
                        scanf("%s", &nas[n].nama);

                        printf("\nMasukkan Alamat Anda: ");
                        scanf("%s", &nas[n].alamat);

                        printf("\nMasukkan Saldo awal: Rp. ");
                        scanf("%d", &nas[n].saldo);
                    }
                    n=n+1;
                    nas[i].no_rek=no;

                    printf("\n================================");
                    printf("\nMasukkan angka sembarang untuk kembali ke menu : ");
                    scanf("%d", &x);
                    goto menu;

        }
        else if(pil==2){
                printf("\n================================");
                printf("\nMasukkan Nomor Rekening : ");
                scanf("%lf", &no);

                for(i=0; i<n; i++){
                            if(no==nas[i].no_rek){
                                pos=i;
                                ketemu=true;
                                break;
                            }
                            else
                                ketemu=false;
                }
                if(ketemu){
                    printf("\n================================");
                    printf("\nMasukkan Nominal Setoran : Rp. ");
                    scanf("%d", &setor);

                    nas[pos].saldo=nas[pos].saldo+setor;

                    printf("\nSetoran Berhasil!");
                    printf("\nJumlah Saldo Anda : Rp. %d", nas[pos].saldo);
                }
                else
                    printf("\nNomor Rekening Tidak Ditemukan!");
                    printf("\nMasukkan angka sembarang untuk kembali ke menu : ");
                    scanf("%d", &x);
                    goto menu;

        }
        else if(pil==3){
                printf("");

        }
        else if(pil==4){
                printf("");

        }
        else if(pil==5){
                printf("");

        }
        else{
                printf("");

        }
        return 0;
};
