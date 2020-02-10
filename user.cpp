#include <iostream>
#include <string>

class User
{
private:
    std::string private_key;        //Plan to be 256bits
public:
    std::string public_key;         //Plan to be 256bits
    std::string user_address;       //Plan to be 64bits
    User();                         //Constructor
    ~User();                        //Decstructor
    std::string generate_private_key();
    std::string generate_public_key();
    std::string generate_user_address();
};

int main()
{

}