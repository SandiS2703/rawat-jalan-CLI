#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

typedef struct{
    int tanggal;
    int bulan;
    int tahun;
}tgl;

typedef struct{
    char nama[20];
    char nomor[20];
    char alamat[20];
    char gender[20];
    char pekerjaan[20];
    tgl tanggalLahir;
    tgl tanggal;
    char kode_klinik[20];
    char nama_klinik[20];
    char poli_dokter[20];
    char kode_dokter[20];
    char nama_dokter[20];
    char spesialis_dokter[20];
    char no_nota[20];
    char no_regist[20];
} bio;

typedef struct{
	char nama[20];
	char username[20];
	int kode;
	char password[20];
}account;

account signin;
account signup;
bio id, ubah, regist;
int n = 8, titleprnt[8], pilihan, keluar, hfw;
char lanjut;
void Register();
void login();
void login_menu();
void mainmenu();
void pasien();
void tambah_pasien();
void lihat_pasien();
void edit_pasien();
void hapus_pasien();
void cari_pasien();
void dokter();
void tambah_dokter();
void lihat_dokter();
void edit_dokter();
void hapus_dokter();
void cari_dokter();
void poli();
void tambah_poli();
void lihat_poli();
void edit_poli();
void hapus_poli();
void cari_poli();
void regist_ulang();
void regis();
void cari_regist();
void lihat_regist();
void nota();
void lihat_nota();
void cetak_nota();

int n, i, offset;
char namafile[20];
FILE *f_struktur;
int main()
{
	do
	{
		SetConsoleTitleA("Program Layanan Rawat Jalan RS Sejahterah");
		system("color f0");
		system("cls");
		login_menu();
	}	while(keluar != 1);
	return 0;
}

void pasien()
{
	int pilih;
	system("cls");
	printf("\t\t Program Layanan Rawat Jalan RS Sejahterah \n");
	printf("\t\t _______________________________________\n");
	printf("\t\t|                                       |\n");
	printf("\t\t|1.Tambah Data Pasien\t\t\t|\n");
	printf("\t\t|2.Tampilkan Data Pasien\t\t|\n");
	printf("\t\t|3.Edit Data Pasien\t\t\t|\n");
	printf("\t\t|4.Hapus Data Pasien\t\t\t|\n");
	printf("\t\t|5.Cari Data Pasien\t\t\t|\n");
	printf("\t\t|99.Kembali\t\t\t\t|\n");
	printf("\t\t|_______________________________________|\n");
	printf("\t\tMasukkan Pilihan : "); scanf("%d", &pilih);
	
	switch(pilih)
	{
			case 1 : 
			{
				tambah_pasien();
				break;
			}
			case 2 : 
			{
				lihat_pasien();
				getch();
				pasien();
				break;
			}
			case 3 : 
			{
				edit_pasien();
				break;
			}
			case 4 : 
			{
				hapus_pasien();
				break;
			}
			case 5 :
			{
				cari_pasien();
				break;
			}
			case 99 : 
			{
				mainmenu();
				break;
			}
			default :pasien();
		}
	
	
}

void dokter()
{
	int pilih;
	system("cls");
	printf("\t\t Program Layanan Rawat Jalan RS Sejahterah \n");
	printf("\t\t _______________________________________\n");
	printf("\t\t|                                       |\n");
	printf("\t\t|1.Tambah Data Dokter\t\t\t|\n");
	printf("\t\t|2.Tampilkan Data Dokter\t\t|\n");
	printf("\t\t|3.Edit Data Dokter\t\t\t|\n");
	printf("\t\t|4.Hapus Data Dokter\t\t\t|\n");
	printf("\t\t|5.Cari Data Dokter\t\t\t|\n");
	printf("\t\t|99.Kembali\t\t\t\t|\n");
	printf("\t\t|_______________________________________|\n");
	printf("\t\tMasukkan Pilihan : "); scanf("%d", &pilih);
	
	switch(pilih)
	{
			case 1 : 
			{
				tambah_dokter();
				break;
			}
			case 2 : 
			{
				lihat_dokter();
				getch();
				dokter();
				break;
			}
			case 3 :
			{
				edit_dokter();
				break;
			}
			case 4 : 
			{
				hapus_dokter();
				break;
			}
			case 5 :
			{
				cari_dokter();
				break;
			}
			case 99 : 
			{
				mainmenu();
				break;
			}
			default : dokter();
			
	}
}

void poli()
{
	int pilih;
	system("cls");
	printf("\t\t Program Layanan Rawat Jalan RS Sejahterah \n");
	printf("\t\t _______________________________________\n");
	printf("\t\t|                                       |\n");
	printf("\t\t|1.Tambah Data Poliklinik\t\t|\n");
	printf("\t\t|2.Tampilkan Data Poliklinik\t\t|\n");
	printf("\t\t|3.Edit Data Poliklinik\t\t\t|\n");
	printf("\t\t|4.Hapus Data Poliklinik\t\t|\n");
	printf("\t\t|5.Cari Data Poliklinik\t\t\t|\n");
	printf("\t\t|99.Kembali\t\t\t\t|\n");
	printf("\t\t|_______________________________________|\n");
	printf("\t\tMasukkan Pilihan : "); scanf("%d", &pilih);
	
	switch(pilih)
	{
		case 1 : 
		{
			tambah_poli();
			break;
		}
		case 2 : 
		{
			lihat_poli();
			getch();
			poli();
			break;
		}
		case 3 : 
		{
			edit_poli();
			break;
		}
		case 4 : 
		{
			hapus_poli();
			break;
		}
		case 5 :
		{
			cari_poli();
			break;
		}
		case 99 : 
		{
			mainmenu();
			break;
		}
		default : poli();
	}
}

