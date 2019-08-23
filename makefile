all: crearHilo crearHilo2

crearHilo: crearHilo.o
	$(CXX) -o $@ $^ -pthread

crearHilo2:crearHilo2.o
	$(CXX) -o $@ $^ -pthread
