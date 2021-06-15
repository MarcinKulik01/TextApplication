#include <iostream>
#include "functions_in_program.h"


bool are_arguments_right(const std::vector<std::string>& arguments){

    std::regex is_flag("(^-.*)||(^--.*)");
    bool operation_a_p = false;
    int index =0;

    for(const auto& arg : arguments) {

        if (!operation_a_p) {

            switch (change_to_enum(arg)) {
                case operation__h: {
                    if (arguments.size() > 1) {
                        std::cout << "flaga --help musi wystepowac samodzielnnie";
                        return false;
                    }
                }
                    break;
                case operation__o : {
                    if(!(index + 1 <= arguments.size()) || std::regex_match(arguments[index + 1], is_flag)) {
                        std::cout << "Po fladze -o powinna sie pojawic sciezka dostepu";
                        return false;
                    }
                }
                    break;
                case operation__n : {
                    if (print_error_about_missing_flag_f(change_to_enum(arguments[0]), "n"))
                        return false;
                }
                    break;
                case operation__d : {
                    if (print_error_about_missing_flag_f(change_to_enum(arguments[0]), "d"))
                        return false;
                }
                    break;
                case operation__dd : {
                    if (print_error_about_missing_flag_f(change_to_enum(arguments[0]), "dd"))
                        return false;
                }
                    break;
                case operation__c : {
                    if (print_error_about_missing_flag_f(change_to_enum(arguments[0]), "c"))
                        return false;
                }
                    break;
                case operation__w : {
                    if (print_error_about_missing_flag_f(change_to_enum(arguments[0]), "w"))
                        return false;
                }
                    break;
                case operation__cw : {
                    if (print_error_about_missing_flag_f(change_to_enum(arguments[0]), "cw"))
                        return false;
                    else if (std::regex_match(arguments[index + 1], is_flag)) {
                        std::cout << "Po fladze -cw nalezy podac slowo";
                        return false;
                    }
                }
                    break;
                case operation__s : {
                    if (print_error_about_missing_flag_f(change_to_enum(arguments[0]), "s"))
                        return false;
                }
                    break;
                case operation__rs : {
                    if (print_error_about_missing_flag_f(change_to_enum(arguments[0]), "rs"))
                        return false;
                }
                    break;
                case operation__f : {
                    if (!(index + 1 <= arguments.size()) || std::regex_match(arguments[index + 1], is_flag)) {

                        std::cout << "Niepoprawne uzycie flagi -f, nalezy podac sciezke";
                        return false;
                    } else if (!(index + 1 <= arguments.size()) || !is_file_exists(arguments[index + 1])) {

                        std::cout << "Niepoprawne uzycie, podany plik nie istnieje";
                        return false;
                    }
                } break;
                case operation__i : {
                    if (arguments.size() > 2 || std::regex_match(arguments[index + 1], is_flag)) {
                        std::cout << "Niepoprawne uzycie flagi -i";
                        return false;
                    }break;

                    case operation__p : {
                        if (print_error_about_missing_flag_f(change_to_enum(arguments[0]), "-p")) {
                            return false;
                        }
                        for (int j = index + 1; j < arguments.size(); j++) {
                            if (std::regex_match(arguments[j], is_flag)) {
                                std::cout << "po fladze -p nie moga znajdowac sie inne flagi";
                                return false;
                            }
                        }
                        operation_a_p = true;
                    }
                    break;
                    case operation__a : {
                        if (print_error_about_missing_flag_f(change_to_enum(arguments[0]), "-a")) {
                            return false;
                        }
                        for (int j = index + 1; j < arguments.size(); j++) {
                            if (std::regex_match(arguments[j], is_flag)) {
                                std::cout << "po fladze -a nie moga znajdowac sie inne flagi";
                                return false;
                            }
                        }
                        operation_a_p = true;
                    }
                    break;
                    case operation__null: {
                        if (!is_flags_before(arguments, index)) {
                            std::cout << "wyraz " + arguments[index] + " nie jest flaga";
                            return false;
                        }
                    }
                    break;
                    default:;
                }
            }
          }
        index++;
    }
    return true;
}