void regist_ulang()
{
	FILE *fptr;
	FILE *ptr;
	FILE *pt;
	FILE *pr;
	fptr = fopen("regist.txt","a+");
	ptr  = fopen("pasien.txt","r");
	pt   = fopen("poli.txt","r");
	pr   = fopen("dokter.txt","r");
	char key_kode[20];
	system("cls");
	printf("Masukkan Tanggal Registrasi : "); scanf("%d %d %d", &id.tanggal.tanggal, &id.tanggal.bulan, &id.tanggal.tahun);
	printf("Masukkan Nomor Registrasi   : "); scanf("%s", id.no_regist);
	system("cls");
	balik :
		lihat_pasien();
		printf("Masukkan Nama pasien yang ingin registrasi ulang : "); scanf("%s", key_kode);
		while(fscanf (ptr,"%s %s %s %s %s %d %d %d\n", id.nama, id.nomor, id.alamat, id.gender, id.pekerjaan, &id.tanggalLahir.tanggal,&id.tanggalLahir.bulan,&id.tanggalLahir.tahun) != EOF)
		{
    		if(strcmp(key_kode,id.nama) == 0)
			{
				system("cls");
				lihat_dokter();
				printf("Masukkan Nama Dokter : "); scanf("%s", regist.nama_dokter);
				system("cls");
				lihat_poli();
				printf("Masukkan Nama Poli Tujuan : "); scanf("%s", regist.nama_klinik);
				fprintf(fptr,"%d %d %d %s %s %s %s %s %s %d %d %d %s %s\n", id.tanggal.tanggal, id.tanggal.bulan, id.tanggal.tahun, id.no_regist, id.nama, id.nomor, id.alamat, id.gender, id.pekerjaan, id.tanggalLahir.tanggal, id.tanggalLahir.bulan, id.tanggalLahir.tahun, regist.nama_dokter, regist.nama_klinik);
			}
    	}
    fclose(fptr);
    fclose(ptr);
    fclose(pt);
    fclose(pr);
    regis();
}

void regis()
{
	int pilih;
	system("cls");
	printf("\t\t Program Layanan Rawat Jalan RS Sejahterah \n");
	printf("\t\t _______________________________________\n");
	printf("\t\t|                                       |\n");
	printf("\t\t|1.Registrasi Ulang\t\t\t|\n");
	printf("\t\t|2.Cari Data Registrasi\t\t\t|\n");
	printf("\t\t|3.Tampilkan Data Registrasi\t\t|\n");
	printf("\t\t|99.Kembali\t\t\t\t|\n");
	printf("\t\t|_______________________________________|\n");
	printf("\t\tMasukkan Pilihan : "); scanf("%d", &pilih);
	
	switch(pilih)
	{
		case 1 : 
		{
			regist_ulang();
			break;
		}
		case 2 : 
		{
			cari_regist();
			getch();
			break;
		}
		case 3 :
		{
			lihat_regist();
			getch();
			break;
		}
		case 99 : 
		{
			mainmenu();
			break;
		}
		default : regis();
	}
}

void lihat_regist()
{
    system("cls");
    FILE *fptr;
    fptr = fopen("regist.txt","r");
    
    while(fscanf(fptr,"%d %d %d %s %s %s %s %s %s %d %d %d %s %s\n", &id.tanggal.tanggal, &id.tanggal.bulan, &id.tanggal.tahun, id.no_regist, id.nama, id.nomor, id.alamat, id.gender, id.pekerjaan, &id.tanggalLahir.tanggal,&id.tanggalLahir.bulan,&id.tanggalLahir.tahun, regist.nama_dokter, regist.nama_klinik) != EOF)
	{
		system("cls");
		printf("Tanggal Registrasi : %d-%d-%d\n", id.tanggal.tanggal, id.tanggal.bulan, id.tanggal.tahun);
		printf("No Registrasi      : %s\n", id.no_regist);
		printf ("Nama              : %s\n" ,id.nama);
		printf ("No HP             : %s\n", id.nomor);
		printf ("Alamat            : %s\n", id.alamat);
		printf ("Jenis Kelamin     : %s\n", id.gender);
		printf ("Pekerjaan         : %s\n", id.pekerjaan);
		printf ("Tanggal lahir     : %d-%d-%d\n\n", id.tanggalLahir.tanggal,id.tanggalLahir.bulan,id.tanggalLahir.tahun);
		printf ("Dokter Yang Menangani : %s\n", regist.nama_dokter);
		printf ("Tempat Poliklinik : %s", regist.nama_klinik);
		getch();
	}
    
    fclose(fptr);
    regis();
}

