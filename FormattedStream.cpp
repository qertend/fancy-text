#include "FormattedStream.h"

#include <ostream>

FormattedStream::FormattedStream(std::ostream& os, bool isGreedy): FormattedBuffer(os.rdbuf(), isGreedy), std::ostream(this), display(os) {}

std::ostream& FormattedStream::CSIsp(int n) {
    return display << "\e[" << n;
}

void FormattedStream::bell() {
    display << "\x07"; //BEL
}

void FormattedStream::cursorUp(int n) {
    CSIsp(n) << 'A';
}

void FormattedStream::cursorDown(int n) {
    CSIsp(n) << 'B';
}

void FormattedStream::cursorRight(int n) {
    CSIsp(n) << 'C';
}

void FormattedStream::cursorLeft(int n) {
    CSIsp(n) << 'D';
}

void FormattedStream::cursorNL(int n) {
    CSIsp(n) << 'E';
}

void FormattedStream::cursorPL(int n) {
    CSIsp(n) << 'F';
}

void FormattedStream::cursorHorizontalAbsolute(int n) {
    CSIsp(n) << 'G';
}

void FormattedStream::eraseInDisplay(EraseType T) {
    CSIsp(T) << 'J';
}

void FormattedStream::eraseInLine(EraseType T) {
    CSIsp(T) << 'K';
}