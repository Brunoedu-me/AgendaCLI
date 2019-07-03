#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//Criação da estrutura do contato.
typedef struct {
char email[50];
char nome[30];
char numero[11];
} Contato;

//Método Adicionar responsável por adicionar os contatos.
int Adicionar(){
	Contato c;
	//Abrindo o arquivo para leitura
	FILE *f = fopen("contatos.dat", "rb");
	/*Verificando se o arquivo existe. 
	Se não eu crio o arquivo de armazenamento
	Se sim apenas atualizo os dados nele
	*/
	if (f == NULL) {
		fclose(f);
		FILE *f = fopen("contatos.dat", "wb");
		printf("Informe o nome do contato: ");
		scanf("%29s", &c.nome);
		printf("Informe o numero do contato: ");
		scanf("%10s", &c.numero);
		printf("Informe o email do contato: ");
		scanf("%49s", &c.email);
		fwrite(&c, sizeof(Contato), 1, f);
		fclose(f);
	}
	else{
		fclose(f);
		FILE *f = fopen("contatos.dat", "ab");
		printf("Informe o nome do contato: ");
		scanf("%s", &c.nome);
		printf("Informe o numero do contato: ");
		scanf("%11s", &c.numero);
		printf("Informe o email do contato: ");
		scanf("%s", &c.email);
		fwrite(&c, sizeof(Contato), 1, f);
		fclose(f);
	}
	return 0;
}

//Método Editar.
int Editar(){
	Contato c;
	char escolha, nome[30];
	FILE *f = fopen("contatos.dat", "rb");
	if (f == NULL) {
		printf("nao ha contatos cadastrados.\n");
		return (EXIT_FAILURE);
	}
	else{
		int i = 1;
		while(!feof(f)){
			fread(&c, sizeof(Contato),1,f);
			if(!feof(f)){
				printf("Nome: %s\n", c.nome);
				printf("Codigo: %d\n", i);
				printf("\n");
			}
			i++;
		}
	}
	rewind(f);
	printf("Informe o nome do contato que deseja editar: ");
	fflush(stdin);
	scanf("%29s", &nome);
	system("cls");
	while(!feof(f)){
		fread(&c, sizeof(Contato),1,f);
		if(!feof(f)){
			if(strcmp(c.nome, nome) == 0){
				printf("Nome: %s\n", c.nome);
				printf("Numero: %s\n", c.numero);
				printf("Email: %s\n", c.email);
				printf("\n");
			}
		}
	}
	fclose(f);
	printf("Deseja mesmo alterar os dados desse contato? (S/N): ");
	fflush(stdin);
	scanf("%1s", &escolha);
	escolha = toupper(escolha);
	if(escolha == 'S'){
		FILE *f = fopen("contatos.dat", "rb");
		FILE *f_copia = fopen("contatosCopia.dat", "a+b");
		system("cls");
		while(!feof(f)){
			fread(&c, sizeof(Contato),1,f);
			if(!feof(f)){
				if(strcmp(c.nome, nome) == 0){
					printf("Informe o novo nome do contato: ");
					scanf("%29s", &c.nome);
					printf("Informe o novo numero do contato: ");
					scanf("%10s", &c.numero);
					printf("Informe o novo email do contato: ");
					scanf("%49s", &c.email);
					fwrite(&c, sizeof(Contato),1,f_copia);
				}
				else{
					fwrite(&c, sizeof(Contato),1,f_copia);
				}
			}
		}
		fclose(f);
		fclose(f_copia);
		
		system("del contatos.dat");
		system("ren contatosCopia.dat contatos.dat");
	}
	return 0;
}