void cari_regist()
{
	char key_kode[20];
	int cari, pilih;
	FILE *fptr;
	
	fptr = fopen("regist.txt", "r");
	ulang :
		system("cls");
		printf("Cari Berdasarkan\n1.Nama\n2.Tanggal lahir\nMasukkan pilihan anda : ");
		scanf("%d", &pilih);
		system("cls");
		lihat_pasien();
		
		switch(pilih)
		{
			case 1 :
				printf("Masukkan nama yang ingin dicari : "); scanf("%s", key_kode);
			    while(fscanf(fptr,"%d %d %d %s %s %s %s %s %s %d %d %d %s %s\n", &id.tanggal.tanggal, &id.tanggal.bulan, &id.tanggal.tahun, id.no_regist, id.nama, id.nomor, id.alamat, id.gender, id.pekerjaan, &id.tanggalLahir.tanggal,&id.tanggalLahir.bulan,&id.tanggalLahir.tahun, regist.nama_dokter, regist.nama_klinik) != EOF)
				{
					if(strcmp(key_kode,id.nama) == 0)
					{
						system("cls");
						printf("Tanggal Registrasi : %d-%d-%d\n", id.tanggal.tanggal, id.tanggal.bulan, id.tanggal.tahun);
						printf("No Registrasi      : %s\n", id.no_regist);
						printf ("Nama              : %s\n" ,id.nama);
				        printf ("No HP             : %s\n", id.nomor);
				        printf ("Alamat            : %s\n", id.alamat);
				        printf ("Jenis Kelamin     : %s\n", id.gender);
				        printf ("Pekerjaan         : %s\n", id.pekerjaan);
				        printf ("Tanggal lahir     : %d-%d-%d\n\n", id.tanggalLahir.tanggal,id.tanggalLahir.bulan,id.tanggalLahir.tahun);
				        printf ("Dokter Yang Menangani : %s\n", regist.nama_dokter);
				        printf ("Tempat Poliklinik : %s", regist.nama_klinik);
				        getch();
				        regis();
					}else{
						system("cls");
						printf("Data Tidak Ditemukan");
						getch();
						cari_regist();
					}
				}
				break;
			case 2 :
				printf("Masukkan tanggal lahir pasien : "); scanf("%d", &cari);
			    while(fscanf(fptr,"%d %d %d %s %s %s %s %s %s %d %d %d %s %s\n", &id.tanggal.tanggal, &id.tanggal.bulan, &id.tanggal.tahun, id.no_regist, id.nama, id.nomor, id.alamat, id.gender, id.pekerjaan, &id.tanggalLahir.tanggal,&id.tanggalLahir.bulan,&id.tanggalLahir.tahun, regist.nama_dokter, regist.nama_klinik) != EOF)
				{
					if(cari == id.tanggalLahir.tanggal)
					{
						system("cls");
						printf("Tanggal Registrasi : %d-%d-%d\n", id.tanggal.tanggal, id.tanggal.bulan, id.tanggal.tahun);
						printf("No Registrasi      : %s\n", id.no_regist);
						printf ("Nama              : %s\n" ,id.nama);
				        printf ("No HP             : %s\n", id.nomor);
				        printf ("Alamat            : %s\n", id.alamat);
				        printf ("Jenis Kelamin     : %s\n", id.gender);
				        printf ("Pekerjaan         : %s\n", id.pekerjaan);
				        printf ("Tanggal lahir     : %d-%d-%d\n\n", id.tanggalLahir.tanggal,id.tanggalLahir.bulan,id.tanggalLahir.tahun);
				        getch();
				        regis();
					}else
					{
						system("cls");
						printf("Data tidak ditemukan");
						getch();
						cari_regist();
					}
				}
			default : goto ulang;
		}
	fclose(fptr);
	getch();
	system("cls");
	regis();
}

void mainmenu()
{
	int pilih;
	system("cls");
	printf("\t\t Program Layanan Rawat Jalan RS Sejahterah \n");
	printf("\t\t _______________________________________\n");
	printf("\t\t|                                       |\n");
	printf("\t\t|1.Data Pasien\t\t\t\t|\n");
	printf("\t\t|2.Data Dokter\t\t\t\t|\n");
	printf("\t\t|3.Data Poliklinik\t\t\t|\n");
	printf("\t\t|4.Data Registrasi Ulang\t\t|\n");
	printf("\t\t|5.Nota\t\t\t\t\t|\n");
	printf("\t\t|99.Log Out\t\t\t\t|\n");
	printf("\t\t|_______________________________________|\n");
	printf("\t\tMasukkan Pilihan : "); scanf("%d", &pilih);
	
	switch(pilih)
	{
		case 1 : 
		{
			pasien();
			break;
		}
		case 2 : 
		{
			dokter();
			break;
		}
		case 3 : 
		{
			poli();
			break;
		}
		case 4 : 
		{
			regis();
			break;
		}
		case 5 : 
		{
			nota();
			break;
		}
		case 99 : 
		{
			login_menu();
			break;
		}
		default : mainmenu();
	}
}

void login_menu()
{
	int i = 0;
	system("cls");
	printf("\t\t Program Layanan Rawat Jalan RS Sejahterah \n");
	printf("\t\t|---------------------------------------|\n");
	printf("\t\t|1.Register\t\t\t\t|\n");
	printf("\t\t|2.Login\t\t\t\t|\n");
	printf("\t\t|99.Exit\t\t\t\t|\n");
	printf("\t\t|=======================================|\n");
	printf("\t\t Masukkan Pilihan : ");
	scanf("%d", &pilihan);
	system("cls");
	
	while(i != 1){
		switch(pilihan){
			case 1 : {
				Register();
				break;
			}
			case 2 : {
				login();
				break;
			}
			case 99 : {
				printf("Terimakasih Telah Menggunakan Program Kami ^^");
				exit(1);
			}
			default : login_menu();
		}
	}
}

