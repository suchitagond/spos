#include <iostream>
using namespace std;

class producer_consumer
{
public:
    int data[5];
    int mutex = 0;
    int empty = 5;
    int full = 0;
    void wait(int &x)
    {
        if (x > 0)
        {
            x--;
        }
    }
    void signal(int &x)
    {
        x++;
    }
    void producer()
    {
        if (mutex == 0 && empty != 0)
        {
            signal(mutex);
            cout << "Enter data to be produce : ";
            cin >> data[full];
            wait(empty);
            signal(full);
            wait(mutex);
        }
        else
        {
            cout << "You can't produce data..." << endl;
        }
        cout << "Mutex : " << mutex << " Empty Blocks : " << empty << " Full Blocks : " << full << endl;
    }
    void consumer()
    {
        if (mutex == 0 && full != 0)
        {
            signal(mutex);
            cout << "Your consumed data is : " << data[full - 1] << endl;
            wait(full);
            signal(empty);
            wait(mutex);
        }
        else
        {
            cout << "You can't consume data..." << endl;
        }
        cout << "Mutex : " << mutex << " Empty Blocks : " << empty << " Full Blocks : " << full << endl;
    }
};

class reader_writer
{
public:
    int read_count = 0;
    int mutex = 0;
    int writer = 0;
    void wait(int &x)
    {
        if (x > 0)
        {
            x--;
        }
    }
    void signal(int &x)
    {
        x++;
    }
    void start_reading()
    {
        if (mutex == 0)
        {
            signal(mutex);
            read_count++;
            cout << read_count << " Reader is reading the file..." << endl;
            if (read_count == 1)
            {
                signal(writer);
            }
            wait(mutex);
        }
        else
        {
            cout << "Sorry you can't read a file..." << endl;
        }
    }
    void stop_reading()
    {
        if (mutex == 0 && read_count >= 1)
        {
            signal(mutex);
            cout << read_count << " stop it's reading..." << endl;
            read_count--;
            if (read_count == 0)
            {
                wait(writer);
            }
            wait(mutex);
        }
        else
        {
            cout << "File is not open for reading..." << endl;
        }
    }
    void start_writing()
    {
        if (mutex == 0 && writer == 0)
        {
            signal(mutex);
            signal(writer);
            cout << "writer is writing in a file..." << endl;
        }
        else
        {
            cout << "Sorry you can't write in a file..." << endl;
        }
    }
    void stop_writing()
    {
        if (mutex != 0 && writer != 0)
        {
            cout << "Stop writing in file...." << endl;
            wait(mutex);
            wait(writer);
        }
        else
        {
            cout << "File is not open for writing..." << endl;
        }
    }
};

class dining_philosopher
{
public:
    int chopstick[5] = {0, 0, 0, 0, 0};
    int flag;
    void wait(int &x)
    {
        if (x > 0)
        {
            x--;
        }
    }
    void signal(int &x)
    {
        x++;
    }
    void Eat_philosopher()
    {
        flag=0;
        for (int i = 0; i < 5; i++)
        {
            if (chopstick[i] == 0 && chopstick[(i + 1)%5] == 0)
            {
                signal(chopstick[i]);
                signal(chopstick[(i + 1) % 5]);
                cout << i + 1 << " philosopher is eating now..." << endl;
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"Enough philosophers are eating food..."<<endl;
        }
    }
    void Think_philosopher()
    {
        flag=0;
        for (int i = 0; i < 5; i++)
        {
            if (chopstick[i] != 0 && chopstick[(i + 1)%5] != 0)
            {
                wait(chopstick[i]);
                wait(chopstick[(i + 1) % 5]);
                cout << i + 1 << " philosopher is thinking now..." << endl;
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"Everyone is thinking right now..."<<endl;
        }
        
    }
};

int main()
{
    int ch;
    char choice;
    producer_consumer pc;
    reader_writer rw;
    dining_philosopher dp;
    do
    {
        cout << "1)producer-consumer\n2)Reader-Writter\n3)Dinning-Philosopher" << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int ch1;
            char ch2;
            do
            {
                cout << "1)producer\n2)consumer" << endl;
                cout << "Enter your choice : ";
                cin >> ch1;
                switch (ch1)
                {
                case 1:
                    pc.producer();
                    cout << endl;
                    break;
                case 2:
                    pc.consumer();
                    cout << endl;
                    break;
                default:
                    cout << "Enter valid choice..." << endl;
                    break;
                }
                cout << "Do you want to continue (y/n): ";
                cin >> ch2;
            } while (ch2 == 'y' || ch2 == 'Y');

            break;
        case 2:
            int ch3;
            char ch4;
            do
            {
                cout << "1)Start reading file\n2)Stop reading file\n3)Start writing file\n4)Stop writing file" << endl;
                cout << "Enter your choice : ";
                cin >> ch3;
                switch (ch3)
                {
                case 1:
                    rw.start_reading();
                    cout << endl;
                    break;
                case 2:
                    rw.stop_reading();
                    cout << endl;
                    break;
                case 3:
                    rw.start_writing();
                    cout << endl;
                    break;
                case 4:
                    rw.stop_writing();
                    cout << endl;
                    break;
                default:
                    cout << "Enter valid choice..." << endl;
                    break;
                }
                cout << "Do you want to continue(y/n) : ";
                cin >> ch4;
            } while (ch4 == 'y' || ch4 == 'Y');
            break;
        case 3:
            int ch5;
            char ch6;
            do
            {
                cout << "1)Eating philosopher\n2)Tinking philosopher" << endl;
                cout << "Enter your choice:";
                cin >> ch5;
                switch (ch5)
                {
                case 1:
                    dp.Eat_philosopher();
                    cout << endl;
                    break;
                case 2:
                    dp.Think_philosopher();
                    cout << endl;
                    break;
                default:
                    cout << "Enter valid choice..." << endl;
                    break;
                }
                cout << "Do you want to continue(y/n) : ";
                cin >> ch6;
            } while (ch6 == 'y' || ch6 == 'Y');
            break;
        default:
            cout << "Enter valid choice..." << endl;
            break;
        }
        cout << "Do you want to continue(y/n) : ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
}