void run_program(const std::vector<std::string>& arguments){

    std::regex expresion("-.*");
    std::string input;
    std::string full_output = " ***************** wynik wykonania sie argumentow podanych do aplikacji PJAText2 ******************";
    std::ofstream output_file;
    bool operation_l = false;
    bool operation_o = false;
    bool operation_i = false;
    int index = 0;

   for(auto const& arg : arguments){

       if(index!=arguments.size()) {

           switch (change_to_enum(arg)) {
               case operations::operation__f:
                   input = load_file_to_string(arguments[index + 1]);
                   break;
               case operations::operation__n: {
                   full_output += "\nLiczba lini w pliku: " + count_line_in_string(input);
                   full_output += "\n";
               }
                   break;
               case operations::operation__d: {
                   full_output += "\nLiczba cyfr w pliku wynosi: " + count_digits_in_string(input);
                   full_output += "\n";
               }
                   break;
               case operations::operation__dd: {
                   full_output += "\nLiczba liczb w pliku: " + count_numbers_in_string(input);
                   full_output += "\n";
               }
                   break;
               case operations::operation__c: {
                   full_output += "\nLiczba znakow w pliku: " + count_chars_in_string(input);
                   full_output += "\n";
               }
                   break;
               case operations::operation__w: {
                   full_output += "\nLiczba slow w pliku: " + count_words_in_string(input);
                   full_output += "\n";
               }
                   break;
               case operations::operation__cw: {
                   full_output += "Liczba wystapien slwoa " + arguments[index + 1] + " w pliku wynosi: " +
                           count_given_word_in_string(input, arguments[index + 1]);
                   full_output += "\n";
               }
                   break;
               case operations::operation__s: {
                   full_output +=
                           "\nPosortowane w kolejnosci alfabetycznej lub od najmniejszego rozmiaru do najwiekszczego:\n " +
                                   sort_words_in_string(input, operation_l);
                   full_output += "\n\n";
                   operation_l = false;
               }
                   break;
               case operations::operation__rs: {
                   full_output +=
                           "\nPosortowane w kolejnosci odwrotnej niz alfabetyczna lub od najwiekszego rozmiaru do najmniejszego:\n " +
                                   reverse_sort_words_in_string(input, operation_l);
                   full_output += "\n\n";
                   operation_l = false;
               }
                   break;
               case operations::operation__a: {
                   auto pom = check_anagrams(vector_for_last_argument_function(arguments, index), input);
                   if (pom.empty())
                       full_output += "\nPalindromy w pliku:\n brak pasujacych\n";
                   else
                       full_output += "\nPalindromy w pliku:\n" + pom + "\n";
                   index = arguments.size();
               }
                   break;
               case operations::operation__p: {
                   auto pom = check_palindromes(vector_for_last_argument_function(arguments, index), input);
                   if (pom.empty())
                       full_output += "\nPalindromy w pliku:\n brak pasujacych";
                   else
                       full_output += "\nPalindromy w pliku:\n" + pom + "\n";
                   index = arguments.size();
               }
                   break;
               case operations::operation__o: {
                   operation_o = true;
                   output_file = std::ofstream(arguments[index + 1]);
               }    break;

               case operations::operation__h: {
                   full_output += help_information();
               }
                   break;
               case operations::operation__i: {

                   auto input_args = load_file_to_string(arguments[index + 1]);
                   auto args = change_input_to_vector(input_args);

                   operation_i = true;

                   if (are_arguments_right(args)) {
                       run_program(args);
                       index = arguments.size();
                   } else
                       index = arguments.size();

               }
                   break;
               case operations::operation__l:
                   operation_l = true;
                   break;
               default:
                   break;

            }
       }
        index++;
    }
    if(arguments.empty() && !operation_i)
      full_output = help_information();
    if(!operation_o  && !operation_i)
        std::cout<<full_output;
    else if(!operation_i)
        output_file << full_output;
}


std::string count_line_in_string(const std::string& file_data){
    if(file_data.empty())
        return "0";
    auto counted_line = std::count_if(file_data.begin(), file_data.end(), [](char a){
        return a == '\n';
    })+1;

    return convert_to_string(counted_line);
}

std::string count_digits_in_string(const std::string&  file_data){
    auto counted_numbers = std::count_if(file_data.begin(), file_data.end(), [](char a){
        return a > 47 && a < 58;
    });
    return convert_to_string(counted_numbers);
}

