#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* dosya;
	int trafikKodu, okutulanTrafikKodu=0, bulunanTrafikKodu=0;
	char sehir[30];

	dosya = fopen("Sehir-Kod.txt", "r"); //Dosyayı Acma

	printf("Okutulan sehir kodu?"); //Sehir kodunun okutulmasi
	scanf("%d",&okutulanTrafikKodu);

	while (fscanf(dosya, "%s %d\n", sehir, &trafikKodu) != EOF)
	{
		if (okutulanTrafikKodu==trafikKodu) //Dosyanin icerisinde sehir kodununu bulmaya calısıyor
		{
			bulunanTrafikKodu = trafikKodu; //Bulursa buldugumuz sehir kodunu baska bir degiskene aktarıyor
		}
	}

	if (bulunanTrafikKodu!=0) //az onceki aktarma yapilmis mi yoksa yapilmamis mi diye kontrol ediyor
	{
		fseek(dosya, 0, SEEK_SET);
		while (fscanf(dosya, "%s %d\n", sehir, &trafikKodu) != EOF)
		{
			if (okutulanTrafikKodu == trafikKodu) // if (bulunanTrafikKodu == trafikKodu) tercih edilebilir
			{
				printf("\n%s Dogu Karadeniz bolgesinde yer alir", sehir);
			}
		}
	}
	else //aktarma yapilmamissa:
	{
		printf("\nHatali Kod Girdiniz");
	}
	fclose(dosya); //Dosyanin kapanmasi

	return (EXIT_SUCCESS);
}
