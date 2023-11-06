#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca de respons�vel por cuidar das strings

int validarCPF(char cpf[]) 
{
    int soma = 0; // Inicia uma vari�vel 'soma' com valor 0
    for (int i = 0; i < 9; i++) // Loop que percorre os 9 primeiros d�gitos do CPF
    {
        soma += (cpf[i] - '0') * (10 - i); // Converte o caractere 'cpf[i]' para um valor num�rico subtraindo o valor ASCII de '0'
        // e multiplica pelo peso correspondente (10 - i)
    }

    int dv1 = (soma % 11 < 2) ? 0 : 11 - (soma % 11); // Calcula o primeiro d�gito verificador (dv1)

    soma = 0; // Zera a vari�vel 'soma' para ser reutilizada
    for (int i = 0; i < 10; i++) // Loop que percorre os 10 d�gitos do CPF
    {
        soma += (cpf[i] - '0') * (11 - i); // Mesmo c�lculo que no primeiro loop, mas incluindo o �ltimo d�gito do CPF
    }

    int dv2 = (soma % 11 < 2) ? 0 : 11 - (soma % 11); // Calcula o segundo d�gito verificador (dv2)

    if ((dv1 == (cpf[9] - '0')) && (dv2 == (cpf[10] - '0'))) // Verifica se os d�gitos calculados batem com os d�gitos do CPF original
    {
        return 1; // CPF v�lido

    } else {
        return 0; // CPF inv�lido
    }
}

int registro()
{
    char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
    //Essas declara��es de vari�veis criam espa�os na mem�ria para armazenar informa��es relacionadas a nomes de 
    //arquivos, CPFs, nomes, sobrenomes e cargos.
    //Cada uma dessas vari�veis ter� a capacidade de armazenar at� 40 caracteres.
    //Elas ser�o utilizadas posteriormente no c�digo para armazenar e manipular informa��es.

    printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se as string (armazenando a informa��o a vari�vel "cpf" na string)

    if (!validarCPF(cpf)) // Verifica se o CPF � v�lido usando a fun��o validarCPF
    {
        printf("CPF inv�lido. Tente novamente.\n"); // Se o CPF � inv�lido, imprime a mensagem no console
        system("pause"); // Pausa a execu��o do programa at� que o usu�rio pressione uma tecla.
        return; // Retorna do contexto atual. Neste caso, se o CPF for inv�lido, a fun��o que a cont�m ser� encerrada aqui.
    }

    strcpy(arquivo, cpf); // Neste caso, a string contida na vari�vel cpf ser� copiada para a vari�vel arquivo.

    FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // Abre o arquivo para escrita ("w").
	fprintf(file,cpf); // Escreve o conte�do da vari�vel 'cpf' no arquivo.
	fclose(file); //fecha o arquivo

    file = fopen(arquivo, "a"); // Abre o arquivo para adi��o de conte�do ("a"). 
    //Isso mant�m o conte�do existente e permite escrever ao final do arquivo.
	fprintf(file,"  NOME: "); //salva o valor do arquivo, sendo "nome" o inicio da informa��o da pr�xima fun��o 
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", nome); // L� o nome digitado pelo usu�rio e armazena na vari�vel 'nome'.

	file = fopen(arquivo, "a"); // Abre o arquivo para adi��o de conte�do ("a").
	fprintf(file,nome); // Escreve o conte�do da vari�vel 'nome' no arquivo.
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo para adi��o de conte�do ("a"). 
    //Isso mant�m o conte�do existente e permite escrever ao final do arquivo.
	fprintf(file,"  SOBRENOME: "); //salva o valor do arquivo, sendo "sobrenome" o inicio da informa��o da pr�xima fun��o
	fclose(file);//fecha o arquivo

    printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", sobrenome); // L� o sobrenome digitado pelo usu�rio e armazena na vari�vel 'sobrenome'.
	
	file = fopen(arquivo, "a"); // Abre o arquivo para adi��o de conte�do ("a").
	fprintf(file,sobrenome); // Escreve o conte�do da vari�vel 'sobrenome' no arquivo.
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo para adi��o de conte�do ("a"). 
    //Isso mant�m o conte�do existente e permite escrever ao final do arquivo.
	fprintf(file,"  CARGO: "); //salva o valor do arquivo sendo "cargo" o inicio da informa��o da pr�xima fun��o 
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cargo);  // L� o cargo digitado pelo usu�rio e armazena na vari�vel 'cargo'.
	
	file = fopen(arquivo, "a"); // Abre o arquivo para adi��o de conte�do ("a").
	fprintf(file,cargo); // Escreve o conte�do da vari�vel 'cargo' no arquivo.
	fclose(file); //fecha o arquivo

    system("pause"); //respons�vel por pausar a informa��o at� que o usu�rio finalize o processo
 
}