std::vector<std::string> change_input_to_vector(const std::string& input){

    auto all_words = std::stringstream(input);
    auto words = std::vector<std::string>();

    for(auto word = std::string(); all_words >> word ;words.push_back(word));

    return words;
}

std::string count_numbers_in_string(const std::string& file_data){

    auto words = change_input_to_vector(file_data);

    std::regex expresion("-{0,1}[0-9]{1,}[.,]{0,1}[0-9]{0,}");

    auto counted_full_numbers = std::count_if(words.begin(),words.end(),[expresion](const std::string& to_check){
        if(!std::regex_match(to_check,expresion))
            return false;
        return true;
    });

    return convert_to_string(counted_full_numbers);
}

std::string count_chars_in_string(const std::string&  file_data){
    auto counted_chars =  std::count_if(file_data.begin(), file_data.end(), [](char a){
        return true;
    });

    return convert_to_string(counted_chars);
}

std::string count_words_in_string(const std::string&  file_data){

    auto how_many_words =  change_input_to_vector(file_data).size();

    return convert_to_string(how_many_words);
}

std::string count_given_word_in_string(const std::string& file_data, const std::string&  arg){

    auto words = change_input_to_vector(file_data);

    auto counted = std::count_if(words.begin(),words.end(),[arg](auto a){
        return a==arg;
    });

    /*
     *  zlicza ilosc wystepowan zadanego slowa
     *  po fladze -cw, brak slowa po fladze
     *  skutkuje bledem z odpowiednim komunikatem
     */

    return convert_to_string(counted);
}


std::string sort_words_in_string(const std::string& file_data, const bool & is_operation_l){

    auto words = change_input_to_vector(file_data);

    if(!is_operation_l)
        std::sort(words.begin(),words.end(),[](const std::string& first, const std::string& second){
            return first < second;
        });
    else
        std::sort(words.begin(),words.end(),[](const std::string& first, const std::string& second) {
            return first.length() < second.length();
        });

    std::string ans;
    int counter = 0;
    for(const auto& word : words){
        ans+=word+" ";
        counter++;
        if(counter==15){
            ans+="\n";
            counter = 0;
        }
    }

    return convert_to_string(ans);
}

std::string reverse_sort_words_in_string(const std::string& file_data, const bool & is_operation_l){

    auto words = change_input_to_vector(file_data);

    if(!is_operation_l)
        std::sort(words.begin(),words.end(),[](const std::string& first, const std::string& second){
            return first > second;
        });
    else
        std::sort(words.begin(),words.end(),[](const std::string& first, const std::string& second) {
            return first.length() > second.length();
        });

    std::string ans;
    int counter =0;
    for(const auto& word : words){
        ans+=word+" ";
        counter++;
        if(counter==15){
            ans+="\n";
            counter = 0;
        }
    }

    return convert_to_string(ans);
}
bool is_anagram(const std::string& input_to_check,std::string anagram){

    if(input_to_check.size()!=anagram.size())
        return false;

    int ans = std::count_if(input_to_check.begin(),input_to_check.end(),[&anagram](char a){
        for(int i=0; i<anagram.size(); i++){
            if(anagram[i] == a) {
                anagram.erase(anagram.begin()+i);
                return true;
            }
        }
        return false;
    });

    if(input_to_check.length() != ans)
        return false;
    return true;
}

std::string check_anagrams(const std::vector<std::string>& input_anagram, const std::string&  file_data){

    auto words = change_input_to_vector(file_data);
    auto data =  std::set<std::string>();

    for(const auto& word : words){

        for(const auto& in_an : input_anagram) {
            if (is_anagram(word, in_an)) {
                data.insert(word);
            }
        }
    }
    std::string ans;
    for(const auto& palindrom : data){
        ans+=palindrom+" ";
    }
    return convert_to_string(ans);
}

bool is_palindrome(const std::string& pal){
    for(int i=0; i<pal.size()/2; i++)
        if(pal[i]!=pal[pal.size()-i-1])
            return false;
    return true;
}

