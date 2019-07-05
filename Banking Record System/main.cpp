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

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
