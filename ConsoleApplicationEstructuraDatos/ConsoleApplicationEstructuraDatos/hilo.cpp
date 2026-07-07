#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore>

using namespace std;

//Crear los bufferes de datos
const int bufferDatos[10];
const int tamanoBuffer = 10;

int totalDatos = 15;


int saldo = 1000;

int datosXtraer = 0;
int datosInsertar = 0;

//Mutex para proteger la sección crítica
mutex mtx;

//espacios disponibles
counting_semaphore<tamanoBuffer> espaciosDisponibles(tamanoBuffer);

//datos dispobler
counting_semaphore<tamanoBuffer> espaciosDisponiblesElementos(0);

void deposita()
{
	mtx.lock();

	//Proteger el saldo
	cout << "saldo antes del mtx" << saldo << endl;
		saldo += 100;

		cout << "saldo antes del mtx" << saldo << endl;
		mtx.unlock();

}

void productor()
{

	/*un bloque que recorra y revise el buffer*/
	/*yo usaria un recorrido, sea while, for, etc.para revisar el buffer y ver si hay datos que extraer o insertar*/
	espaciosDisponibles.acquire();
	mtx.lock();

	//Proteger el saldo
	cout << "saldo antes del mtx" << saldo << endl;
	saldo += 100;

	cout << "saldo antes del mtx" << saldo << endl;
	mtx.unlock();

	espaciosDisponibles.release();//avisa de un dato nuevo

}


void consumidor	()
{

	/*un bloque que recorra y revise el buffer*/
	/*yo usaria un recorrido, sea while, for, etc.para revisar el buffer y ver si hay datos que extraer o insertar*/
	espaciosDisponibles.acquire();
	mtx.lock();

	//Proteger el saldo
	cout << "saldo antes del mtx" << saldo << endl;
	saldo += 100;

	cout << "saldo antes del mtx" << saldo << endl;
	mtx.unlock();

	espaciosDisponibles.release();//avisa de un dato nuevo

	this_thread::sleep_for(chrono::milliseconds(1000)); // Simula el tiempo de procesamiento

}




void controlBuffer() {
	//Revisa el buffer, yo usaria un recorrido, sea while, for, etc. para revisar el buffer y ver si hay datos que extraer o insertar
}

int main()
{

	thread t1(deposita);
	thread t2(deposita);

	thread productos(productor);
	thread consumidor(deposita);
	
	t1.join();
	t2.join();
	cout << "Saldo final: " << saldo << endl;
	return 0;
}