#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
struct nasabah
{
    char nama[50];
    char alamat[30];
    long int no_rek;
    int saldo;
};
int main()
{
    int n=0;
    char b1;
    struct nasabah nas[50], pen[50];
    int i, j, pil, x, pos, pas, TB, saldo, nominal_tujuan, piltrf;
    long int no;
    long int no_rek;
    long int no_tujuan;
    int setor, tarik;
    bool ketemu=0;
    time_t ambil_waktu;
    printf("Selamat Datang di BANK INDONESIA!");
    printf("\nSilahkan tentukan pilihan anda : \n");
    menu :
        printf("\n==================================");
        printf("\n|         BANK INDONESIA         |");
        printf("\n==================================");
        printf("\n__________Menu Transaksi__________");
        printf("\n|  1. Pendaftaran Nasabah        |");
        printf("\n|  2. Setor Tunai                |");
        printf("\n|  3. Tarik Tunai                |");
	printf("\n|  4. Transfer                   |");
        printf("\n|  5. Cetak Daftar Nasabah       |");
        printf("\n|  6. Cari Nasabah               |");
        printf("\n|  7. Keluar                     |");
        printf("\n|________________________________|");
        printf("\nPilihan anda : ");
        scanf("%d", &pil);

        if(pil==1)
            {
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
                        printf("\nNomor Rekening Sudah Terdaftar, Coba Lagi!");
                    }
                    else {
                        printf("\n================================");
                        printf("\nMasukkan Nama Anda: ");
                        scanf("%s", &nas[n].nama);

                        printf("\nMasukkan Alamat Anda: ");
                        scanf("%s", &nas[n].alamat);

                        printf("\nMasukkan Saldo Awal: Rp. ");
                        scanf("%d", &nas[n].saldo);
                    }
                    n=n+1;
                    nas[i].no_rek=no;

                    printf("\n================================");
                    printf("\nMasukkan Angka Sembarang Untuk Kembali Ke Menu : ");
                    scanf("%d", &x);
		    system("clear");
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
			
		    printf("\nApakah anda ingin mencetak resi(y/t)?");
                    scanf("%s", &b1);

                   	 if (b1=='y' || b1=='Y'){
			    time(&ambil_waktu);
			    FILE * fPointer;
			    fPointer = fopen ("setortunai.txt", "w");

			    fprintf (fPointer, "		  BANK INDONESIA        \n");
			    fprintf (fPointer, "\n");
			    fprintf (fPointer, "%s", ctime (&ambil_waktu));
			    fprintf (fPointer, "KCU JPU CRM-1\n");
			    fprintf (fPointer, "==============================================\n");

			    fprintf (fPointer, " %.lf\n", nas[pos].no_rek);
			    fprintf (fPointer, "\nDEPOSIT KE TABUNGAN   		    Rp.%d", setor);
			    fprintf (fPointer, "\nSALDO ANDA  		            Rp.%d", nas[pos].saldo);
			    fprintf (fPointer, "\n");
			    fprintf (fPointer, "\n");
			    fprintf (fPointer, "\n");
			    fprintf (fPointer, "		  BANK INDONESIA        \n");
			    fprintf (fPointer, "\n");
			    fprintf (fPointer, "\n");
			    fprintf (fPointer, "Kunjungi www.bankindonesia.com untuk infomasi\n");
			    fprintf (fPointer, "            dan promo-promo menarik          \n");

			    fclose(fPointer);
			    printf("\nResi sudah tercetak!");
			    printf("\nMasukkan Angka Sembarang Untuk Kembali Ke Menu : ");
			    scanf("%d", &x);
			    system("clear");
			    goto menu;

                    	}
                    	else
                        	system("clear");
                        	goto menu;
                }
                else
                    printf("\nNomor Rekening Tidak Ditemukan!");
                    printf("\nMasukkan Angka Sembarang Untuk Kembali Ke Menu : ");
                    scanf("%d", &x);
		    system("clear");
                    goto menu;

        }
        else if(pil==3){
                printf("\n====================================");
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
                	printf("\nMasukkan Jumlah Penarikan : Rp. ");
                	scanf("%d", &tarik);

                	if(tarik<(nas[pos].saldo)) {
                		nas[pos].saldo=nas[pos].saldo-tarik;
                		printf("\nPenarikan Berhasil, Sisa Saldo Anda : Rp. %d", nas[pos].saldo);
				
				printf("\nApakah anda ingin mencetak resi(y/t)?");
				scanf("%s", &b1);

                        	if (b1=='y' || b1=='Y'){
					time(&ambil_waktu);
					FILE * fPointer;
					fPointer = fopen ("penarikan.txt", "w");

					fprintf (fPointer, "		  BANK INDONESIA        \n");
					fprintf (fPointer, "\n");
					fprintf (fPointer, "%s", ctime (&ambil_waktu));
					fprintf (fPointer, "KCU JPU CRM-1\n");
					fprintf (fPointer, "==============================================\n");

					fprintf (fPointer, " %.lf\n", nas[pos].no_rek);
					fprintf (fPointer, "\nPenarikan Jumlah   		    Rp.%d", tarik);
					fprintf (fPointer, "\nSALDO ANDA  		            Rp.%d", nas[pos].saldo);
					fprintf (fPointer, "\n");
					fprintf (fPointer, "\n");
					fprintf (fPointer, "\n");
					fprintf (fPointer, "		  BANK INDONESIA        \n");
					fprintf (fPointer, "\n");
					fprintf (fPointer, "\n");
					fprintf (fPointer, "Kunjungi www.bankindonesia.com untuk infomasi\n");
					fprintf (fPointer, "             dan promo-promo menarik         \n");

					fclose(fPointer);
					printf("\nResi sudah tercetak!");
					printf("\nMasukkan Angka Sembarang Untuk Kembali Ke Menu : ");
					scanf("%d", &x);
					system("clear");
					goto menu;

				}
				else
					system("clear");
					goto menu;

                	}
                	else
                		printf("Maaf Saldo Anda Tidak Mencukupi");
			}
				else
					printf("\nNomor Rekening Tidak Ditemukan!");
					printf("\nMasukkan Angka Sembarang Untuk Kembali Ke Menu : ");
					scanf("%d", &x);
					system("clear");
					goto menu;
       	}
	
	else if(pil==4){

        	printf("\n===========================================");
        	printf("\n|  1. Transfer Ke Rekening Bank Indonesia |");
		printf("\n|  2. Transfer Ke Rekening Bank Lain      |");
		printf("\nPilihan anda : ");
		scanf("%d", &piltrf);

			switch(piltrf){
				case 1:
					printf("\n====================================");
                			printf("\nMasukkan Nomor Rekening Anda: ");
                			scanf("%lf", &no);

                			for(i=0; i<n; i++){
                    				if(no==nas[i].no_rek){
                                		pos=i;
                                		ketemu=true;
                            			}
                            			else
                                		ketemu=false;
						}

					if(ketemu){

						printf("\nMasukan No.Rek Tujuan: ");
						scanf("%d", &no_tujuan);
							
						for(j=0; j<n; j++){
                    				if(no==pen[j].no_rek){
                                		pas=i;
                                		ketemu=true;
                            			}
                            			else
                                		ketemu=false;
						}

						printf("\nMasukan Nominal yang akan ditransfer: Rp.");
						scanf("%d", &nominal_tujuan);

						if(nominal_tujuan<(nas[pos].saldo)){
				    			nas[pos].saldo = nas[pos].saldo - nominal_tujuan;
							nas[pas].saldo = nas[pas].saldo + nominal_tujuan;
							printf("\nTransfer Berhasil, Saldo anda sekarang: Rp.%d", nas[pos].saldo);
							
							printf("\nIngin Mencetak Resi? (y/t) :");
                           				scanf("%s", &b1);
							
                           				if (b1=='y' || b1=='Y'){
                            					time(&ambil_waktu);
                            					FILE * fPointer;
                       						fPointer = fopen ("trfbankindo.txt", "w");

                        					fprintf (fPointer, "		BANK INDONESIA        \n");
                       						fprintf (fPointer, "\n");
                        					fprintf (fPointer, "%s", ctime (&ambil_waktu));
                        					fprintf (fPointer, "KCU JPU CRM-1\n");
                        					fprintf (fPointer, "==============================================\n");
                        					fprintf (fPointer, " %.lf\n", nas[pos].no_rek);
                        					fprintf (fPointer, "\nNAMA PENGIRIM   		      %s", nas[pos].nama);
                        					fprintf (fPointer, "\nREK.TUJUAN  		      %d", no_tujuan);
                        					fprintf (fPointer, "\nNAMA PENERIMA                   %s", nas[pas].nama);
                        					fprintf (fPointer, "\nJUMLAH                          Rp.%d", nominal_tujuan);
                       						fprintf (fPointer, "\n");
                        					fprintf (fPointer, "\n");
                        					fprintf (fPointer, "          SIMPAN RESI INI SEBAGAI\n");
                        					fprintf (fPointer, "          BUKTI TRANSAKSI YANG SAH\n");
                        					fprintf (fPointer, "\n");
                        					fprintf (fPointer, "		BANK INDONESIA        \n");
                        					fprintf (fPointer, "\n");
                        					fprintf (fPointer, "\n");
                        					fprintf (fPointer, "Kunjungi www.bankindonesia.com untuk infomasi\n");
                        					fprintf (fPointer, "            dan promo-promo menarik          \n");
                        					fclose(fPointer);
                        					printf("\nResi sudah tercetak!");
                        					printf("\nMasukkan Angka Sembarang Untuk Kembali Ke Menu : ");
                       			 			scanf("%d", &x);
                        					system("clear");
                       						goto menu;
									}
						else if(nominal_tujuan>(nas[pos].saldo)){
							printf("\nMaaf Saldo Anda Tidak Mencukupi");
							printf("\nMasukkan Angka Sembarang Untuk Kembali Ke Menu : ");
							scanf("%d", &x);
							system("clear");
							goto menu;
							}
					}
					else
                   		 		printf("\nNomor Rekening Tidak Ditemukan!");
                    				printf("\nMasukkan Angka Sembarang Untuk Kembali Ke Menu : ");
                    				scanf("%d", &x);
						system("clear");
                    				goto menu;

			}	
			switch(piltrf){
				case 2:
					printf("\n====================================");
                			printf("\nTransfer Ke Rekening Bank Lain Akan Dikenakan Pajak Rp.6.500 Lanjutkan?(y/t): "); scanf("%s", &b1);
                				if (b1=='y' || b1=='Y'){
                				goto trfbeda;
						}
						else {
						goto menu;
						}


						trfbeda:
						TB=6500;

						printf("\n====================================");
                        			printf("\nMasukkan Nomor Rekening Anda: ");
                        			scanf("%lf", &no);

                            			for(i=0; i<n; i++){
                    					if(no==nas[i].no_rek){
                               				pos=i;
                                			ketemu=true;
                            				}
                           			else
                                		ketemu=false;}


						if(ketemu){
						printf("\nMasukan No.Rek Tujuan: ");
						scanf("%d", &no_tujuan);
						printf("\nMasukan Nominal yang akan ditransfer: Rp.");
						scanf("%d", &nominal_tujuan);

						if(nominal_tujuan<nas[pos].saldo){
                        			nas[pos].saldo= nas[pos].saldo - nominal_tujuan - TB;
						printf("\nTransfer Berhasil, Saldo anda sekarang: Rp.%d", nas[pos].saldo);
						printf("\nMasukkan Angka Sembarang Untuk Kembali Ke Menu");
                        			scanf("%d", &x);
						system("clear");
                        			goto menu;
                           				}
						else if (nominal_tujuan>nas[pos].saldo){
						printf("\nMaaf Saldo Anda Tidak Mencukupi");
						printf("\nMasukkan Angka Sembarang Untuk Kembali Ke Menu");
                        			scanf("%d", &x);
						system("clear");
                        			goto menu;
		  					}
						} 
						else
                    				printf("\nNomor Rekening Tidak Ditemukan!");
                    				printf("\nMasukkan Angka Sembarang Untuk Kembali Ke Menu : ");
                    				scanf("%d", &x);
						system("clear");
                    				goto menu;
			}}
        else if(pil==5){
               
                printf("\n|==============================================================|");
                printf("\n|                   DAFTAR NASABAH BANK                        |");
                printf("\n|====|================|============|=============|=============|");
                printf("\n| NO |  NO REKENING   |    NAMA    |   ALAMAT    | TOTAL SALDO |");
                printf("\n|====|================|============|=============|=============|");
            for(i=0; i<n; i++)
        {
            printf("\n");
	    printf("%3d", i+1);
            printf("%\t%.lf", nas[i].no_rek);
            printf("%13s", nas[i].nama);
            printf("%15s", nas[i].alamat);
	    printf("%\t\t%.lf", (nas[i].saldo)+(nas[i].saldo*0.1));

        }
		
       	printf("\n|====|================|============|=============|=============|");
	printf("\n|==============================================================|");
        printf("\n|    JUMLAH TOTAL SALDO SETELAH DITAMBAH BUNGA 10 %            |");
        printf("\n|______________________________________________________________|\n");
        printf("\nMasukkan Angka Sembarang Untuk Kembali Ke Menu : ");
	scanf("%d", &x);
	system("clear");
	goto menu;
        }
        else if(pil==6){

                printf("==========================================================");
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
                printf("\nNOMOR REKENING ANDA : %.lf", nas[pos].no_rek);
                printf("\nNAMA NASABAH        : %s" , nas[pos].nama);
                printf("\nALAMAT NASABAH      : %s" , nas[pos].alamat);
                printf("\nSALDO               : Rp. %d" , nas[pos]. saldo);
		printf("\nTOTAL SALDO SETELAH BUNGA : Rp. %lf\n", (nas[i].saldo)+(nas[i].saldo*0.1));
		printf("\nMasukkan Angka Sembarang Untuk Kembali Ke Menu : ");
                scanf("%d", &x);
		system("clear");
                goto menu;
        }

        else{
                printf("==========================================================");
                printf("\nNomor Rekening Tidak ditemukan!");
                printf("\nMasukkan Angka Sembarang Untuk Kembali Ke Menu : ");
		scanf("%d", &x);
		system("clear");
		goto menu;

        }}
        else if(pil==7)
        {
                printf("\n|_____________________________________________________|");
                printf("\n|       TERIMA KASIH TELAH BERTRANSAKSI DISINI");
                printf("\n|=====================================================|");
        }
	else 
		printf("Nomor yang anda masukkan tidak sesuai, coba lagi!");
            	system("clear");
            	goto menu;
        return 0;

};

        
