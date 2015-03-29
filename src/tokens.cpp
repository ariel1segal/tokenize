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
* File: tokens.cpp 
* Author: Ariel Segal 
* Date:  March 28, 2015 
* Description:
* This file contains the bodies of the functions of the Tokenize Module. 
* Explanations are in the comments in the source.
*/ 

#include <algorithm>
#include <iostream>
#include "tokens.h"

using namespace std;

// Holds the default separator for the delimiters string. Is changed with the
// function set_delim .
string delim_separator = ":";

// change the default separator for the delimiters string.
// This function is not thread safe, because it updates a global variable.
void set_delim(string delim)
{
	delim_separator = delim;
}

// Prototypes of the functions that are not exposed in this module. It is a good
// practice to give default values for parameters in the prototype even when a 
// prototype is not needed.
vector<string> split(const string &text, const string &delimiter, const bool &delimIsText = false);
void multisplit(vector<string> &result, vector<string> &vorig, vector<string> &vdelim, const bool &delimIsText = false);

// get a vector of tokens from a string supports any size of delimiter, but does
// not support more then one delimiter. This function is used to extract the
// delimiters from the delimiters string, and in the function 'multisplit' that
// does support more then one delimiter.
// If 'delimIsText' is true treat the delimiter as also a token.
vector<string> split(const string &text, const string &delimiter, const bool &delimIsText)
{
	vector<string> tokens;
	string chop;
	size_t first = 0;
	size_t last = 0;
	while(true)
	{
		last = text.find(delimiter, first);
		if(string::npos == last)
			chop = text.substr(first, string::npos);
		else
			chop = text.substr(first, last - first);
		if(chop.length() > 0)
			tokens.push_back(chop);
		if(string::npos == last)
			break;
		first = last + delimiter.length();
		if(delimIsText && (delim_separator != delimiter))
		{
			tokens.push_back(delimiter);
			if(!(first < text.length()))
				break;
		}
	}
	return tokens;
}

// Split each string in the vector 'vorig' according to a delimiter in vectors 
// 'vdelim'. Do this process in loops through all strings and all delimiters.
// If 'delimIsText' is true treat the delimiter as also a token.
// Put the final result in 'result'.
void multisplit(vector<string> &result, vector<string> &vorig, vector<string> &vdelim, const bool &delimIsText)
{
	int vindex = 0;
	vector<string> tokens[2];
	tokens[vindex] = vorig;
	for(auto it : vdelim) // for each delimiter
	{
		while(tokens[vindex].size() > 0) // for each slice of text
		{
			string slice = tokens[vindex].back();
			tokens[vindex].pop_back();
			vector<string> vtemp = split(slice, it, delimIsText); // split the slice to a temp vector

			// append temp vector to the other vector
			tokens[!vindex].reserve(tokens[!vindex].size() + vtemp.size());
			tokens[!vindex].insert(tokens[!vindex].begin(), vtemp.begin(), vtemp.end());
		}
		vindex = !vindex; //switch vector
	}
	result = tokens[vindex];
}

// Split a string into tokens, supporting delimiters of any size, more then one
// delimiter, and able to recognize a delimiter to be also a token.
// Parameters:
// text - The string to split.
// delimlist - A list of delimiters.
// delimtok - A list of delimiters that are also tokens.
// The function returns a vector of tokens.
vector<string> tokenize(const string &text, const string &delimlist, const string &delimtok)
{
	vector<string> vdelim = split(delimlist, delim_separator);
	vector<string> vdelimtok = split(delimtok, delim_separator);
	vector<string> vorig;
	vorig.push_back(text);
	vector<string> tok;
	multisplit(tok, vorig, vdelim);
  vector<string> result;
	multisplit(result, tok, vdelimtok, true);
	return result;
}