std::string check_palindromes(const std::vector<std::string>& input_palindrome, const std::string&  file_data) {

    auto words = change_input_to_vector(file_data);
    auto data =  std::set<std::string>();

    for(const auto& in_pa : input_palindrome) {
        if (is_palindrome(in_pa)) {
            for(const auto& wor : words){
                if(wor == in_pa)
                    data.insert(in_pa);
            }
        }
    }
    std::string ans;
    for(const auto& palindrom : data){
        ans+=palindrom+" ";
    }
    return convert_to_string(ans);
}

std::string load_file_to_string(const std::string& path){
    auto file = std::ifstream(path);
    auto stream = std::stringstream();
    stream << file.rdbuf();
    std::string input = stream.str();
    return input;
}

std::vector<std::string> vector_for_last_argument_function(const std::vector<std::string>& arguments,const int index){
    std::vector<std::string> ans;
    for(int i=index+1; i<arguments.size(); i++){
        ans.push_back(arguments[i]);
    }
    return ans;
}

bool is_file_exists(const std::string& name) {
    std::ifstream file(name.c_str());
    return file.good();
}

bool is_flags_before(const std::vector<std::string>& arguments,const int& i){
    if(arguments[i-1]=="-f" || arguments[i-1]=="--file"){
        return true;
    }
    if(arguments[i-1]=="-o" || arguments[i-1]=="--output"){
        return true;
    }
    if(arguments[i-1]=="-i" || arguments[i-1]=="--input"){
        return true;
    }
    if(arguments[i-1]=="-cw" || arguments[i-1]=="--count_word"){
        return true;
    }
    return false;
}

operations change_to_enum(const std::string& to_change){

    if(to_change == "-f" || to_change == "--file" ) return operations::operation__f;
    else if(to_change == "-n"|| to_change == "--newlines" ) return operations::operation__n;
    else if(to_change == "-d"|| to_change == "--digits" ) return operations::operation__d;
    else if(to_change == "-dd"|| to_change == "--numbers" ) return operations::operation__dd;
    else if(to_change == "-c"|| to_change == "--chars" ) return operations::operation__c;
    else if(to_change == "-w"|| to_change == "--words" ) return operations::operation__w;
    else if(to_change == "-s"|| to_change == "--sorted" ) return operations::operation__s;
    else if(to_change == "-rs"|| to_change == "--reverse-sorted" ) return operations::operation__rs;
    else if(to_change == "-a"|| to_change == "--anagrams" ) return operations::operation__a;
    else if(to_change == "-p"|| to_change == "--palindroms" ) return operations::operation__p;
    else if(to_change == "-o"|| to_change == "--output" ) return operations::operation__o;
    else if(to_change == "-i"|| to_change == "--input" ) return operations::operation__i;
    else if(to_change == "-l"|| to_change == "--by-length" ) return operations::operation__l;
    else if(to_change == "-cw"|| to_change == "--count_word" ) return operations::operation__cw;
    else if(to_change == "--help" ) return operations::operation__h;
    return operations::operation__null;
}

