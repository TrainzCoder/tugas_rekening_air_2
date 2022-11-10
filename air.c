#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ADMINISTRASI 2500
#define BPM_R 1000
#define BPM_U 2000

// deklarasi variable yang dibutuhkan
char nama_konsumen[40], alamat[50];
float tarif_per_kubik, biaya_per_kubik, tagihan, denda;
int pemakaian_bulan_lalu, pemakaian_bulan_ini;

// deklarasi fungsi dan prosedur
int main();
void menu_golongan();

void close()
{
  printf("\n\tTekan enter untuk melanjutkan...");
  getchar();
  system("cls");
}

void end()
{
  printf("\n\t========================================================");
  printf("\n\t       Terima Kasih Telah Menggunakan Layanan Kami      ");
  printf("\n\t========================================================");
  getchar();
  system("cls");
}

void ulang()
{
  int menu;
  printf("\n\n\t--------------------------------------------------------");
  printf("\n\tApakah anda ingin mengulang ?            ");
  printf("\n\t--------------------------------------------------------");
  printf("\n\t[1] Ya              ");
  printf("\n\t[2] Tidak           ");
  printf("\n\t--------------------------------------------------------");
  printf("\n\tMasukkan pilihan  : ");
  while (scanf("%d", &menu) == 0 || menu < 1 || menu > 2)
  {
    printf("\t---------------------------------------");
    printf("\n\tKarakter yang anda masukan salah");
    printf("\n\t,asukan harus berupa angka");
    printf("\n\t---------------------------------------");
    printf("\n\tMasukkan pilihan : ");
    while (menu = getchar() != '\n')
      ;
  }

  switch (menu)
  {
  case 1:
    close();
    main();
    break;
  case 2:
    close();
    end();
    break;
  }
}

void open()
{
  printf("\n\t=========================================================");
  printf("\n\t                      Selamat datang                     ");
  printf("\n\t         Silahkan isi data diri terlebih dahulu!         ");
  printf("\n\t=========================================================");

  printf("\n\tMasukan nama anda  : ");
  fgets(nama_konsumen, 40, stdin);
  nama_konsumen[strcspn(nama_konsumen, "\n")] = '\0';

  printf("\n\tMasukan alamat anda  : ");
  fgets(alamat, 50, stdin);
  alamat[strcspn(alamat, "\n")] = '\0';

  close();
}

void cetak(char nama[], char alamat[], char golongan[], float bpm, float denda, float biaya_per_kubik, float tagihan)
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  FILE *fptr;

  fptr = fopen("bukti-pembayaran.txt", "w");

  if (fptr == NULL)
  {
    printf("Unable to create file.\n");
    exit(EXIT_FAILURE);
  }

  fprintf(fptr, "\n\t===============================================================");
  fprintf(fptr, "\n\t    Toko Aizen Dewa Satir \n");
  fprintf(fptr, "\n\t---------------------------------------------------------------");
  fprintf(fptr, "\n\t                      BUKTI PEMBAYARAN AIR                   ");
  fprintf(fptr, "\n\t---------------------------------------------------------------\n");
  fprintf(fptr, "\n\t  Nama                      : %s", nama);
  fprintf(fptr, "\n\t  Alamat                    : %s", alamat);
  fprintf(fptr, "\n\t  Tgl Pembayaran            : %d-%02d-%02d %02d:%02d:%02d ", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
  fprintf(fptr, "\n\t  Golongan                  : %s", golongan);
  fprintf(fptr, "\n\t  Biaya Administrasi        : Rp. 2500");
  fprintf(fptr, "\n\t  Biaya BPM                 : Rp. %2.f", bpm);
  fprintf(fptr, "\n\t  Biaya Denda               : Rp. %2.f", denda);
  fprintf(fptr, "\n\t  Biaya Pemakaian Air(m^3)  : Rp. %2.f", biaya_per_kubik);
  fprintf(fptr, "\n\n\t  Jumlah Tagihan anda  : Rp. %2.f", tagihan);
  fprintf(fptr, "\n\n\n\t=============================================================");

  fclose(fptr);

  printf("\n\tBukti pembayaran berhasil dicetak!");
  ulang();
}

