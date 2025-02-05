#ifndef USER_H
#define USER_H

#include <string>

extern std::string currentUser;  // Declare currentUser globally
extern std::string username;     // Declare username globally

bool createAccount();
bool login();
void logout();

#endif //USER_H

