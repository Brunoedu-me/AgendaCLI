#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


/*Criação da estrutura do contato.
Nela temos os campos nome, numero, email*/
typedef struct {
char email[50];
char nome[30];
char numero[11];
} Contato;

/*Chamando as funções*/
void Tela_inicial();
int Menu();


int main(int argc, char *argv[]) {
	int sair;
	do{
		sair = Menu();
	}while(sair == 0);
	return 0;
}
/*Essa função verifica o tamanho da string informada*/
int strtam(char str[]){
	int cont = 0, tam = 0;
	while(str[cont] != '\0'){
		cont++;
		tam++;
	}
	return tam;
}
/*Essa função procura pelos nomes que contém os caracteres informados.*/
int strPesquisar(char str[], char cmp[]){
	int cont = 0, tem = 0;
	while(str[cont] != '\0'){
		if(str[cont] == cmp[cont]){
			tem++;
		}
		cont++;
	}
	if(tem == strtam(str)){
		return 1;
	}
	else{
		return 0;
	}
}
/*Essa função verifica se o nome é igual ao informado*/
int strPesquisarTotal(char str[], char cmp[]){
	int cont = 0, tem = 0;
	while(str[cont] != '\0'){
		if(str[cont] == cmp[cont]){
			tem++;
		}
		cont++;
	}
	if(tem == strtam(cmp)){
		return 1;
	}
	else{
		return 0;
	}
}
/*Essa função verifica se há espaço no nome informado*/
int VerificarEspaco(char str[]){
	int cont = 0, tem = 0;
	while(str[cont] != '\0'){
		cont++;
		if(str[cont] == ' '){
			tem++;	
		}
	}
	return tem;
}
/*Essa função gera a lista que vai ser mostrada para o usuário*/
int GerarLista(char letra[]){
	Contato c;
	int j, ver = 0, fim = 0;
	FILE *f = fopen("contatos.dat", "rb");
	while(!feof(f)){
		fread(&c, sizeof(Contato),1,f);	
		if(!feof(f)){
			if(strPesquisar(letra, c.nome) == 1){
				int tamanho = strtam(c.nome);
				if(ver == 0){
					printf("+");
					for(j = 0; j < 30; j++){
						printf("-");
					}
					printf("+\n");
					printf("|");
					for(j =0; j < strtam(letra); j++){
						printf("%c",letra[j]);
					}
					printf("|");
					for(j = 0; j < (29 - strtam(letra)); j++){
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
				fim = 1;
			}
		}
	}
	fclose(f);
	return fim;
}
/*Essa função vai pesquisar e chamar o gerar com os contatos encontrados*/
void Pesquisar(FILE *f){
	Contato c;
	int i;
	char pesquisa[30];
	printf("Pesquisar: ");
	fflush(stdin);
	scanf("%30[^\n]", &pesquisa);
	system("cls");
	if(GerarLista(pesquisa) == 1){
		printf("+");
		for(i = 0; i < 30; i++){
			printf("-");	
		}
		printf("+\n");
	}
	else{
		printf("Nenhum contato encontrado\n");
	}
}

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
		fflush(stdin);
		scanf("%29[^\n]", &c.nome);
		printf("Informe o numero do contato: ");
		fflush(stdin);
		scanf("%10s", &c.numero);
		printf("Informe o email do contato: ");
		fflush(stdin);
		scanf("%49s", &c.email);
		if(c.nome == "" || c.numero == "" || c.email == ""){
			system("cls");
			printf("Um dos campos está vazio\n");
			system("pause");
		}
		else{
			fwrite(&c, sizeof(Contato), 1, f);
		}
		fclose(f);
	}
	else{
		fclose(f);
		FILE *f = fopen("contatos.dat", "ab");
		printf("Informe o nome do contato: ");
		fflush(stdin);
		scanf("%29[^\n]", &c.nome);
		printf("Informe o numero do contato: ");
		fflush(stdin);
		scanf("%11s", &c.numero);
		printf("Informe o email do contato: ");
		fflush(stdin);
		scanf("%s", &c.email);
		if(c.nome == "" || c.numero == "" || c.email == ""){
			system("cls");
			printf("Um dos campos está vazio\n");
			system("pause");
		}
		else{
			fwrite(&c, sizeof(Contato), 1, f);
		}
		fclose(f);
	}
	return 0;
}

