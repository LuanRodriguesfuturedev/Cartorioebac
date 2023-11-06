#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca de responsável por cuidar das strings

int validarCPF(char cpf[]) 
{
    int soma = 0; // Inicia uma variável 'soma' com valor 0
    for (int i = 0; i < 9; i++) // Loop que percorre os 9 primeiros dígitos do CPF
    {
        soma += (cpf[i] - '0') * (10 - i); // Converte o caractere 'cpf[i]' para um valor numérico subtraindo o valor ASCII de '0'
        // e multiplica pelo peso correspondente (10 - i)
    }

    int dv1 = (soma % 11 < 2) ? 0 : 11 - (soma % 11); // Calcula o primeiro dígito verificador (dv1)

    soma = 0; // Zera a variável 'soma' para ser reutilizada
    for (int i = 0; i < 10; i++) // Loop que percorre os 10 dígitos do CPF
    {
        soma += (cpf[i] - '0') * (11 - i); // Mesmo cálculo que no primeiro loop, mas incluindo o último dígito do CPF
    }

    int dv2 = (soma % 11 < 2) ? 0 : 11 - (soma % 11); // Calcula o segundo dígito verificador (dv2)

    if ((dv1 == (cpf[9] - '0')) && (dv2 == (cpf[10] - '0'))) // Verifica se os dígitos calculados batem com os dígitos do CPF original
    {
        return 1; // CPF válido

    } else {
        return 0; // CPF inválido
    }
}

int registro()
{
    char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
    //Essas declarações de variáveis criam espaços na memória para armazenar informações relacionadas a nomes de 
    //arquivos, CPFs, nomes, sobrenomes e cargos.
    //Cada uma dessas variáveis terá a capacidade de armazenar até 40 caracteres.
    //Elas serão utilizadas posteriormente no código para armazenar e manipular informações.

    printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); // %s refere-se as string (armazenando a informação a variável "cpf" na string)

    if (!validarCPF(cpf)) // Verifica se o CPF é válido usando a função validarCPF
    {
        printf("CPF inválido. Tente novamente.\n"); // Se o CPF é inválido, imprime a mensagem no console
        system("pause"); // Pausa a execução do programa até que o usuário pressione uma tecla.
        return; // Retorna do contexto atual. Neste caso, se o CPF for inválido, a função que a contém será encerrada aqui.
    }

    strcpy(arquivo, cpf); // Neste caso, a string contida na variável cpf será copiada para a variável arquivo.

    FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // Abre o arquivo para escrita ("w").
	fprintf(file,cpf); // Escreve o conteúdo da variável 'cpf' no arquivo.
	fclose(file); //fecha o arquivo

    file = fopen(arquivo, "a"); // Abre o arquivo para adição de conteúdo ("a"). 
    //Isso mantém o conteúdo existente e permite escrever ao final do arquivo.
	fprintf(file,"  NOME: "); //salva o valor do arquivo, sendo "nome" o inicio da informação da próxima função 
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", nome); // Lê o nome digitado pelo usuário e armazena na variável 'nome'.

	file = fopen(arquivo, "a"); // Abre o arquivo para adição de conteúdo ("a").
	fprintf(file,nome); // Escreve o conteúdo da variável 'nome' no arquivo.
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo para adição de conteúdo ("a"). 
    //Isso mantém o conteúdo existente e permite escrever ao final do arquivo.
	fprintf(file,"  SOBRENOME: "); //salva o valor do arquivo, sendo "sobrenome" o inicio da informação da próxima função
	fclose(file);//fecha o arquivo

    printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", sobrenome); // Lê o sobrenome digitado pelo usuário e armazena na variável 'sobrenome'.
	
	file = fopen(arquivo, "a"); // Abre o arquivo para adição de conteúdo ("a").
	fprintf(file,sobrenome); // Escreve o conteúdo da variável 'sobrenome' no arquivo.
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo para adição de conteúdo ("a"). 
    //Isso mantém o conteúdo existente e permite escrever ao final do arquivo.
	fprintf(file,"  CARGO: "); //salva o valor do arquivo sendo "cargo" o inicio da informação da próxima função 
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cargo);  // Lê o cargo digitado pelo usuário e armazena na variável 'cargo'.
	
	file = fopen(arquivo, "a"); // Abre o arquivo para adição de conteúdo ("a").
	fprintf(file,cargo); // Escreve o conteúdo da variável 'cargo' no arquivo.
	fclose(file); //fecha o arquivo

    system("pause"); //responsável por pausar a informação até que o usuário finalize o processo
 
}


