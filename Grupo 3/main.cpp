#include <stdio.h>
#include <conio.h> 
#include <stdlib.h>
#include <locale.h>
#include <iostream>
using namespace std;



//===================== STRUCT==============================
struct Aluno
{
    char Nome[100], Turma;
	int Numero, Ano;
};
struct Aluno Aluno;
//===========================================================



 int main( )
 {
	setlocale(LC_ALL, "Portuguese");
 
 
 
// =========================== VAR======================================= 
	char ch;
	int opcao, n, sair=0;
	bool t=false;
	
//=======================================================================

	FILE *fp;
	FILE *fp2;   
	fp = fopen("dados.dat", "a");
	if ((fp == NULL)){
    	cout<<"ERRO!\nNão foi criado\n";
    	cout<<"\n\nDigite uma tecla para terminar Programa\n";
    	fclose(fp);fflush(stdin);exit(0);}
	fclose(fp);
// =========================== MENU=======================================
  	do{
  		system("cls");
  		cout<<"\n_____________________________________________________________________________________________\n";
		cout<<"\n\nEscolha uma opção\n";
		cout<<"\t\t1 - Inserir Novo Aluno\n";
    	cout<<"\t\t2 - Ver todos os Alunos\n";
    	cout<<"\t\t3 - Pesquisar um Aluno\n";
    	cout<<"\t\t4 - Atualizar Aluno\n";
    	cout<<"\t\t5 - Eliminar Aluno\n";
    	cout<<"\t\t6 - Apagar todos os Alunos\n";
    	cout<<"\t\t0 - SAIR\n\n";
    	cout<<"\nESCOLHA UMA OPÇÃO: ";
    	scanf("%d", &opcao);

    	switch(opcao){
//============================================================================== INSERIR ===================================================================    		
    		case 1:                                                               
    			system("cls"); 
				FILE *fp;   
				fp = fopen("dados.dat", "a");
  
				do{
   					system("cls"); 
     
   					cout<<"\n\nNome: ";
   					fflush(stdin);
					gets(Aluno.Nome); 
   
   					cout<<"\n\nNumero: ";
   					fflush(stdin);
					cin>>Aluno.Numero;

					cout<<"\n\nTurma: ";
					fflush(stdin);
					cin>> Aluno.Turma;   
   
					cout<<"\n\nAno: ";
					fflush(stdin);
					cin>> Aluno.Ano;
   
					fwrite(&Aluno, sizeof(Aluno), 1, fp);
    
					cout<<"\n\nClique em ESC para sair\n\n";  
					cout<<"\t ou em outra tecla para novo registo\n\n";
       				fflush(stdin);
					
				}while (getch() != 27);    

				fclose(fp);break;
//============================================================================== CONSULTAR ===================================================================   					
    		case 2:
    			system("cls"); 
				fp = fopen("dados.dat", "r");t=false; 
				 
    			while (fread(&Aluno, sizeof(Aluno), 1, fp)){
          		
          			cout<<"_________________________________________________________________________________________"<<endl<<endl;
					cout<<"Nome: "<< Aluno.Nome;
        			cout<<"\nNumero: "<< Aluno.Numero;
        			cout<<"\nTurma: "<< Aluno.Turma;
          			cout<<"\nAno: "<< Aluno.Ano<<endl;t=true;}
					   
				cout<<"_________________________________________________________________________________________"<<endl<<endl;
				fclose(fp);
				if(t==false)cout<<"\nNÂO EXISTE NENHUM ALUNO\n\n\n";
				system("pause");
    			break;
//============================================================================== PESQUISAR ===================================================================    			
    		case 3:
    			system("cls"); 
    			fp = fopen("dados.dat", "r");  

				cout<<"Qual o numero de aluno?"<<endl;
				fflush(stdin);
    			cin>>n;
    
    			while (fread(&Aluno, sizeof(Aluno), 1, fp)){
    				if(Aluno.Numero==n){
    					system("cls");
						cout<<"_________________________________________________________________________________________"<<endl<<endl;
          				cout<<"Nome: "<< Aluno.Nome;
          				cout<<"\nNumero: "<< Aluno.Numero;
          				cout<<"\nTurma: "<< Aluno.Turma;
    					cout<<"\nAno: "<< Aluno.Ano<<endl; 
						cout<<"_________________________________________________________________________________________"<<endl<<endl<<endl<<endl;
						cout<<"\t\t\t\t\tINTRUDUZA QUALQUER VALOR PARA VOLTAR AO MENU\n";}} 
						system("pause");
					fclose(fp);  
 		    		break;
//============================================================================== ATUALIZAR ===================================================================    			
    		case 4:
    			system("cls");      
				fp = fopen("dados.dat", "r"); 
				fp2 = fopen("dados2.dat", "a");     
	
    			cout<<"Qual o numero de aluno?"<<endl;
    			fflush(stdin);
    			cin>>n;t=false;
    			system("cls");
    			
    			while (fread(&Aluno, sizeof(Aluno), 1, fp)){   	
        			if(n!=Aluno.Numero){
        				fwrite(&Aluno, sizeof(Aluno), 1, fp2);
					}else{
						cout<<"insira o novo nome:  ";
        				cin>>Aluno.Nome;
        				cout<<"insira o novo numero:  ";
        				cin>>Aluno.Numero;
        				cout<<"insira o nova turma:  ";
        				cin>>Aluno.Turma;
        				cout<<"insira o novo ano letivo:  ";
        				cin>>Aluno.Ano;
        				fwrite(&Aluno, sizeof(Aluno), 1, fp2);
						t=true;}} 
				
				if(t==false)cout<<"Erro ao atualizar os dados";
				
				cout<<"\t\t\t\t\tINTRUDUZA QUALQUER VALOR PARA VOLTAR AO MENU\n\n";
				fclose(fp); fclose(fp2);
				remove("dados.dat");rename("dados2.dat", "dados.dat");
				system("pause");
    			break;
//============================================================================== ELEMINAR ===================================================================
    		case 5:
    			system("cls");     
				fp = fopen("dados.dat", "r"); 
				fp2 = fopen("dados2.dat", "a");     
	
    			cout<<"Qual o numero de aluno?"<<endl;
    			fflush(stdin);
    			cin>>n;t=false;
    			system("cls");
    			
    			while (fread(&Aluno, sizeof(Aluno), 1, fp)){   	
        			if(n!=Aluno.Numero){
        				fwrite(&Aluno, sizeof(Aluno), 1, fp2);
					}else{
						cout<<"Dados do aluno eliminado com sucesso"<<endl;
						t=true;}} 
				
				if(t==false)cout<<"Erro ao eliminar os dados";
				cout<<"\t\t\t\t\tINTRUDUZA QUALQUER VALOR PARA VOLTAR AO MENU\n\n";
				fclose(fp); fclose(fp2);
				remove("dados.dat");rename("dados2.dat", "dados.dat");
				system("pause");
    			break;
//============================================================================== ELEMINAR ARQUIVO ======================================================    			
			case 6:
                fp2 = fopen("dados2.dat", "a");
                remove("dados.dat");rename("dados2.dat", "dados.dat");
                system("cls");
				cout<<"Dados eliminado com sucesso.\n"<<endl<<endl;
                system("pause");
				fclose(fp2);
                break;
//============================================================================== SAIR ===================================================================    
    		case 0 :
    			exit(0);
    			break;
//============================================================================== Default ===================================================================
    		default:
    			cout<<"Valor invalido";
    			break;
    	}
   } while (true);return 0;} 
