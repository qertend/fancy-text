#ifndef FormattedBufferH
#define FormattedBufferH

#include "Format.h"
#include <streambuf>

class FormattedBuffer: public Format, public std::streambuf {
    private:
        bool greedy;
        std::streambuf* buf;
        bool updateNeeded;

        void setUpdateNeeded() override;
    public:
        FormattedBuffer(std::streambuf*, bool = false);
        bool getGreedy();
        void doUpdate();
    protected:
        std::streamsize xsputn(const char_type* s, std::streamsize n) override;
        int_type overflow(int_type c) override;
};

#endif