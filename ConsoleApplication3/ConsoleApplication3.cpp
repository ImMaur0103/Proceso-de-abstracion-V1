
#include "resource.h"
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace System;


class FiguraGeometrica
{
public:
	double base;
	double altura;
	double ancho;

public:
	virtual void AgregarValores(double b, double alt, double an) {
		base = b;
		altura = alt;
		ancho = an;
	}

	double CalcularPerimetro() {
		return 0;
	}

};

class Rectangulo : public FiguraGeometrica
{
public:
	double CalcularPerimetro() {
		return 2 * base + 2 * altura;
	}



	Rectangulo operator + (Rectangulo &rec) {
		Rectangulo recito;
		recito.base = this->base + rec.base;
		recito.altura = this->altura + rec.altura;
		recito.ancho = 0;
		return recito;
	}
};

class Triangulo : public FiguraGeometrica {
public:
	double CalcularPerimetro() {
		return 2 * sqrt((base / 2) * (base / 2) + altura * altura) + base;
	}
};

class Circulo : public FiguraGeometrica {
public:
	double CalcularPerimetro() {
		return 2 * 3.14159 * (ancho / 2);
	}
	double CalcularArea() {
		return 3.1416 * ancho * ancho;
	}
};

class base {
public:
	virtual void print()
	{
		Console::WriteLine("print base class");
	}

	void show()
	{
		Console::WriteLine("show base class");
	}
};

class derived : public base {
public:
	void print()
	{
		Console::WriteLine("print derived class");
	}

	void show()
	{
		Console::WriteLine("show derived class");
	}
};
int main(array<System::String ^> ^args)
{
	base *bptr = new base();
	Rectangulo rectangulo;
	Rectangulo rectangulo2;
	Triangulo *triangulo = new Triangulo();
	Circulo *circulo = new Circulo();
	double base = 0, altura = 0, ancho = 0;

	rectangulo2.AgregarValores(5, 4, 0);

	for (int i = 0; i < Console::WindowWidth; i++) {
		Console::SetCursorPosition(i, Console::WindowHeight / 2);
		Console::Write("_");
	}

	for (int i = 0; i < Console::WindowHeight; i++) {
		Console::SetCursorPosition(Console::WindowWidth / 2, i);
		Console::Write("|");
	}

	Console::WriteLine("Ingrese datos del Rectangulo");
	Console::WriteLine("Ingrese la base");
	base = Convert::ToDouble(Console::ReadLine());
	Console::WriteLine("Ingrese la altura");
	altura = Convert::ToDouble(Console::ReadLine());
	rectangulo.AgregarValores(base, altura, 0);

	Console::WriteLine("Ingrese datos del Triangulo");
	Console::WriteLine("Ingrese la base");
	base = Convert::ToDouble(Console::ReadLine());
	Console::WriteLine("Ingrese la altura");
	altura = Convert::ToDouble(Console::ReadLine());
	triangulo->AgregarValores(base, altura, 0);

	Console::WriteLine("Ingrese datos del Circulo");
	Console::WriteLine("Ingrese diametro");
	ancho = Convert::ToDouble(Console::ReadLine());
	circulo->AgregarValores(0, 0, ancho);

	Rectangulo rectangulito = rectangulo + rectangulo2;

	Console::WriteLine("Perimetro del Rectangulo: " + rectangulo.CalcularPerimetro());
	Console::WriteLine("Perimetro del Rectangulo: " + rectangulito.CalcularPerimetro());
	Console::WriteLine("Perimetro del Triangulo: " + triangulo->CalcularPerimetro());
	Console::WriteLine("Perimetro del Circulo: " + circulo->CalcularPerimetro());
	Console::WriteLine("Perimetro del Circulo: " + circulo->CalcularArea());

	Console::ReadKey();
	
	derived d;
	
	bptr = &d;
	// virtual function, binded at runtime 
	bptr->print();

	// Non-virtual function, binded at compile time 
	bptr->show();

    return 0;
}