void konfirmasi_cetak(char nama[], char alamat[], char golongan[], float bpm, float denda, float biaya_per_kubik, float tagihan)
{
  int menu;
  printf("\n\n\t--------------------------------------------------------");
  printf("\n\tApakah anda ingin mencetak bukti pembayaran ?            ");
  printf("\n\t--------------------------------------------------------");
  printf("\n\t[1] Ya              ");
  printf("\n\t[2] Tidak           ");
  printf("\n\t--------------------------------------------------------");
  printf("\n\tMasukkan pilihan  : ");
  while (scanf("%d", &menu) == 0 || menu < 1 || menu > 2)
  {
    printf("\t---------------------------------------");
    printf("\n\tKarakter yang anda masukan salah");
    printf("\n\t,asukan harus berupa angka");
    printf("\n\t---------------------------------------");
    printf("\n\tMasukkan pilihan : ");
    while (menu = getchar() != '\n')
      ;
  }

  switch (menu)
  {
  case 1:
    cetak(nama, alamat, golongan, bpm, denda, biaya_per_kubik, tagihan);
    break;
  case 2:
    ulang();
    break;
  }
}

void format(char nama[], char alamat[], char golongan[], float bpm, float denda, float biaya_per_kubik, float tagihan)
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  printf("\n\t===============================================================");
  printf("\n\t    Toko Aizen Dewa Satir \n");
  printf("\n\t---------------------------------------------------------------");
  printf("\n\t                      BUKTI PEMBAYARAN AIR                   ");
  printf("\n\t---------------------------------------------------------------\n");
  printf("\n\t  Nama                      : %s", nama);
  printf("\n\t  Alamat                    : %s", alamat);
  printf("\n\t  Tgl Pembayaran            : %d-%02d-%02d %02d:%02d:%02d ", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
  printf("\n\t  Golongan                  : %s", golongan);
  printf("\n\t  Biaya Administrasi        : Rp. 2500");
  printf("\n\t  Biaya BPM                 : Rp. %2.f", bpm);
  printf("\n\t  Biaya Denda               : Rp. %2.f", denda);
  printf("\n\t  Biaya Pemakaian Air(m^3)  : Rp. %2.f", biaya_per_kubik);
  printf("\n\n\t  Jumlah Tagihan anda  : Rp. %2.f", tagihan);
  printf("\n\n\n\t=============================================================");

  konfirmasi_cetak(nama, alamat, golongan, bpm, denda, biaya_per_kubik, tagihan);
}

