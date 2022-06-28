#!/bin/sh -f
./lexer $* | ./parser $* | ./semant $* 