3.2. tokens.cpp
3.3. tokens.h
3.4. Makefile
4. An empty directory 'bin' - this is where the binary files will be after
   compiling the source code.

Motivation:
C++ does not provide a tokenizing mechanism per se. It is of course possible to
use the C library function 'strtok' but this is a limited option. It supports 
only a delimiter of one character, which is filtered out. To extract the tokens 
from a string, the user needs to repeatedly call the tokenize function in a loop, 
each time getting the next token. This makes the code look ugly, and it is not 
an elegant solution. 

Boost library however, provides a more convenient way, the function 'split'. This
function returns all the tokens at one call in an STL vector. However, this 
option is also limited. It supports delimiters of only one character, and cannot
handle situations when the delimiter is itself a token. Consider the following
expression:
"value==((length+256)/(width-16))"
The characters '(', ')', '+', '/' are not only delimiters, they are needed to
evaluate the expression, and should be treated as a token. The string "==" 
cannot even be a delimiter. This expression has no other characters that can be
delimiters. The following string expresses the same expression and can be parsed
using space as a limiter:
"value == ( ( length + 256 ) / ( width - 16 ) )"

The object of this work is to write a tokenize function that returns all the 
tokens at once, and enable delimiters of more then one character.

Description:
Tokenizer Module consists only of one source file "token.cpp", and one header 
file "Token.h". The Module features:
1. Returning all tokens at once in an STL vector.
2. Supports delimiters of any length.
3. Enables treating some delimiters as tokens, while others are regular 
   delimiters in the same parse.

Using the module in code:
The tokenizer function accepts the string to parse, and two delimiters strings,
one for regular delimiters, and the other for delimiters that are also tokens.

std::vector<std::string> tokenize(const std::string &text, // string to parse
           const std::string &delimlist, // delimiters string
           const std::string &delimtok = ""); // delimiters that are also tokens

Constructing the delimiters string:
Since a delimiter can be of any size, this string itself needs a delimiter.
Examples of delimiter strings:

" :\t:\n:;"
"(:):[:]:==:!="
"quick:fox:over:lazy"

The default delimiter for the delimiters string is ':'. If ':' is needed as a 
delimiter for the text to parse there is a way to change it with the following 
interface:

void set_delim(std::string delim);
   
The "main" of the the program is a test that demonstrates the above features.

Producing the binary file to execute:
1. Create a new directory.
2. Open the tarball in the new directory.
3. 'cd' to the new directory.
4. 'cd' into 'src' directory.
5. Type 'make'
6. the binary file produced will be in 'bin' directory.
