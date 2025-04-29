#ifndef FormattedBufferH
#define FormattedBufferH

#include "Format.h"
#include <streambuf>

class FormattedBuffer: public Format, public streambuf {
    private:
        std::streambuf* buf;
    public:
    FormattedBuffer();
    FormattedBuffer(streambuf*);

    protected:
    streamsize xsputn(const char_type* s, streamsize n) override;
    int_type overflow(int_type c) override;
};

#endif