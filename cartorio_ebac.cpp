#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocações de texto por região (idiomas)
#include <string.h> // Biblioteca responsável por cuidar das strings

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~FUNÇÕES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int registro() {
	// Criação de variáveis.
	char arquivo[40]; // Os colchetes indicam que a variável é uma string, 
	char cpf[40]; //     e dentro deles um espaço reservado (40 caracteres)
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int registrarNovamente=0;
	
	// ~~~~~~~~ Início do cadastro ~~~~~~~~	
	do {
		printf("### Cartório da EBAC - Registro de Nomes ###\n\n");
		// Coletando as informações do usuário.
		printf("Digite o CPF a ser cadastrado: "); // Recebe o CPF
		scanf("%s", &cpf); // "%s" refere-se a uma string.
		strcpy(arquivo, cpf); // Copia o valor de uma string para outra. (paraOndeVai[arquivo], deOndeVem[cpf]).
		
		FILE *file; // FILE é uma função da biblioteca | *file cria um arquivo 'file'.
		file = fopen(arquivo, "w"); // fopen abre o arquivo da variável e executa uma ação "w" para escrever.
		fprintf(file, "CPF: %s", cpf);
		fclose(file); // Fecha o arquivo.
		
		file = fopen(arquivo, "a"); // Abre o arquivo e executa "a" para atualizar.
		fprintf(file, ", "); // Escreve " ,"
		fclose(file); // Fecha.
		
		
		printf("Digite o nome a ser cadastrado: "); // Recebe o nome
		scanf("%s", &nome); // Armazena na variável o que foi digitado pelo usuário.
		fclose(file); // Fecha.
		
		file = fopen(arquivo, "a"); // Abre o arquivo para atualizar.
		fprintf(file, "Nome: %s", nome); // Escreve no arquivo os dados da variável referenciada.
		fclose(file); // Fecha.
		
		file = fopen(arquivo, "a"); // Abre o arquivo.
		fprintf(file, ", "); // Escreve " ,"
		fclose(file); // Fecha.
		
		
		printf("Digite o sobrenome a ser cadastrado: "); // Recebe o sobrenome
		scanf("%s", &sobrenome); // Armazena o que foi digitado pelo usuário.
		fclose(file); // Fecha.
		
		file = fopen(arquivo, "a"); // Abre o arquivo.
		fprintf(file, "Sobrenome: %s", sobrenome); // Escreve no arquivo.
		fclose(file); // Fecha.
		
		file = fopen(arquivo, "a"); // Abre o arquivo .
		fprintf(file, ", "); // Escreve " ,"
		fclose(file); // Fecha.
		

		printf("Digite o cargo a ser cadastrado: "); // Recebe o cargo.
		scanf("%s", &cargo); // Armazena o que foi digitado pelo usuário.
		fclose(file); // Fecha.
		
		file = fopen(arquivo, "a"); // Abre o arquivo.
		fprintf(file, "Cargo: %s", cargo); // Escreve no arquivo os dados da variável referenciada.
		fclose(file); // Fecha.
		// ~~~~~~~~ Fim do cadastro ~~~~~~~~
		 
		system("cls");
		
		// Mensagem de sucesso e opções adicionais.
		printf("### Cartório da EBAC - Registro de Nomes ###\n\n");
		printf("Cadastro feito com sucesso!\n\n\n\n");
		printf("Deseja fazer um novo registro?\n\n");
		printf("\t1 - Sim\n");
		printf("\t2 - Voltar ao menu principal\n\n");
		printf("Opção: ");
		scanf("%d", &registrarNovamente);
		
		system("cls");
	} while (registrarNovamente == 1); // Fim da repetição
}

int consulta() {
	char cpf[40]; // Variável que recebe o valor digitado pelo usuário.
	char conteudo[100]; // Variável que armazena o conteúdo do arquivo das informações.
	
	int consultarNovamente=0;	
	
	do { // Início da repetição.
		setlocale(LC_ALL, "Portuguese"); // Define a linguagem.
		
		printf("### Cartório da EBAC - Registro de Nomes ###\n\n");
		printf("Digite o CPF a ser consultado: ");
		scanf("%s", &cpf);
			
		system("cls");
				
		FILE *file;
		file = fopen(cpf, "r"); // Abre o arquivo  e lê ("r") tudo o que estiver dentro dele.
			
		if (file == NULL) { // "Se o arquivo for nulo..."
			printf("Usuário não encontrado.\n\n\n"); // Mensagem de erro.
		}
		
		while(fgets(conteudo, 100, file) != NULL) { // Enquanto estiver algum conteúdo no arquivo ele armazena na variável (conteúdo)
			printf("### Cartório da EBAC - Registro de Nomes ###\n\n");
			printf("Estas são as informações do usuário: \n");
			printf("%s", conteudo); // Mostra as informações da variável "conteudo".
			printf("\n\n\n\n");
		}
		
		fclose(file);
		
		printf("Deseja fazer uma nova consulta?\n\n");
		printf("\t1 - Sim\n");
		printf("\t2 - Voltar ao menu principal\n\n");
		printf("Opção: ");
		scanf("%d", &consultarNovamente); // Manda a informação do usuário para a variável "nova_consulta".
		
		system("cls");
		
		// Mensagem de erro
		if(consultarNovamente <=0 || consultarNovamente >=3) { // "Se a variável "nova_consulta" for menor ou igual a 3 ou for maior ou igual a 3..."
			printf("Esta não é uma opção válida.\n");
			system("pause");
		}
	} while(consultarNovamente == 1); // Fim da repetição.
}

