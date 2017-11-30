#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Fiyat
{
    ogrenci=20,
    tam=30
};
enum secim
{
    bilet,
    doluluk_yonlendirme,
    hasilat_yonlendirme,
    devam_et
};

typedef struct
{
    int matine[5][50];
}kirmizi;
typedef struct
{
    int matine[5][50];
}mavi;
typedef struct
{
    int matine[5][50];
}yesil;
typedef struct
{
    yesil y;
    mavi m;
    kirmizi k;
}salon;
enum salon_Nu
{
    kirm,
    mav,
    yes
};
int main()
{
   FILE *sifre,*kontrol_sifre;
   float kayitli_sifre=5464,girilen_sifre;
   sifre=fopen("sifre.txt","w");
   fprintf(sifre,"%f",kayitli_sifre);
   fclose(sifre);
   sifre_girisi:
   printf("sifre giriniz:\n");
   scanf("%f",&girilen_sifre);
   kontrol_sifre=fopen("kontrol_sifre.txt","w");
   fprintf(kontrol_sifre,"%f",girilen_sifre);
   fclose(kontrol_sifre);

   sifre=fopen("sifre.txt","r");
   kontrol_sifre=fopen("kontrol_sifre.txt","r");
   char sifre_elemani,kontrol_elemani;
   int ayni_olan_say=0;
   while(sifre_elemani!= EOF)
   {
       sifre_elemani=getc(sifre);
       kontrol_elemani=getc(kontrol_sifre);
       if(sifre_elemani==kontrol_elemani)
        continue;
       else
        {
            printf("YANLIS GIRIS YAPTINIZ!!\n");
            goto sifre_girisi;
        }
   }


    int yonlendirme,i,j,sayac,devam_mi;
    salon s;
for(i=0;i<5;i++)
{
    for(j=0;j<50;j++)
    {
        s.k.matine[i][j]==0;
        s.m.matine[i][j]==0;
        s.y.matine[i][j]==0;
    }
}
int dondurulecek=0;
do{
    printf("............SINEMA OTOMASYONU........\n");
    printf("Bilet satisi icin-->0\n");
    printf("Doluluk bilgisi icin-->1\n");
    printf("Hasilat icin seciniz-->2\nSECINIZ.\n");
    scanf("%d",&yonlendirme);
    if(yonlendirme!= bilet && yonlendirme!=doluluk_yonlendirme && yonlendirme!=hasilat_yonlendirme)
    {
        printf("Yanlis giris yaptiniz.\n");
        goto sifre_girisi;
    }
    if(yonlendirme==bilet)
        dondurulecek=Bilet_satisi(bilet,dondurulecek);
    if(yonlendirme==doluluk_yonlendirme)
        Bilet_satisi(doluluk_yonlendirme);
    if(yonlendirme==hasilat_yonlendirme)
        Hasilat(hasilat_yonlendirme);

                printf("Devam etmek icin 3 sec\n");
                scanf("%d",&devam_mi);
}while(devam_mi==devam_et);
printf("cikis yapiliyor...");
    return 0;

}

int Bilet_satisi(int yonlendirme,int dondurulecek)
{
    FILE *doluluk;
    salon s;

    int salon_num,mati_num;
    switch(yonlendirme)
    {
    case bilet:
konum1:
    printf("bir salon seciniz:\nKirmizi:0\tMavi:1\tyesil:2\n");
    scanf("%d",&salon_num);
    if(salon_num!=kirm &&salon_num!=mav &&salon_num!=yes)
goto konum1;
    printf("matine seciniz:\n");
    scanf("%d",&mati_num);

   switch(salon_num)
   {
    case kirm:
        srand( time(NULL));
        int rastgele=rand()%50;
        int *kirmizi_salon;
        kirmizi_salon=s.k.matine;
        int i=((mati_num-1)*50)+rastgele;
        if ( *(kirmizi_salon+i) != 1 )
           {
               *(kirmizi_salon+i)==1;
        printf("\n\nKirmizi salon\t%d. matine\t%d. koltuk a kayit yapildi.\n\n",mati_num,rastgele);

        doluluk=fopen("doluluk.txt","a");
        fprintf(doluluk,"Kirmizi salon %d. matine %d. koltuk dolu.\n",mati_num,rastgele);
        fclose(doluluk);
           }

        break;
    case mav:
           srand( time(NULL));
           int rastgele1=rand()%50;
           int *mavi_salon;
           mavi_salon=s.m.matine;
           int a=((mati_num-1)*50)+rastgele1;
           if(*(mavi_salon+a)!=1)
            {
               *(mavi_salon+a)==1;
               printf("\n\nMavi salon\t%d. matine\t%d. koltuk a kayit yapildi.\n\n",mati_num,rastgele1);
               doluluk=fopen("doluluk.txt","a");
        fprintf(doluluk,"Mavi salon %d. matine %d. koltuk dolu.\n",mati_num,rastgele1);
            fclose(doluluk);
            }
        break;
    case yes:
        srand( time(NULL));
        int rastgele2=rand()%50;
        int *yesil_salon;
        yesil_salon=s.y.matine;
        int b=((mati_num-1)*50)+rastgele2;
        if(*(yesil_salon+b)!=1)
        {
           *(yesil_salon+b)==1;
            printf("\n\nYesil salon\t%d. matine\t%d. koltuk a kayit yapildi.\n\n",mati_num,rastgele2);
            doluluk=fopen("doluluk.txt","a");
        fprintf(doluluk,"Yesil salon %d. matine %d. koltuk dolu.\n",mati_num,rastgele2);
            fclose(doluluk);
        }
        break;
   }
   return ucret(dondurulecek);
   break;
    case doluluk_yonlendirme:
        doluluk=fopen("doluluk.txt","r");
    char kontrol;
    while(kontrol != EOF){
         kontrol=getc(doluluk);
         putchar(kontrol);
    }
    fclose(doluluk);
    break;
    }
}
int ucret(int dondurulen)
{
    int sec,Toplam_hasilat=dondurulen;
    printf("ogrenci icin 1\ttam icin 2 seciniz ");
    scanf("%d",&sec);
    if(sec==1)
        {
            printf("ogrenci ucreti::20 TL \n\n");
            Toplam_hasilat+=ogrenci;
            Hasilat(Toplam_hasilat);
            return Toplam_hasilat;
        }
    else
        {
            printf("Tam ucret::30TL\n\n");
            Toplam_hasilat+=tam;
            Hasilat(Toplam_hasilat);
            return Toplam_hasilat;
        }
}

int Hasilat(int k)
{
        FILE *hasilat;
        if(k!=hasilat_yonlendirme)
        {
            hasilat=fopen("hasilat.txt","w");
            fprintf(hasilat,"Hasilat:%d\n",k);
            fclose(hasilat);
        }
        int ara_eleman;
        hasilat=fopen("hasilat.txt","r");
        do{
            ara_eleman=getc(hasilat);
            putchar(ara_eleman);
        }while(ara_eleman != EOF);
        fclose(hasilat);
}
