
#include <stdio.h>
#include <string.h>
#define MAX 100

/*
AGENDA DO ESTAGIÁRIO

1 - Cadastrar serviçal
2 - novas tarefas
3 - data e hora
4 - prioridade
5 - remover
6 - pontos totais 
*/


typedef struct {//int codigo;
                char nomePaciente[50];
	            char descricaoProblema[120];
	            char dataDeInclusao[12];
	      //      int pesoPrioridade;
	            char status[20];
	            char cadcpf[11];
	            char cadtelefone[11];
			}PACIENTE;
			
typedef struct {PACIENTE indice[MAX];
	            int ult;
			}HOSPITAL;
			
void inserir_paciente(PACIENTE novoCadastro, HOSPITAL *clinica){
    clinica->indice[clinica->ult] = novoCadastro;
    clinica->ult++;
}

void listar_pacientes(HOSPITAL clinica){
    int i;
   // i = clinica.ult;
    for(i=0;i<clinica.ult;i++){
        printf("Posicao do paciente na fila: %d\n", clinica.ult);
        printf("Nome do paciente: %s\n", clinica.indice[i].nomePaciente);
        printf("Descricao do problema: %s\n", clinica.indice[i].descricaoProblema);
        printf("Data de inclusao: %s\n", clinica.indice[i].dataDeInclusao);
        printf("cadasto de cpf %s\n", clinica.indice[i].cadcpf);
        printf("cadastro de telefone%s\n", clinica.indice[i].cadtelefone);
    }
    
}

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
        
        inserir_paciente(novoCadastro, &clinica);
       // printf("%d", clinica.ult);
       // registrar_medico(cadastrado, &hospital);
       
     //  printf("%s", clinica.indice[clinica.ult].dataDeInclusao);
        break;
        
        case 2:
        listar_pacientes(clinica);
      //  alterar_dados(&hospital);
        break;
        
        
        
        
	}
    } while(opcao!=3);
    
}

/*
			
 TAD - GARAGEM
  1. iniciar garagem
  2. Cadastrar Cliente
  3. Estacionar veiculo
  4. Pagar estacionamento
  5. Calcular arrecadação diarias
  6. Calcular arrecadação mensais
  7. Listar clientes mensais
  8. Listar clientes diariaristas
  9. Listar todos veiculos por dia
  10. Buscar local chassis
  
  
  void Inicia_Garagem(GARAGEM *g){
	  g->prim = 0;
	  g->ult = g->prim;
	  g->qtd = 0;
	  printf("Entre com o nome da garagem\n");
	  fgets(g->nome_estacionamento, 50, stdin);
	  getchar();
	  printf("Entre com o CNPJ da Garagem\n");
	  fgets(g->cnpj, 20, stdin);
	  getchar();
	  printf("Entre com o Telefone da Garagem\n");
	  fgets(g->tel,15,stdin);
	  getchar();
	  
  }
  void Menu(){
	  printf("MENU DAS FUNCIONALIDADES DA GARAGEM\n");
	  printf("1. Cadastrar Cliente\n");
	  printf("2. Cadastrar Cliente\n");
	  printf("3. Pagar Estacionamento\n");
	  printf("4. Calcular Arrecadacao Diaria\n");
	  printf("5. Calcular Arrecadacao Mensal\n");
	  printf("6. Listar Clientes Mensais\n");
	  printf("7. Listar Clientes Diaristas\n");
	  printf("8. Listar todos veículos em um dado dia\n");
	  printf("9. Localizar veiculo por chassi\n");
	  printf("10. Fim\n");
	  printf("Entre com a opcao desejada: \n");
	  	  
  }
  
  void Ler_cliente(CLIENTE *x) {
	  printf("Entre com o nome do Cliente\n");
	  fgets(x->nome_cliente,40,stdin);
	  printf("Entre com o Chassi do carro\n");
	  fgets(x->chassi, 18, stdin);
	  printf("Entre com a placa do carroa\n");
	  fgets(x->placa,8,stdin);
	  printf("Entre com o telefone\n");
	  fgets(x->tel_cliente,15,stdin);
	  getchar();
	  printf("Entre com o status do cliente - m - d - h\n");
	  scanf("%c",&x->status);
	  getchar();
	  
	  
  }
  
  void Cadastrar_cliente(GARAGEM *g, CLIENTE x){
	  if(g->qtd==Max)
	     printf("A GARAGEM ESTA CHEIA - ALTERAR TAMANHO\n");
	   else{ g->elem[g->ult]=x;
		     g->ult++;
		     g->qtd++;
		    }  
  }
  
  int buscar_veiculo(GARAGEM g, char x[]) {
     int i;
     i = g.prim;
     while((i<g.ult)&&(strcmp(x,g.elem[i].placa)!=0))
        i++;
     if(i==g.ult)
        return 0;
      else return i;
     }
     
  int main(){
	  CLIENTE C;
      GARAGEM G;
      char placa[8];
      int op, i;
      Inicia_Garagem(&G);
	  do{ Menu();
		  scanf("%d",&op);
		  switch (op){
			  case 1:  C.cod_cli=G.qtd + 1;
			           Ler_cliente(&C);
			           Cadastrar_cliente(&G, C);
			      break;
			  case 2: printf("Entre com a placa do veiculo\n");
			          fgets(placa, 8, stdin);
			          getchar();
			          i = buscar_veiculo(G, placa);
			          if(i==0)
			             printf("O Veiculo nao esta cadastrado\n");
			           else {printf("Entre com data_chegada\n");
						     fgets(G.elem[i-1].data_chegada, 15,stdin);
						     getchar();
						     printf("Entre com horario_chegada\n");
						     fgets(G.elem[i-1].horario_chegada, 9,stdin);
						     printf("Entre com o numero da garagem\n");
						     scanf("%d",&(G.elem[i-1].nr_garagem));
						 }
			      break;
			  case 3:
			      break;
			  case 4:
			      break;
			  case 5:
			      break;
			  case 6:
			      break;
			  case 7:
			      break;
			  case 8:
			      break;
			  case 9:
			      break;
			  case 10: printf("Obrigado por usar nosso sistema\n");
			      break;
			  default: printf("Entre com uma opcao valida - Obrigado\n");
			      break;
			  }
		}while(op!=10);
 
	  
	  return 0;
  }

*/







