// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

template<typename T>
class Pila
{
private:
	T* Datos;
	int Cima;
	const int numeroElementos;

public:
	Pila(int _numeroElementos) : numeroElementos(_numeroElementos) {
		Datos = new T[numeroElementos];
		Cima = -1;
	}
	~Pila() { delete[] Datos; }
	void Insertar(T c);
	T Sacar();
	bool Vacia();
	bool Llena();
};

template<class T>
void Pila<T>::Insertar(T elementoInsertar) {
	if (!Llena()) {
		Cima++;
		Datos[Cima] = elementoInsertar;
		
		UE_LOG(LogTemp, Log, TEXT("Se insertado satisfactoriamente"));
		//cout << "Se insertado satisfactoriamente" << endl;
	}
	else {
		UE_LOG(LogTemp, Log, TEXT("No se pudo ingresar el elemento en la pila"));
		//cout << "No se pudo ingresar el elemento en la pila" << endl;
	}
}

template<class T>
T Pila<T>::Sacar() {
	if (!Vacia()) {
		T elementoSacar = Datos[Cima];
		Cima--;
		return elementoSacar;
	}
	else {
		UE_LOG(LogTemp, Log, TEXT("No se pudo sacar el elemento de la pila"));
		//cout << "No se pudo sacar el elemento de la pila" << endl;
	}
}

template<class T>
bool Pila<T>::Vacia() {
	if (Cima < 0) {
		return true;
	}
	else
		return false;
}

template<class T>
bool Pila<T>::Llena() {
	if (Cima < numeroElementos - 1) {
		return false;
	}
	else {
		return true;
	}
		
}

