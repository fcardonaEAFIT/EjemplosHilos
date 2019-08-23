all: crearHilo crearHilo2 crearHilo3

crearHilo: crearHilo.o
	$(CXX) -o $@ $^ -pthread

crearHilo2: crearHilo2.o
	$(CXX) -o $@ $^ -pthread

crearHilo3: crearHilo3.o
	$(CXX) -o $@ $^ -pthread
