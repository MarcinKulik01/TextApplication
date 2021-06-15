#include <iostream>
#include "functions_in_program.h"

int main(int args_count,const  char* args[]) {

     const auto arguments = std::vector<std::string>(args + 1, args + args_count);

         if(are_arguments_right(arguments)){
           run_program(arguments);
         }
}


