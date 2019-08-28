#include <pthread.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct DosEnteros {
  int primero;
  int segundo;
};

void*
hiloExec(void *arg) {
  DosEnteros *p = ((DosEnteros *) arg);

  for (int i = 0; i < p->primero; ++i) {
    cout << "Hola " << i << endl;
  }

  int *ret = new int;

  *ret = p->segundo;

  delete p;

  return (void *) ret;
}

int
main() {
  pthread_t hilo;
  DosEnteros *p = new DosEnteros;

  p->primero = 10000;
  p->segundo = 20;

  if (pthread_create(&hilo, NULL, hiloExec, (void *)p) != 0) {
    cerr << "Fallo creacion de hilo" << endl;
    exit(0);
  }

  pthread_t hilo2;
  p = new DosEnteros;

  p->primero = 20000;
  p->segundo = 30;

  if (pthread_create(&hilo2, NULL, hiloExec, (void *)p) != 0) {
    cerr << "Fallo creacion de hilo" << endl;
    exit(0);
  }

  int *retValHilo;

  pthread_join(hilo, (void **) &retValHilo);

  cout << "Mi hijo termino con estado " << *retValHilo << endl;

  delete retValHilo;

  pthread_join(hilo2, (void **) &retValHilo);

  cout << "Mi hijo termino con estado " << *retValHilo << endl;

  delete retValHilo;

  return 0;
}
