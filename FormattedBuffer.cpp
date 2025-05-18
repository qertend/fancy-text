#include "FormattedBuffer.h"

FormattedBuffer::FormattedBuffer(std::streambuf* sb, bool isGreedy) : buf(sb), greedy(isGreedy) {}

bool FormattedBuffer::getGreedy() {
    return greedy;
}

void FormattedBuffer::doUpdate() {
        //reset previous formats (things like invisible don't have their own off code)
        std::string format = getResetString();

        //add the current format codes
        format.append(getFormatString());
        
        //write new format to stream
        buf->sputn(format.c_str(), format.length());
}

std::streamsize FormattedBuffer::xsputn(const char_type* s, std::streamsize n) {
    /* Insert formatting */
    if (!greedy || setUpdateNeeded(false) == true) doUpdate();

    std::streamsize re = 0;
    
    for (int i = 0; i < n; i++) {
        //avoid unwanted coloring due to newlines
        if (s[n] == '\n') {
            //reset formatting to default values
            std::string format = getResetString();
            buf->sputn(format.c_str(), format.length());
            //write newline char
            //mmm pointer arithmetic
            re += buf->sputn(s+n, 1);
            //redo formatting
            doUpdate();
        }
        else re += buf->sputn(s+n, 1);
    }

    if (!greedy) {
        std::string format = this->getResetString();
        buf->sputn(format.c_str(), format.length());
    }

    return re;
}


std::streambuf::int_type FormattedBuffer::overflow(int_type c) {
    buf->sputc(c);
    return c;
}
