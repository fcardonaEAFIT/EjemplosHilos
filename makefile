all: crearHilo

crearHilo: crearHilo.o
	$(CXX) -o $@ $^ -pthread
