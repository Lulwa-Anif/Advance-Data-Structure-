
#include<iostream>
#include<string>
using namespace std;
struct Client{
    string name;
    string phn;
};
class LinearHash{
    private:
    static const int size=10;
    Client table[size];
    public:
    int hashFunction(string name)
    {
        int hash=0;
        for(char c:name)
        {
            hash+=c;
        }
        return hash%size;
    }
    void insert(Client client)
    {
        int index=hashFunction(client.name);
        while(table[index].name!="")
        {
            index=(index+1)%size;
        }
        table[index]=client;
    }
    string search(string fname,int comp)
    {
        int index=hashFunction(fname);
        while(table[index].name!="")
        {
            comp++;
        
            if(table[index].name==fname)
            {
                return table[index].phn;
            }
            index=(index+1)%size;   
        }
        return "Not found";
    }
};
class QuadraHash{
    private:
    static const int size=10;
    Client table[size];
    public:
    int hashFunction(string name)
    {
        int hash=0;
        for(char c:name)
        {
            hash+=c;
        }
        return hash%size;
    }
    void insert(Client client)
    {
        int index=hashFunction(client.name);
        int i=1;
        while(table[index].name!="")
        {
            
            index=(index+i*i)%size;
            i++;
        }
        table[index]=client;
    }
    string search(string fname,int comp)
    {
        int index=hashFunction(fname);
        int i=1;
        while(table[index].name!="")
        {
            comp++;
            
            if(table[index].name==fname)
            {
                return table[index].phn;
            }
            index=(index+i*i)%size;
            i++;
        }
        return "Not found";
    }
};

int main()
{
    LinearHash l;
    QuadraHash q;
    int choice;
    string name,phn;
    int lc=0;
    int qc=0;
    do{
        cout<<"Menu:"<<endl;
        cout<<"1.Add Client"<<endl;
        cout<<"2.Search Client"<<endl;
        cout<<"3.Compare"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
            {
                cout<<"Enter client name"<<endl;
                cin>>name;
                cout<<"Enter client phone"<<endl;
                cin>>phn;
                Client client;
                client.name=name;
                client.phn=phn;
                l.insert(client);
                q.insert(client);
                break;
            }
              case 2:
                cout << "Enter client name to search: ";
                cin >> name;
                cout << "Linear Probing: " << l.search(name, lc) << endl;
                cout << "Quadratic Probing: " << q.search(name, qc) << endl;
                break;
            case 3:
                cout << "Comparisons made for Linear Probing: " << lc << endl;
                cout << "Comparisons made for Quadratic Probing: " << qc << endl;
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
