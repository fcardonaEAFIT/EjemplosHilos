#include <iostream>
#include <sched.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int k;

int
hiloExec(void *arg) {

  for (int i = 0; i < 5000; ++i) 
    k++;

  return 0;
}

int
main() {

   char *stackHilo[5];

   for (int i = 0; i < 5; i++)
     stackHilo[i] = new char[1024];

   pid_t hilo[5];

   for (int i = 0; i < 5; i++) {

     hilo[i] = clone(hiloExec, stackHilo[i] + 1024,
		     CLONE_FILES | CLONE_FS | CLONE_IO | CLONE_PARENT 
		     | CLONE_SIGHAND | CLONE_VM, NULL, NULL, NULL);
   }


   for (int i = 0; i < 5; i++) {
     int status;

     waitpid(hilo[i], &status, 0);

   }

   cout << "K: " << k << endl;

   return 0;
}