//Método Editar.
int Editar(){
	Contato c;
	int i,j, ver;
	char escolha, nome[30];
	FILE *f = fopen("contatos.dat", "rb");
	//Verifica se há contatos cadastrados.
	if (f == NULL) {
		printf("nao ha contatos cadastrados.\n");
		return (EXIT_FAILURE);
	}
	else{
		Pesquisar(f);
		rewind(f);
		printf("Informe o nome do contato que deseja editar: ");
		fflush(stdin);
		scanf("%30[^\n]", &nome);
		system("cls");
		while(!feof(f)){
			fread(&c, sizeof(Contato),1,f);
			if(!feof(f)){
				if(VerificarEspaco(nome) == 1){
					if(strPesquisarTotal(c.nome, nome) == 1){
						printf("Nome: %s\n", c.nome);
						printf("Numero: %s\n", c.numero);
						printf("Email: %s\n", c.email);
						printf("\n");
					}
				}
				else if(VerificarEspaco(nome) == 0){
					if(strPesquisar(c.nome, nome) == 1){
						printf("Nome: %s\n", c.nome);
						printf("Numero: %s\n", c.numero);
						printf("Email: %s\n", c.email);
						printf("\n");
					}
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
					if(strPesquisarTotal(c.nome, nome) == 1){
						printf("Informe o novo nome do contato: ");
						fflush(stdin);
						scanf("%30[^\n]", &c.nome);
						printf("Informe o novo numero do contato: ");
						fflush(stdin);
						scanf("%10s", &c.numero);
						printf("Informe o novo email do contato: ");
						fflush(stdin);
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
	}
	return 0;
}

/*
Método Listar. 
Essa função é responsável por listar os contatos
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
		Pesquisar(f);
		char escolha, nome[30];
		printf("Deseja ver detalhe de algum contato? (S/N): ");
		fflush(stdin);
		scanf("%1s", &escolha);
		escolha = toupper(escolha);	
		rewind(f);
		if(escolha == 'S'){
			printf("Informe o nome do contato que deseja ver detalhe: ");
			fflush(stdin);
			scanf("%30[^\n]", &nome);
			system("cls");
			while(!feof(f)){
				fread(&c, sizeof(Contato),1,f);
				if(!feof(f)){
					if(VerificarEspaco(nome) == 1){
						if(strPesquisarTotal(c.nome, nome) == 1){
							printf("Nome: %s\n", c.nome);
							printf("Numero: %s\n", c.numero);
							printf("Email: %s\n", c.email);
							printf("\n");
						}
					}
					else if(VerificarEspaco(nome) == 0){
						if(strPesquisar(c.nome, nome) == 1){
							printf("Nome: %s\n", c.nome);
							printf("Numero: %s\n", c.numero);
							printf("Email: %s\n", c.email);
							printf("\n");
						}
					}
				}
			}
			system("pause");
		}
	}
	fclose(f);
	return 0;
}
/*Método Excluir.
Essa função é responsável por verificar e excluir o contato desejado*/
int Excluir(){
	Contato c;
	int i,j, ver = 0, tem = 0;
	char escolha, nome[30];
	FILE *f = fopen("contatos.dat", "rb");
	if (f == NULL) {
		printf("nao ha contatos cadastrados.\n");
		return (EXIT_FAILURE);
	}
	else{
		Pesquisar(f);
		rewind(f);
		printf("Informe o nome do contato que deseja excluir: ");
		fflush(stdin);
		scanf("%30[^\n]", &nome);
		system("cls");
		while(!feof(f) && ver == 0){
		fread(&c, sizeof(Contato),1,f);
			if(!feof(f)){
				if(strPesquisarTotal(c.nome, nome) == 1){
					tem = 1;
					ver = 1;
				}
			}
		}
		fclose(f);
		if(tem == 1 && ver == 1){
			printf("%s\n", c.nome);
			printf("Deseja mesmo Exluir esse contato? (S/N): ");
			fflush(stdin);
			scanf("%1s", &escolha);
			escolha = toupper(escolha);
			system("cls");
			if(escolha == 'S'){
				printf("Excluindo...\n");
				FILE *f = fopen("contatos.dat", "rb");
				FILE *f_copia = fopen("contatosCopia.dat", "a+b");
				while(!feof(f)){
					fread(&c, sizeof(Contato),1,f);
					if(!feof(f)){
						if(strPesquisarTotal(c.nome, nome) == 0){
							fwrite(&c, sizeof(Contato),1,f_copia);
						}
					}
				}
				fclose(f);
				fclose(f_copia);
				
				system("del contatos.dat");
				system("ren contatosCopia.dat contatos.dat");
			}
			else if(escolha == 'N'){
				printf("Voce decidiu nao excluir\n");
			}
			else{
				printf("Opcao nao encontrada\n");
			}
		}
		else{
			printf("Usuario nao encontrado\n");
		}
	}
	return 0;
}

/*Método Tela_Inicial.
Cria a logo do programa
*/
void Tela_inicial(){
	system("color 2");
	int i,j,l,m, ver;
	//Criei cada letra como marcações em binário colocando sharp onde tem o número 1
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
	for(i = 0; i < 7; i++){
		for(j = 0; j < 11; j++){
			if(j == 0){
				for(l = 0; l < 30; l++){
					printf(" ");
				}
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
	printf("\n");
	printf("\n");
	for(i = 0; i < 40; i++){
		printf(" ");
	}
	printf("Escolha uma das opcoes abaixo:\n");
	for(i = 1; i < 6; i++){
		for(j = 0; j < 45; j++){
			printf(" ");
		}
		switch(i){
			case 1:
				printf("1 - Adicionar\n");
				break;
			case 2:
				printf("2 - Listar\n");
				break;
			case 3:
				printf("3 - Editar\n");
				break;
			case 4:
				printf("4 - Excluir\n");
				break;
			case 5:
				printf("ESC - Sair\n");
				break;
				
		}
	}
}

/*
Método Menu.
Responsável por direcionar o usuário para os outros métodos.
*/ 
int Menu(){
	int i;
	system("cls");
	Tela_inicial();
	char sair, tecla;
	int verificador;
	printf("\n");
	for(i = 0; i < 45; i++){
		printf(" ");
	}
	fflush(stdin);
	tecla = getch();
	system("cls");
	switch(tecla){
		case 49:
			Adicionar();
			return 0;
			break;
		case 50:
			Listar();
			return 0;
			break;
		case 51:
			Editar();
			return 0;
			break;
		case 52:
			Excluir();
			system("PAUSE");
			return 0;
			break;
		case 27:
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
					system("cls");
					verificador = 0;
					printf("Entrada invalida.\n");
					system("pause");
					system("cls");
				}
			}while(verificador == 0);
			break;
		default:
			printf("Entrada invalida.\n");
			printf("Pressione qualquer tecla para continuar...");
			getch();
			system("cls");
			break;
	}
}
