#include <iostream>
#include <thread>
using namespace std;

// function to be used in callable
void func_dummy(int N)
 {

   int i = 2;

   for(int j = 2; j < N; j++)
   {
     while(i * i <= j)
     {
       if(j%i == 0)
       {
         break;
       }
       i++;
     }
     cout<<"From THREAD 3: "<< i<<endl;
   }

   // for (int i = 0; i < N; i++) {
   // cout << "Thread 1 :: callable => function pointer\n";
 }

// A callable object
class thread_obj {
 public:
   void operator()(int n) {
     int i = 2;

     for(int j = 2; j < n; j++)
     {
       while(i * i <= j)
       {
         if(j%i == 0)
         {
           break;
         }
         i++;
       }
       cout<<"From THREAD 2: "<< i<<endl;
     }
       // for (int i = 0; i < n; i++)
       //     cout << "Thread 2 :: callable => function object\n";
   }
};

int main()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
// Define a Lambda Expression
auto f = [](int n) {

  int i = 2;

  for(int j = 2; j < n; j++)
  {
    while(i * i <= j)
    {
      if(j%i == 0)
      {
        break;
      }
      i++;
    }
    cout<<"From THREAD 1: "<< i<<endl;
  }

   // for (int i = 0; i < n; i++)
   // cout << "Thread 3 :: callable => lambda expression\n";
   };
//launch thread using function pointer as callable
thread th1(func_dummy, 1000000);

// launch thread using function object as callable
thread th2(thread_obj(), 1000000);

//launch thread using lambda expression as callable
thread th4(f, 1000000);
thread th3(f, 1000000);

thread th5(func_dummy, 1000000);

// launch thread using function object as callable
thread th6(thread_obj(), 1000000);

//launch thread using lambda expression as callable
thread th7(f, 1000000);

thread th8(func_dummy, 1000000);

// launch thread using function object as callable
thread th9(thread_obj(), 1000000);

//launch thread using lambda expression as callable
thread th10(f, 1000000);

thread th11(func_dummy, 1000000);

// launch thread using function object as callable
thread th12(thread_obj(), 1000000);

//launch thread using lambda expression as callable
thread th13(f, 1000000);
thread th14(func_dummy, 1000000);

// launch thread using function object as callable
thread th15(thread_obj(), 1000000);

//launch thread using lambda expression as callable
thread th16(f, 1000000);
thread th17(func_dummy, 1000000);

// launch thread using function object as callable
thread th18(thread_obj(), 1000000);

//launch thread using lambda expression as callable
thread th19(f, 1000000);
// Wait for thread t1 to finish
 th1.detach();
// Wait for thread t2 to finish
th2.detach();

// Wait for thread t3 to finish
th3.join();
// Wait for thread t1 to finish
 th4.join();
// Wait for thread t2 to finish
th5.join();

// Wait for thread t3 to finish
th6.join();
// Wait for thread t1 to finish
 th7.join();
// Wait for thread t2 to finish
th8.join();

// Wait for thread t3 to finish
th9.join();
th10.join();

th11.join();

th12.join();

// Wait for thread t3 to finish
th13.join();

th14.join();
th15.join();

// Wait for thread t3 to finish
th16.join();

th17.join();
th18.join();

// Wait for thread t3 to finish
th19.join();


return 0;
}