int deletar() {
	char cpf[40];
	
	int deletarNovamente = 0;
	
	do {
		printf("### Cartório da EBAC - Registro de Nomes ###\n\n");
		printf("Digite o CPF do usuário a ser deletado: "); // Recebe os dados do usuário a ser deletado.
		scanf("%s", cpf);
		
		system("cls");
			
		FILE *file;
		file = fopen(cpf, "r");	// Abre o arquivo.
		
		if(file != NULL) { // "Se file for diferente de nulo..."
			fclose(file); // Fecha o arquivo.
			remove(cpf); // Apaga o arquivo.
			
			printf("### Cartório da EBAC - Registro de Nomes ###\n\n");
			printf("Usuário deletado com sucesso!\n\n\n"); // Mensagem de confirmação.
			printf("Deseja fazer uma nova remoção?\n\n");
			printf("\t1- Sim\n");
			printf("\t2- Não\n\n");
			printf("Opção:");
			scanf("%d", &deletarNovamente);
			system("cls");
		} else { // "Se não..."
			printf("Usuário não encontrado\n\n"); // Mensagem de erro.
			system("pause");
		}
	} while ( deletarNovamente == 1);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~ INÍCIO DO PROGRAMA ~~~~~~~~~~~~~~~~~~~~~~~~

int main() {
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	// ~~~~~~ Definindo variáveis ~~~~~~
	int opcao = 0; // Variáveis do menu principal
	int lacoMenu = 1; // Loop menu principal
	char usuarioDigitado[10] = "a";
	char senhaDigitada[10] = "a";
	int comparaUsuario;
	int comparaSenha;
	int lacoLogin = 0; // Loop login
	
	// ~~~~~~ Validação de usuário ~~~~~~
	do {
		system("cls");
		
		printf("### Cartório da EBAC - Registro de Nomes ###\n\n");
		printf("\tLogin de administrador.\n\n\tUsuário: ");
		scanf("%s", &usuarioDigitado);
		
		comparaUsuario = strcmp(usuarioDigitado, "admin"); //strcmp compara o valore da variável 'senhadigitada' com um valor pré definido 'admin', se forem iguais ele retorna o valor 0.
		
		if(comparaUsuario == 0) { // Se o valor de 'comparaUsuario' for igual a 0, prossiga...
		
			// ~~~~~~ Validação da senha ~~~~~~
			printf("\tSenha: ");
			scanf("%s", &senhaDigitada);
			
			comparaSenha = strcmp(senhaDigitada, "admin"); // resultado = strcmp(str1, str2)

			if(comparaSenha == 0) { // Aguarda return 0 do 'comparaSenha'
				for(lacoMenu = 1;lacoMenu = 1;)	{
					system("cls");
					
					// Início do menu
					printf("### Cartório da EBAC - Registro de Nomes ###\n\n");
					printf("Escolha a opção desejada:\n\n");
					printf("\t1 - Registrar\n");
					printf("\t2 - Consultar\n");
					printf("\t3 - Deletar\n\n");
					printf("\t4 - Sair do sistema\n\n");
					printf("Opção: ");
					scanf("%d", &opcao); // Recebe a informação digitada pelo usuário e armazena na variável int
					// Fim do menu
					
					system("cls"); 
					
					// Opções de seleção
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
						printf("### Cartório da EBAC - Registro de Nomes ###\n\n");
						printf("Obrigado por utilizar o sistema!\n\n");
						return 0;
						break;
						
						default:
						printf("### Cartório da EBAC - Registro de Nomes ###\n\n");
						printf("Esta não é uma opção válida.\n\n");
						system("pause");
						break;
						// Fim da seleção
					}
				}
			} else { //Mensagem de erro (Senha incorreta)
				system("cls");
				printf("### Cartório da EBAC - Registro de Nomes ###\n\n");
				printf("Senha incorreta.\n\n\n\n\n");
				printf("\t1 - Tentar novamente\n\t2 - Sair do programa\n\n");
				printf("Opção: ");
				scanf("%i", &lacoLogin);		
			}
		} else { //Mensagem de erro (Usuário incorreto)
			system("cls");
			printf("### Cartório da EBAC - Registro de Nomes ###\n\n");
			printf("Usuário incorreto.\n\n\n\n\n");
			printf("\t1 - Tentar novamente\n\t2 - Sair do programa\n\n");
			printf("Opção: ");
			scanf("%i", &lacoLogin);		
		}
	} while (lacoLogin == 1); // Enquanto a variável 'lacoLogin' valer 1, volte para o menu de login.
}
