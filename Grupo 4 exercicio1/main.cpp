#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
using namespace std;

class imc
{
private: 
    float altura; // atributo privado

public:

float IMC;
float massa;

   void setAltura(float a)//setter
    {
        altura = a;
    }


    int getAltura()//getter
    {
        return altura;
    }

    imc(float x, float y, float z) {//construtor 
      IMC = x;
      massa = y;
      setAltura(z);
    }

    };

int main(){
	setlocale(LC_ALL, "Portuguese");//ativa��o dos caracteres especiais portugueses 

	float y, x, z;//massa, IMC, altura    
	
	cout<<"Digite o valor da sua massa: "<<endl<<"Exemplo: 60"<<endl;
   	fflush(stdin);//limpar cache do teclado
   	cin>>y;
   
   	cout<<endl<<endl<<"Digite o valor da altura em metros: "<<endl<<"Exemplo: 1.80"<<endl;
   	fflush(stdin);
   	cin>>z;
   	
    x=y/(z*z);//calcular o IMC
    imc pessoa(x, y, z);//cria��o do 1 obj
    cout<<endl<<"A sua altura � "<<z<<" m, a sua massa � "<<pessoa.massa<<" kg, o seu IMC � de "<<pessoa.IMC<<" kg/m2"<<endl<<endl;
   
    y=25*(z*z);//calcular o peso maximo que se pode ter no estado saudavel
    imc ImcCerto(25,y,z);
    y=18.5*(z*z);//calcular o peso minimo no estado saudavel
    imc ImcCerto2(18.5,y,z);
    cout<<"A sua massa ideal esta entre os "<<ImcCerto.massa<<" kg e os "<<ImcCerto2.massa<<" kg"; 

	return 0;
}
