#include "Exception.h"
#include <sstream>

BimoException::BimoException(int line, const char* file) noexcept
    : line( line ) , file( file )
{}

const char* BimoException::what() const noexcept
{
    std::ostringstream oss;
    oss << GetType() << std::endl
        << GetOriginString();
    whatBuffer = oss.str();
    return whatBuffer.c_str();
}

const char* BimoException::GetType() const noexcept
{
    return "Bimo Exception";
}

int BimoException::GetLine() const noexcept
{
    return line;
}

const std::string& BimoException::GetFile() const noexcept
{
    return file;
}

std::string BimoException::GetOriginString() const noexcept
{
    std::ostringstream oss;
    oss << "[File] " << file << std::endl
        << "[Line] " << line;
    return oss.str();
}

