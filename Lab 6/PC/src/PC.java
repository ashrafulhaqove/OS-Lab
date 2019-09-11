import java.util.Scanner;
import java.util.concurrent.Semaphore;
import java.util.logging.Level;
import java.util.logging.Logger;


class Q
{
    // an item
    int item;

    // semCon initialized with 0 permits
    // to ensure put() executes first
    static Semaphore semCon = new Semaphore(0);

    static Semaphore semProd = new Semaphore(1);

    // to get an item from buffer
    void get()
    {
        try {
            // Before consumer can consume an item,
            // it must acquire a permit from semCon
            semCon.acquire();
        }
        catch(InterruptedException e) {
            System.out.println("InterruptedException caught");
        }

        // consumer consuming an item
        System.out.println("Consumer consumed item : " + item);

        // After consumer consumes the item,
        // it releases semProd to notify producer
        semProd.release();
    }

    // to put an item in buffer
    void put(int item)
    {
        try {
            // Before producer can produce an item,
            // it must acquire a permit from semProd
            semProd.acquire();
        } catch(InterruptedException e) {
            System.out.println("InterruptedException caught");
        }

        // producer producing an item
        this.item = item;

        System.out.println("Producer produced item : " + item);

        // After producer produces the item,
        // it releases semCon to notify consumer
        semCon.release();
    }
}

// Producer class
class Producer implements Runnable
{
    Q q;
    int PID;
    Producer(Q q, int PID) {
        this.q = q;
        new Thread(this, "Producer P" + PID).start();
          }

    public void run() {
           Scanner reader = new Scanner(System.in);  // Reading from System.in
         try {
            while(true){

System.out.println("Producer"  + PID + ": Enter a number:  ");
int n = reader.nextInt(); // Scans the next token of the input as an int.
//once finished

            q.put(n, PID); }

        } catch (InterruptedException ex) {
            Logger.getLogger(Producer.class.getName()).log(Level.SEVERE, null, ex);
        }

         reader.close();

    }
}

// Consumer class
class Consumer implements Runnable
{
    int CID;
    Q q;
    Consumer(Q q, int CID){
        this.q = q;
        new Thread(this, "Consumer C " + CID).start();
    }

    public void run()
    {
        try {
        while(true){
           q.get(CID);
        }
        } catch (InterruptedException ex) {
            Logger.getLogger(Consumer.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}

// Driver class
class PC
{
    public static void main(String args[])
    {
        // creating buffer queue
        Q q = new Q();

        // starting consumer thread
        new Consumer(q,0);
        new Consumer(q,1);
        new Consumer(q,2);

        new Producer(q,0);
        new Producer(q,1);
       // new Producer(q,2);
        //new Consumer(q);

        // starting producer thread
    }
}
