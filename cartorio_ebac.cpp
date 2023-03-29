#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca de aloca��es de texto por regi�o (idiomas)
#include <string.h> // Biblioteca respons�vel por cuidar das strings

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~FUN��ES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int registro() { // Fun��o respons�vel por cadastrar os usu�rios no sistema.

	// Cria��o de vari�veis.
	char arquivo[40]; // Os colchetes indicam que a vari�vel � uma string, e dentro deles um espa�o reservado (40 caracteres)
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	// In�cio do cadastro.
	int registrar_novamente=0;
	
	do {
		printf("Digite o CPF a ser cadastrado: "); // Coletando as informa��es do usu�rio.
		scanf("%s", &cpf); // "%s" refere-se a uma string.
		
		strcpy(arquivo, cpf); // Copia os valores das strings. (paraOndeVai[arquivo], deOndeVem[cpf]).
		
		FILE *file; // FILE � uma fun��o da biblioteca | *file cria um arquivo 'file'.
		file = fopen(arquivo, "w"); // fopen abre o arquivo da vari�vel e executa uma a��o "w" para escrever.
		fprintf(file, "CPF: %s", cpf);
		fclose(file); // Fecha o arquivo.
		
		file = fopen(arquivo, "a"); // Abre o arquivo e executa "a" para atualizar.
		fprintf(file, ", "); // Escreve " ,"
		fclose(file); // Fecha.
		
		printf("Digite o nome a ser cadastrado: "); // Coletando as informa��es.
		scanf("%s", &nome); // Armazena na vari�vel o que foi digitado pelo usu�rio.
		fclose(file); // Fecha.
		
		file = fopen(arquivo, "a"); // Abre o arquivo para atualizar.
		fprintf(file, "Nome: %s", nome); // Escreve no arquivo os dados da vari�vel referenciada.
		fclose(file); // Fecha.
		
		file = fopen(arquivo, "a"); // Abre o arquivo.
		fprintf(file, ", "); // Escreve " ,"
		fclose(file); // Fecha.
		
		printf("Digite o sobrenome a ser cadastrado: "); // Coletando as informa��es.
		scanf("%s", &sobrenome); // Armazena o que foi digitado pelo usu�rio.
		fclose(file); // Fecha.
		
		file = fopen(arquivo, "a"); // Abre o arquivo.
		fprintf(file, "Sobrenome: %s", sobrenome); // Escreve no arquivo.
		fclose(file); // Fecha.
		
		file = fopen(arquivo, "a"); // Abre o arquivo .
		fprintf(file, ", "); // Escreve " ,"
		fclose(file); // Fecha.
		
		printf("Digite o cargo a ser cadastrado: "); // Coletando as informa��es.
		scanf("%s", &cargo); // Armazena o que foi digitado pelo usu�rio.
		fclose(file); // Fecha.
		
		file = fopen(arquivo, "a"); // Abre o arquivo.
		fprintf(file, "Cargo: %s", cargo); // Escreve no arquivo os dados da vari�vel referenciada.
		fclose(file); // Fecha.
		
		system("cls"); // Fim do cadastro.
		
		printf("Cadastro feito com sucesso!\n\n\n"); // Mensagem de sucesso e op��es adicionais.
		printf("Deseja fazer um novo registro?\n\n");
		printf("\t1 - Sim\n");
		printf("\t2 - Voltar ao menu principal\n\n");
		printf("Op��o: ");
		scanf("%d", &registrar_novamente);
		
		system("cls");
	} while (registrar_novamente == 1); // Fim da repeti��o
}

int consulta() {
	char cpf[40]; // Vari�vel que recebe o valor digitado pelo usu�rio.
	char conteudo[100]; // Vari�vel que armazena o conte�do do arquivo das informa��es.
	
	int consultar_novamente=0;	
	
	do { // In�cio da repeti��o.
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem.
			
		printf("Digite o CPF a ser consultado: ");
		scanf("%s", &cpf);
			
		system("cls");
				
		FILE *file;
		file = fopen(cpf, "r"); // Abre o arquivo  e l� ("r") tudo o que estiver dentro dele.
			
		if (file == NULL) { // "Se o arquivo for nulo..."
			printf("Usu�rio n�o encontrado.\n\n\n"); // Mensagem de erro.
		}
			
		while(fgets(conteudo, 100, file) != NULL) { // Enquanto estiver algum conte�do no arquivo ele armazena na vari�vel (conte�do)
			printf("Estas s�o as informa��es do usu�rio: \n");
			printf("%s", conteudo); // Mostra as informa��es da vari�vel "conteudo".
			printf("\n\n\n\n");
		}
		
		fclose(file);
		
		printf("Deseja fazer uma nova consulta?\n\n");
		printf("\t1 - Sim\n");
		printf("\t2 - Voltar ao menu principal\n\n");
		printf("Op��o: ");
		scanf("%d", &consultar_novamente); // Manda a informa��o do usu�rio para a vari�vel "nova_consulta".
		
		system("cls");
		
		if(consultar_novamente <=0 || consultar_novamente >=3) { // "Se a vari�vel "nova_consulta" for menor ou igual a 3 ou for maior ou igual a 3..."
			printf("Esta n�o � uma op��o v�lida.\n");
			system("pause");
		}
	} while(consultar_novamente == 1); // Fim da repeti��o.
}

int deletar() {
	char cpf[40];
	
	int deletar_novamente = 0;
	
	do {
		printf("Digite o CPF do usu�rio a ser deletado: "); // Recebe os dados do usu�rio a ser deletado.
		scanf("%s", cpf);
		
		system("cls");
			
		FILE *file;
		file = fopen(cpf, "r");	// Abre o arquivo.
		
		if(file != NULL) { // "Se file for diferente de nulo..."
			fclose(file); // Fecha o arquivo.
			remove(cpf); // Apaga o arquivo.
			
			printf("Usu�rio deletado com sucesso!\n\n\n"); // Mensagem de confirma��o.
			printf("Deseja fazer uma nova remo��o?\n\n");
			printf("\t1- Sim\n");
			printf("\t2- N�o\n\n");
			printf("Op��o:");
			scanf("%d", &deletar_novamente);
			system("cls");
		} else { // "Se n�o..."
			printf("Usu�rio n�o encontrado\n\n"); // Mensagem de erro.
			system("pause");
		}
	} while ( deletar_novamente == 1);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ IN�CIO DO PROGRAMA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main() {
	int opcao=0; // Definindo vari�veis
	int laco=1;

	for(laco=1;laco=1;)	{
		system("cls"); // Limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
		
		printf("### Cart�rio da EBAC ###\n\n"); // In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); // Fim do menu
		
		scanf("%d", &opcao); // Recebe a informa��o digitada pelo usu�rio e armazena na vari�vel int
		
		system("cls"); 
		
		switch(opcao) { // In�cio da sele��o
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Esta n�o � uma op��o v�lida.\n");
			system("pause");
			break; // Fim da sele��o
		}
	}
}