int consulta()
{
    char cpf[40]; //Declara uma vari�vel chamada cpf do tipo char, que pode armazenar at� 40 caracteres.
    char conteudo[200]; //Declara uma vari�vel chamada conteudo do tipo char, que pode armazenar at� 200 caracteres.

    printf("Digite o CPF a ser consultado: "); // Exibe a mensagem solicitando ao usu�rio que digite o CPF.
    scanf("%s", cpf); // L� o CPF digitado pelo usu�rio e o armazena na vari�vel 'cpf'.

    if (!validarCPF(cpf)) // Verifica se o CPF � v�lido usando a fun��o validarCPF
    {
        printf("CPF inv�lido. Tente novamente.\n"); // Se o CPF � inv�lido, imprime a mensagem no console
        system("pause"); //respons�vel por pausar a informa��o at� que o usu�rio finalize o processo
        return; // Retorna da fun��o
    }

    FILE *file; // Declara uma vari�vel do tipo 'FILE' para manipular o arquivo
    file = fopen(cpf, "r"); // Tenta abrir o arquivo com o nome do CPF em modo de leitura ("r")

    if (file == NULL) // Verifica se o arquivo foi aberto corretamente
    {   // Se o arquivo n�o foi encontrado, imprime uma mensagem de erro
        printf("Erro: O arquivo solicitado n�o foi encontrado ou n�o existe. Por favor, verifique o caminho e tente novamente.\n\n");
    }

    while (fgets(conteudo, 200, file) != NULL) // L� o conte�do do arquivo linha por linha at� o final do arquivo
    {   // Imprime as informa��es do usu�rio (no caso, o conte�do do arquivo)
        printf("\nEssas s�o as informa��es do usu�rio:\nCPF: "); // Imprime as informa��es do usu�rio (no caso, o conte�do do arquivo)
        printf("%s", conteudo); // Exibe o conte�do da vari�vel 'conteudo', que cont�m informa��es sobre o usu�rio, na tela.
        printf("\n\n");
    }
    
    system("pause"); // Pausa a execu��o do programa at� que o usu�rio pressione uma tecla

}

int deletar()
{
    char cpf[40]; // Declara��o de uma vari�vel 'cpf' como uma array de caracteres com espa�o para 40 caracteres.

    printf("Digite o CPF a ser deletado: "); // Exibe a mensagem solicitando ao usu�rio que digite o CPF que deseja deletar.
    scanf("%s", cpf); // L� o CPF digitado pelo usu�rio e o armazena na vari�vel 'cpf'.

    FILE *file; // Declara uma vari�vel do tipo 'FILE' para manipular o arquivo
    file = fopen(cpf, "r"); // Tenta abrir o arquivo com o nome do CPF em modo de leitura ("r")
	fclose(file); //fecha o arquivo

    remove(cpf); //respons�vel por remover
	
	if(file == NULL) //an�lise de usu�rio inexistente 
    // Esta linha verifica se o ponteiro 'file' � nulo, o que indica que houve um problema ao abrir 
    // o arquivo ou o arquivo n�o foi encontrado.
	{
		printf("Usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}

    remove(cpf); //respons�vel por remover
   
	if(file != NULL) //an�lise de usu�rio existente
    // Esta linha verifica se o ponteiro 'file' n�o � nulo, o que indica que o arquivo foi aberto com sucesso.
	{
	    printf("Usu�rio deletado com sucesso!.\n");
		system("pause");
		fclose(file); //fecha o arquivo
	}
    
}

int main()
{
    int opcao=0; // Declara��o de uma vari�vel inteira chamada 'opcao' e inicializa��o com o valor 0.
    int x=1; // Declara��o de uma vari�vel inteira chamada 'x' e inicializa��o com o valor 1.

    for(x=1;x=1;) // In�cio de um loop 'for'. 
    //A vari�vel 'x' � inicializada com 1 e a condi��o de repeti��o � 'x=1', o que far� o loop se repetir indefinidamente.
    {

        system("cls"); // Limpa a tela do console.

        setlocale(LC_ALL, "Portuguese"); // Configura a linguagem local para Portugu�s.

        printf("   Cart�rio da EBAC   \n\n"); //INICIO MENU
        printf("\t1 - Registro de nomes:\n");
        printf("\t2 - Consultar nomes:\n");
        printf("\t3 - Deletar nomes:\n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Op��o:"); // Solicita ao usu�rio para escolher uma op��o do menu. //FIM MENU

        scanf("%d", &opcao); // L� a op��o escolhida pelo usu�rio e a armazena na vari�vel 'opcao'.

        system("cls"); // Limpa a tela do console.

        switch (opcao) // In�cio de uma estrutura de sele��o 'switch' baseada no valor de 'opcao'.
        {
            case 1: // Se a op��o escolhida for 1, executa o c�digo abaixo:
            registro(); // Chama a fun��o 'registro'.
            break; // Sai da estrutura de sele��o.

            case 2: // Se a op��o escolhida for 2, executa o c�digo abaixo:
            consulta(); // Chama a fun��o 'consulta'.
            break; // Sai da estrutura de sele��o.

            case 3: // Se a op��o escolhida for 3, executa o c�digo abaixo:
            deletar(); // Chama a fun��o 'deletar'.
            break; // Sai da estrutura de sele��o.

            case 4: // Se a op��o escolhida for 4, executa o c�digo abaixo:
            printf("Obrigado por utilizar o sistema!\n"); //imprimi a mensagem na tela do usu�rio
            return 0;//Essa linha termina a execu��o da fun��o atual e terminar� o programa.
            break;// Sai da estrutura de sele��o.
        
            default: // Se a op��o n�o for nenhum dos casos acima, executa o c�digo abaixo:
            printf("Essa op��o n�o existe!\n");
            system("pause");
            break; // Sai da estrutura de sele��o.
        }

    }
}