void non_niaga_subsidi()
{
  int menu;
  printf("\n\t=========================================================");
  printf("\n\t            Silahkan pilih kategori yang sesuai          ");
  printf("\n\t=========================================================");
  printf("\n\tBerdasarkan sumber daya listrik dan terdapat jalan       ");
  printf("\n\tdengan kelebaran sesuai pilihan termasuk saluran got     ");
  printf("\n\t=========================================================");
  printf("\n\t [1] Sumber daya listrik 450 VA  (0-3.99) meter  ");
  printf("\n\t [2] Sumber daya listrik 900 VA  (0-3.99) meter  ");
  printf("\n\t [3] Sumber daya listrik 450 VA  (4-6.99) meter  ");
  printf("\n\t [4] Sumber daya listrik 900 VA  (4-6.99) meter  ");
  printf("\n\t [5] Sumber daya listrik 450 VA  (7-10.0) meter  ");
  printf("\n\t [6] Sumber daya listrik 900 VA  (7-10.0) meter  ");
  printf("\n\t [7] Sumber daya listrik 450 VA  (>10) meter     ");
  printf("\n\t [8] Sumber daya listrik 900 VA  (>10) meter     ");
  printf("\n\tSilahkan pilih kategori sesuai nomor : ");
  while (scanf("%d", &menu) == 0 || menu < 1 || menu > 8)
  {
    printf("\t---------------------------------------");
    printf("\n\tNomor yang anda masukan salah");
    printf("\n\tSilahkan masukan ulang");
    printf("\n\t---------------------------------------");
    printf("\n\tSilahkan pilih kategori sesuai nomor : ");
    while (menu = getchar() != '\n')
      ;
  }
  close();

  printf("\n\t=========================================================");
  printf("\n\t                   Non Niaga Bersubsidi                  ");
  printf("\n\t=========================================================");
  printf("\n\tMasukan pemakaian sebelumnya (m^3) : ");
  while (scanf("%d", &pemakaian_bulan_lalu) == 0)
  {
    printf("\t---------------------------------------");
    printf("\n\tNilai yang anda masukan salah");
    printf("\n\tSilahkan masukan ulang");
    printf("\n\t---------------------------------------");
    printf("\n\tMasukan pemakaian sebelumnya (m^3) : ");
    while (pemakaian_bulan_lalu = getchar() != '\n')
      ;
  }
  printf("\n\tMasukan pemakaian saat ini (m^3) : ");
  while (scanf("%d", &pemakaian_bulan_ini) == 0 || pemakaian_bulan_ini < pemakaian_bulan_lalu)
  {
    printf("\t---------------------------------------");
    printf("\n\tNilai yang anda masukan salah");
    printf("\n\tSilahkan masukan ulang");
    printf("\n\t---------------------------------------");
    printf("\n\tMasukan pemakaian saat ini (m^3) : ");
    while (pemakaian_bulan_ini = getchar() != '\n')
      ;
  }

  float pemakaian = pemakaian_bulan_ini - pemakaian_bulan_lalu;
  close();

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  if (menu == 1)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 1780 : 5880;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_R + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_R + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "D1-1", BPM_R, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 2)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 2060 : 5940;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_R + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_R + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "D1-2", BPM_R, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 3)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 2340 : 6000;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_R + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_R + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "D2-1", BPM_R, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 4)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 2620 : 6060;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_R + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_R + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "D2-2", BPM_R, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 5)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 2900 : 6120;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_R + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_R + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "D3-1", BPM_R, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 6)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 3180 : 6180;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_R + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_R + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "D3-2", BPM_R, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 7)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 3460 : 6240;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_R + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_R + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "D4-1", BPM_R, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 8)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 3740 : 6300;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_R + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_R + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "D4-2", BPM_R, denda, biaya_per_kubik, tagihan);
  }
}

