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
* File: tokens.h 
* Author: Ariel Segal 
* Date:  March 28, 2015 
* Description: 
* Tokenizer Module exposes two interfaces, the tokenize function, and a function
* to change the default delimiter for the delimiters strings.
* Tokenizer Module features:
* 1. Returning all tokens at once in an STL vector.
* 2. Supports delimiters of any length.
* 3. Enables treating some delimiters as tokens, while others are regular 
*   delimiters in the same parse.
*/ 

#ifndef _TOKENS_H_
#define _TOKENS_H_

#include <vector>
#include <string>

// Split string into tokens. Determine the delimiters and define some of them to
// also be tokens.
std::vector<std::string> tokenize(const std::string &text, // string to parse
                                  const std::string &delimlist, // delimiters string
                                  const std::string &delimtok = ""); // delimiters that are also tokens

// Change the operators between delimiters.
// This function is not thread safe, because it updates a global variable.
void set_delim(std::string delim);


#endif // _TOKENS_H_
