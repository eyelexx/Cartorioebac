#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca de aloca��es de texto por regi�o (idiomas)
#include <string.h> // Biblioteca respons�vel por cuidar das strings

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~FUN��ES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int registro() {
	// Cria��o de vari�veis.
	char arquivo[40]; // Os colchetes indicam que a vari�vel � uma string, 
	char cpf[40]; //     e dentro deles um espa�o reservado (40 caracteres)
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int registrarNovamente=0;
	
	// ~~~~~~~~ In�cio do cadastro ~~~~~~~~	
	do {
		printf("### Cart�rio da EBAC - Registro de Nomes ###\n\n");
		// Coletando as informa��es do usu�rio.
		printf("Digite o CPF a ser cadastrado: "); // Recebe o CPF
		scanf("%s", &cpf); // "%s" refere-se a uma string.
		strcpy(arquivo, cpf); // Copia o valor de uma string para outra. (paraOndeVai[arquivo], deOndeVem[cpf]).
		
		FILE *file; // FILE � uma fun��o da biblioteca | *file cria um arquivo 'file'.
		file = fopen(arquivo, "w"); // fopen abre o arquivo da vari�vel e executa uma a��o "w" para escrever.
		fprintf(file, "CPF: %s", cpf);
		fclose(file); // Fecha o arquivo.
		
		file = fopen(arquivo, "a"); // Abre o arquivo e executa "a" para atualizar.
		fprintf(file, ", "); // Escreve " ,"
		fclose(file); // Fecha.
		
		
		printf("Digite o nome a ser cadastrado: "); // Recebe o nome
		scanf("%s", &nome); // Armazena na vari�vel o que foi digitado pelo usu�rio.
		fclose(file); // Fecha.
		
		file = fopen(arquivo, "a"); // Abre o arquivo para atualizar.
		fprintf(file, "Nome: %s", nome); // Escreve no arquivo os dados da vari�vel referenciada.
		fclose(file); // Fecha.
		
		file = fopen(arquivo, "a"); // Abre o arquivo.
		fprintf(file, ", "); // Escreve " ,"
		fclose(file); // Fecha.
		
		
		printf("Digite o sobrenome a ser cadastrado: "); // Recebe o sobrenome
		scanf("%s", &sobrenome); // Armazena o que foi digitado pelo usu�rio.
		fclose(file); // Fecha.
		
		file = fopen(arquivo, "a"); // Abre o arquivo.
		fprintf(file, "Sobrenome: %s", sobrenome); // Escreve no arquivo.
		fclose(file); // Fecha.
		
		file = fopen(arquivo, "a"); // Abre o arquivo .
		fprintf(file, ", "); // Escreve " ,"
		fclose(file); // Fecha.
		

		printf("Digite o cargo a ser cadastrado: "); // Recebe o cargo.
		scanf("%s", &cargo); // Armazena o que foi digitado pelo usu�rio.
		fclose(file); // Fecha.
		
		file = fopen(arquivo, "a"); // Abre o arquivo.
		fprintf(file, "Cargo: %s", cargo); // Escreve no arquivo os dados da vari�vel referenciada.
		fclose(file); // Fecha.
		// ~~~~~~~~ Fim do cadastro ~~~~~~~~
		 
		system("cls");
		
		// Mensagem de sucesso e op��es adicionais.
		printf("### Cart�rio da EBAC - Registro de Nomes ###\n\n");
		printf("Cadastro feito com sucesso!\n\n\n\n");
		printf("Deseja fazer um novo registro?\n\n");
		printf("\t1 - Sim\n");
		printf("\t2 - Voltar ao menu principal\n\n");
		printf("Op��o: ");
		scanf("%d", &registrarNovamente);
		
		system("cls");
	} while (registrarNovamente == 1); // Fim da repeti��o
}

int consulta() {
	char cpf[40]; // Vari�vel que recebe o valor digitado pelo usu�rio.
	char conteudo[100]; // Vari�vel que armazena o conte�do do arquivo das informa��es.
	
	int consultarNovamente=0;	
	
	do { // In�cio da repeti��o.
		setlocale(LC_ALL, "Portuguese"); // Define a linguagem.
		
		printf("### Cart�rio da EBAC - Registro de Nomes ###\n\n");
		printf("Digite o CPF a ser consultado: ");
		scanf("%s", &cpf);
			
		system("cls");
				
		FILE *file;
		file = fopen(cpf, "r"); // Abre o arquivo  e l� ("r") tudo o que estiver dentro dele.
			
		if (file == NULL) { // "Se o arquivo for nulo..."
			printf("Usu�rio n�o encontrado.\n\n\n"); // Mensagem de erro.
		}
		
		while(fgets(conteudo, 100, file) != NULL) { // Enquanto estiver algum conte�do no arquivo ele armazena na vari�vel (conte�do)
			printf("### Cart�rio da EBAC - Registro de Nomes ###\n\n");
			printf("Estas s�o as informa��es do usu�rio: \n");
			printf("%s", conteudo); // Mostra as informa��es da vari�vel "conteudo".
			printf("\n\n\n\n");
		}
		
		fclose(file);
		
		printf("Deseja fazer uma nova consulta?\n\n");
		printf("\t1 - Sim\n");
		printf("\t2 - Voltar ao menu principal\n\n");
		printf("Op��o: ");
		scanf("%d", &consultarNovamente); // Manda a informa��o do usu�rio para a vari�vel "nova_consulta".
		
		system("cls");
		
		// Mensagem de erro
		if(consultarNovamente <=0 || consultarNovamente >=3) { // "Se a vari�vel "nova_consulta" for menor ou igual a 3 ou for maior ou igual a 3..."
			printf("Esta n�o � uma op��o v�lida.\n");
			system("pause");
		}
	} while(consultarNovamente == 1); // Fim da repeti��o.
}