/*
Método Listar. 
Lista todos os contatos salvos.
*/ 
int Listar(){
	Contato c;
	int i,j, ver = 0;
	FILE *f = fopen("contatos.dat", "rb");
	if (f == NULL) {
		printf("nao ha contatos cadastrados.\n");
		system("pause");
		return (EXIT_FAILURE);
	}
	else{
		for(i = 0; i < 26; i++){
			ver = 0;
			rewind(f);
			while(!feof(f)){
				switch(i){
					case 0:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'a') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("A");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 1:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'b') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("B");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 2:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'c') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("C");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 3:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'd') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("D");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 4:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'e') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("E");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 5:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'f') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("F");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 6:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'g') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("G");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 7:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'h') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("H");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 8:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'i') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("I");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 9:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'j') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("J");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 10:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'k') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("K");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 11:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'l') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("L");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 12:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'm') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("M");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 13:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'n') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("N");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 14:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'o') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("O");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 15:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'p') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("P");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 16:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'q') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("Q");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 17:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'r') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("R");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 18:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 's') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("S");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 19:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 't') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("T");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 20:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'u') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("U");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 21:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'v') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("V");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 22:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'w') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("W");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 23:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'x') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("X");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 24:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'y') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("Y");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
					case 25:
						fread(&c, sizeof(Contato),1,f);
						if(!feof(f)){
							if((c.nome[0] - 'z') == 0){
								int tamanho = strlen(c.nome);
								if(ver == 0){
									printf("+");
									for(j = 0; j < 30; j++){
										printf("-");
									}
									printf("+\n");
									printf("|");
									printf("Z");
									printf("|");
									for(j = 0; j < 28; j++){
										printf(" ");
									}
									printf("|\n");
									printf("+-+\n");
									ver++;
								}
								printf("|");
								printf("%s", c.nome);
								for(j = 0; j < (30 - tamanho); j++){
									printf(" ");
								}
								printf("|\n");
							}
						}
						break;
				}
			}
		}
		printf("+");
		for(j = 0; j < 30; j++){
			printf("-");	
		}
		printf("+\n");
		char escolha, nome[30];
		printf("Deseja ver detalhe de algum contato? (S/N): ");
		fflush(stdin);
		scanf("%1s", &escolha);
		escolha = toupper(escolha);	
		rewind(f);
		if(escolha == 'S'){
			printf("Informe o nome do contato que deseja ver detalhe: ");
			fflush(stdin);
			scanf("%29s", &nome);
			system("cls");
			while(!feof(f)){
				fread(&c, sizeof(Contato),1,f);
				if(!feof(f)){
					if(strcmp(c.nome, nome) == 0){
						printf("Nome: %s\n", c.nome);
						printf("Numero: %s\n", c.numero);
						printf("Email: %s\n", c.email);
						printf("\n");
					}
				}
			}
			system("pause");
		}
	}
	fclose(f);
	return 0;
}

int Excluir(){
	Contato c;
	char escolha, nome[30];
	FILE *f = fopen("contatos.dat", "rb");
	if (f == NULL) {
		printf("nao ha contatos cadastrados.\n");
		return (EXIT_FAILURE);
	}
	else{
		while(!feof(f)){
			fread(&c, sizeof(Contato),1,f);
			if(!feof(f)){
				printf("Nome: %s\n", c.nome);
				printf("\n");
			}
		}
	}
	fclose(f);
	printf("Informe o nome do contato que deseja excluir: ");
	fflush(stdin);
	scanf("%29s", &nome);
	system("cls");
	printf("Deseja mesmo Exluir esse contato? (S/N): ");
	fflush(stdin);
	scanf("%1s", &escolha);
	escolha = toupper(escolha);
	system("cls");
	printf("Excluindo...\n");
	if(escolha == 'S'){
		FILE *f = fopen("contatos.dat", "rb");
		FILE *f_copia = fopen("contatosCopia.dat", "a+b");
		while(!feof(f)){
			fread(&c, sizeof(Contato),1,f);
			if(!feof(f)){
				if(strcmp(c.nome, nome) != 0){
					fwrite(&c, sizeof(Contato),1,f_copia);
				}
			}
		}
		fclose(f);
		fclose(f_copia);
		
		system("del contatos.dat");
		system("ren contatosCopia.dat contatos.dat");
	}
	return 0;
}

