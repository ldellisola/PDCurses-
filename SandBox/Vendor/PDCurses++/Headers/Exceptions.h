#pragma once
#include <vector>
#include <string>
#include <map>
#include <exception>




#define THROWIF(cond) if(cond) throw new ErrorException();


class ErrorException : std::exception 
{
public:
	ErrorException(std::string msg = "PDCurses Error") :std::exception(msg.c_str()) {}
};