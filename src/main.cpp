/* 
* Copyright (C) 2015 by Ariel Segal 
* This file is part of "Tokenizer Module" work 
* The contents of this file are subject to the terms of the Common 
* Development and Distribution License (the "License"). You may not use this file 
* except in compliance with the License. A copy of this license is distributed with
* this work in file LICENSE You can also obtain a copy of the License at 
* http://opensource.org/licenses/CDDL-1.0. See the License for the specific 
* language governing permissions and limitations under the License. When 
* distributing the software, include this License Header Notice in each file and 
* include the License file at http://opensource.org/licenses/CDDL-1.0. 
* The Initial Developer of the Original Software is Ariel Segal 

* Version: 1.0 
* File: main.cpp 
* Author: Ariel Segal 
* Date:  March 28, 2015 
* Description: 
* This program is a test that demonstrates the following features of the 
* Tokenizer Module:
* 1. Returning all tokens at once in an STL vector.
* 2. Supports delimiters of any length.
* 3. Enables treating some delimiters as tokens, while others are regular 
*    delimiters in the same parse.
*/ 

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "tokens.h"

using namespace std;

// Display results of the demostration.
string display(const vector<string> &tokens, const string &title, const string &text, const string &delim, const string &delimtok = "")
{
	stringstream result;
	result << title << endl;
	result << "Delimiters: " << delim << endl;
	if(delimtok.length())
		result << "Delim and token: " << delimtok << endl;
	result << "Text: " << text << endl;
	result << "Tokens:" << endl;
	for(auto it : tokens)
	{
		result << it << endl;
	}
	return result.str();
}

// Demonstate the use and features of the tokenizer module.
int main(int argc, char *argv[])
{
	// Delimiter is more then one character.
	string sentence = "_$&$_The_$&$_quick_$&$_brown_$&$_fox_$&$_jumps_$&$_over_$&$_the_$&$_lazy_$&$_dog_$&$_";
	string delimiter = "_$&$_";
	vector<string> tokens;
	tokens = tokenize(sentence, delimiter);
	cout << display(tokens, "Single Delimiter", sentence, delimiter);
	tokens.clear();
	
	// Multiple delimiters, white space and ';'.
	sentence = " The quick\tbrown\nfox jumps\tover\nthe lazy\tdog;";
	delimiter = " :\t:\n:;";
	tokens = tokenize(sentence, delimiter);
	cout << display(tokens, "Multiple Delimiters", sentence, delimiter);
	tokens.clear();
	
	// Multiple delimiters, some are also tokens themselves. Useful for parsing expressions with operations.
	sentence = ";(The [ quick==brown!=fox] != (jumps)\tover the lazy\tdog);";
	delimiter = " :\t:\n:;";
	string delimtok = "(:):[:]:==:!=";
	tokens = tokenize(sentence, delimiter, delimtok);
	cout << display(tokens, "Multiple Delimiters when some are also tokens", sentence, delimiter, delimtok);
	tokens.clear();
	
	// Multiple delimiters, some are also tokens themselves. keywords can also be delimiters.
	sentence = "Thequickbrownfoxjumpsoverthelazydog";
	delimiter = " ";
	delimtok = "quick:fox:over:lazy";
	tokens = tokenize(sentence, delimiter, delimtok);
	cout << display(tokens, "Multiple Delimiters when some are also tokens", sentence, delimiter, delimtok);
	tokens.clear();
	
	// The default separator between delimiters is ':'. If ':' itself is a delimiter, change the separator to something else.
	set_delim("|");
	sentence = "The:quick:brown:fox:jumps:over:the:lazy:dog:";
	delimiter = ":";
	tokens = tokenize(sentence, delimiter);
	cout << display(tokens, "Change delimiter seperator from ':' to '|'", sentence, delimiter);
	return 0;
}

