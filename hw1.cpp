#include <iostream>
#include <string>
#include <cmath>
#include <thread>
#include <chrono>

using namespace std;
void sumforward(int a,int b,double* sum){
    // compute from 1 to 1/n
    for (double i=a;i<b;i++){
        *sum+=(1.0/i);
    }
    
}

void sumbackward(int a,int b,double* sum){

    // compute from 1/n to 1
    for (int i = a; i >= b; --i) {
        *sum += 1.0 / i;
    }
  
}

//6 threads
int main(int argc, char* argv[]){
int n = atol(argv[1]);
double sum_forward1= 0.0;
double sum_forward2= 0.0;
double sum_forward3= 0.0;
double sum_forward4= 0.0;
double sum_forward5= 0.0;
double sum_forward6= 0.0;
double sum_backward1 = 0.0;
double sum_backward2 = 0.0;
double sum_backward3 = 0.0;
double sum_backward4 = 0.0;
double sum_backward5 = 0.0;
double sum_backward6 = 0.0;
thread f1(&sumforward,1,n/4,&sum_forward1);
thread f2(&sumforward,n/4+1,n/2,&sum_forward2);
thread f3(&sumforward,n/2,n*(3.0/4.0),&sum_forward3);
thread f4(&sumforward,n*(3.0/4.0)+1,n,&sum_forward4);
thread f5(&sumforward,n*(3.0/4.0)+1,n,&sum_forward4);
thread f6(&sumforward,n*(3.0/4.0)+1,n,&sum_forward4);
thread b1(&sumbackward,n,(n*(3.0/4.0)),&sum_backward1);
thread b2(&sumbackward,(n*(3.0/4.0))-1,n/2,&sum_backward2);
thread b3(&sumbackward,(n/2)-1,n/4,&sum_backward3);
thread b4(&sumbackward,(n/4)-1,1,&sum_backward4);
thread b5(&sumbackward,(n/4)-1,1,&sum_backward4);
thread b6(&sumbackward,(n/4)-1,1,&sum_backward4);
f1.join();
f2.join();
f3.join();
f4.join();
f5.join();
f6.join();
b1.join();
b2.join();
b3.join();
b4.join();
b5.join();
b6.join();
cout<<100/8<<endl;
cout<<100/7<<endl;
cout<<100/6<<endl;
double sum_forward = sum_forward1 + sum_forward2 + sum_forward3 +sum_forward4 + sum_forward5 + sum_forward6;
double sum_backward = sum_backward1 + sum_backward2 + sum_backward3 + sum_backward4 + sum_backward5 + sum_backward6;

cout<< "the sum from forward is"<<sum_forward<<endl;
cout<< "the sum from backward is"<<sum_backward<<endl;
cout<< "this is 4 threads"<<endl;
}

//4 threads
/*
int main(int argc, char* argv[]){
int n = atol(argv[1]);
double sum_forward1= 0.0;
double sum_forward2= 0.0;
double sum_forward3= 0.0;
double sum_forward4= 0.0;
double sum_backward1 = 0.0;
double sum_backward2 = 0.0;
double sum_backward3 = 0.0;
double sum_backward4 = 0.0;
thread f1(&sumforward,1,n/4,&sum_forward1);
thread f2(&sumforward,n/4+1,n/2,&sum_forward2);
thread f3(&sumforward,n/2,n*(3.0/4.0),&sum_forward3);
thread f4(&sumforward,n*(3.0/4.0)+1,n,&sum_forward4);
thread b1(&sumbackward,n,(n*(3.0/4.0)),&sum_backward1);
thread b2(&sumbackward,(n*(3.0/4.0))-1,n/2,&sum_backward2);
thread b3(&sumbackward,(n/2)-1,n/4,&sum_backward3);
thread b4(&sumbackward,(n/4)-1,1,&sum_backward4);
f1.join();
f2.join();
f3.join();
f4.join();
b1.join();
b2.join();
b3.join();
b4.join();
double sum_forward = sum_forward1 + sum_forward2 + sum_forward3 +sum_forward4;
double sum_backward = sum_backward1 + sum_backward2 + sum_backward3 + sum_backward4;

cout<< "the sum from forward is"<<sum_forward<<endl;
cout<< "the sum from backward is"<<sum_backward<<endl;
cout<< "this is 4 threads"<<endl;
}
*/


