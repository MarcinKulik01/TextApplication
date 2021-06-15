#ifndef PROJEKT_FUNCTIONS_IN_PROGRAM_H
#define PROJEKT_FUNCTIONS_IN_PROGRAM_H

#include <string>
#include <vector>
#include <regex>
#include <fstream>
#include <sstream>
#include <set>

/**
 * Checks if the given arguments are consistent with
 * the program assumptions.If it finds an incompatible
 * order, it will display an appropriate message and
 * return false.
 *
 * @param arguments - string vector containing program arguments.
 * @return True if arguments are in correct way and false if not.
 */
bool are_arguments_right(const std::vector<std::string>& arguments);

/**
 * Executes given arguments.
 *
 * @param arguments - string vector containing program arguments.
 */
void run_program(const std::vector<std::string>& arguments);

/**
 * Loads the file to which the path was given in the argument.
 *
 * @param path - string containing data from the source file.
 * @return The contents of the file as a string
 *
 */
std::string load_file_to_string(const std::string& path);

/**
 * Counts the number of lines present in the file .
 *
 * @param file_data - string containing data from the source file.
 * @return The number of lines in the file as a string.
 */
std::string count_line_in_string(const std::string& file_data);

/**
 * Counts the number of digits present in the file.
 *
 * @param file_data - string containing data from the source file.
 * @return The number of digits in the file as a string.
 */
std::string count_digits_in_string(const std::string&  file_data);

/**
 * Counts the number of numbers present in the file.
 *
 * @param file_data - string containing data from the source file.
 * @return The number of numbers in the file as a string.
 */
std::string count_numbers_in_string(const std::string&  file_data);

/**
 * Counts the number of chars present in the file.
 *
 * @param file_data - string containing data from the source file.
 * @return The number of chars in the file as a string.
 */
std::string count_chars_in_string(const std::string& file_data);

/**
 * Counts the number of words present in the file.
 *
 * @param file_data - string containing data from the source file.
 * @return The number of words in the file as a string.
 */
std::string count_words_in_string(const std::string&  file_data);

/**
 * Counts the number of specific word given as an argument which is present in the file.
 *
 * @param file_data - string containing data from the source file.
 * @param arg - string containing looking word.
 * @return The number of numbers in the file as a string.
 */
std::string count_given_word_in_string(const std::string&  file_data, const std::string&  arg);

/**
 * Sorts the words given by the file_data alphabetically.
 * If the if_operation_l modifier is present, it sorts
 * by word length from shortest to longest.
 *
 * @param file_data - string containing data from the source file.
 * @param is_operation_l - bool containing optional function modification.
 * @return The sorted words in file_data.
 */
std::string sort_words_in_string(const std::string&  file_data, const bool &is_operation_l = false);

/**
 * Sorts the words given by the file_data in reverse order
 * than alphabetically.If the if_operation_l modifier is present, it sorts
 * by word length from longest to shortest.
 *
 * @param file_data - string containing data from the source file.
 * @param is_operation_l - bool containing optional function modification.
 * @return The sorted words in file_data.
 */
std::string reverse_sort_words_in_string(const std::string&  file_data, const bool & is_operation_l = false);

/**
 * It stores information on flags that the program will handle
 *
 * @return The string of flag information
 */
std::string help_information();


/**
 * Calls a function to check if input_anagram contains any anagrams. Checks if the
 * given anagrams are in the source file. if so adds them to the container.
 *
 * @param input_anagram - string vector of words which could be anagrams.
 * @param file_data - string containing data from the source file.
 * @return The string of anagrams which appear in the vector and in the source file.
 */
std::string check_anagrams(const std::vector<std::string>& input_anagram, const std::string& file_data);

/**
 * Calls a function to check if input_palindrome contains any file_data.
 * if so adds them to the container.
 *
 * @param input_palindrome - string argument which is based to looking palindromes.
 * @param file_data - string containing data from the source file.
 * @return The string of palindromes container which.
 */
std::string check_palindromes(const std::vector<std::string>& input_palindrome, const std::string& file_data);

/**
 * Replace string with vector string.
 *
 * @param input - string to change.
 * @return vector of string elements.
 */
std::vector<std::string> change_input_to_vector(const std::string& input);

/**
 * Replace vector string to smaller vector from index to end.
 *
 * @param arguments - string vector to change.
 * @param index - int value from which the new vector begins.
 * @return vector from index to end.
 */
std::vector<std::string>  vector_for_last_argument_function(const std::vector<std::string>& arguments,int index);


/**
 * Checks if input_to_check can be anagram of anagram argument.
 *
 * @param anagram - string which is .
 * @param input_to_check - string to check.
 * @return true if it is anagram and false if not.
 */
bool is_anagram(const std::string& input_to_check,std::string anagram);

/**
 * Checking if path is an correct path to existing program.
 *
 * @param path - string argument to check.
 * @return true if it exist and false if not.
 */
bool is_file_exists(const std::string& path);

/**
 * Checks if pal is an palindrome.
 *
 * @param pal - string argument to check.
 * @return true if it is palindrome and false if not.
 */
bool is_palindrome(const std::string& pal);

/**
 * Checks if it is reasonable to
 * provide an argument that is not a flag.
 *
 * @param arguments - string vector of program arguments.
 * @param index - int value of argument number.
 * @return true if is allowed and false if not.
 */
bool is_flags_before(const std::vector<std::string>& arguments,const int& index);

/**
 * Includes all possible operations in the form of an enum.
 */
enum operations{
    operation__h,operation__f,operation__n,operation__d,operation__dd,operation__c,
    operation__w,operation__cw,operation__s,operation__rs,operation__l,operation__a,
    operation__p,operation__o,operation__i,operation__null
};

/**
 * Checking if oper_0 equals operation__f. Then writing an error with the given flag
 *
 * @param oper_0 - operation form of first program argument.
 * @param flag - the string value of performed flag.
 * @return true if check is correct and false if not.
 */
bool print_error_about_missing_flag_f(const operations& oper_0,const std::string& flag);

/**
 * Change the to_change for a enum value.
 *
 * @param to_change - string to change.
 * @return the enum value corresponding to the string operation.
 */
operations change_to_enum(const std::string& to_change);

/**
 * Converts an argument to a string
 *
 * @tparam T1  - template represented types.
 * @param arg_to_convert - template type which have to be converted.
 * @return converted argument.
 */
template <typename T1>
std::string convert_to_string(T1 arg_to_convert);


#endif //PROJEKT_FUNCTIONS_IN_PROGRAM_H
