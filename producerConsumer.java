package Mythread;




class buffer
{
    static Semaphore emptyCount = new Semaphore(10);
    static Semaphore fullcount = new Semaphore(0);


    static Semaphore mutex = new Semaphore(1);



}


class Consumer implements Runnable
{

    Customer

    @Override
    public void run()
    {

    }
}


class Producer implements Runnable
{

    @Override
    public void run()
    {



    }
}








public class Mythread
{
    public static void main(String args[])
    {
        buffer b = new buffer();

        Producer   p = new Producer();

        Consumer   c = new Consumer();

        Thread thread1 = new Thread(p);
        thread1.start();


        Thread thread2 = new Thread(c);
        thread2.start();
    }
}
