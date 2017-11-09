all: Ondas datos1d graficas




graficas:Plots.py
	python Plots.py

datos1d:Ondas.x
	./Ondas.x

Ondas:Ondas.c
	gcc -o Ondas.x Ondas.c
