#include <iostream>
#include <fstream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;
using namespace std;

class account_query
{
    private:
        char account_number[20];
        char firstName[10];
        char lastName[10];
        float total_Balance;
    public:
        void read_data();
        void show_data();
        void write_rec();
        void read_rec();
        void search_rec();
        void edit_rec();
        void delete_rec();
};
void account_query::read_data()
{
    cout<<"\nEnter Account Number: ";
    cin>>account_number;
    cout<<"Enter First Name: ";
    cin>>firstName;
    cout<<"Enter Last Name: ";
    cin>>lastName;
    cout>>"Enter Balance: ";
    cin>>total_Balance;
    cout<<endl;
}
void account_query::show_data(){
    cout<<"Account Number: "<<account_number<<endl;
    cout<<"First Name: "<<firstName<<endl;
    cout<<"Last Name: "<<lastName<<endl;
    cout<<"Current Balance: Rs. "<<total_Balance<<endl;
    cout<<"--------------------------------------"<<endl;
}
void account_query::write_rec(){
    ofstream outfile;
    outfile.open("record.bank",ios::binary|ios::app);
    read_data();
    outfile.write(reinterpret_cast<char *>(this),sizeof(*this));
    outfile.close();
}
void account_query::read_rec(){
    ifstream infile;
    infile.open("record.bank",ios::binary);
    if(!infile){
        cout<<"Error in opening! File not found!"<<endl;
        return;
    }
    cout<<"\n***Data from file***"<<endl;
    while(!infile.eof()){
        if(infile.read(reinterpret_cast<char*>(this), sizeof(*this))>0)
        {
            show_data();
        }
    }
    infile.close();
}
void account_query::search_rec(){
    int n;
    ifstream infile;
    infile.open("record.bank",ios::binary);
    if(!infile){
        cout<<"\nError in opening! File not found!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count=infile.tellg()/sizeof(*this);
    cout<<"\n There are "<count<<" records in the file";
    cout<<"\n Enter record number to search: ";
    cin>>n;
    infile.seekg((n-1)*sizeof(*this));
    infile.read(reinterpret_cast<char*>(this),sizeof(*this));
    show_data();
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