void nota()
{
int i = 0;
	system("cls");
	printf("\t\t Program Layanan Rawat Jalan RS Sejahterah \n");
	printf("\t\t|---------------------------------------|\n");
	printf("\t\t|1.Cetak Nota\t\t\t\t|\n");
	printf("\t\t|2.Lihat Nota\t\t\t\t|\n");
	printf("\t\t|99.Kembali\t\t\t\t|\n");
	printf("\t\t|=======================================|\n");
	printf("\t\t Masukkan Pilihan : ");
	scanf("%d", &pilihan);
	system("cls");
	
	while(i != 1)
	{
		switch(pilihan)
		{
			case 1 : 
			{
				cetak_nota();
				break;
			}
			case 2 : 
			{
				lihat_nota();
				break;
			}
			case 99 : 
			{
				mainmenu();
				break;
			}
			default : nota();
		}
	}
}

void Register()
{
	int kode;
	f_struktur = fopen("register.txt","r+");
		
	regist:
		system("cls");
		printf ("Masukkan Kode Admin : "); 
		fflush(stdin); 
		scanf("%d", &kode);
		
		while(fscanf(f_struktur, "%s %d %s %s\n" , signup.nama, &signup.kode, signup.username, signup.password) != EOF )
		{
			if(signup.kode == kode)
			{
				printf("Kode %d sudah digunakan!\n", kode);
				getch();
				goto regist;
			}
		}
			
		printf("Masukkan Nama		: "); fflush(stdin); gets(signup.nama);
		signup.kode = kode;
		printf("Masukkan Username	: "); fflush(stdin); gets(signup.username);
		printf("Masukkan Password	: "); fflush(stdin); gets(signup.password);
		fprintf(f_struktur, "%s %d %s %s\n", signup.nama, signup.kode, signup.username, signup.password);
		fclose(f_struktur);
		login_menu();
}

void login()
{
	int i;
	char confirm;
	f_struktur = fopen("register.txt","r");
	
	loginpage:
		system("cls");
		printf("Masukkan Username	: "); fflush(stdin); gets(signin.username);
		printf("Masukkan Password	: "); fflush(stdin); gets(signin.password);
		printf("Anda yakin ingin masuk(Y/N)"); scanf("%c", &confirm);
		if(confirm == 'n' || confirm == 'N')
		{
			system("cls");
			login_menu();
		}
		system("cls");
	while(fscanf(f_struktur, "%s %d %s %s\n" , signup.nama, &signup.kode, signup.username, signup.password) != EOF )
	{
		if(strcmp(signin.username, signup.username) == 0)
		{
			if(strcmp(signin.password, signup.password) == 0)
			{
				i = 1;
				printf("SELAMAT DATANG :)\n");
				mainmenu();
			}
		}
	}
}

void tambah_pasien()
{
    system("cls");

    f_struktur = fopen("pasien.txt","a+");

    printf ("Masukkan Nama                      : "); fflush(stdin); gets(id.nama);
    printf ("Masukkan No HP                     : "); fflush(stdin); gets(id.nomor);
    printf ("Masukkan Alamat                    : "); fflush(stdin); gets(id.alamat);
    printf ("Masukkan Jenis Kelamin             : "); fflush(stdin); gets(id.gender);
    printf ("Masukkan Pekerjaan                 : "); fflush(stdin); gets(id.pekerjaan);
    printf ("Masukkan tanggal lahir(DD MM YY)   : "); scanf("%d %d %d",&id.tanggalLahir.tanggal,&id.tanggalLahir.bulan,&id.tanggalLahir.tahun);
    fprintf (f_struktur,"%s %s %s %s %s %d %d %d\n", id.nama, id.nomor, id.alamat, id.gender, id.pekerjaan, id.tanggalLahir.tanggal,id.tanggalLahir.bulan,id.tanggalLahir.tahun);
		
	fclose(f_struktur);
    getch();
    pasien();
}

void lihat_pasien()
{
    system("cls");
    f_struktur = fopen("pasien.txt","r");
    
    while(fscanf (f_struktur,"%s %s %s %s %s %d %d %d\n", id.nama, id.nomor, id.alamat, id.gender, id.pekerjaan, &id.tanggalLahir.tanggal,&id.tanggalLahir.bulan,&id.tanggalLahir.tahun) != EOF)
	{
    	
        printf ("Nama              : %s\n" ,id.nama);
        printf ("No HP             : %s\n", id.nomor);
        printf ("Alamat            : %s\n", id.alamat);
        printf ("Jenis Kelamin     : %s\n", id.gender);
        printf ("Pekerjaan         : %s\n", id.pekerjaan);
        printf ("Tanggal lahir     : %d-%d-%d\n\n", id.tanggalLahir.tanggal,id.tanggalLahir.bulan,id.tanggalLahir.tahun);
        
    }
    
    fclose(f_struktur);
}

