#include <iostream>
#include <pthread.h>
#include <errno.h>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

using namespace std;

void* hilo(void*);

const int N = 5;
const char *message[N] = { "Hola hilo",
			   "Adios hilo",
			   "Quibuo hilo",
			   "Sisas hilo",
			   "listo papi"
};

int
main() {
  pthread_t ph_hilo[N];

  for (int i = 0; i < N; i++) {
    if (pthread_create(&ph_hilo[i], nullptr, hilo, (void *) message[i]) != 0) {
      cerr << "No se pudo crear hilo: " << errno << endl;
      _exit(1);
    }
  }

  for (int i = 0; i < N; i++) {
    char *valRet;
    pthread_join(ph_hilo[i], (void **) &valRet);
    cout << (char *) valRet << endl;
    delete []valRet;
  }

  return 0;
}

void* hilo(void *arg) {
  const char *mensaje = (const char*) arg;
  char *cambio = new char[strlen(mensaje) + 1];
  cout << mensaje << endl;

  int i;
  for (i = 0; mensaje[i]; i++)
    cambio[i] = mensaje[i] != ' ' ? mensaje[i] : '*';

  cambio[i] = '\0';

  return cambio;
}
