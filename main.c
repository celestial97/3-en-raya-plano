#include <stdio.h>
#include <stdlib.h>

// By Oscar Gomez "celestial97"

int juego();
void estadisticas();
int ganadas1=0,ganadas2=0, empate=0,pj;

int main()
{
	int op, num, ganador, nj, ni;
	char c;
	do{
		printf("\n\nMENU PRINCIPAL, escoja una opcion:\n");
		printf("  1. Iniciar una nueva partida.\n");
		printf("  2. Estadisticas\n");
		printf("  3. Salir del programa.\n\n");
		scanf("%d",&op);        
		system("cls");
		switch(op){
			case 1:
			juego();
			break;
			
			case 2:
			estadisticas();
			break;
			
			case 3:
			break;
			
			
			default: printf("\n\nOpcion incorrecta, vuelva a escoger una opcion.\n\n");
		}
	}
	while(op!=3);
	printf("\n\nMuchas gracias por jugar el 3 en raya.\n\n");
	return 0;
}



int juego(){
	int fin=0, i=0, j=0, seleccion, num, corr=0, turnoe=0;
	int turno=1, aux;
	char casilla[3][3]={49,50,51,52,53,54,55,56,57}; /*puesto en codigo ASCII, 49=0, 50=1...*/
	while (fin<5){
		system("cls");
		printf("---------------------\n");
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
			printf("|  %c  |", casilla[i][j]);
			}
		printf("\n---------------------\n");
		}
		if (turno==1){
			printf("selecione casilla jugador 1: ");
			corr=0;
			do{
			scanf("%d", &seleccion);
			num=seleccion+48;
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					aux = casilla[i][j];
					if(aux == num){
						casilla[i][j]=157;
						corr=1;
					}
				}
			}
			if(corr==0)
				printf("\ncasilla introducida erronea, introduzca otra:");
			}while(corr==0);
			turno++;
			for(i=0;i<3;i++){
				if((casilla[i][0]==casilla[i][1])&&(casilla[i][1]==casilla[i][2]))
						fin=6;
				if((casilla[0][i]==casilla[1][i])&&(casilla[1][i]==casilla[2][i]))
						fin=6;
				if((casilla[0][0]==casilla[1][1])&&(casilla[1][1]==casilla[2][2]))
						fin=6;
				if((casilla[0][2]==casilla[1][1])&&(casilla[1][1]==casilla[2][0]))
						fin=6;
			}
			turnoe++;
			if(turnoe==9)
				if(fin!=6)
					fin=8;
		}
		else if(turno==2){
			printf("selecione casilla jugador 2: ");
			corr=0;
			do{
			scanf("%d", &seleccion);
			num = seleccion+48;
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					aux = casilla[i][j];
					if(aux == num){
						casilla[i][j]=88;
						corr=1;
					}
				}
			}
			if(corr==0)
				printf("\ncasilla introducida erronea, introduzca otra:");
			}while(corr==0);
			turnoe++;
			turno--;
			for(i=0;i<3;i++){
				if(casilla[i][0]==casilla[i][1])
					if(casilla[i][1]==casilla[i][2])
						fin=7;
				if(casilla[0][i]==casilla[1][i])
					if(casilla[1][i]==casilla[2][i])
						fin=7;
				if(casilla[0][0]==casilla[1][1])
					if(casilla[1][1]==casilla[2][2])
						fin=7;
				if(casilla[0][2]==casilla[1][1])
					if(casilla[1][1]==casilla[2][0])
						fin=7;
			}
		}
	}
	system("cls");
	if (fin==6){
		printf("FELICIDADES JUGADOR 1, ES EL GANADOR");
		ganadas1++;
	}
	else if (fin==7){
		printf("FELICIDADES JUGADOR 2, ES EL GANADOR");
		ganadas2++;
	}
	else if(fin==8){
		printf("EMPATE");
		empate++;
	}
}

void estadisticas(){
	system("cls");
	printf("estas son las estadisticas actuales:\n");
	pj=ganadas1+ganadas2+empate;
	printf("partidas jugadas: %d\n", pj);
	printf("ganadas jugador 1: %d\n", ganadas1);
	printf("ganadas jugador 2: %d\n", ganadas2);
	printf("empatadas: %d", empate);
}
