/*  Membros
Gabriel Borges Garcia - 202201691
Joao Vitor Alves dos Reis - 202201697
Jheissyane Kelly da Silva Souza - 202201694
Mateus Henrique Ghandi de Oliveira - 202201706
*/ // puta que pariu git sucumba


#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
                char nomePaciente[50];
	            char descricaoProblema[120];
	            char dataDeInclusao[12];
	            int cor;
	            char status[20];
	            char cadcpf[15];//batata
	            char cadtelefone[15];
			}PACIENTE;
			
typedef struct {PACIENTE indice[MAX];
	            int ult;
			}HOSPITAL;

void cadastrar_paciente(PACIENTE novoCadastro, HOSPITAL *clinica){
        printf("Insira o nome do paciente\n");
        scanf("%[^\n]", novoCadastro.nomePaciente);
        getchar();
        
        printf("Insira a descricao do problema\n");
        scanf("%[^\n]", novoCadastro.descricaoProblema);
        getchar();  
        
        printf("Insira a data\n");
        scanf("%[^\n]", novoCadastro.dataDeInclusao);
        getchar();
       
        printf("Insira seu cpf\n");
        scanf("%[^\n]", novoCadastro.cadcpf);
        getchar();
        
        printf("Insira seu numero de telefone\n");
        scanf("%[^\n]", novoCadastro.cadtelefone);
        getchar();
        
        do{
        printf("Digite o numero de prioridade do atendimento\n");
        printf("Urgência baixa - verde (1)\n");
        printf("Urgência media - amarelo (2)\n");
        printf("Urgência alta - vermelho (3)\n");
        scanf("%d", &novoCadastro.cor);
        }
        while(novoCadastro.cor>3 || novoCadastro.cor<1);
        getchar();
        
    clinica->indice[clinica->ult] = novoCadastro;
    clinica->ult++;
        
        //inserir_paciente(novoCadastro, clinica); // colocar os dados do paciente no hospital
}

void listar_pacientes(HOSPITAL clinica){
    int i;
    for(i=0;i<clinica.ult;i++){
        printf("Posicao do paciente na fila: %d\n", clinica.ult);
        printf("Nome do paciente: %s\n", clinica.indice[i].nomePaciente);
        printf("Descricao do problema: %s\n", clinica.indice[i].descricaoProblema);
        printf("Data de inclusao: %s\n", clinica.indice[i].dataDeInclusao);
        printf("Cadasto de cpf: %s\n", clinica.indice[i].cadcpf);
        printf("Cadastro de telefone: %s\n", clinica.indice[i].cadtelefone);
        if(clinica.indice[i].cor==1){
        printf("Urgencia de atendimento baixa - VERDE\n");
    }
    else if(clinica.indice[i].cor==2){
        printf("Urgencia de atendimento media - AMARELO\n");
    }
    else{
        printf("Urgencia de atendimento alta - VERMELHO\n");
    }
}}

int main(){
    PACIENTE novoCadastro;
    HOSPITAL clinica;
    int opcao;
    
    clinica.ult = 0;
    
    do{
	 printf("**************************\n");
     printf("*          menu          *\n");
     printf("*  1-Registrar paciente  *\n");
	 printf("*  2-listar pacientes    *\n");
     printf("*         3-Sair         *\n");
     printf("**************************\n");
     
     scanf("%d", &opcao);
     getchar();  
     
     switch(opcao){
        case 1:
        cadastrar_paciente(novoCadastro, &clinica);
        break;
        
        case 2:
        listar_pacientes(clinica);
        break;
        
	}
    } while(opcao!=3);
    
}