void edit_pasien()
{
	FILE *fold;
	FILE *fnew;
	char key_kode[20];
	int pilih;
	
	fold = fopen("pasien.txt", "r");
	fnew = fopen("pasien_new.txt", "w+");
	
	system("cls");
	lihat_pasien();
	printf("Masukkan Nama Pasien yang Datanya akan diubah : ");
	scanf("%s", key_kode);
	
	while(fscanf(fold, "%s %s %s %s %s %d %d %d\n", id.nama, id.nomor, id.alamat, id.gender, id.pekerjaan, &id.tanggalLahir.tanggal,&id.tanggalLahir.bulan,&id.tanggalLahir.tahun) != EOF)
	{
		if(strcmp(key_kode, id.nama) == 0)
		{
			printf("Data yang ingin diubah?\n1. Nama\n2. No Hp\n3. Alamat\n4. Gender\n5. Pekerjaan\n6. Tanggal Lahir\nInput pilihan Anda : ");
			scanf("%d", &pilih);
			
			if(pilih == 1)
			{
				printf("Nama baru : "); scanf("%s", ubah.nama);
				fprintf(fnew, "%s %s %s %s %s %d %d %d\n", ubah.nama, id.nomor, id.alamat, id.gender, id.pekerjaan, id.tanggalLahir.tanggal,id.tanggalLahir.bulan,id.tanggalLahir.tahun);
				system("cls");
			}else if(pilih == 2)
			{
				printf("No Hp baru : "); scanf("%s", ubah.nomor);
				fprintf(fnew, "%s %s %s %s %s %d %d %d\n", id.nama, ubah.nomor, id.alamat, id.gender, id.pekerjaan, id.tanggalLahir.tanggal,id.tanggalLahir.bulan,id.tanggalLahir.tahun);
				system("cls");
			}else if(pilih == 3)
			{
				printf("Alamat baru : "); scanf("%s", ubah.alamat);
				fprintf(fnew, "%s %s %s %s %s %d %d %d\n", id.nama, id.nomor, ubah.alamat, id.gender, id.pekerjaan, id.tanggalLahir.tanggal,id.tanggalLahir.bulan,id.tanggalLahir.tahun);
				system("cls");
			}else if(pilih == 4)
			{
				printf("Gender baru : "); scanf("%s", ubah.gender);
				fprintf(fnew, "%s %s %s %s %s %d %d %d\n", id.nama, id.nomor, id.alamat, ubah.gender, id.pekerjaan, id.tanggalLahir.tanggal,id.tanggalLahir.bulan,id.tanggalLahir.tahun);
				system("cls");
			}else if(pilih == 5)
			{
				printf("Pekerjaan baru : "); scanf("%s", ubah.pekerjaan);
				fprintf(fnew, "%s %s %s %s %s %d %d %d\n", id.nama, id.nomor, id.alamat, id.gender, ubah.pekerjaan, id.tanggalLahir.tanggal,id.tanggalLahir.bulan,id.tanggalLahir.tahun);
				system("cls");
			}else if(pilih == 6)
			{
				printf("Tanggal Lahir baru(DD MM YY) : "); scanf("%d %d %d", &ubah.tanggalLahir.tanggal, &ubah.tanggalLahir.bulan, &ubah.tanggalLahir.tahun);
				fprintf(fnew, "%s %s %s %s %s %d %d %d\n", id.nama, id.nomor, id.alamat, id.gender, id.pekerjaan, ubah.tanggalLahir.tanggal, ubah.tanggalLahir.bulan, ubah.tanggalLahir.tahun);
				system("cls");
			}
		}else
		{
			fprintf(fnew, "%s %s %s %s %s %d %d %d\n", id.nama, id.nomor, id.alamat, id.gender, id.pekerjaan, id.tanggalLahir.tanggal,id.tanggalLahir.bulan,id.tanggalLahir.tahun);
		}
	}
	system("cls");
	fclose(fold);
	fclose(fnew);
	printf("Data sudah diubah");
	remove("pasien.txt");
	rename("pasien_new.txt","pasien.txt");
	getch();
	pasien();
}

void hapus_pasien()
{
    FILE *fold;
	FILE *fnew;
	char key_kode[20];
	int pilih;
	
	fold = fopen("pasien.txt", "r");
	fnew = fopen("pasien_new.txt", "w");
	
	system("cls");
	lihat_pasien();
	printf("Masukkan Nama Pasien yang Datanya akan diubah : ");
	scanf("%s", key_kode);
	while(fscanf(fold, "%s %s %s %s %s %d %d %d\n", id.nama, id.nomor, id.alamat, id.gender, id.pekerjaan, &id.tanggalLahir.tanggal,&id.tanggalLahir.bulan,&id.tanggalLahir.tahun) != EOF)
	{
		if(strcmp(key_kode,id.nama) != 0)
		{
			fprintf(fnew, "%s %s %s %s %s %d %d %d\n", id.nama, id.nomor, id.alamat, id.gender, id.pekerjaan, id.tanggalLahir.tanggal,id.tanggalLahir.bulan,id.tanggalLahir.tahun);
		}
	}
	printf("Data %s berhasil dihapus\n", key_kode);
	system("cls");
	fclose(fold);
	fclose(fnew);
	printf("Data sudah dihapus");
	remove("pasien.txt");
	rename("pasien_new.txt","pasien.txt");
	getch();
	pasien();
}

void tambah_dokter()
{
    system("cls");
	FILE *fptr;
    fptr = fopen("dokter.txt","a+");
	lihat_poli();
    printf ("Masukkan Kode              : "); fflush(stdin); gets(id.kode_dokter);
	printf ("Masukkan Nama              : "); fflush(stdin); gets(id.nama_dokter);
    printf ("Masukkan Spesialis         : "); fflush(stdin); gets(id.spesialis_dokter);
    printf ("Masukkan Poliklinik        : "); fflush(stdin); gets(id.poli_dokter);

    fprintf (fptr,"%s %s %s %s\n", id.kode_dokter, id.nama_dokter, id.spesialis_dokter, id.poli_dokter);
		
	fclose(fptr);
    getch();
    
    dokter();
}

void lihat_dokter()
{
    system("cls");
    f_struktur = fopen("dokter.txt","r");
    
    while(fscanf (f_struktur,"%s %s %s %s\n", id.kode_dokter, id.nama_dokter, id.spesialis_dokter, id.poli_dokter) != EOF)
	{
    	
        printf ("Kode              : %s\n" ,id.kode_dokter);
        printf ("Nama              : %s\n", id.nama_dokter);
        printf ("Spesialis         : %s\n", id.spesialis_dokter);
        printf ("Poli              : %s\n\n", id.poli_dokter);
        
    }
    
    fclose(f_struktur);
}

