#ifndef FormattedBufferH
#define FormattedBufferH

#include "Format.h"
#include <streambuf>

class FormattedBuffer: public Format, public std::streambuf {
    private:
        std::streambuf* buf;
    public:
    FormattedBuffer();
    FormattedBuffer(std::streambuf*);

    protected:
    std::streamsize xsputn(const char_type* s, std::streamsize n) override;
    int_type overflow(int_type c) override;
};

#endif