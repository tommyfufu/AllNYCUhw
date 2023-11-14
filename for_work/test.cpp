#include <iostream>
using namespace std;

class user_class{
public:
    int user_permission;
};

enum Permission{
    permission_none=0, 
    permission_read=1, 
    permission_write=2,
    permission_exec=4,
    permission_del = 8
};
//在使用上增加可讀性，例如授予對應的權限
int main()
{
    user_class user1;
    user1.user_permission = permission_read | permission_write;
    if((user1.user_permission&permission_write) == permission_write)
    {
        //user1 has write permission
    }
}