void edit_dokter()
{
	FILE *fold;
	FILE *fnew;
	char key_kode[20];
	int pilih;
	
	fold = fopen("dokter.txt", "r");
	fnew = fopen("dokter_new.txt", "w+");
	
	system("cls");
	lihat_dokter();
	printf("Masukkan Kode Dokter yang akan diubah : ");
	scanf("%s", key_kode);
	
    while(fscanf (fold,"%s %s %s %s\n", id.kode_dokter, id.nama_dokter, id.spesialis_dokter, id.poli_dokter) != EOF)
	{
    	
		if(strcmp(key_kode,id.kode_dokter) == 0)
		{
			printf("Data yang ingin diubah?\n1. Kode\n2. Nama\n3. Spesialis\n4. Poli\nInput pilihan Anda : ");
			scanf("%d", &pilih);
			
			if(pilih == 1)
			{
				printf("Kode baru : "); scanf("%s", ubah.kode_dokter);
				fprintf(fnew, "%s %s %s %s\n", ubah.kode_dokter, id.nama_dokter, id.spesialis_dokter, id.poli_dokter);
				system("cls");
			}else if(pilih == 2)
			{
				printf("Nama baru : "); scanf("%s", ubah.nama_dokter);
				fprintf(fnew, "%s %s %s %s\n", id.kode_dokter, ubah.nama_dokter, id.spesialis_dokter, id.poli_dokter);
				system("cls");
			}else if(pilih == 3)
			{
				printf("Spesialis baru : "); scanf("%s", ubah.spesialis_dokter);
				fprintf(fnew, "%s %s %s %s\n", id.kode_dokter, id.nama_dokter, ubah.spesialis_dokter, id.poli_dokter);
				system("cls");
			}else if(pilih == 4)
			{
				printf("Poli baru : "); scanf("%s", ubah.poli_dokter);
				fprintf(fnew, "%s %s %s %s\n", id.kode_dokter, id.nama_dokter, id.spesialis_dokter, ubah.poli_dokter);
				system("cls");
			}
		}else
		{
			fprintf(fnew, "%s %s %s %s\n", id.kode_dokter, id.nama_dokter, id.spesialis_dokter, id.poli_dokter);
		}
	}
	system("cls");
	fclose(fold);
	fclose(fnew);
	printf("Data sudah diubah");
	remove("dokter.txt");
	rename("dokter_new.txt","dokter.txt");
	getch();
	dokter();
}

void hapus_dokter()
{
    FILE *fold;
	FILE *fnew;
	char key_kode[20];
	int pilih;
	
	fold = fopen("dokter.txt", "r");
	fnew = fopen("dokter_new.txt", "w");
	
	system("cls");
	lihat_dokter();
	printf("Masukkan Kode Dokter yang Datanya Akan Dihapus : ");
	scanf("%s", key_kode);
	while(fscanf (fold,"%s %s %s %s\n", id.kode_dokter, id.nama_dokter, id.spesialis_dokter, id.poli_dokter) != EOF)
	{
		if(strcmp(key_kode,id.kode_dokter) != 0)
		{
			fprintf(fnew, "%s %s %s %s\n", id.kode_dokter, id.nama_dokter, id.spesialis_dokter, id.poli_dokter);
		}
	}
	system("cls");
	fclose(fold);
	fclose(fnew);
	printf("Data berhasil dihapus\n");
	remove("dokter.txt");
	rename("dokter_new.txt","dokter.txt");
	getch();
	dokter();
}

void tambah_poli()
{
    system("cls");

    f_struktur = fopen("poli.txt","a+");

    printf ("Masukkan Kode Klinik         : "); fflush(stdin); gets(id.kode_klinik);
	printf ("Masukkan Nama Klinik         : "); fflush(stdin); gets(id.nama_klinik);


    fprintf (f_struktur,"%s %s\n", id.kode_klinik, id.nama_klinik);
		
	fclose(f_struktur);
    getch();
    
    poli();
}

void lihat_poli()
{
    system("cls");
    f_struktur = fopen("poli.txt","r");
    
    while(fscanf (f_struktur,"%s %s\n", id.kode_klinik, id.nama_klinik) != EOF)
	{
    	
        printf ("Kode Klinik             : %s\n" ,id.kode_klinik);
        printf ("Nama Klinik             : %s\n\n", id.nama_klinik);
        
    }
    
    fclose(f_struktur);
}

void edit_poli()
{
	FILE *fold;
	FILE *fnew;
	char key_kode[20];
	int pilih;
	
	fold = fopen("poli.txt", "r");
	fnew = fopen("poli_new.txt", "w+");
	
	system("cls");
	lihat_poli();
	printf("Masukkan Kode Poli yang akan diubah : ");
	scanf("%s", key_kode);
	
    while(fscanf (fold,"%s %s\n", id.kode_klinik, id.nama_klinik) != EOF)
	{
    	
		if(strcmp(key_kode,id.kode_klinik) == 0)
		{
			printf("Data yang ingin diubah?\n1. Kode\n2. Nama\nInput pilihan Anda : ");
			scanf("%d", &pilih);
			
			if(pilih == 1)
			{
				printf("Kode baru : "); scanf("%s", ubah.kode_klinik);
				fprintf(fnew, "%s %s\n", ubah.kode_klinik, id.nama_klinik);
				system("cls");
			}else if(pilih == 2)
			{
				printf("Nama baru : "); scanf("%s", ubah.nama_klinik);
				fprintf(fnew, "%s %s\n", id.kode_klinik, ubah.nama_klinik);
				system("cls");
			}
		}else
		{
			fprintf(fnew, "%s %s\n", id.kode_klinik, id.nama_klinik);
		}
	}
	system("cls");
	fclose(fold);
	fclose(fnew);
	printf("Data sudah diubah");
	remove("poli.txt");
	rename("poli_new.txt","poli.txt");
	getch();
	poli();
}

