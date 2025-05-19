#include "FormattedStream.h"

#include <iostream>

FormattedStream::FormattedStream(std::ostream& os, bool isGreedy): FormattedBuffer(os.rdbuf(), isGreedy), std::ostream(this), display(os) {}
FormattedStream::FormattedStream(bool isGreedy): FormattedBuffer(std::cout.rdbuf(), isGreedy), std::ostream(this), display(std::cout) {}
