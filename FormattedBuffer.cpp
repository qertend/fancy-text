#include "FormattedBuffer.h"

FormattedBuffer::FormattedBuffer(streambuf* sb) : buf(sb) {}

FormattedBuffer::FormattedBuffer(): buf(std::cout.rdbuf()) {}

streamsize FormattedBuffer::xsputn(const char_type* s, streamsize n) {
    string format = this->getFormatString();
    buf->sputn(format.c_str(), format.length());

    streamsize re = buf->sputn(s, n);

    format = this->getResetString();
    buf->sputn(format.c_str(), format.length());

    return re;
}


streambuf::int_type FormattedBuffer::overflow(int_type c) {
    buf->sputc(c);
    return c;
}