void hapus_poli()
{
    FILE *fold;
	FILE *fnew;
	char key_kode[20];
	int pilih;
	
	fold = fopen("poli.txt", "r");
	fnew = fopen("poli_new.txt", "w");
	
	system("cls");
	lihat_poli();
	printf("Masukkan Kode Poliklinik yang Datanya Akan Dihapus : ");
	scanf("%s", key_kode);
	while(fscanf (fold,"%s %s\n", id.kode_klinik, id.nama_klinik) != EOF)
	{
		getch();
		if(strcmp(key_kode,id.kode_klinik) != 0)
		{
			fprintf(fnew, "%s %s\n", id.kode_klinik, id.nama_klinik);
		}
	}
	system("cls");
	fclose(fold);
	fclose(fnew);
	printf("Data berhasil dihapus\n");
	remove("poli.txt");
	rename("poli_new.txt","poli.txt");
	getch();
	poli();
}

void cari_poli()
{
	char key_kode[20];
	FILE *fptr;
	
	fptr = fopen("poli.txt", "r");
	
	system("cls");
	lihat_poli();
	printf("Masukkan Nama Poli yang akan dicari : ");
	scanf("%s", key_kode);
	system("cls");
    while(fscanf (fptr,"%s %s\n", id.kode_klinik, id.nama_klinik) != EOF)
	{
		if(strcmp(key_kode,id.nama_klinik) == 0)
		{
			printf("Berikut ini data yang anda cari :\n");
			printf ("Kode Klinik             : %s\n" ,id.kode_klinik);
        	printf ("Nama Klinik             : %s\n\n", id.nama_klinik);
		}
	}
	fclose(f_struktur);
	getch();
	system("cls");
	poli();
}

void cari_dokter()
{
	char key_kode[20];
	FILE *fptr;
	
	fptr = fopen("dokter.txt", "r");
	
	system("cls");
	lihat_dokter();
	printf("Masukkan Nama Dokter yang akan dicari : ");
	scanf("%s", key_kode);
	system("cls");
    while(fscanf (fptr,"%s %s %s %s\n", id.kode_dokter, id.nama_dokter, id.spesialis_dokter, id.poli_dokter) != EOF)
	{
		if(strcmp(key_kode,id.nama_dokter) == 0)
		{	
	        printf ("Kode              : %s\n" ,id.kode_dokter);
	        printf ("Nama              : %s\n", id.nama_dokter);
	        printf ("Spesialis         : %s\n", id.spesialis_dokter);
	        printf ("Poli              : %s\n\n", id.poli_dokter);
    	}
	}
	fclose(fptr);
	getch();
	system("cls");
	dokter();
}

void cari_pasien()
{
	char key_kode[20];
	int cari, pilih;
	FILE *fptr;
	
	fptr = fopen("pasien.txt", "r");
	ulang :
		system("cls");
		printf("Cari Berdasarkan\n1.Nama\n2.Tanggal lahir\nMasukkan pilihan anda : ");
		scanf("%d", &pilih);
		system("cls");
		lihat_pasien();
		
		switch(pilih)
		{
			case 1 :
				printf("Masukkan nama yang ingin dicari : "); scanf("%s", key_kode);
			    while(fscanf (fptr,"%s %s %s %s %s %d %d %d\n", id.nama, id.nomor, id.alamat, id.gender, id.pekerjaan, &id.tanggalLahir.tanggal,&id.tanggalLahir.bulan,&id.tanggalLahir.tahun) != EOF)
				{
					if(strcmp(key_kode,id.nama) == 0)
					{
						system("cls");
						printf ("Nama              : %s\n" ,id.nama);
				        printf ("No HP             : %s\n", id.nomor);
				        printf ("Alamat            : %s\n", id.alamat);
				        printf ("Jenis Kelamin     : %s\n", id.gender);
				        printf ("Pekerjaan         : %s\n", id.pekerjaan);
				        printf ("Tanggal lahir     : %d-%d-%d\n\n", id.tanggalLahir.tanggal,id.tanggalLahir.bulan,id.tanggalLahir.tahun);
					}
				}
				break;
			case 2 :
				printf("Masukkan tanggal lahir pasien : "); scanf("%d", &cari);
				while(fscanf (fptr,"%s %s %s %s %s %d %d %d\n", id.nama, id.nomor, id.alamat, id.gender, id.pekerjaan, &id.tanggalLahir.tanggal,&id.tanggalLahir.bulan,&id.tanggalLahir.tahun) != EOF)
				{
					if(cari == id.tanggalLahir.tanggal)
					{
						system("cls");
						printf ("Nama              : %s\n" ,id.nama);
				        printf ("No HP             : %s\n", id.nomor);
				        printf ("Alamat            : %s\n", id.alamat);
				        printf ("Jenis Kelamin     : %s\n", id.gender);
				        printf ("Pekerjaan         : %s\n", id.pekerjaan);
				        printf ("Tanggal lahir     : %d-%d-%d\n\n", id.tanggalLahir.tanggal,id.tanggalLahir.bulan,id.tanggalLahir.tahun);
					}
				}
				break;
			default : cari_pasien();
		}
	fclose(fptr);
	getch();
	system("cls");
	pasien();
}