int consulta()
{
    char cpf[40]; //Declara uma variável chamada cpf do tipo char, que pode armazenar até 40 caracteres.
    char conteudo[200]; //Declara uma variável chamada conteudo do tipo char, que pode armazenar até 200 caracteres.

    printf("Digite o CPF a ser consultado: "); // Exibe a mensagem solicitando ao usuário que digite o CPF.
    scanf("%s", cpf); // Lê o CPF digitado pelo usuário e o armazena na variável 'cpf'.

    if (!validarCPF(cpf)) // Verifica se o CPF é válido usando a função validarCPF
    {
        printf("CPF inválido. Tente novamente.\n"); // Se o CPF é inválido, imprime a mensagem no console
        system("pause"); //responsável por pausar a informação até que o usuário finalize o processo
        return; // Retorna da função
    }

    FILE *file; // Declara uma variável do tipo 'FILE' para manipular o arquivo
    file = fopen(cpf, "r"); // Tenta abrir o arquivo com o nome do CPF em modo de leitura ("r")

    if (file == NULL) // Verifica se o arquivo foi aberto corretamente
    {   // Se o arquivo não foi encontrado, imprime uma mensagem de erro
        printf("Erro: O arquivo solicitado não foi encontrado ou não existe. Por favor, verifique o caminho e tente novamente.\n\n");
    }

    while (fgets(conteudo, 200, file) != NULL) // Lê o conteúdo do arquivo linha por linha até o final do arquivo
    {   // Imprime as informações do usuário (no caso, o conteúdo do arquivo)
        printf("\nEssas são as informações do usuário:\nCPF: "); // Imprime as informações do usuário (no caso, o conteúdo do arquivo)
        printf("%s", conteudo); // Exibe o conteúdo da variável 'conteudo', que contém informações sobre o usuário, na tela.
        printf("\n\n");
    }
    
    system("pause"); // Pausa a execução do programa até que o usuário pressione uma tecla

}

int deletar()
{
    char cpf[40]; // Declaração de uma variável 'cpf' como uma array de caracteres com espaço para 40 caracteres.

    printf("Digite o CPF a ser deletado: "); // Exibe a mensagem solicitando ao usuário que digite o CPF que deseja deletar.
    scanf("%s", cpf); // Lê o CPF digitado pelo usuário e o armazena na variável 'cpf'.

    FILE *file; // Declara uma variável do tipo 'FILE' para manipular o arquivo
    file = fopen(cpf, "r"); // Tenta abrir o arquivo com o nome do CPF em modo de leitura ("r")
	fclose(file); //fecha o arquivo

    remove(cpf); //responsável por remover
	
	if(file == NULL) //análise de usuário inexistente 
    // Esta linha verifica se o ponteiro 'file' é nulo, o que indica que houve um problema ao abrir 
    // o arquivo ou o arquivo não foi encontrado.
	{
		printf("Usuário não se encontra no sistema!.\n");
		system("pause");
	}

    remove(cpf); //responsável por remover
   
	if(file != NULL) //análise de usuário existente
    // Esta linha verifica se o ponteiro 'file' não é nulo, o que indica que o arquivo foi aberto com sucesso.
	{
	    printf("Usuário deletado com sucesso!.\n");
		system("pause");
		fclose(file); //fecha o arquivo
	}
    
}

int main()
{
    int opcao=0; // Declaração de uma variável inteira chamada 'opcao' e inicialização com o valor 0.
    int x=1; // Declaração de uma variável inteira chamada 'x' e inicialização com o valor 1.

    for(x=1;x=1;) // Início de um loop 'for'. 
    //A variável 'x' é inicializada com 1 e a condição de repetição é 'x=1', o que fará o loop se repetir indefinidamente.
    {

        system("cls"); // Limpa a tela do console.

        setlocale(LC_ALL, "Portuguese"); // Configura a linguagem local para Português.

        printf("   Cartório da EBAC   \n\n"); //INICIO MENU
        printf("\t1 - Registro de nomes:\n");
        printf("\t2 - Consultar nomes:\n");
        printf("\t3 - Deletar nomes:\n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Opção:"); // Solicita ao usuário para escolher uma opção do menu. //FIM MENU

        scanf("%d", &opcao); // Lê a opção escolhida pelo usuário e a armazena na variável 'opcao'.

        system("cls"); // Limpa a tela do console.

        switch (opcao) // Início de uma estrutura de seleção 'switch' baseada no valor de 'opcao'.
        {
            case 1: // Se a opção escolhida for 1, executa o código abaixo:
            registro(); // Chama a função 'registro'.
            break; // Sai da estrutura de seleção.

            case 2: // Se a opção escolhida for 2, executa o código abaixo:
            consulta(); // Chama a função 'consulta'.
            break; // Sai da estrutura de seleção.

            case 3: // Se a opção escolhida for 3, executa o código abaixo:
            deletar(); // Chama a função 'deletar'.
            break; // Sai da estrutura de seleção.

            case 4: // Se a opção escolhida for 4, executa o código abaixo:
            printf("Obrigado por utilizar o sistema!\n"); //imprimi a mensagem na tela do usuário
            return 0;//Essa linha termina a execução da função atual e terminará o programa.
            break;// Sai da estrutura de seleção.
        
            default: // Se a opção não for nenhum dos casos acima, executa o código abaixo:
            printf("Essa opção não existe!\n");
            system("pause");
            break; // Sai da estrutura de seleção.
        }

    }
}
