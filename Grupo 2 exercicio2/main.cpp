#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
 
using namespace std;
  


int main(int argc, char *argv[]) 
{
	setlocale(LC_ALL, "Portuguese");
	
	FILE *fp1; 
	FILE *fp2;
   	string a="Ana\n";
   	string b="ana\n";
	char str[20]; 
	remove("fich1.txt");remove("fich2.txt");
	
	
	fp1 = fopen("fich1.txt" , "a");
	char texto[]="Rui\nNuno\nAna\nLeo\nAna\nTito\nAna\nZelia\nana\n";
	if (fp1 != NULL){
		for (int i=0; texto[i]; i++){
			fputc(texto[i], fp1);}
			printf("Texto escrito no fich1 dados.txt\n\n");
			fclose(fp1);
			
	}else{printf("\n\nTexto NAO foi escrito no file\n\n");}fclose(fp1);
	
	
   	fp1 = fopen("fich1.txt" , "r");
   	fp2 = fopen("fich2.txt" , "a");
   	if((fp1 == NULL)||(fp2 == NULL))
    {
      perror("Erro na abertura do ficheiro de leitura");
      return(-1);
    }
   	

    while( fgets (str, 20, fp1 ) != NULL )  {
    if((str!=a)&&(str!=b)) fputs(str, fp2);
	
    }
    
	cout<<"\t\t\t\t===================================================="<<endl<<
	      "\t\t\t\t=         Ficheiro escrito com sucesso             ="<<endl<<
		  "\t\t\t\t====================================================\n\n\n\n";
	fclose(fp1);fclose(fp2);
	system("PAUSE");
		
	return 0;
}

