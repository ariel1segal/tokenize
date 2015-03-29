# Copyright (C) 2015 by Ariel Segal 
# This file is part of "Tokenizer Module" work 
# The contents of this file are subject to the terms of the Common 
# Development and Distribution License (the "License"). You may not use this file 
# except in compliance with the License. A copy of this license is distributed with
# this work in file LICENSE You can also obtain a copy of the License at 
# http://opensource.org/licenses/CDDL-1.0. See the License for the specific 
# language governing permissions and limitations under the License. When 
# distributing the software, include this License Header Notice in each file and 
# include the License file at http://opensource.org/licenses/CDDL-1.0. 
# The Initial Developer of the Original Software is Ariel Segal 

# Version: 1.0 
# File: Makefile 
# Author: Ariel Segal 
# Date:  March 28, 2015 

CC := g++ -std=c++11
SRCDIR := .
BUILDDIR := ../bin
CFLAGS := -g -Wall
TARGET := $(BUILDDIR)/tokens
 
SRCEXT := cpp
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
DEPS := $(OBJECTS:.o=.deps)

all: $(TARGET)
$(TARGET): $(OBJECTS)
	@echo " Linking..."; $(CC) $(CFLAGS) $^ -o $(TARGET)
 
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo " CC $<"; $(CC) $(CFLAGS) -MD -MF $(@:.o=.deps) -c -o $@ $<
 
clean:
	@echo " Cleaning..."; rm -f $(BUILDDIR)/*.o $(BUILDDIR)/*.deps $(BUILDDIR)/$(TARGET)
 
-include $(DEPS)
 
.PHONY: clean
