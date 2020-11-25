#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    if (argc < 2 || argc > 2)
    {
        cout << "usage:" << endl;
        cout << "      " << argv[0] << "user" << endl;
    }
    else
    {
        cout << "Hello," << argv[1] << "." << endl;
        cout << "welcome to the CLI's world." << endl;
    }
    return 0;
}