void non_niaga_tanpa_subsidi()
{
  int menu;

  printf("\n\t=========================================================");
  printf("\n\t            Silahkan pilih kategori yang sesuai          ");
  printf("\n\t=========================================================");
  printf("\n\tBerdasarkan sumber daya listrik dan terdapat jalan       ");
  printf("\n\tdengan kelebaran sesuai pilihan termasuk saluran got     ");
  printf("\n\t=========================================================");
  printf("\n\t [1] Sumber daya listrik 1.300 VA  (0-3.99) meter  ");
  printf("\n\t [2] Sumber daya listrik > 1.300 VA  (0-3.99) meter  ");
  printf("\n\t [3] Sumber daya listrik 1.300 VA  (4-6.99) meter  ");
  printf("\n\t [4] Sumber daya listrik > 1.300 VA  (4-6.99) meter  ");
  printf("\n\t [5] Sumber daya listrik 1.300 VA  (7-10.0) meter  ");
  printf("\n\t [6] Sumber daya listrik > 1.300 VA  (7-10.0) meter  ");
  printf("\n\t [7] Sumber daya listrik 1.300 VA  (>10) meter     ");
  printf("\n\t [8] Sumber daya listrik > 1.300 VA  (>10) meter     ");
  printf("\n\t---------------------------------------------------------");
  printf("\n\t Dan jika di rumahnya terdapat usaha");
  printf("\n\t dengan sumber daya listrik sesuai ketentuan dibawah");
  printf("\n\t---------------------------------------------------------");
  printf("\n\t [9] Sumber daya listrik 1.300 VA  (0-3.99) meter  ");
  printf("\n\t [10] Sumber daya listrik > 1.300 VA  (0-3.99) meter  ");
  printf("\n\t [11] Sumber daya listrik 1.300 VA  (4-6.99) meter  ");
  printf("\n\t [12] Sumber daya listrik > 1.300 VA  (4-6.99) meter  ");
  printf("\n\tSilahkan pilih kategori sesuai nomor : ");
  while (scanf("%d", &menu) == 0 || menu < 1 || menu > 12)
  {
    printf("\t---------------------------------------");
    printf("\n\tNomor yang anda masukan salah");
    printf("\n\tSilahkan masukan ulang");
    printf("\n\t---------------------------------------");
    printf("\n\tSilahkan pilih kategori sesuai nomor : ");
    while (menu = getchar() != '\n')
      ;
  }
  close();

  printf("\n\t=========================================================");
  printf("\n\t              Non Niaga Tanpa Bersubsidi                 ");
  printf("\n\t=========================================================");
  printf("\n\tMasukan pemakaian sebelumnya (m^3) : ");
  while (scanf("%d", &pemakaian_bulan_lalu) == 0)
  {
    printf("\t---------------------------------------");
    printf("\n\tNilai yang anda masukan salah");
    printf("\n\tSilahkan masukan ulang");
    printf("\n\t---------------------------------------");
    printf("\n\tMasukan pemakaian sebelumnya (m^3) : ");
    while (pemakaian_bulan_lalu = getchar() != '\n')
      ;
  }
  printf("\n\tMasukan pemakaian saat ini (m^3) : ");
  while (scanf("%d", &pemakaian_bulan_ini) == 0 || pemakaian_bulan_ini < pemakaian_bulan_lalu)
  {
    printf("\t---------------------------------------");
    printf("\n\tNilai yang anda masukan salah");
    printf("\n\tSilahkan masukan ulang");
    printf("\n\t---------------------------------------");
    printf("\n\tMasukan pemakaian saat ini (m^3) : ");
    while (pemakaian_bulan_ini = getchar() != '\n')
      ;
  }

  float pemakaian = pemakaian_bulan_ini - pemakaian_bulan_lalu;
  close();

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  if (menu == 1)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 6340 : 9600;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_R + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_R + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "D1-3", BPM_R, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 2)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 6420 : 9650;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_R + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_R + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "D1-4", BPM_R, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 3)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 6490 : 9800;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_R + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_R + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "D2-3", BPM_R, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 4)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 6570 : 9950;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_R + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_R + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "D2-4", BPM_R, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 5)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 6640 : 10100;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_R + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_R + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "D3-3", BPM_R, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 6)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 6720 : 10250;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_R + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_R + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "D3-4", BPM_R, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 7)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 6790 : 10400;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_R + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_R + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "D4-3", BPM_R, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 8)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 6870 : 10550;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_R + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_R + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "D4-4", BPM_R, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 9)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 6940 : 10700;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_R + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_R + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "D5-1", BPM_R, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 10)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 7020 : 10850;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_R + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_R + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "D5-2", BPM_R, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 11)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 7090 : 11000;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_R + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_R + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "D5-3", BPM_R, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 12)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 7170 : 11150;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_R + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_R + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "D5-4", BPM_R, denda, biaya_per_kubik, tagihan);
  }
}

void rumah_tangga()
{
  int menu;
  printf("\n\t=========================================================");
  printf("\n\t                  Golongan Rumah Tangga                  ");
  printf("\n\t=========================================================");
  printf("\n\t[1] Non Niaga Bersubsidi");
  printf("\n\t[2] Non Niaga tanpa Bersubsidi");
  printf("\n\t---------------------------------------------------------");
  printf("\n\t[0] Kembali");
  printf("\n\t=========================================================");
  printf("\n\tSilahkan pilih golongan sesuai nomor : ");
  while (scanf("%d", &menu) == 0 || menu < 0 || menu > 2)
  {
    printf("\t---------------------------------------");
    printf("\n\tNomor yang anda masukan salah");
    printf("\n\tSilahkan masukan ulang");
    printf("\n\t---------------------------------------");
    printf("\n\tSilahkan pilih golongan sesuai nomor : ");
    while (menu = getchar() != '\n')
      ;
  }
  close();
  switch (menu)
  {
  case 1:
    non_niaga_subsidi();
    break;
  case 2:
    non_niaga_tanpa_subsidi();
    break;
  default:
    menu_golongan();
  }
}

