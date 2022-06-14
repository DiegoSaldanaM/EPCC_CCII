/*Usted administra una fábrica de robots.
Cuando un robot sale de la fábrica, no tiene nombre.
La primera vez que enciende un robot, se genera un nombre aleatorio en
formato de dos letras mayúsculas seguidas de tres dígitos, como RZ123 o
CD731.
Cuando necesitamos resetear un robot a su configuración de fábrica, su
nombre se borra. De modo que la próxima vez que se le pregunte su nombre,
ese robot responderá con un nuevo nombre aleatorio.
Los nombres de los robot deben ser aleatorios: no deben seguir una
secuencia predecible. El uso de nombres aleatorios implica un riesgo de
colisiones. Su solución debe garantizar que cada robot existente tenga un
nombre único.
Use la cabecera <random>
Pruebe su solución generando 100 robots, luego en un ciclo resetee sus
nombres y asigne nuevos nombre, compruebe que sus nombres siguen
siendo únicos.*/

#include <bits/stdc++.h>
using namespace std;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> rand_ascii('A','Z');
uniform_int_distribution<> rand_int(0,9);

class Robot{
private:
	string nombre;
public:
	Robot(){nombre=nombre_random();}

	void resetear(){
        nombre = nombre_random();
    }

	string obtener_nombre(){
        return nombre;
    }

	string nombre_random(){
		nombre="";
		nombre+= char(rand_ascii(gen));
		nombre+= char(rand_ascii(gen));
		nombre+=to_string(rand_int(gen))+to_string(rand_int(gen))+to_string(rand_int(gen));
		return nombre;
	}

	void imprimir(){
		cout<<"El nombre del robot es: "<<nombre<<endl;
	}
};


void verif_nombres(vector<Robot> R)
{
	for (int i = 0; i < R.size(); i++){
		for (int j = i+1; j < R.size(); j++){
			if (R.at(i).obtener_nombre() == R.at(j).obtener_nombre()){
				cout<<"Nombre repetido encontrado, reseteando."; 
                R.at(j).resetear();
			}
		}
	}
	cout<<"No se obtuvieron nombres repetidos."<<endl;
}

int main()
{
	int n;
	cout<<"Ingrese la cantidad de robots: ";
    cin>>n;

	vector<Robot> rellenar_vector(n);
	verif_nombres(rellenar_vector);
	
	cout<<"Imprimiendo robots generados: "<<endl; 
	for(Robot i:rellenar_vector){
        i.imprimir();
    }
    
	for(Robot & i:rellenar_vector){
        i.resetear();
    } 
	verif_nombres(rellenar_vector);
	cout<<"Reseteando robots: "<<endl;
	for(Robot i:rellenar_vector){
        i.imprimir();
    }

	return 0;
}