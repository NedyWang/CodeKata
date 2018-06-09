#include <pthread.h>
#include <iostream>

static pthread_key_t key;
static pthread_once_t once_key;

static void make_key() {
    pthread_key_create(&key, NULL);
}

int get_value() {
    return *(int*)pthread_getspecific(key);
}

void* func(void* arg) {
    int x = 0;
    pthread_setspecific(key, &x);
    std::cout << get_value() << std::endl;
}

int main() {
    pthread_once(&once_key, make_key);
    pthread_t tid;
    pthread_create(&tid, NULL, func, NULL);
    pthread_join(tid, NULL);
    pthread_key_delete(key);
    return 0;
}
