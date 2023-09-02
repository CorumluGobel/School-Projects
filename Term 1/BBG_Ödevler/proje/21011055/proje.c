#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main(){
	char difficultyChoice[7], tableEasy[5][6], tableMedium[7][8], tableHard[9][10], m = 49, play[5];
	int i, j, a, b, difficulty, easy[4][4], medium[6][6], hard[8][8], row1, column1, row2, column2, counter = 0, memoryEasy[2][3], memoryMedium[6][3], memoryHard[16][3], row1_COM, column1_COM, row2_COM, column2_COM, point = 0, point_COM = 0;
	int turnCounter = 0, turnCounter_COM = 0, condition = 0;
	
	
	
	
	//difficulty choosing /**DONE**/
	printf("\t \t Welcome to Matching Game \n");
	printf("Type 'play' to Play: ");
	scanf("%s", play);
	if(play[0] != 'p'){
		return 0;
	}
	system("cls");
	printf("\t Difficulty Choices: easy, medium, hard \n");
	
	printf("Choose Difficulty: ");
	scanf("%s", difficultyChoice);
	system("cls");
	
	if(difficultyChoice[0] == 'e'){
		difficulty = 1;
	}
	else if(difficultyChoice[0] == 'm'){
		difficulty = 2;
	}
	else if(difficultyChoice[0] == 'h'){
		difficulty = 3;
	}
	
		
	/******************randomizing numbers*******************/ /**DONE**/
	srand(time(NULL));
	//easy
	
	if(difficulty == 1){
		for(i = 0; i <= 3; i++){
			for(j = 0; j <= 3; j++){
				easy[i][j] = 0;
			}
		}
		for(i = 1; i <= 8; i++){
			a = rand() % 4;
			b = rand() % 4;
			while(easy[a][b] != 0){
				a = rand() % 4;
				b = rand() % 4;
			}
			easy[a][b] = i;
			a = rand() % 4;
			b = rand() % 4;
			while(easy[a][b] != 0){
				a = rand() % 4;
				b = rand() % 4;
			}
			easy[a][b] = i;
		}
		for(i = 0; i <= 3; i++){
			for(j = 0; j <= 3; j++){
				printf(" %4d", easy[i][j]);
			}
			printf("\n");
		}
	}
	
	
	//medium
	
	if(difficulty == 2){
		for(i = 0; i <= 5; i++){
			for(j = 0; j <= 5; j++){
				medium[i][j] = 0;
			}
		}
		
		for(i = 1; i <= 18; i++){
			a = rand() % 6;
			b = rand() % 6;
			while(medium[a][b] != 0){
				a = rand() % 6;
				b = rand() % 6;
			}
			medium[a][b] = i;
			a = rand() % 6;
			b = rand() % 6;
			while(medium[a][b] != 0){
				a = rand() % 6;
				b = rand() % 6;
			}
			medium[a][b] = i;
		}
		
		for(i = 0; i <= 5; i++){
			for(j = 0; j <= 5; j++){
				printf(" %4d", medium[i][j]);
			}
			printf("\n");
		}
	}
	
	//hard
	if(difficulty == 3){
		for(i = 0; i <= 7; i++){
			for(j = 0; j <= 7; j++){
				hard[i][j] = 0;
			}
		}
		
		for(i = 1; i <= 32; i++){
			a = rand() % 8;
			b = rand() % 8;
			while(hard[a][b] != 0){
				a = rand() % 8;
				b = rand() % 8;
			}
			hard[a][b] = i;
			a = rand() % 8;
			b = rand() % 8;
			while(hard[a][b] != 0){
				a = rand() % 8;
				b = rand() % 8;
			}
			hard[a][b] = i;
		}
		
		for(i = 0; i <= 7; i++){
			for(j = 0; j <= 7; j++){
				printf(" %4d", hard[i][j]);
			}
			printf("\n");
		}
	}
	
	Sleep(3000);
	system("cls");
	/******************making the table********************/

	//easy table
	
	if(difficulty == 1){
		for(i = 1; i <= 4; i++){
			for(j = 1; j <= 4; j++){
				tableEasy[i][j] = '*';
			}
		}
		tableEasy[0][0] = 48;
		for(i = 1; i <= 4; i++){
			tableEasy[i][0] = m;
			tableEasy[0][i] = m;
			m++;
		}
	}
	

	
	//medium table
	if(difficulty == 2){
		for(i = 1; i <= 6; i++){
			for(j = 1; j <= 6; j++){
				tableMedium[i][j] = '*';
			}
		}
		tableMedium[0][0] = 48;
		for(i = 1; i <= 6; i++){
			tableMedium[i][0] = m;
			tableMedium[0][i] = m;
			m++;
		}
	}
	
	
	//hard table
	if(difficulty == 3){
		for(i = 1; i <= 8; i++){
			for(j = 1; j <= 8; j++){
				tableHard[i][j] = '*';
			}
		}
		tableHard[0][0] = 48;
		for(i = 1; i <= 8; i++){
			tableHard[i][0] = m;
			tableHard[0][i] = m;
			m++;
		}
	}
	/***********************memory******************/
	for(i = 0; i <= 5; i++){
		for(j = 0; j <= 2; j++){
			memoryMedium[i][j] = 0;
		}
	}
	for(i = 0; i <= 15; i++){
		for(j = 0; j <= 2; j++){
			memoryHard[i][j] = 0;
		}
	}
	
	
	/********************entering coordinates***********************/
	while(counter == 0 || counter == 1){
		while(counter == 0){
			counter = 0;
			
			if(difficulty == 1){
				for(i = 0; i <= 4; i++){
					for(j = 0; j <= 4; j++){
						printf(" %c", tableEasy[i][j]);
					}
					printf("\n");
				}
			
				printf("Player's Turn \n");
			
				printf("Enter First Coordinates: ");
				scanf("%d %d", &row1, &column1);
			
				tableEasy[row1][column1] = 48 + easy[row1-1][column1-1];
				
				
				for(i = 0; i <= 4; i++){
					for(j = 0; j <= 4; j++){
						printf(" %c", tableEasy[i][j]);
					}
					printf("\n");
				}
				
				printf("Enter Second Coordinates: ");
				scanf("%d %d", &row2, &column2);
				system("cls");
			
				tableEasy[row2][column2] = 48 + easy[row2-1][column2-1];
				printf("\n");
				
				for(i = 0; i <= 4; i++){
					for(j = 0; j <= 4; j++){
						printf(" %c", tableEasy[i][j]);
					}
					printf("\n");
				}
				memoryEasy[0][0] = easy[row1-1][column1-1];
				memoryEasy[0][1] = row1;
				memoryEasy[0][2] = column1;
				
				memoryEasy[1][0] = easy[row2-1][column2-1];
				memoryEasy[1][1] = row2;
				memoryEasy[1][2] = column2;
				
				if(easy[row1-1][column1-1] != easy[row2-1][column2-1]){
					counter = 1;
					tableEasy[row1][column1] = '*';
					tableEasy[row2][column2] = '*';
				}
				else{
					tableEasy[row1][column1] = '-';
					tableEasy[row2][column2] = '-';
					point = point + 100;
				}
				if(point == 500 || (point == 400 && point_COM == 400)){
					counter = 2;
				}
				printf("\n");
				for(i = 0; i <= 4; i++){
					for(j = 0; j <= 4; j++){
						printf(" %c", tableEasy[i][j]);
					}
					printf("\n");
				}
			}
			if(difficulty == 2){
				for(i = 0; i <= 6; i++){
					for(j = 0; j <= 6; j++){
						printf(" %c", tableMedium[i][j]);
					}
					printf("\n");
				}
			
				printf("Player's Turn \n");
			
				printf("Enter First Coordinates: ");
				scanf("%d %d", &row1, &column1);
				
				tableMedium[row1][column1] = 48 + medium[row1-1][column1-1];
				
				for(i = 0; i <= 6; i++){
					for(j = 0; j <= 6; j++){
						printf(" %c", tableMedium[i][j]);
					}
					printf("\n");
				}
				printf("Enter Second Coordinates: ");
				scanf("%d %d", &row2, &column2);
				system("cls");
				
				tableMedium[row2][column2] = 48 + medium[row2-1][column2-1];
				printf("\n");
				
				for(i = 0; i <= 6; i++){
					for(j = 0; j <= 6; j++){
						printf(" %c", tableMedium[i][j]);
					}
					printf("\n");
				}
				for(i = 0; i <= 3; i++){
					for(j = 0; j <= 2; j++){
						memoryMedium[i][j] = memoryMedium[i+2][j];
					}
				}
				memoryMedium[4][0] = medium[row1-1][column1-1];
				memoryMedium[4][1] = row1;
				memoryMedium[4][2] = column1;
				memoryMedium[5][0] = medium[row2-1][column2-1];
				memoryMedium[5][1] = row2;
				memoryMedium[5][2] = column2;
				
				if(medium[row1-1][column1-1] != medium[row2-1][column2-1]){
					counter = 1;
					tableMedium[row1][column1] = '*';
					tableMedium[row2][column2] = '*';
				}
				else{
					tableMedium[row1][column1] = '-';
					tableMedium[row2][column2] = '-';
					point += 100;
				}
				if(point == 1000 || (point == 900 && point_COM == 900)){
					counter = 2;
				}
				printf("\n");
				for(i = 0; i <= 6; i++){
					for(j = 0; j <= 6; j++){
						printf(" %c", tableMedium[i][j]);
					}
					printf("\n");
				}
				
			}
			if(difficulty == 3){
				for(i = 0; i <= 8; i++){
					for(j = 0; j <= 8; j++){
						printf(" %c", tableHard[i][j]);
					}
					printf("\n");
				}
			
				printf("Player's Turn \n");
			
				printf("Enter First Coordinates: ");
				scanf("%d %d", &row1, &column1);
				
				tableHard[row1][column1] = 48 + hard[row1-1][column1-1];
			
				for(i = 0; i <= 8; i++){
					for(j = 0; j <= 8; j++){
						printf(" %c", tableHard[i][j]);
					}
					printf("\n");
				}
				printf("Enter Second Coordinates: ");
				scanf("%d %d", &row2, &column2);
				system("cls");
				
				tableHard[row2][column2] = 48 + hard[row2-1][column2-1];
				printf("\n");
				
				for(i = 0; i <= 8; i++){
					for(j = 0; j <= 8; j++){
						printf(" %c", tableHard[i][j]);
					}
					printf("\n");
				}
				for(i = 0; i <= 13; i++){
					for(j = 0; j <= 2; j++){
						memoryHard[i][j] = memoryHard[i+2][j];
					}
				}
				memoryHard[14][0] = hard[row1-1][column1-1];			
				memoryHard[14][1] = row1;	
				memoryHard[14][2] = column1;
				memoryHard[15][0] = hard[row2-1][column2-1];
				memoryHard[15][1] = row2;
				memoryHard[15][2] = column2;
				
				if(hard[row1-1][column1-1] != hard[row2-1][column2-1]){
					counter = 1;
					tableHard[row1][column1] = '*';
					tableHard[row2][column2] = '*';
				}
				else{
					tableHard[row1][column1] = '-';
					tableHard[row2][column2] = '-';
					point += 100;
				}
				if(point == 1900 || (point == 1800 && point_COM == 1800)){
					counter = 2;
				}
				printf("\n");
				for(i = 0; i <= 8; i++){
					for(j = 0; j <= 8; j++){
						printf(" %c", tableHard[i][j]);
					}
					printf("\n");
				}
			}
			turnCounter++;
			Sleep(2500);
			system("cls");
		}
		
		
		while(counter == 1){
			printf("Computer's Turn \n");
			if(difficulty == 1){
				row1_COM = rand() % 4 + 1;
				column1_COM = rand() % 4 + 1;
				while(tableEasy[row1_COM][column1_COM] == '-'){
					row1_COM = rand() % 4 + 1;
					column1_COM = rand() % 4 + 1;
				}
				tableEasy[row1_COM][column1_COM] = 48 + easy[row1_COM-1][column1_COM-1];
				
				for(i = 0; i <= 4; i++){
					for(j = 0; j <= 4; j++){
						printf(" %c", tableEasy[i][j]);
					}
					printf("\n");
				}
				for(i = 0; i <= 1; i++){
					if(easy[row1_COM-1][column1_COM-1] == memoryEasy[i][0]){
						row2_COM = memoryEasy[i][1];
						column2_COM = memoryEasy[i][2];
					}
					else{
						row2_COM = rand() % 4 + 1;
						column2_COM = rand() % 4 + 1;
						while(tableEasy[row2_COM][column2_COM] == '-' || (row2_COM == row1_COM && column2_COM == column1_COM)){
							row2_COM = rand() % 4 + 1;
							column2_COM = rand() % 4 + 1;
						}
					}
				}	
				tableEasy[row2_COM][column2_COM] = 48 + easy[row2_COM-1][column2_COM-1];
				printf("\n");
				
				for(i = 0; i <= 4; i++){
					for(j = 0; j <= 4; j++){
						printf(" %c", tableEasy[i][j]);
					}
					printf("\n");
				}
				if(easy[row1_COM-1][column1_COM-1] != easy[row2_COM-1][column2_COM-1]){
					counter = 0;
					tableEasy[row1_COM][column1_COM] = '*';
					tableEasy[row2_COM][column2_COM] = '*';
				}
				else{
					tableEasy[row1_COM][column1_COM] = '-';
					tableEasy[row2_COM][column2_COM] = '-';
					point_COM = point_COM + 100;
				}
				printf("\n");
				for(i = 0; i <= 4; i++){
					for(j = 0; j <= 4; j++){
						printf(" %c", tableEasy[i][j]);
					}
					printf("\n");
				}
				if(point_COM == 500 || (point == 400 && point_COM == 400)){
					counter = 2;
				}
			}
			//medium
			if(difficulty == 2){
				i = 0;
				condition = 0;
				while(i <= 5 && condition == 0){
					j = i + 1;
					while(j <= 5 && condition == 0){
						if(memoryMedium[i][0] == memoryMedium[j][0] && (tableMedium[memoryMedium[i][1]][memoryMedium[i][2]] != '-') && (memoryMedium[i][1] != memoryMedium[j][1] || memoryMedium[i][2] != memoryMedium[j][2])){
							row1_COM = memoryMedium[j][1];
							column1_COM = memoryMedium[j][2];
							condition = 1;
						}
						else{
							row1_COM = rand() % 6 + 1;
							column1_COM = rand() % 6 + 1;
							while(tableMedium[row1_COM][column1_COM] == '-'){
								row1_COM = rand() % 6 + 1;
								column1_COM = rand() % 6 + 1;
							}
						}
						j++;
					}
					i++;
				}
				
				tableMedium[row1_COM][column1_COM] = 48 + medium[row1_COM-1][column1_COM-1];
				for(i = 0; i <= 6; i++){
					for(j = 0; j <= 6; j++){
						printf(" %c", tableMedium[i][j]);
					}
					printf("\n");
				}
				
				i = 0;
				condition = 0;
				while(i <= 5 && condition == 0){
					
					if(medium[row1_COM-1][column1_COM-1] == memoryMedium[i][0] && (row1_COM != memoryMedium[i][1] || column1_COM != memoryMedium[i][2])){
						row2_COM = memoryMedium[i][1];
						column2_COM = memoryMedium[i][2];
						condition = 1;
					}
					else{
						row2_COM = rand() % 6 + 1;
						column2_COM = rand() % 6 + 1;
						while(tableMedium[row2_COM][column2_COM] == '-' || (row2_COM == row1_COM && column2_COM == column1_COM)){
							row2_COM = rand() % 6 + 1;
							column2_COM = rand() % 6 + 1;
						}
					}
					i++;
				}
				tableMedium[row2_COM][column2_COM] = 48 + medium[row2_COM-1][column2_COM-1];
				printf("\n");
				
				for(i = 0; i <= 6; i++){
					for(j = 0; j <= 6; j++){
						printf(" %c", tableMedium[i][j]);
					}
					printf("\n");
				}
				
				if(medium[row1_COM-1][column1_COM-1] != medium[row2_COM-1][column2_COM-1]){
					counter = 0;
					tableMedium[row1_COM][column1_COM] = '*';
					tableMedium[row2_COM][column2_COM] = '*';
				}
				else{
					tableMedium[row1_COM][column1_COM] = '-';
					tableMedium[row2_COM][column2_COM] = '-';
					point_COM = point_COM + 100;
				}
				printf("\n");
				for(i = 0; i <= 6; i++){
					for(j = 0; j <= 6; j++){
						printf(" %c", tableMedium[i][j]);
					}
					printf("\n");
				}
				if(point_COM == 1000 || (point == 900 && point_COM == 900)){
					counter = 2;
				}
				
				for(i = 0; i <= 3; i++){
					for(j = 0; j <= 2; j++){
						memoryMedium[i][j] = memoryMedium[i+2][j];
					}
				}
				
				memoryMedium[4][0] = medium[row1_COM-1][column1_COM-1];
				memoryMedium[4][1] = row1_COM;
				memoryMedium[4][2] = column1_COM;
				memoryMedium[5][0] = medium[row2_COM-1][column2_COM-1];
				memoryMedium[5][1] = row2_COM;
				memoryMedium[5][2] = column2_COM;
				
				
			}
			if(difficulty == 3){
				i = 0;
				condition = 0;
				while(i <= 15 && condition == 0){
					j = i + 1;
					while(j <= 15 && condition == 0){
						if(memoryHard[i][0] == memoryHard[j][0] && tableHard[memoryHard[i][1]][memoryHard[i][2]] != '-' && (memoryHard[i][1] != memoryHard[j][1] || memoryHard[i][2] != memoryHard[j][2])){
							row1_COM = memoryHard[i][1];
							column1_COM = memoryHard[i][2];
							condition = 1;
						}
						else{
							row1_COM = rand() % 8 + 1;
							column1_COM = rand() % 8 + 1;
							while(tableHard[row1_COM][column1_COM] == '-'){
								row1_COM = rand() % 8 + 1;
								column1_COM = rand() % 8 + 1;
							}
						}
						j++;
					}
					i++;
				}
				
				tableHard[row1_COM][column1_COM] = 48 + hard[row1_COM-1][column1_COM-1];
				
				for(i = 0; i <= 8; i++){
					for(j = 0; j <= 8; j++){
						printf(" %c", tableHard[i][j]);
					}
					printf("\n");
				}
				i = 0;
				condition = 0;
				while(i <= 15 && condition == 0){
					if(hard[row1_COM-1][column1_COM-1] == memoryHard[i][0] && (row1_COM != memoryHard[i][1] || column1_COM != memoryHard[i][2])){
						row2_COM = memoryHard[i][1];
						column2_COM = memoryHard[i][2];
						condition = 1;
					}
					else{
						row2_COM = rand() % 8 + 1;
						column2_COM = rand() % 8 + 1;
						while(tableHard[row2_COM][column2_COM] == '-' || (row2_COM == row1_COM && column2_COM == column1_COM)){
							row2_COM = rand() % 8 + 1;
							column2_COM = rand() % 8 + 1;
						}
					}
					i++;
				}
				tableHard[row2_COM][column2_COM] = 48 + hard[row2_COM-1][column2_COM-1];
				printf("\n");
				
				for(i = 0; i <= 8; i++){
					for(j = 0; j <= 8; j++){
						printf(" %c", tableHard[i][j]);
					}
					printf("\n");
				}
				if(hard[row1_COM-1][column1_COM-1] != hard[row2_COM-1][column2_COM-1]){
					counter = 0;
					tableHard[row1_COM][column1_COM] = '*';
					tableHard[row2_COM][column2_COM] = '*';
				}
				else{
					tableHard[row1_COM][column1_COM] = '-';
					tableHard[row2_COM][column2_COM] = '-';
					point_COM = point_COM + 100;
				}
				printf("\n");
				for(i = 0; i <= 8; i++){
					for(j = 0; j <= 8; j++){
						printf(" %c", tableHard[i][j]);
					}
					printf("\n");
				}
				if(point_COM == 1900 || (point == 1800 && point_COM == 1800)){
					counter = 2;
				}
				
				for(i = 0; i <= 13; i++){
					for(j = 0; j <= 2; j++){
						memoryHard[i][j] = memoryHard[i+2][j];
					}
				}
				
				memoryHard[14][0] = hard[row1_COM-1][column1_COM-1];
				memoryHard[14][1] = row1_COM;
				memoryHard[14][2] = column1_COM;
				memoryHard[15][0] = hard[row2_COM-1][column2_COM-1];
				memoryHard[15][1] = row2_COM;
				memoryHard[15][2] = column2_COM;
				
			}
			turnCounter_COM++;
			Sleep(2500);
			system("cls");
		}
	}
	if(point > point_COM){
		printf("Player Has Won! \n Amount of Guesses: %d", turnCounter);
	}
	else if(point < point_COM){
		printf("Computer Has Won! \n Amount of Guesses: %d", turnCounter_COM);
	}
	else{
		printf("It's a Draw!");
	}
	return 0;
}
