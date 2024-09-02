#pragma once
#include <exception>
#include <string>

class BimoException : public std::exception
{
public:
	BimoException(int line , const char * file ) noexcept;
	const char * what() const noexcept override;
	virtual const char * GetType() const noexcept;
	int GetLine() const noexcept;
	const std::string& GetFile() const noexcept;
	std::string GetOriginString() const noexcept;
private:
	int line;
	std::string file;
protected:
	mutable std::string whatBuffer;
};

