#include "FormattedBuffer.h"

void FormattedBuffer::setUpdateNeeded() {
    updateNeeded = true;
}

FormattedBuffer::FormattedBuffer(std::streambuf *sb, bool isGreedy) : buf(sb), greedy(isGreedy), updateNeeded(true) {}

bool FormattedBuffer::getGreedy() {
    return greedy;
}

void FormattedBuffer::doUpdate() {
        updateNeeded = false;
        //reset previous formats (things like invisible don't have their own off code)
        std::string format = getResetString();

        //add the current format codes
        format.append(getFormatString());
        
        //write new format to stream
        buf->sputn(format.c_str(), format.length());
}

std::streamsize FormattedBuffer::xsputn(const char_type* s, std::streamsize n) {
    /* Insert formatting */
    if (!greedy || updateNeeded) doUpdate();

    std::streamsize re = 0;
    
    for (int i = 0; i < n; i++) {
        //avoid unwanted coloring due to newlines
        if (s[i] == '\n') {
            //reset formatting to default values
            std::string format = getResetString();
            buf->sputn(format.c_str(), format.length());
            //write newline char
            //mmm pointer arithmetic
            re += buf->sputn(s+i, 1);
            //redo formatting
            doUpdate();
        }
        else re += buf->sputn(s+i, 1);
    }

    //re += buf->sputn(s, n);

    if (!greedy) {
        std::string format = this->getResetString();
        buf->sputn(format.c_str(), format.length());
    }

    return re;
}
