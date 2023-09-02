#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include "image_processing.cpp"

using namespace std;

void Dilation(int n, int filter_size, short* resimadres_org);
void Erosion(int n, int filter_size, short* resimadres_org);

int main(void) {
	int M, N, Q, i, j, filter_size;
	bool type;
	int efile;
	char org_resim[100], dil_resim[] = "dilated.pgm", ero_resim[] = "eroded.pgm";
	do {
		printf("Orijinal resmin yolunu (path) giriniz:\n-> ");
		scanf("%s", &org_resim);
		system("CLS");
		efile = readImageHeader(org_resim, N, M, Q, type);
	} while (efile > 1);
	int** resim_org = resimOku(org_resim);

	printf("Orjinal Resim Yolu: \t\t\t%s\n", org_resim);
	
	short *resimdizi_org = (short*) malloc(N*M * sizeof(short));

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			resimdizi_org[i*N + j] = (short)resim_org[i][j];

	int menu;
	printf("Yapmak istediginiz islemi giriniz...\n");
	printf("1-) Dilation\n");
	printf("2-) Erosion\n");
	printf("3-) Cikis\n> ");
	scanf("%d", &menu);
	printf("Filtre boyutunu giriniz: ");
	scanf("%d", &filter_size);

	switch (menu){
		case 1:
			Dilation(N*M, filter_size, resimdizi_org);
			resimYaz(dil_resim, resimdizi_org, N, M, Q);
			break;
		case 2:
			Erosion(N*M, filter_size, resimdizi_org);
			resimYaz(ero_resim, resimdizi_org, N, M, Q);
			break;
		case 3:
			system("EXIT");
			break;
		default:
			system("EXIT");
			break;
	}

	system("PAUSE");
	return 0;
}

void Dilation(int n, int filter_size, short* resim_org) {
	/*for (int i = 0; i < 512; i++)
		for (int j = 0; j < 512; j++)
			resim_org[i][j] = 255;*/
	__asm {
		//KODUNUZU BURAYA YAZINIZ, ASAGIDAKI 5 ORNEK ERISIM ICIN VERILMISTIR SIZ YAZMAYA BASLAMADAN SILINIZ
		MOV EDI, resim_org
		MOV ECX, n
		
		
		
		XOR EDX, EDX
		MOV EAX, 512
		MOV EBX, filter_size
		DEC EBX
		MUL EBX
		
		

		ADD EDI, EAX
		ADD EDI, EBX
		SUB ECX, EAX
		
		XOR EBX, EBX
		L1:
		
		XOR EAX, EAX


		PUSH ECX
		MOV ECX, filter_size
		
		PUSH EBX
		PUSH EAX
		PUSH EDX
		XOR EDX, EDX
		MOV EAX, 512
		DEC ECX
		MUL ECX
		INC ECX
		SUB EBX, EAX
		SUB EBX, ECX
		INC EBX
		POP EDX
		POP EAX
		
		L2:

		PUSH ECX
		MOV ECX, filter_size

		PUSH EBX
		L3:

		
		CMP WORD PTR[EDI+EBX], AX
		JBE BRANCH
		MOV AX, WORD PTR[EDI+EBX]
		BRANCH:
		ADD EBX, 2
		
		LOOP L3

		POP EBX
		POP ECX
		
		ADD EBX, 1024



		LOOP L2

		POP EBX
		POP ECX
		
		
		PUSH AX
		

		INC EDX


		PUSH EBX
		MOV EBX, filter_size
		MOV EAX, 513
		SUB EAX, EBX
		POP EBX
		CMP EDX, EAX
		JNE B1
		MOV EAX, filter_size
		ADD EAX, EAX
		DEC EAX
		DEC EAX
		ADD EBX, EAX
		SHR EAX, 1
		SUB ECX, EAX
		XOR EDX, EDX
		B1:
		ADD EBX, 2



		LOOP L1

			
		MOV ECX, n
		SHL EAX, 1
		SUB EBX, 2
		SUB EBX, EAX
		SHR EAX, 1
		MOV EDX, 512
		MUL EDX
		SUB ECX, EAX
		XOR EDX, EDX
		L4:

		POP AX
		MOV WORD PTR[EDI + EBX], AX
		INC EDX

		PUSH EBX
		MOV EBX, filter_size
		MOV EAX, 513
		SUB EAX, EBX
		POP EBX
		CMP EDX, EAX
		JNE B2
		MOV EAX, filter_size
		ADD EAX, EAX
		DEC EAX
		DEC EAX
		SUB EBX, EAX
		SHR EAX, 1
		SUB ECX, EAX
		XOR EDX, EDX
		B2:
		SUB EBX, 2

		LOOP L4
		
	}
	printf("\nDilation islemi sonucunda resim \"dilated.pgm\" ismiyle olusturuldu...\n");
}

void Erosion(int n, int filter_size, short* resim_org) {
	__asm {
		//KODUNUZU BURAYA YAZINIZ, ASAGIDAKI 5 ORNEK ERISIM ICIN VERILMISTIR SIZ YAZMAYA BASLAMADAN SILINIZ
		MOV EDI, resim_org
		MOV ECX, n
		



		XOR EDX, EDX
		MOV EAX, 512
		MOV EBX, filter_size
		DEC EBX
		MUL EBX



		ADD EDI, EAX
		ADD EDI, EBX
		SUB ECX, EAX

		XOR EBX, EBX
		L1 :

		MOV EAX, 255


		PUSH ECX
		MOV ECX, filter_size

		PUSH EBX
		PUSH EAX
		PUSH EDX
		XOR EDX, EDX
		MOV EAX, 512
		DEC ECX
		MUL ECX
		INC ECX
		SUB EBX, EAX
		SUB EBX, ECX
		INC EBX
		POP EDX
		POP EAX

		L2 :

		PUSH ECX
		MOV ECX, filter_size

		PUSH EBX
		L3 :


		CMP WORD PTR[EDI + EBX], AX
		JAE BRANCH
		MOV AX, WORD PTR[EDI + EBX]
		BRANCH :
		ADD EBX, 2

		LOOP L3

		POP EBX
		POP ECX

		ADD EBX, 1024



		LOOP L2

		POP EBX
		POP ECX



		INC EDX
			
		PUSH AX
			
		PUSH EBX
		MOV EBX, filter_size
		MOV EAX, 513
		SUB EAX, EBX
		POP EBX
		CMP EDX, EAX
		JNE B1
		MOV EAX, filter_size
		ADD EAX, EAX
		DEC EAX
		DEC EAX
		ADD EBX, EAX
		SHR EAX, 1
		SUB ECX, EAX
		XOR EDX, EDX
		B1 :
		ADD EBX, 2



		LOOP L1
		
		
		MOV ECX, n
		SHL EAX, 1
		SUB EBX, 2
		SUB EBX, EAX
		SHR EAX, 1
		MOV EDX, 512
		MUL EDX
		SUB ECX, EAX
		XOR EDX, EDX
		L4:

		POP AX
		MOV WORD PTR[EDI+EBX], AX
		INC EDX

		PUSH EBX
		MOV EBX, filter_size
		MOV EAX, 513
		SUB EAX, EBX
		POP EBX
		CMP EDX, EAX
		JNE B2
		MOV EAX, filter_size
		ADD EAX, EAX
		DEC EAX
		DEC EAX
		SUB EBX, EAX
		SHR EAX, 1
		SUB ECX, EAX
		XOR EDX, EDX
		B2:
		SUB EBX, 2

		LOOP L4
	}
	printf("\nErosion islemi sonucunda resim \"eroded.pgm\" ismiyle olusturuldu...\n");
}