/*Método Tela_Inicial.
Cria a logo do programa
*/
void Tela_inicial(){
	system("color 2");
	int i,j,l,m, ver;
	//Criei cada letra como marcações em binário colocando asterisco onde tem o número 1
	char arrA[7][9] = {{0,0,0,1,1,1,0,0,0},{0,0,1,1,0,1,1,0,0},{0,1,1,0,0,0,1,1,0},{1,1,0,0,0,0,0,1,1},{1,1,1,1,1,1,1,1,1},{1,1,0,0,0,0,0,1,1},{1,1,0,0,0,0,0,1,1}};
	char arrG[7][9] = {{0,1,1,1,1,1,1,0,0},{1,1,0,0,0,0,1,1,0},{1,1,0,0,0,0,0,0,0},{1,1,0,0,0,1,1,1,1},{1,1,0,0,0,0,1,1,0},{1,1,0,0,0,0,1,1,0},{0,1,1,1,1,1,1,0,0}};
	char arrE[7][8] = {{1,1,1,1,1,1,1,1},{1,1,0,0,0,0,0,0},{1,1,0,0,0,0,0,0},{1,1,1,1,1,1,1,0},{1,1,0,0,0,0,0,0},{1,1,0,0,0,0,0,0},{1,1,1,1,1,1,1,1}};
	char arrN[7][8] = {{1,1,0,0,0,0,1,1},{1,1,1,0,0,0,1,1},{1,1,1,1,0,0,1,1},{1,1,0,1,1,0,1,1},{1,1,0,0,1,1,1,1},{1,1,0,0,0,1,1,1},{1,1,0,0,0,0,1,1}};
	char arrD[7][9] = {{1,1,1,1,1,1,1,1,0},{1,1,0,0,0,0,0,1,1},{1,1,0,0,0,0,0,1,1},{1,1,0,0,0,0,0,1,1},{1,1,0,0,0,0,0,1,1},{1,1,0,0,0,0,0,1,1},{1,1,1,1,1,1,1,1,0}};
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	for(i = 0; i < 7; i++){
		for(j = 0; j < 11; j++){
			if(j == 0){
				printf("            ");
				for(l = 0; l < 1; l++){
					for(m = 0; m < 9; m++){
						if(arrA[i][m] == 1){
							printf("#");
						}
						else{
							printf(" ");
						}
					}
				}
			}
			else if(j == 2){
				for(l = 0; l < 1; l++){
					for(m = 0; m < 9; m++){
						if(arrG[i][m] == 1){
							printf("#");
						}
						else{
							printf(" ");
						}
					}
				}
			}
			else if(j == 4){
				for(l = 0; l < 1; l++){
					for(m = 0; m < 8; m++){
						if(arrE[i][m] == 1){
							printf("#");
						}
						else{
							printf(" ");
						}
					}
				}
			}
			else if(j == 6){
				for(l = 0; l < 1; l++){
					for(m = 0; m < 8; m++){
						if(arrN[i][m] == 1){
							printf("#");
						}
						else{
							printf(" ");
						}
					}
				}
			}
			else if(j == 8){
				for(l = 0; l < 1; l++){
					for(m = 0; m < 9; m++){
						if(arrD[i][m] == 1){
							printf("#");
						}
						else{
							printf(" ");
						}
					}
				}
			}
			else if(j == 10){
				for(l = 0; l < 1; l++){
					for(m = 0; m < 9; m++){
						if(arrA[i][m] == 1){
							printf("#");
						}
						else{
							printf(" ");
						}
					}
				}
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
	getch();
}

/*
Método Menu.
Responsável pelo direcionar o usuário para os outros métodos.

OBS: A opção de sair está dando um bug gostaria de uma ajuda :) .
*/ 
int Menu(){
	system("cls");
	char sair;
	int escolha, verificador;
	printf("Escolha uma das opcoes abaixo.\n");
	printf("1 - Adicionar\n");
	printf("2 - Listar\n");
	printf("3 - Editar\n");
	printf("4 - Excluir\n");
	printf("5 - Sair\n");
	printf("Digite sua escolha: ");
	scanf("%d", &escolha);
	system("cls");
	switch(escolha){
		case 1:
			Adicionar();
			return 0;
			break;
		case 2:
			Listar();
			return 0;
			break;
		case 3:
			Editar();
			return 0;
			break;
		case 4:
			Excluir();
			system("PAUSE");
			return 0;
			break;
		case 5:
			do{
				printf("Deseja mesmo sair? (S/N): ");
				scanf("%1s", &sair);
				sair = toupper(sair);
				fflush(stdin);
				if(sair == 'S'){
					verificador = 1;
					return 1;
				}
				else if(sair == 'N'){
					verificador = 1;
					return 0;
				}
				else{
					verificador = 0;
					printf("Entrada invalida.\n");
					printf("Pressione qualquer tecla para continuar...");
					getch();
					system("cls");
				}
			}while(verificador == 0);
			break;
	}
}

int main(int argc, char *argv[]) {
	int sair;
	Tela_inicial();
	do{
		sair = Menu();
	}while(sair == 0);
	return 0;
}
