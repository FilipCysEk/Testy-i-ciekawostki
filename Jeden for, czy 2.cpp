#include <iostream>
#include <ctime>

using namespace std;

void allocating(double **mac, int size){
	try{
		for(int i = 0; i < size; i++)
			mac[i] = new double[size];
	}
	catch(bad_alloc){
		cout << "Brak pamieci!!" << endl;
		exit(1);
	}
}

void deleting(double **mac, int size){
	for(int i = 0; i < size; i++)
		delete(mac[i]);
		
	delete(mac);
}

void zerowanie1(double **mac, int size){
	for(int i = 0; i < size *size; i++)
		mac[i/size][i%size] = 0;
}

void zerowanie2(double **mac, int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++)
			mac[i][j] = 0;
	}
}

int main(){
	//30000 - 6GB
	int n = 10000;
	double **a = new double *[n];
	allocating(a, n);
	
	double **b = new double *[n];
	allocating(b, n);
	cout<< "Zaalokowane" << endl;
	
	clock_t start2 = clock();
	
	zerowanie2(a, n);
	
	clock_t stop2 = clock();
	
	clock_t start1 = clock();
	
	zerowanie1(a, n);
	
	clock_t stop1 = clock();
	
	
	
	cout << "Zerowanie 1: " << stop1 - start1 <<endl; 
	cout << "Zerowanie 2: " << stop2 - start2 <<endl;
	
	system("PAUSE");
	deleting(a, n);
	deleting(b, n);
	
	return 0;
}