int deletar() {
	char cpf[40];
	
	int deletarNovamente = 0;
	
	do {
		printf("### Cart�rio da EBAC - Registro de Nomes ###\n\n");
		printf("Digite o CPF do usu�rio a ser deletado: "); // Recebe os dados do usu�rio a ser deletado.
		scanf("%s", cpf);
		
		system("cls");
			
		FILE *file;
		file = fopen(cpf, "r");	// Abre o arquivo.
		
		if(file != NULL) { // "Se file for diferente de nulo..."
			fclose(file); // Fecha o arquivo.
			remove(cpf); // Apaga o arquivo.
			
			printf("### Cart�rio da EBAC - Registro de Nomes ###\n\n");
			printf("Usu�rio deletado com sucesso!\n\n\n"); // Mensagem de confirma��o.
			printf("Deseja fazer uma nova remo��o?\n\n");
			printf("\t1- Sim\n");
			printf("\t2- N�o\n\n");
			printf("Op��o:");
			scanf("%d", &deletarNovamente);
			system("cls");
		} else { // "Se n�o..."
			printf("Usu�rio n�o encontrado\n\n"); // Mensagem de erro.
			system("pause");
		}
	} while ( deletarNovamente == 1);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~ IN�CIO DO PROGRAMA ~~~~~~~~~~~~~~~~~~~~~~~~

int main() {
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	// ~~~~~~ Definindo vari�veis ~~~~~~
	int opcao = 0; // Vari�veis do menu principal
	int lacoMenu = 1; // Loop menu principal
	char usuarioDigitado[10] = "a";
	char senhaDigitada[10] = "a";
	int comparaUsuario;
	int comparaSenha;
	int lacoLogin = 0; // Loop login
	
	// ~~~~~~ Valida��o de usu�rio ~~~~~~
	do {
		system("cls");
		
		printf("### Cart�rio da EBAC - Registro de Nomes ###\n\n");
		printf("\tLogin de administrador.\n\n\tUsu�rio: ");
		scanf("%s", &usuarioDigitado);
		
		comparaUsuario = strcmp(usuarioDigitado, "admin"); //strcmp compara o valore da vari�vel 'senhadigitada' com um valor pr� definido 'admin', se forem iguais ele retorna o valor 0.
		
		if(comparaUsuario == 0) { // Se o valor de 'comparaUsuario' for igual a 0, prossiga...
		
			// ~~~~~~ Valida��o da senha ~~~~~~
			printf("\tSenha: ");
			scanf("%s", &senhaDigitada);
			
			comparaSenha = strcmp(senhaDigitada, "admin"); // resultado = strcmp(str1, str2)

			if(comparaSenha == 0) { // Aguarda return 0 do 'comparaSenha'
				for(lacoMenu = 1;lacoMenu = 1;)	{
					system("cls");
					
					// In�cio do menu
					printf("### Cart�rio da EBAC - Registro de Nomes ###\n\n");
					printf("Escolha a op��o desejada:\n\n");
					printf("\t1 - Registrar\n");
					printf("\t2 - Consultar\n");
					printf("\t3 - Deletar\n\n");
					printf("\t4 - Sair do sistema\n\n");
					printf("Op��o: ");
					scanf("%d", &opcao); // Recebe a informa��o digitada pelo usu�rio e armazena na vari�vel int
					// Fim do menu
					
					system("cls"); 
					
					// Op��es de sele��o
					switch(opcao) {
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
						printf("### Cart�rio da EBAC - Registro de Nomes ###\n\n");
						printf("Obrigado por utilizar o sistema!\n\n");
						return 0;
						break;
						
						default:
						printf("### Cart�rio da EBAC - Registro de Nomes ###\n\n");
						printf("Esta n�o � uma op��o v�lida.\n\n");
						system("pause");
						break;
						// Fim da sele��o
					}
				}
			} else { //Mensagem de erro (Senha incorreta)
				system("cls");
				printf("### Cart�rio da EBAC - Registro de Nomes ###\n\n");
				printf("Senha incorreta.\n\n\n\n\n");
				printf("\t1 - Tentar novamente\n\t2 - Sair do programa\n\n");
				printf("Op��o: ");
				scanf("%i", &lacoLogin);		
			}
		} else { //Mensagem de erro (Usu�rio incorreto)
			system("cls");
			printf("### Cart�rio da EBAC - Registro de Nomes ###\n\n");
			printf("Usu�rio incorreto.\n\n\n\n\n");
			printf("\t1 - Tentar novamente\n\t2 - Sair do programa\n\n");
			printf("Op��o: ");
			scanf("%i", &lacoLogin);		
		}
	} while (lacoLogin == 1); // Enquanto a vari�vel 'lacoLogin' valer 1, volte para o menu de login.
}
