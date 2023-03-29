#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocações de texto por região (idiomas)
#include <string.h> // Biblioteca responsável por cuidar das strings

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~FUNÇÕES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int registro() { // Função responsável por cadastrar os usuários no sistema.

	// Criação de variáveis.
	char arquivo[40]; // Os colchetes indicam que a variável é uma string, e dentro deles um espaço reservado (40 caracteres)
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	// Início do cadastro.
	int registrar_novamente=0;
	
	do {
		printf("Digite o CPF a ser cadastrado: "); // Coletando as informações do usuário.
		scanf("%s", &cpf); // "%s" refere-se a uma string.
		
		strcpy(arquivo, cpf); // Copia os valores das strings. (paraOndeVai[arquivo], deOndeVem[cpf]).
		
		FILE *file; // FILE é uma função da biblioteca | *file cria um arquivo 'file'.
		file = fopen(arquivo, "w"); // fopen abre o arquivo da variável e executa uma ação "w" para escrever.
		fprintf(file, "CPF: %s", cpf);
		fclose(file); // Fecha o arquivo.
		
		file = fopen(arquivo, "a"); // Abre o arquivo e executa "a" para atualizar.
		fprintf(file, ", "); // Escreve " ,"
		fclose(file); // Fecha.
		
		printf("Digite o nome a ser cadastrado: "); // Coletando as informações.
		scanf("%s", &nome); // Armazena na variável o que foi digitado pelo usuário.
		fclose(file); // Fecha.
		
		file = fopen(arquivo, "a"); // Abre o arquivo para atualizar.
		fprintf(file, "Nome: %s", nome); // Escreve no arquivo os dados da variável referenciada.
		fclose(file); // Fecha.
		
		file = fopen(arquivo, "a"); // Abre o arquivo.
		fprintf(file, ", "); // Escreve " ,"
		fclose(file); // Fecha.
		
		printf("Digite o sobrenome a ser cadastrado: "); // Coletando as informações.
		scanf("%s", &sobrenome); // Armazena o que foi digitado pelo usuário.
		fclose(file); // Fecha.
		
		file = fopen(arquivo, "a"); // Abre o arquivo.
		fprintf(file, "Sobrenome: %s", sobrenome); // Escreve no arquivo.
		fclose(file); // Fecha.
		
		file = fopen(arquivo, "a"); // Abre o arquivo .
		fprintf(file, ", "); // Escreve " ,"
		fclose(file); // Fecha.
		
		printf("Digite o cargo a ser cadastrado: "); // Coletando as informações.
		scanf("%s", &cargo); // Armazena o que foi digitado pelo usuário.
		fclose(file); // Fecha.
		
		file = fopen(arquivo, "a"); // Abre o arquivo.
		fprintf(file, "Cargo: %s", cargo); // Escreve no arquivo os dados da variável referenciada.
		fclose(file); // Fecha.
		
		system("cls"); // Fim do cadastro.
		
		printf("Cadastro feito com sucesso!\n\n\n"); // Mensagem de sucesso e opções adicionais.
		printf("Deseja fazer um novo registro?\n\n");
		printf("\t1 - Sim\n");
		printf("\t2 - Voltar ao menu principal\n\n");
		printf("Opção: ");
		scanf("%d", &registrar_novamente);
		
		system("cls");
	} while (registrar_novamente == 1); // Fim da repetição
}

int consulta() {
	char cpf[40]; // Variável que recebe o valor digitado pelo usuário.
	char conteudo[100]; // Variável que armazena o conteúdo do arquivo das informações.
	
	int consultar_novamente=0;	
	
	do { // Início da repetição.
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem.
			
		printf("Digite o CPF a ser consultado: ");
		scanf("%s", &cpf);
			
		system("cls");
				
		FILE *file;
		file = fopen(cpf, "r"); // Abre o arquivo  e lê ("r") tudo o que estiver dentro dele.
			
		if (file == NULL) { // "Se o arquivo for nulo..."
			printf("Usuário não encontrado.\n\n\n"); // Mensagem de erro.
		}
			
		while(fgets(conteudo, 100, file) != NULL) { // Enquanto estiver algum conteúdo no arquivo ele armazena na variável (conteúdo)
			printf("Estas são as informações do usuário: \n");
			printf("%s", conteudo); // Mostra as informações da variável "conteudo".
			printf("\n\n\n\n");
		}
		
		fclose(file);
		
		printf("Deseja fazer uma nova consulta?\n\n");
		printf("\t1 - Sim\n");
		printf("\t2 - Voltar ao menu principal\n\n");
		printf("Opção: ");
		scanf("%d", &consultar_novamente); // Manda a informação do usuário para a variável "nova_consulta".
		
		system("cls");
		
		if(consultar_novamente <=0 || consultar_novamente >=3) { // "Se a variável "nova_consulta" for menor ou igual a 3 ou for maior ou igual a 3..."
			printf("Esta não é uma opção válida.\n");
			system("pause");
		}
	} while(consultar_novamente == 1); // Fim da repetição.
}

int deletar() {
	char cpf[40];
	
	int deletar_novamente = 0;
	
	do {
		printf("Digite o CPF do usuário a ser deletado: "); // Recebe os dados do usuário a ser deletado.
		scanf("%s", cpf);
		
		system("cls");
			
		FILE *file;
		file = fopen(cpf, "r");	// Abre o arquivo.
		
		if(file != NULL) { // "Se file for diferente de nulo..."
			fclose(file); // Fecha o arquivo.
			remove(cpf); // Apaga o arquivo.
			
			printf("Usuário deletado com sucesso!\n\n\n"); // Mensagem de confirmação.
			printf("Deseja fazer uma nova remoção?\n\n");
			printf("\t1- Sim\n");
			printf("\t2- Não\n\n");
			printf("Opção:");
			scanf("%d", &deletar_novamente);
			system("cls");
		} else { // "Se não..."
			printf("Usuário não encontrado\n\n"); // Mensagem de erro.
			system("pause");
		}
	} while ( deletar_novamente == 1);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ INÍCIO DO PROGRAMA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main() {
	int opcao=0; // Definindo variáveis
	int laco=1;

	for(laco=1;laco=1;)	{
		system("cls"); // Limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
		
		printf("### Cartório da EBAC ###\n\n"); // Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); // Fim do menu
		
		scanf("%d", &opcao); // Recebe a informação digitada pelo usuário e armazena na variável int
		
		system("cls"); 
		
		switch(opcao) { // Início da seleção
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
			printf("Esta não é uma opção válida.\n");
			system("pause");
			break; // Fim da seleção
		}
	}
}

