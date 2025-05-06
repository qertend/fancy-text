#include "FormattedBuffer.h"

FormattedBuffer::FormattedBuffer(std::streambuf* sb) : buf(sb) {}

FormattedBuffer::FormattedBuffer(): buf(std::cout.rdbuf()) {}

std::streamsize FormattedBuffer::xsputn(const char_type* s, std::streamsize n) {
    std::string format = this->getFormatString();
    buf->sputn(format.c_str(), format.length());

    std::streamsize re = buf->sputn(s, n);

    format = this->getResetString();
    buf->sputn(format.c_str(), format.length());

    return re;
}


std::streambuf::int_type FormattedBuffer::overflow(int_type c) {
    buf->sputc(c);
    return c;
}
