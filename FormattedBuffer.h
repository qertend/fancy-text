#ifndef FormattedBufferH
#define FormattedBufferH

#include "Format.h"
#include <streambuf>

class FormattedBuffer: public Format, public std::streambuf {
    private:
        std::streambuf* buf;
        const bool greedy;
        bool updateNeeded;

        void setUpdateNeeded() override;
    
    protected:
        std::streamsize xsputn(const char_type* s, std::streamsize n) override;
    
    public:
        FormattedBuffer(std::streambuf*, bool = false);
        bool getGreedy();
        void doUpdate();
};

#endif