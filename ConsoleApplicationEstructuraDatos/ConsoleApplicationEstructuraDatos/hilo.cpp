#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int saldo = 1000;

//Mutex para proteger la sección crítica
mutex mtx;

void deposita()
{
	mtx.lock();

	//Proteger el saldo
		saldo += 100;

		mtx.unlock();	

}

int main()
{
	thread t1(deposita);
	thread t2(deposita);
	t1.join();
	t2.join();
	cout << "Saldo final: " << saldo << endl;
	return 0;
}