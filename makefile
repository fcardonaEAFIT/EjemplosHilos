all: crearHilo crearHilo2 crearHilo3 crearHilo4 linuxHNK linuxHNU syncHNK sync2HNK

crearHilo: crearHilo.o
	$(CXX) -o $@ $^ -pthread

crearHilo2: crearHilo2.o
	$(CXX) -o $@ $^ -pthread

crearHilo3: crearHilo3.o
	$(CXX) -o $@ $^ -pthread

crearHilo4: crearHilo4.o
	$(CXX) -o $@ $^ -pthread

linuxHNK: linuxHNK.o
	$(CXX) -o $@ $^

syncHNK: syncHNK.o
	$(CXX) -o $@ $^

sync2HNK: sync2HNK.o
	$(CXX) -o $@ $^

linuxHNU: linuxHNU.o
	$(CXX) -o $@ $^ -pthread

clean:
	rm -f crearHilo crearHilo2 crearHilo3 crearHilo4 linuxHNK linuxHNU syncHNK sync2HNK
	rm -f *.o
	rm -f *.cpp~ makefile~