std::string help_information(){


    return "\n(HELP) Znajdujesz sie w HELPIE programu PJAText2 (HELP)\n\n"
          "Narzędzie jest wygodnym w użyciu programem, który służy  do przeróżnych operacji\n "
          "na zawartościach plików tekstowych zapisanych w formacie ANSI\n\n"
          "FLAGA nazwa\n     -f\n  ALIAS nazwa\n     --file\n"
          "OPIS DZIALANIA\n"
          "     Oczekuje, że następnym argumentem będzie ścieżka do pliku źródłowego.\n"
          "     W przypadku niepoprawnej ścieżki wyświetli się odpowiedni komunikat\n\n"
          "FLAGA nazwa\n     -n\n  ALIAS nazwa\n     --newlines\n"
          "OPIS DZIALANIA\n"
          "     Wyswietla liczbę linii z pliku źródłowego. Do jej dzialania potrzebna \n"
          "     jest flaga -f, która musi byc zadeklarowana wczesniej\n\n"
          "FLAGA nazwa\n     -d\n  ALIAS nazwa\n     --digits\n"
          "OPIS DZIALANIA\n"
          "     Wyswietla liczbę cyfr z pliku źródłowego.  Do jej dzialania potrzebna \n"
          "     jest flaga -f, która musi byc zadeklarowana wczesniej \n\n"
          "FLAGA nazwa\n     -dd\n  ALIAS nazwa\n     --numbers\n"
          "OPIS DZIALANIA\n"
          "     Wyswietla liczbę liczb z pliku źródłowego.  Do jej dzialania potrzebna \n"
          "     jest flaga -f, która musi byc zadeklarowana wczesniej \n\n"
          "FLAGA nazwa\n     -c\n  ALIAS nazwa\n     --chars\n"
          "OPIS DZIALANIA\n"
          "     Wyswietla liczbę znakow z pliku źródłowego.  Do jej dzialania potrzebna \n"
          "     jest flaga -f, która musi byc zadeklarowana wczesniej \n\n"
          "FLAGA nazwa\n     -w\n  ALIAS nazwa\n     --words\n"
          "OPIS DZIALANIA\n"
          "     Wyswietla liczbę slow z pliku źródłowego.  Do jej dzialania potrzebna \n"
          "     jest flaga -f, która musi byc zadeklarowana wczesniej \n\n"
          "FLAGA nazwa\n     -s\n  ALIAS nazwa\n     --sorted\n"
          "OPIS DZIALANIA\n"
          "     Wyswietla posortowane alfabetycznie dane z pliku źródłowego. Do jej \n"
          "     dzialania potrzebna jest flaga -f, która musi byc zadeklarowana wczenisej \n\n"
          "FLAGA nazwa\n     -rs\n  ALIAS nazwa\n     --reverse-sorted\n"
          "OPIS DZIALANIA\n"
          "     Wyswietla posortowane odwrotnie niz alfabetycznie dane z pliku źródłowego. Do jej \n"
          "     dzialania potrzebna jest flaga -f, która musi byc zadeklarowana wczenisej \n\n"
          "FLAGA nazwa\n     -l\n  ALIAS nazwa\n     --by-length\n"
          "OPIS DZIALANIA\n"
          "     Modyfikuje dzialanie flagi -s i -rs w taki sposob ze zmieniana jest kolejnosc z\n"
          "     alfabetycznej na dlugsc poszczegolnych slow. Musi zostac zadeklarowana przed flagami\n\n"
          "     -s lub -rs \n\n"
          "FLAGA nazwa\n     -a\n  ALIAS nazwa\n     --anagrams\n"
          "OPIS DZIALANIA\n"
          "     Wystepujace po niej elementy traktowane sa jako slowa. Program sprawdza czy sa one\n"
          "     anagramami po czym wyszukuje je w pliku zrodlowym i wypisuje\n\n"

          "FLAGA nazwa\n     -o\n  ALIAS nazwa\n     --output\n"
          "OPIS DZIALANIA\n"
          "     Oczekuje, że następnym argumentem będzie ścieżka do pliku pliku."
          "     Zostana do niego zapisany efekt dzialania programy\n\n"

          "FLAGA nazwa\n     -p\n  ALIAS nazwa\n     --palindromes\n"
          "OPIS DZIALANIA\n"
          "     Wystepujace po niej elementy traktowane sa jako slowa. Program sprawdza czy sa one\n"
          "     palindronami po czym wyszukuje je w pliku zrodlowym i wypisuje\n\n"

          "FLAGA nazwa\n     -i\n  ALIAS nazwa\n     --input\n"
          "OPIS DZIALANIA\n"
          "     Oczekuje, że następnym argumentem będzie ścieżka do pliku wejsciowego.\n"
          "     Modifikuje ono dzialanie programu w taki sposob ze kolejne argumenty sa \n"
          "     pobierane z pliku, UWAGA FLAGA MOZE WYSTEPOWAC TYLKO SAMODZIELNIE\n\n"

          "FLAGA nazwa\n     -cw\n  ALIAS nazwa\n     --count_word\n"
          "OPIS DZIALANIA\n"
          "     Oczekuje, że następnym argumentem będzie slowo, ktorego ilosc wystepowan\n"
          "     w plik zrodlowym zostanie zliczona \n";

}


template <typename T1>
std::string convert_to_string(T1 t1){
    std::stringstream ss;
    ss << t1;
    return ss.str();
}

bool print_error_about_missing_flag_f(const operations& oper_0,const std::string& flag){
    if(oper_0!=operation__f) {
        std::cout << "braki flagi -f przy uzyciu flagi " + flag;
        return true;
    }
    return false;
}