//2 Threads
/*
int main(int argc, char* argv[]){
int n = atol(argv[1]);
double sum_forward1= 0.0;
double sum_forward2= 0.0;
double sum_backward1 = 0.0;
double sum_backward2 = 0.0;
thread t(&sumforward,1,n/2,&sum_forward1);
thread t1(&sumforward,n/2+1,n,&sum_forward2);
thread t2(&sumbackward,n,n/2,&sum_backward1);
thread t3(&sumbackward,n/2-1,1,&sum_backward2);
t.join();
t1.join();
t2.join();
t3.join();
double sum_forward = sum_forward1 + sum_forward2;
double sum_backward = sum_backward1 + sum_backward2;

cout<< "the sum from forward is"<<sum_forward<<endl;
cout<< "the sum from backward is"<<sum_backward<<endl;
cout<< "this is 2 threads"<<endl;
}
*/


//Single thread
/*
int main(int argc, char* argv[]){
int n = atol(argv[1]);
double sum_forward=0.0;
sumforward(1,n,&sum_forward);
double sum_backward=0.0;
sumbackward(n,1,&sum_backward);



cout<< "the sum from forward is"<<sum_forward<<endl;
cout<< "the sum from backward is"<<sum_backward<<endl;
}
*/
/*
For Single Thread, Number 100,100'000',100'000'000 are tested and results are below

n=100
the sum from forward is5.17738
the sum from backward is5.18738

real	0m0.005s
user	0m0.002s
sys	0m0.003s


n=100'000

the sum from forward is12.0901
the sum from backward is12.0901

real	0m0.007s
user	0m0.003s
sys	0m0.005s


n=100'000'000

the sum from forward is18.9979
the sum from backward is18.9979

real	0m0.358s
user	0m0.354s
sys	0m0.003s

*/

/*
For 2 Threads, Number 100,100'000',100'000'000 are tested and results are below
n=100;
the sum from forward is5.15738
the sum from backward is5.18738
this is 2 threads

real	0m0.006s
user	0m0.003s
sys	0m0.003s

n=100'000;
the sum from forward is12.0901
the sum from backward is12.0901
this is 2 threads

real	0m0.007s
user	0m0.008s
sys	0m0.001s

n=100'000'000;
the sum from forward is18.9979
the sum from backward is18.9979
this is 2 threads

real	0m0.195s
user	0m0.643s
sys	0m0.002s


Question: Run multiple times then time actually increases
*/

/*
For 4 Threads, Number 100,100'000',100'000'000 are tested and results are below
n=100;
the sum from forward is5.12404
the sum from backward is5.18738
this is 4 threads

real	0m0.007s
user	0m0.004s
sys	0m0.004s


n=100'000;
the sum from forward is12.0901
the sum from backward is12.0901
this is 4 threads

real	0m0.007s
user	0m0.009s
sys	0m0.004s

n=100'000'000;
the sum from forward is18.9979
the sum from backward is18.9979
this is 4 threads

real	0m0.163s
user	0m0.949s
sys	0m0.005s


*/

/*
For 6 Threads, Number 100,100'000',100'000'000 are tested and results are below
n=100;
n=100'000;
n=100'000'000;

*/

/*
For 8 Threads, Number 100,100'000',100'000'000 are tested and results are below
n=100;
n=100'000;
n=100'000'000;

*/

/*
For 16 Threads, Number 100,100'000',100'000'000 are tested and results are below
n=100;
n=100'000;
n=100'000'000;

*/