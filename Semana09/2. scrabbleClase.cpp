/*En el juego de Scrabble, cada ficha contiene una letra, que se usa para formar
palabras en filas y columnas, y una puntuación, que se usa para determinar el
valor de las palabras.
1. Escriba una definición para una clase llamada ficha que represente fichas
de Scrabble. Los atributos de la clase ficha deben incluir un caracter llamado
letra y un entero llamado valor.
2. Escriba un constructor que tome parámetros llamados letra y valor e
inicialice las variables de los atributos.
3. Escriba un método llamado imprimir que tome un objeto ficha como
parámetro y muestre los atributos en un formato fácil de leer.
4. Escriba una definición para una clase llamada Scrabble que represente un
jugador de scrabble. Los atributos de la clase deben incluir un nombre para
identificar al jugador y una colección de 7 fichas.
5. Escriba un método en Scrabble que genere las 7 fichas necesarias en forma
aleatoria.
6. Pruebe su clase Scrabble creando jugadores de scrabble (de 2 a 4) y los
muestre en pantalla*/

#include <iostream>
#include <random>
using namespace std;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<>rand_digits(97,122);

class ficha{
public:
	friend class Scrabble;
	ficha();
	ficha(char letra, int valor);
	~ficha();
private:
	void convertir_minus(char& L);
	bool validar_letra(char& L);
	char letra;
	int valor;
};

class Scrabble{
public:
	Scrabble();
	~Scrabble();
	void generar_fichas();
	void definir_nombre(string nombre);
	const void imprimir_fichas();
private:
	string nombre;
	ficha* L1;
};

ficha::ficha(){
	letra = 'a';
	valor = 0;
}

ficha::ficha(char letra, int valor){
	if (validar_letra(letra))
		this->letra = letra;
	else
		this->letra = 'a';
	this->valor = valor;
}

ficha::~ficha(){
}

void ficha::convertir_minus(char& L){
	L = tolower(L);
}

bool ficha::validar_letra(char& L){
	convertir_minus(L);
	for (int i = 97; i < 123; i++){
		if (i == L){
            return true;
        }	
	}
	return false;
}

Scrabble::Scrabble(){
	L1 = new ficha[3];
	nombre = "Aux";
}

Scrabble::~Scrabble(){
	delete[] L1;
}

void Scrabble::definir_nombre(string nombre){
	this->nombre = nombre;
}

void Scrabble::generar_fichas(){
	char aux;
	for (int i = 0; i < 7; i++){
		aux = rand_digits(gen);
		L1[i].letra = aux;
		L1[i].valor = 1+rand()%(10-1);
	}
}

const void Scrabble::imprimir_fichas(){
    cout<<endl;
	cout << "El nombre del jugador es: " << nombre << endl;
	for (int i = 0; i < 7; i++){
		cout << "Letra generada aleatoriamente: "<< L1[i].letra << endl <<"Valor de la letra: " << L1[i].valor << endl;
	}
		
}

int main(){
    const string Nombres[] = {"Diego","Juan","Luciana","Jaime","Javier","Lucho"};
    Scrabble* Jugadores = new Scrabble[6];
   
    for (auto i = 0; i < 6; i++){
        Jugadores[i].definir_nombre(Nombres[i]);
        Jugadores[i].generar_fichas();
        Jugadores[i].imprimir_fichas();
    }

    delete [] Jugadores;
    return 0;
}