void niaga_kecil()
{
  int menu;
  printf("\n\t=========================================================");
  printf("\n\t            Silahkan pilih kategori yang sesuai          ");
  printf("\n\t=========================================================");
  printf("\n\tmemiliki bidang usaha dan di depan usaha terdapat        ");
  printf("\n\tjalan dengan kelebaran 0-6.99 meter termasuk got dan     ");
  printf("\n\tsumber daya listrik sesuai dibawah ini   ");
  printf("\n\t=========================================================");
  printf("\n\t [1] Sumber daya listrik 450 VA     ");
  printf("\n\t [2] Sumber daya listrik 900 VA     ");
  printf("\n\t [3] Sumber daya listrik 1300 VA    ");
  printf("\n\t [4] Sumber daya listrik > 1300 VA  ");
  printf("\n\tSilahkan pilih kategori sesuai nomor : ");
  while (scanf("%d", &menu) == 0 || menu < 1 || menu > 4)
  {
    printf("\t---------------------------------------");
    printf("\n\tNomor yang anda masukan salah");
    printf("\n\tSilahkan masukan ulang");
    printf("\n\t---------------------------------------");
    printf("\n\tSilahkan pilih kategori sesuai nomor : ");
    while (menu = getchar() != '\n')
      ;
  }
  close();

  printf("\n\t=========================================================");
  printf("\n\t                        Niaga Kecil                      ");
  printf("\n\t=========================================================");
  printf("\n\tMasukan pemakaian sebelumnya (m^3) : ");
  while (scanf("%d", &pemakaian_bulan_lalu) == 0)
  {
    printf("\t---------------------------------------");
    printf("\n\tNilai yang anda masukan salah");
    printf("\n\tSilahkan masukan ulang");
    printf("\n\t---------------------------------------");
    printf("\n\tMasukan pemakaian sebelumnya (m^3) : ");
    while (pemakaian_bulan_lalu = getchar() != '\n')
      ;
  }
  printf("\n\tMasukan pemakaian saat ini (m^3) : ");
  while (scanf("%d", &pemakaian_bulan_ini) == 0 || pemakaian_bulan_ini < pemakaian_bulan_lalu)
  {
    printf("\t---------------------------------------");
    printf("\n\tNilai yang anda masukan salah");
    printf("\n\tSilahkan masukan ulang");
    printf("\n\t---------------------------------------");
    printf("\n\tMasukan pemakaian saat ini (m^3) : ");
    while (pemakaian_bulan_ini = getchar() != '\n')
      ;
  }

  float pemakaian = pemakaian_bulan_ini - pemakaian_bulan_lalu;
  close();

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  if (menu == 1)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 9200 : 10950;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_U + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_U + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "E1-1", BPM_U, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 2)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 9500 : 11250;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_U + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_U + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "E1-2", BPM_U, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 3)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 9800 : 11550;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_U + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_U + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "E1-3", BPM_U, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 4)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 10100 : 11850;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_U + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_U + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "E1-4", BPM_U, denda, biaya_per_kubik, tagihan);
  }
}

