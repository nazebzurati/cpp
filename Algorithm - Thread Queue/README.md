Thread queue is a queue of a singleton (only one instance and globally available) with one running thread. In this example shows that if you are implementing multithread, cout will have this interleaving state / race condition on who can display on the console at one point of time. The reason why use thread queue is basically to have one thread to sequentially display out the "cout" stored in a queue. This method would prevent interleaving state / race condition from happening and improve your application performance (using other threads instead the main thread to do this operation: also suitable for filestream writing and reading) although this problem may solved just by using printf or a mutex lock guard.

To disable the thread queue, please use below value on line 81
```
#define USE_QUEUE false
```

To enable the thread queue, please use below value on line 81
```
#define USE_QUEUE true
```