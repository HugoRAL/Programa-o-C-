#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
using namespace std;


void contaVogais();
void contaConsoantes();
void contaPalavras();


int main(int argc, char *argv[]){
	setlocale(LC_ALL, "Portuguese");
		FILE *fp;char texto[]="A cidade de Lisboa";
//=======================================================================

	fp = fopen("fich1.txt", "a");

		if (fp != NULL)
	{
		for (int i=0; texto[i]; i++)
		{
			fputc(texto[i], fp);
		}
		printf("\n\nTexto escrito no fich dados.txt\n\n");
	
		fclose(fp);
	}
	else
	{
		printf("\n\nTexto NAO foi escrito no file\n\n");
	}fclose(fp);
//======================================================================


	fp = fopen("fich1.txt", "r");
	
	if (fp != NULL){
		
		
		cout<<"Neste ficheiro existem:"<<endl<<endl;
		contaVogais();
		contaConsoantes();
		contaPalavras();

		fclose(fp);
	}else{
		cout << "Erro na abretura do ficheiro";
	}

	system("pause");
	fclose(fp);
	return 0;
}

void contaVogais(){
	
	FILE *fp;
	fp = fopen("fich1.txt", "r");
	int Vogais = 0;
	int a=0;
	int e=0;
	int i=0;
	int o=0;
	int u=0;
	char ch;
	
	while( (ch=fgetc(fp)) != EOF){
		
		if ((ch=='A') || (ch=='a')){Vogais++;a++;} 
		else if ((ch=='E')||(ch=='e')){Vogais++;e++;}
		else if ((ch=='I')||(ch=='i')){Vogais++;i++;}
		else if ((ch=='O')||(ch=='o')){Vogais++;o++;}
		else if ((ch=='U')||(ch=='u')){Vogais++;u++;} 
		
		
	}cout<<"Existem "<<Vogais<<" vogais"<<endl<<"Existem "<< a << " A"<<endl<<"Existem "<< e << " E"<<endl<<"Existem "<< i << " I"<<endl<<"Existem "<< o << " O"<<endl<<"Existem "<< u << " U"<<endl<<endl;
}
void contaConsoantes(){
	
	FILE *fp;
	fp = fopen("fich1.txt", "r");
	int Consoantes = 0;
	char ch;
	
	while ((ch=fgetc(fp)) != EOF){
		
		if ((ch=='B') || (ch=='C') || (ch=='D') || (ch=='F') || (ch=='G') || (ch=='H') || (ch=='J') || (ch=='K') || (ch=='L') || (ch=='M') || (ch=='N') || (ch=='P') || (ch=='Q') || (ch=='R') || (ch=='S') || (ch=='T') || (ch=='V') || (ch=='W') || (ch=='X') || (ch=='Y') || (ch=='Z') ||
			(ch=='b') || (ch=='c') || (ch=='d') || (ch=='f') || (ch=='g') || (ch=='h') || (ch=='j') || (ch=='k') || (ch=='l') || (ch=='m') || (ch=='n') || (ch=='p') || (ch=='q') || (ch=='r') || (ch=='s') || (ch=='t') || (ch=='v') || (ch=='w') || (ch=='x') || (ch=='y') || (ch=='z'))
		{	
			Consoantes++;
		}
	}cout<<"Existem "<<Consoantes<<" Consoantes"<<endl;
}
void contaPalavras(){
	
	FILE *fp;
	fp = fopen("fich1.txt", "r");
	char ch;
	int Palavra = 1;
	
	while((ch=fgetc(fp)) != EOF){
		if ((ch == ' ')||(ch=='\n')){
			Palavra++;
		}
	}
	cout<<"Existem"<< Palavra<<" Palavras"<<endl<<endl;
}


