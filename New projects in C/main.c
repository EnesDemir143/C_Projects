//Kodda geliştirmeler yapılacak.

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

struct oda
{
    int odanum;
    int yatak_sayısı;
    float ucret;
    char manzara[50];
};

struct musteri
{
    char ad[100];
    struct oda odabilgileri;
    char giriş[20];
    char cıkıs[20];
    float toplamucret;
};

int tarihKarsilastir( char tarih1[],  char tarih2[]) {
    //Sort işlemi aslında amaç olarak sıralama yapar burda da tarihler var bunlarda sıralanabilr.
    //Tarihleride bu şekilde yıl ay ve gün olarak sıralayabiliriz.
    int gun1, ay1, yil1;
    int gun2, ay2, yil2;

    // Tarihleri "gg/aa/yyyy" formatında ayrıştırma
    sscanf(tarih1, "%d/%d/%d", &gun1, &ay1, &yil1);
    sscanf(tarih2, "%d/%d/%d", &gun2, &ay2, &yil2);

    // Yıl karşılaştırması
    if (yil1 != yil2) {
        return yil1 - yil2;
    }

    // Ay karşılaştırması
    if (ay1 != ay2) {
        return ay1 - ay2;
    }

    // Gün karşılaştırması
    return gun1 - gun2;
}

void rezervasyonekle(struct musteri musteri1[],int i){

    printf("Müşteri Adı: ");
    fgets(musteri1[i].ad,sizeof(musteri1[i].ad),stdin);
    musteri1[i].ad[strcspn(musteri1[i].ad,"\n")] = '\0';

    printf("Oda numarası: ");
    scanf("%d",&musteri1[i].odabilgileri.odanum);
    getchar();

    printf("Yatak sayısı: ");
    scanf("%d",&musteri1[i].odabilgileri.yatak_sayısı);
    getchar();

    printf("Ücret: ");
    scanf("%f",&musteri1[i].odabilgileri.ucret);
    getchar();

    printf("Manzara: ");
    fgets(musteri1[i].odabilgileri.manzara,sizeof(musteri1[i].odabilgileri.manzara),stdin);
    musteri1[i].odabilgileri.manzara[strcspn(musteri1[i].odabilgileri.manzara,"\n")] = '\0';
    
    printf("Giriş tarihi (gg/aa/yyyy): ");
    fgets(musteri1[i].giriş,sizeof(musteri1[i].giriş),stdin);
    musteri1[i].giriş[strcspn(musteri1[i].giriş,"\n")] = '\0';

    printf("Çıkış tarihi (gg/aa/yyyy): ");
    fgets(musteri1[i].cıkıs,sizeof(musteri1[i].cıkıs),stdin);
    musteri1[i].cıkıs[strcspn(musteri1[i].cıkıs,"\n")] = '\0';

    printf("Rezervasyon başarıyla eklendi!\n");
    
}

void rezervasyonlarılistele(struct musteri musteri1[],int i){
    for (int a = 0; a < i; a++)
    {
        printf("Ad:%s\n",musteri1[a].ad);
        printf("No:%d\n",musteri1[a].odabilgileri.odanum);
        printf("Giriş:%s\n",musteri1[a].giriş);
        printf("Çıkış:%s\n",musteri1[a].cıkıs);
        printf("ToplamUcret:%f\n",musteri1[a].odabilgileri.ucret);//Geliştirilebilir.
    }
    
    
}
void odanumgöreara(struct musteri musteri1[],int i){
    int arananno;
    printf("Aranan oda numarası: ");
    scanf("%d",&arananno);
    getchar();
    
    for (int a = 0; a < i; a++)
    {
        if(musteri1[a].odabilgileri.odanum==arananno){
            printf("Eşleşen rezervasyon :\n");
            printf("Ad:%s\n",musteri1[a].ad);
            printf("No:%d\n",musteri1[a].odabilgileri.odanum);
            printf("Giriş:%s\n",musteri1[a].giriş);
            printf("Çıkış:%s\n",musteri1[a].cıkıs);
            printf("ToplamUcret:%f\n",musteri1[a].odabilgileri.ucret);
            break;
        }
    }
    
    
}
void giriştarihinegöresıra(struct musteri musteri1[], int i) {
    struct musteri temp;
    for (int j = 0; j < i - 1; j++) {
        for (int f = 0; f < i - j - 1; f++) {
            if (tarihKarsilastir(musteri1[f].giriş, musteri1[f + 1].giriş) > 0) {
                // Eğer `musteri1[f]` tarihi `musteri1[f + 1]` tarihinden büyükse, yer değiştir
                temp = musteri1[f];
                musteri1[f] = musteri1[f + 1];
                musteri1[f + 1] = temp;
            }
        }
    }

    // Sıralanmış rezervasyonları yazdırma
    for (int a = 0; a < i; a++) {
        printf("Ad: %s\n", musteri1[a].ad);
        printf("No: %d\n", musteri1[a].odabilgileri.odanum);
        printf("Giriş: %s\n", musteri1[a].giriş);
        printf("Çıkış: %s\n", musteri1[a].cıkıs);
        printf("Toplam Ücret: %f\n", musteri1[a].odabilgileri.ucret);
    }
}

int main(){
    int seçim,kişisayısı=0;
    struct musteri musteri1[100];

    do
    {
        printf("----Otel rezervasyon sistemi---\n");
        printf("1. Rezervasyon ekle\n");
        printf("2. Rezervasyonları listele\n");
        printf("3. Oda numarasına göre ara\n");
        printf("4. Giriş tarihine göre sırala\n");
        printf("5. Çıkış\n");
        printf("Seçiminizi yapınız: ");
        scanf("%d",&seçim);
        getchar();
        switch (seçim)
        {
        case 1:printf("Yeni müşteri ekleyin:\n");
            rezervasyonekle(musteri1,kişisayısı);
            kişisayısı++;
            break;
        case 2 :printf("Tüm rezervasyonlar:\n");
            rezervasyonlarılistele(musteri1,kişisayısı);
            break;
        case 3:printf("Oda numarasına göre sıralama:\n");
            odanumgöreara(musteri1,kişisayısı);
            break;
        case 4:printf("Giriş tarihine göre sıralama: \n");
            giriştarihinegöresıra(musteri1,kişisayısı);
            break;
        case 5:printf("Programdan çıkılıyor...\n");
            break;
        default:printf("Geçersiz bir seçim yaptınız.Tekrar giriniz");
        //Burayı geliştirebilirsin...
            break;;
        }
    } while (seçim!=5);
    
    return 0;








}