void niaga_sedang()
{
  int menu;
  printf("\n\t=========================================================");
  printf("\n\t            Silahkan pilih kategori yang sesuai          ");
  printf("\n\t=========================================================");
  printf("\n\tmemiliki bidang usaha dan di depan usaha terdapat        ");
  printf("\n\tjalan dengan kelebaran 7 - 10 meter termasuk got dan     ");
  printf("\n\tsumber daya listrik sesuai dibawah ini   ");
  printf("\n\t=========================================================");
  printf("\n\t [1] Sumber daya listrik 450 VA     ");
  printf("\n\t [2] Sumber daya listrik 900 VA     ");
  printf("\n\t [3] Sumber daya listrik 1300 VA    ");
  printf("\n\t [4] Sumber daya listrik > 1300 VA  ");
  printf("\n\tSilahkan pilih kategori sesuai nomor : ");
  while (scanf("%d", &menu) == 0 || menu < 1 || menu > 4)
  {
    printf("\t---------------------------------------");
    printf("\n\tNomor yang anda masukan salah");
    printf("\n\tSilahkan masukan ulang");
    printf("\n\t---------------------------------------");
    printf("\n\tSilahkan pilih kategori sesuai nomor : ");
    while (menu = getchar() != '\n')
      ;
  }
  close();

  printf("\n\t=========================================================");
  printf("\n\t                       Niaga Sedang                      ");
  printf("\n\t=========================================================");
  printf("\n\tMasukan pemakaian sebelumnya (m^3) : ");
  while (scanf("%d", &pemakaian_bulan_lalu) == 0)
  {
    printf("\t---------------------------------------");
    printf("\n\tNilai yang anda masukan salah");
    printf("\n\tSilahkan masukan ulang");
    printf("\n\t---------------------------------------");
    printf("\n\tMasukan pemakaian sebelumnya (m^3) : ");
    while (pemakaian_bulan_lalu = getchar() != '\n')
      ;
  }
  printf("\n\tMasukan pemakaian saat ini (m^3) : ");
  while (scanf("%d", &pemakaian_bulan_ini) == 0 || pemakaian_bulan_ini < pemakaian_bulan_lalu)
  {
    printf("\t---------------------------------------");
    printf("\n\tNilai yang anda masukan salah");
    printf("\n\tSilahkan masukan ulang");
    printf("\n\t---------------------------------------");
    printf("\n\tMasukan pemakaian saat ini (m^3) : ");
    while (pemakaian_bulan_ini = getchar() != '\n')
      ;
  }

  float pemakaian = pemakaian_bulan_ini - pemakaian_bulan_lalu;
  close();

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  if (menu == 1)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 10400 : 12150;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_U + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_U + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "E2-1", BPM_U, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 2)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 10700 : 12550;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_U + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_U + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "E2-2", BPM_U, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 3)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 11000 : 13150;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_U + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_U + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "E2-3", BPM_U, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 4)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 11300 : 13950;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_U + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_U + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "E2-4", BPM_U, denda, biaya_per_kubik, tagihan);
  }
}