void cetak_nota()
{
	char key_kode[20];
	int harga, daftar, tanggal, bulan, tahun;
	FILE *fptr;
	FILE *ptr;
	
	ptr = fopen("regist.txt", "r");
	fptr = fopen("nota.txt", "a+");
	printf("Tanggal(DD MM YY)         : "); scanf("%d %d %d", &tanggal, &bulan, &tahun);
	printf("Masukkan Nomor Nota       : "); scanf("%s", id.no_nota);
	sini :
		system("cls");
		lihat_pasien();
		printf("Masukkan Nama Pasien : "); scanf("%s", key_kode);
		while(fscanf(ptr,"%d %d %d %s %s %s %s %s %s %d %d %d %s %s\n", &id.tanggal.tanggal, &id.tanggal.bulan, &id.tanggal.tahun, id.no_regist, id.nama, id.nomor, id.alamat, id.gender, id.pekerjaan, &id.tanggalLahir.tanggal,&id.tanggalLahir.bulan,&id.tanggalLahir.tahun, regist.nama_dokter, regist.nama_klinik) != EOF)
		{
			if(strcmp(key_kode,id.nama) == 0)
			{
				system("cls");
				printf("Masukkan Biaya Konsultasi : Rp."); scanf("%d", &harga);
				printf("Masukkan Biaya Pendaftaran(jika pasien baru) : Rp."); scanf("%d", &daftar);
				system("cls");
				printf("==================================================================\n");
		        printf("||\t\t          RS Sejahtera           \t\t||\n");
		        printf("||\t\t                               \t\t\t||\n");
		        printf("==================================================================\n");
		        printf("||Tanggal          : %d-%d-%d          \t\t\t||\n", tanggal, bulan, tahun);
		        printf("||No Nota          : %s               \t\t\t\t||\n", id.no_nota);
		        printf("||Nama Pasien      : %s                          \t\t||\n", id.nama);
		        printf("||No HP            : %s                      \t\t||\n", id.nomor);
		        printf("||Jenis Kelamin    : %s                          \t\t||\n", id.gender);
		        printf("||Tanggal Lahir    : %d-%d-%d         \t\t\t\t||\n", id.tanggalLahir.tanggal, id.tanggalLahir.bulan, id.tanggalLahir.tahun);
		        printf("||Nama Dokter      : %s                          \t\t||\n", regist.nama_dokter);
		        printf("||Nama Poliklinik  : %s                          \t\t||\n", regist.nama_klinik);
		        printf("||--------------------------------------------------------------||\n");
		        printf("||Biaya Konsultasi : %d                          \t\t||\n", harga);
		        printf("||Total Bayar      : %d                          \t\t||\n", harga + daftar);
		        printf("==================================================================\n");
		        getch();
		        fprintf(fptr,"%d %d %d %s %s %s %s %d %d %d %s %s %d %d\n", tanggal, bulan, tahun, id.no_nota, id.nama, id.nomor, id.gender, id.tanggalLahir.tanggal, id.tanggalLahir.bulan, id.tanggalLahir.tahun, regist.nama_dokter, regist.nama_klinik, harga, daftar);
			}else
			{
				printf("Pasien Belum Terdaftar\n");
				getch();
				goto sini;
			}
		}
		getch();
		fclose(ptr);
		fclose(fptr);
		nota();
}

void lihat_nota()
{
	char key_kode[20];
	int harga, daftar, tanggal, bulan, tahun;
	FILE *ptr;
	ptr = fopen("nota.txt","r");
	
	while(fscanf(ptr,"%d %d %d %s %s %s %s %d %d %d %s %s %d %d\n", &tanggal, &bulan, &tahun, id.no_nota, id.nama, id.nomor, id.gender, &id.tanggalLahir.tanggal, &id.tanggalLahir.bulan, &id.tanggalLahir.tahun, regist.nama_dokter, regist.nama_klinik, &harga, &daftar) != EOF )
	{
			system("cls");
			printf("==================================================================\n");
	        printf("||\t\t          RS Sejahtera           \t\t||\n");
	        printf("||\t\t                               \t\t\t||\n");
	        printf("==================================================================\n");
	        printf("||Tanggal          : %d-%d-%d          \t\t\t||\n", tanggal, bulan, tahun);
	        printf("||No Nota          : %s               \t\t\t\t||\n", id.no_nota);
	        printf("||Nama Pasien      : %s                          \t\t||\n", id.nama);
	        printf("||No HP            : %s                      \t\t||\n", id.nomor);
	        printf("||Jenis Kelamin    : %s                          \t\t||\n", id.gender);
	        printf("||Tanggal Lahir    : %d-%d-%d         \t\t\t\t||\n", id.tanggalLahir.tanggal, id.tanggalLahir.bulan, id.tanggalLahir.tahun);
	        printf("||Nama Dokter      : %s                          \t\t||\n", regist.nama_dokter);
	        printf("||Nama Poliklinik  : %s                          \t\t||\n", regist.nama_klinik);
	        printf("||--------------------------------------------------------------||\n");
	        printf("||Biaya Konsultasi : %d                          \t\t||\n", harga);
	        printf("||Total Bayar      : %d                          \t\t||\n", daftar + harga);
	        printf("==================================================================\n\n");
	        
	}
	
	fclose(ptr);
	getch();
	nota();
}
