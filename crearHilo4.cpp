#include <iostream>
#include <pthread.h>
#include <errno.h>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

using namespace std;

void* hilo(void*);

const int N = 5;
int var = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int
main() {
  pthread_t ph_hilo[N];

  for (int i = 0; i < N; i++) {
    if (pthread_create(&ph_hilo[i], nullptr, hilo, nullptr) != 0) {
      cerr << "No se pudo crear hilo: " << errno << endl;
      _exit(1);
    }
  }

  for (int i = 0; i < N; i++) {
    void *valRet;
    pthread_join(ph_hilo[i], &valRet);
  }

  cout << "Var: " << var << endl;

  return 0;
}

void* hilo(void *arg) {
  int value = 10;

  for (int i = 0; i < 5000; i++) {
    pthread_mutex_lock(&mutex);
    var++;
    pthread_mutex_unlock(&mutex);
  }

  return &value;
}