void niaga_besar()
{
  int menu;
  printf("\n\t=========================================================");
  printf("\n\t            Silahkan pilih kategori yang sesuai          ");
  printf("\n\t=========================================================");
  printf("\n\tmemiliki bidang usaha dan di depan usaha terdapat        ");
  printf("\n\tjalan dengan kelebaran > 10 meter termasuk got dan     ");
  printf("\n\tsumber daya listrik sesuai dibawah ini   ");
  printf("\n\t=========================================================");
  printf("\n\t [1] Sumber daya listrik 450 VA     ");
  printf("\n\t [2] Sumber daya listrik 900 VA     ");
  printf("\n\t [3] Sumber daya listrik 1300 VA    ");
  printf("\n\t [4] Sumber daya listrik > 1300 VA  ");
  printf("\n\tSilahkan pilih kategori sesuai nomor : ");
  while (scanf("%d", &menu) == 0 || menu < 1 || menu > 4)
  {
    printf("\t---------------------------------------");
    printf("\n\tNomor yang anda masukan salah");
    printf("\n\tSilahkan masukan ulang");
    printf("\n\t---------------------------------------");
    printf("\n\tSilahkan pilih kategori sesuai nomor : ");
    while (menu = getchar() != '\n')
      ;
  }
  close();

  printf("\n\t=========================================================");
  printf("\n\t                        Niaga Besar                      ");
  printf("\n\t=========================================================");
  printf("\n\tMasukan pemakaian sebelumnya (m^3) : ");
  while (scanf("%d", &pemakaian_bulan_lalu) == 0)
  {
    printf("\t---------------------------------------");
    printf("\n\tNilai yang anda masukan salah");
    printf("\n\tSilahkan masukan ulang");
    printf("\n\t---------------------------------------");
    printf("\n\tMasukan pemakaian sebelumnya (m^3) : ");
    while (pemakaian_bulan_lalu = getchar() != '\n')
      ;
  }
  printf("\n\tMasukan pemakaian saat ini (m^3) : ");
  while (scanf("%d", &pemakaian_bulan_ini) == 0 || pemakaian_bulan_ini < pemakaian_bulan_lalu)
  {
    printf("\t---------------------------------------");
    printf("\n\tNilai yang anda masukan salah");
    printf("\n\tSilahkan masukan ulang");
    printf("\n\t---------------------------------------");
    printf("\n\tMasukan pemakaian saat ini (m^3) : ");
    while (pemakaian_bulan_ini = getchar() != '\n')
      ;
  }

  float pemakaian = pemakaian_bulan_ini - pemakaian_bulan_lalu;
  close();

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  if (menu == 1)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 11600 : 14750;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_U + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_U + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "E3-1", BPM_U, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 2)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 11900 : 15050;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_U + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_U + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "E3-2", BPM_U, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 3)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 12500 : 15850;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_U + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_U + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "E3-3", BPM_U, denda, biaya_per_kubik, tagihan);
  }
  else if (menu == 4)
  {
    tarif_per_kubik = (pemakaian >= 0 && pemakaian <= 10) ? 12500 : 16650;
    biaya_per_kubik = tarif_per_kubik * pemakaian;
    denda = (tm.tm_mday <= 15) ? 0 : (0.05 * biaya_per_kubik);

    if (denda == 0)
    {
      tagihan = ADMINISTRASI + BPM_U + (tarif_per_kubik * pemakaian);
    }
    else
    {
      tagihan = ADMINISTRASI + BPM_U + denda + (tarif_per_kubik * pemakaian);
    }

    format(nama_konsumen, alamat, "E3-4", BPM_U, denda, biaya_per_kubik, tagihan);
  }
}

void usaha()
{
  int menu;
  printf("\n\t=========================================================");
  printf("\n\t                      Golongan Usaha                     ");
  printf("\n\t=========================================================");
  printf("\n\t[1] Niaga Kecil");
  printf("\n\t[2] Niaga Sedang");
  printf("\n\t[3] Niaga Besar");
  printf("\n\t---------------------------------------------------------");
  printf("\n\t[0] Kembali");
  printf("\n\t=========================================================");
  printf("\n\tSilahkan pilih golongan sesuai nomor : ");
  while (scanf("%d", &menu) == 0 || menu < 0 || menu > 3)
  {
    printf("\t---------------------------------------");
    printf("\n\tNomor yang anda masukan salah");
    printf("\n\tSilahkan masukan ulang");
    printf("\n\t---------------------------------------");
    printf("\n\tSilahkan pilih golongan sesuai nomor : ");
    while (menu = getchar() != '\n')
      ;
  }
  close();
  switch (menu)
  {
  case 1:
    niaga_kecil();
    break;
  case 2:
    niaga_sedang();
    break;
  case 3:
    niaga_besar();
    break;
  default:
    menu_golongan();
  }
}

void menu_golongan()
{
  int menu;
  printf("\n\t=========================================================");
  printf("\n\t                 Silahkan pilih golongan..               ");
  printf("\n\t=========================================================");
  printf("\n\t[1] Rumah Tangga");
  printf("\n\t[2] Usaha");
  printf("\n\t=========================================================");
  printf("\n\tSilahkan pilih golongan sesuai nomor : ");
  while (scanf("%d", &menu) == 0 || menu < 1 || menu > 2)
  {
    printf("\t---------------------------------------");
    printf("\n\tNomor yang anda masukan salah");
    printf("\n\tSilahkan masukan ulang");
    printf("\n\t---------------------------------------");
    printf("\n\tSilahkan pilih golongan sesuai nomor : ");
    while (menu = getchar() != '\n')
      ;
  }
  close();

  switch (menu)
  {
  case 1:
    rumah_tangga();
    break;
  case 2:
    usaha();
    break;
  }
}

int main(void)
{
  open();
  menu_golongan();
}